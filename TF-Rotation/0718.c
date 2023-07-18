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

double g_angle_degree;
double g_angle_radian;
double g_Rotation_matrix[2][2];
double g_Rotation_matrix_inverse[2][2];

void Set_rotation_matrix(double m_angle_degree)
{
	g_angle_radian = DEG2RAD(m_angle_degree);

	g_Rotation_matrix[0][0] = cos(g_angle_radian);   g_Rotation_matrix[0][1] = -sin(g_angle_radian);
	g_Rotation_matrix[1][0] = sin(g_angle_radian);   g_Rotation_matrix[1][1] = cos(g_angle_radian);

	printf("Set Rotation : ");
	printf("\n");
	printf("%6.3lf  %6.3lf\n", g_Rotation_matrix[0][0], g_Rotation_matrix[0][1]);
	printf("%6.3lf  %6.3lf\n", g_Rotation_matrix[1][0], g_Rotation_matrix[1][1]);
}

void Set_rotation_matrix_inverse(double m_angle_degree)
{
	g_angle_radian = DEG2RAD(m_angle_degree);

	g_Rotation_matrix_inverse[0][0] = cos(g_angle_radian);   g_Rotation_matrix_inverse[0][1] = sin(g_angle_radian);
	g_Rotation_matrix_inverse[1][0] = -sin(g_angle_radian);  g_Rotation_matrix_inverse[1][1] = cos(g_angle_radian);

	printf("Set Rotation_Inverse : ");
	printf("\n");
	printf("%6.3lf  %6.3lf\n", g_Rotation_matrix_inverse[0][0], g_Rotation_matrix_inverse[0][1]);
	printf("%6.3lf  %6.3lf\n", g_Rotation_matrix_inverse[1][0], g_Rotation_matrix_inverse[1][1]);
}


void TF_BaseLinkMap2BaseLink(Point2D* p_base_link_Point2d, const Point2D* kBase_link_map_point2d, const Pose2D* kBase_link_origin) {
	Set_rotation_matrix(kBase_link_origin->theta);
	p_base_link_Point2d->x = (g_Rotation_matrix[0][0] * kBase_link_map_point2d->x) + (g_Rotation_matrix[0][1] * kBase_link_map_point2d->y);
	p_base_link_Point2d->y = (g_Rotation_matrix[1][0] * kBase_link_map_point2d->x) + (g_Rotation_matrix[1][1] * kBase_link_map_point2d->y);
	printf("base_link_Point2D.x : %6.3lf\n", base_link_Point2D.x);
	printf("base_link_Point2D.y : %6.3lf\n\n", base_link_Point2D.y);
}
void TF_BaseLink2BaseLinkMap(const Point2D* kBase_link_Point2d, Point2D* p_base_link_map_point2d, const Pose2D* kBase_link_origin) {
	Set_rotation_matrix_inverse(kBase_link_origin->theta);
	p_base_link_map_point2d->x = (g_Rotation_matrix_inverse[0][0] * kBase_link_Point2d->x) + (g_Rotation_matrix_inverse[0][1] * kBase_link_Point2d->y);
	p_base_link_map_point2d->y = (g_Rotation_matrix_inverse[1][0] * kBase_link_Point2d->x) + (g_Rotation_matrix_inverse[1][1] * kBase_link_Point2d->y);
	printf("p_base_link_map_Point2D.x : %6.3lf\n", base_link_map_Point2D.x);
	printf("p_base_link_map_Point2D.y : %6.3lf\n\n", base_link_map_Point2D.y);
}

int _tmain(int argc, _TCHAR* argv[]){
	base_link_origin.x = 0.0;
	base_link_origin.y = 0.0;

	base_link_origin.theta = -90;
	base_link_map_Point2D.x=-2;
	base_link_map_Point2D.y = 4;

/*
	printf("angle(deg) : ");
	scanf_s("%lf", &base_link_origin.theta);
	printf("base_link_map_Point2D.x : ");
	scanf_s("%lf", &base_link_map_Point2D.x);
	printf("base_link_map_Point2D.y : ");
	scanf_s("%lf", &base_link_map_Point2D.y);
*/

	TF_BaseLinkMap2BaseLink(&base_link_Point2D, &base_link_map_Point2D, &base_link_origin);

	TF_BaseLink2BaseLinkMap(&base_link_Point2D, &base_link_map_Point2D, &base_link_origin);


	return 0;
}
