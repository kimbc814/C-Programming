#pragma warning(disable :4996)
#define MAX_DATA_NO 100
#include<math.h>
#include<stdio.h>

double sonar_data[MAX_DATA_NO] = { -1, };
int no_line = -1;

int read_sonar() {
	double temp;

	int result;
	FILE* fs = fopen("C:/Users/user/Desktop/c/sonar.dat", "r");
	if (fs == NULL) {
		printf("file does not EXIT");
	}
	else {
		do {
			result = fscanf(fs, "%lf", &temp);
			sonar_data[++no_line] = temp;

		} while (result != EOF);
		fclose(fs);
		printf("line : %d\n", no_line);

		for (int i = 0; i < no_line; i++) {
			printf("%d %lf\n", i + 1, sonar_data[i]);
		}
	}
}
	float avrg(){

		double Sum, m;

		Sum = 0;
		for (int i = 0; i < no_line; i++) {
			Sum += sonar_data[i];
		}
		m = Sum / no_line;
		printf(" 평균 : %lf\n", m);
	}
	float csqrt() {
		double Sum = 0, m = 0, v = 0, a = 0;

		for (int i = 0; i < no_line; i++) {
			Sum += (sonar_data[i] - m) * (sonar_data[i] - m);
		}
	
		v = Sum / no_line;

		a = sqrt(v);

		printf(" 표준편차 : %lf\n", a);
	}
	int main(){
		read_sonar();
		avrg();
		csqrt();



		return 0;
	}
	
