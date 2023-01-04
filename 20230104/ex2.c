#include<stdio.h>

int main(){
	int N,M;
	int imsi;
	
	while(1){
		pritnf("(ex: 1 10)typing two num. :  ");
		scanf("%d%d",&N,&M);
		if((N>=0&&N<100000)&&(M>=0&&M<100000))break;
		printf("error 0<N,M<10000\n");
		printf("retry.. \n");
	}
	if(N>M){
		imsi=N;
		N=M;
		M=imsi;
	}
	printf("\result n%d~%d\n",N,M);
	for(i=N;i<=M;i++)
		printf("%d",i);
	
	return 0;
}
