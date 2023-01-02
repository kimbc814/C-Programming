#include<stdio.h>
void example1(){
	FILE *fp=fopen("data.txt","wt");
	if(fp==NULL){
		puts("파일오픈 실패!");
		return ;
	}
	
	fputc('A',fp);
	fputc('B',fp);
	fputc('C',fp);
	fputs("\nabc\n",fp);
	fprintf(fp,"%c\n",'c');
	fclose(fp);
	return ;
}

void example2(){
	
	FILE *fp=fopen("data.txt","rt");
	if(fp==NULL){
		puts("파일오픈 실패!");
		return ;
	}
	for(int i=0;i<10;i++){
		char ch;//= fgetc(fp);
		fscanf(fp, "%c", &ch);
		printf("%c", ch);
	}
	
	fclose(fp);
	return ;
}
int main(){
	example1();
	example2();
	int data1=0;
	double data2=0.0;
	FILE *fp=fopen("data1.txt","rt");
	if(fp==NULL){
		puts("파일오픈 실패!");
		return -1;
	}
	for(int i=0;i<2;i++){
		fscanf(fp, "%d", &data1);
		printf("%d\n", data1);
	}
	for(int i=0;i<2;i++){
		fscanf(fp, "%lf", &data2);
		printf("%lf\n", data2);
	}
	
	fclose(fp);
	return 0;
}