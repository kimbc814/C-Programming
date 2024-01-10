#define _USE_MATH_DEFINES

#include<iostream>
#include <math.h>

using namespace std;

void main() {
	double R = 0.0;
	double L = 0.0;
	double C = 0.0;
	double frequency = 0.0;
	double V_p = 0.0;

	double X_L = 0.0;
	double X_C = 0.0;
	double Z = 0.0;
	
	double I_p = 0.0;
	double phase_angle = 0.0;
	
	cout << "input R (ohm): ";
	cin >> R;

	cout << "input L (Henry): ";
	cin >> L;

	cout << "input C (micro Farad): ";
	cin >> C;
	C = C / pow(10,6);
	
	cout << "input frequency : ";
	cin >> frequency;

	cout << "input V_p : ";
	cin >> V_p;
	
	X_L = 2 * M_PI * frequency * L;
	X_C = 1.0 / (2 * M_PI * frequency * C);
	Z = sqrt(pow(R, 2) + pow(X_L - X_C, 2));
	I_p = V_p / Z;
	phase_angle =180.0/M_PI * atan( (X_L - X_C) / R);


	printf("X_L = 2 * PI * frequency * L =  %0.3lf(ohm)\n", X_L);
	printf("X_C =1 / (2 * PI * frequency * C) = %0.3lf(ohm)\n", X_C);
	printf("Z = (R^2 + (X_L -X_C)^2 )^(1/2) = %0.3lf(ohm)\n", Z);

	printf("I_p = V_p / Z = %0.3lf (A)\n", I_p);
	printf("phase angle = atan((X_L-X_C) / R) = %0.1lf(deg)\n", phase_angle);


	printf("V_R최대 = I_최대 * R = (%0.3lf ohm)(%0.3lf ohm) = %0.2lf V\n", I_p, R, I_p * R);
	printf("V_L최대 = I_최대 * L = (%0.3lf ohm)(%0.3lf ohm) = %0.2lf V\n", I_p, X_L, I_p * X_L);
	printf("V_C최대 = I_최대 * C = (%0.3lf ohm)(%0.3lf ohm) = %0.2lf V\n", I_p, X_C, I_p * X_C);

}

