#define MAX_DATA_NO 100
#include<math.h>
#include<stdio.h>

double sonar_data[MAX_DATA_NO]={-1,};

int main()
{
	double temp,Sum,m,v,a;
	int no_line = -1;
	int result;
	FILE* fs = fopen("sonar.dat", "r");
	if(fs ==NULL){
		printf("file does not EXIT");
	}
	else{
		do{
		result = fscanf(fs,"%lf", &temp);
		sonar_data[++no_line]=temp;
	
		}while(result != EOF);
		fclose(fs);
		printf("line : %d\n",no_line);
		
		for(int i=0;i<no_line;i++){
			printf("%d %lf\n",i+1,sonar_data[i]);
		}
		
    	Sum=0;
		for(int i=0;i<no_line;i++){
			Sum+=sonar_data[i];
		}
		m=Sum/no_line;
		
		Sum=0;
		for(int i=0;i<no_line;i++){
			Sum+=(sonar_data[i]-m)*(sonar_data[i]-m);
		}
		v=Sum/no_line;
		
		a=sqrt(v);
		
		printf(" 평균 : %lf\n",m);
		printf(" 표준편차 : %lf\n",a);
		
		
	}
	return 0;
}
