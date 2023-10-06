#include<stdio.h>
#include<math.h>

#define DATA_SIZE_TEMPERATURE_RESISTANCE 7

struct {
	double X[DATA_SIZE_TEMPERATURE_RESISTANCE];
	double Y[DATA_SIZE_TEMPERATURE_RESISTANCE];
}cal_data;

cal_data = {
	{106.0,315.0,481.0,736.0,936.0,1083.0,1232.0},
	{1.56,2.67,3.55,4.90,5.95,6.74,7.53}
};

double solution(double resistance){
	int i;
	double x1 = cal_data.X[i];
	double x2 = cal_data.X[i + 1];
	double y1 = cal_data.Y[i];
	double y2 = cal_data.Y[i + 1];
	double t;
	double resistance0 = 1.0;

	for (int j = 0; j < DATA_SIZE_TEMPERATURE_RESISTANCE - 1; j++)
	{
		if (resistance < cal_data.X[0])
		{
			i = 0;
		}
		else if ((resistance >= cal_data.X[j]) && (resistance < cal_data.X[j + 1]))
		{
			i = j;
		}
		else
		{
			i = DATA_SIZE_TEMPERATURE_RESISTANCE - 2;
		}
	}
	double m = ((y2 - y1) / (x2 - x1));
	t = (resistance - resistance0) / m;
	return t;
}

int main(){
	double resistance = 3.0 / (340 * pow(10.0, -3.0));
	printf("Resistance = %0.3lf (ohm)\nt = %0.3lf(Celsius)\n", resistance, solution(resistance));
	return 0;
}