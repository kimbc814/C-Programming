#include<stdio.h>
#define NO_MAX_WAYPOINTS 50

float   X[NO_MAX_WAYPOINTS] = {0,};
float   Y[NO_MAX_WAYPOINTS] = {0,};
float YAW[NO_MAX_WAYPOINTS] = {0,};

int read_waypoints_data(void){

   FILE *fp = fopen("waypoints.dat", "r");

	int no_line = -1;
	int result;
	float x,y,yaw;   

   do{
      result = fscanf(fp,"%f %f %f", &x,&y,&yaw);
	   no_line++;
	   X[no_line] = x;
	   Y[no_line] = y;
	   YAW[no_line] = yaw;
     

   } while(result !=EOF);
 // printf("END OF LINE  : %d\n", no_line);
  return no_line;
}
int main(){
	int num1 = read_waypoints_data();
	printf("END OF LINE  : %d\n",num1);
	for (int i = 0; i < num1; i++) {
			printf("%2d %10.3f %10.3f %10.3f\n", i + 1, X[i],Y[i],YAW[i]);
		}
	return 0;
}
