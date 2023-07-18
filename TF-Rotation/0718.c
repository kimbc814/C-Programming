// TF_Rotation.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.

#include "stdafx.h"
#define _USE_MATH_DEFINES
#include "math.h"

#define RAD2DEG(x)   x*180/M_PI
#define DEG2RAD(x)   x/180*M_PI

typedef struct 
{
	double x;
	double y;
	double theta;
} Pose2D;

typedef struct
{
	double x;
	double y;	
} Point2D;

Pose2D    base_link_origin;
Point2D   base_link_Point2D, base_link_map_Point2D;

double angle_degree;
double angle_radian;
double Rotation_matrix[2][2];
double Rotation_matrix_inverse[2][2];

void set_rotation_matrix(double m_angle_degree)
{
	angle_radian = DEG2RAD(m_angle_degree);

	Rotation_matrix[0][0] = cos(angle_radian);   Rotation_matrix[0][1] = -sin(angle_radian);
	Rotation_matrix[1][0] = sin(angle_radian);   Rotation_matrix[1][1] = cos(angle_radian);

	printf("Set Rotation : ");
	printf("\n");
	printf("%6.3lf  %6.3lf\n", Rotation_matrix[0][0], Rotation_matrix[0][1]);
	printf("%6.3lf  %6.3lf\n", Rotation_matrix[1][0], Rotation_matrix[1][1]);
}

void set_rotation_matrix_inverse(double m_angle_degree)
{
	angle_radian = DEG2RAD(m_angle_degree);

	Rotation_matrix_inverse[0][0] = cos(angle_radian);   Rotation_matrix_inverse[0][1] = sin(angle_radian);
	Rotation_matrix_inverse[1][0] = -sin(angle_radian);  Rotation_matrix_inverse[1][1] = cos(angle_radian);

	printf("Set Rotation_Inverse : ");
	printf("\n");
	printf("%6.3lf  %6.3lf\n", Rotation_matrix_inverse[0][0], Rotation_matrix_inverse[0][1]);
	printf("%6.3lf  %6.3lf\n", Rotation_matrix_inverse[1][0], Rotation_matrix_inverse[1][1]);
}


void TF_base_link_base_link_map(Point2D base_link_Point2D, Point2D *base_link_map_point2d, Pose2D base_link_origin)
{
	double Trans_X = (Rotation_matrix_inverse[0][0] * base_link_Point2D.x) + (Rotation_matrix_inverse[0][1] * base_link_Point2D.y);
	double Trans_Y = (Rotation_matrix_inverse[1][0] * base_link_Point2D.x) + (Rotation_matrix_inverse[1][1] * base_link_Point2D.y);
	
	printf("TF_base_link_base_link_map : ");
	printf("X : %6.3lf Y :  %6.3lf  \n", Trans_X,Trans_Y);
}

void TF_base_link_map_base_link(Point2D base_link_Point2D, Point2D* base_link_map_point2d, Pose2D base_link_origin)
{
	double Trans_x = (Rotation_matrix[0][0] * base_link_map_point2d->x) + (Rotation_matrix[0][1] * base_link_map_point2d->y);
	double Trans_y = (Rotation_matrix[1][0] * base_link_map_point2d->x) + (Rotation_matrix[1][1] * base_link_map_point2d->y);

	printf("TF_base_link_map_base_link : ");
	printf("X : %6.3lf  Y: %6.3lf  \n", Trans_x, Trans_y);
}


int _tmain(int argc, _TCHAR* argv[])
{
	//angle_degree = 90;
	//angle_radian = DEG2RAD(angle_degree);

	base_link_origin.x = 0.0;
	base_link_origin.y = 0.0;
	base_link_origin.theta = -90;	

	base_link_Point2D.x = 4.0;
	base_link_Point2D.y = 2.0;
	 
	base_link_map_Point2D.x = -2.0;
	base_link_map_Point2D.y = 4.0;

	set_rotation_matrix(base_link_origin.theta);
	set_rotation_matrix_inverse(base_link_origin.theta);
	
	TF_base_link_base_link_map(base_link_Point2D, &base_link_map_Point2D, base_link_origin);
	TF_base_link_map_base_link(base_link_Point2D, &base_link_map_Point2D, base_link_origin);

	return 0;
}
