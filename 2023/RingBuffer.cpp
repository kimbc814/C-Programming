#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	
	int ringBuff[5] = { 0, };
	int index = 0;
	while (1) {
		if (index > 4) {
			index = 0;
		}
		cout << index+1 << " 번째 데이터 입력하시오 : ";
		scanf("%d", &ringBuff[index]);

		for (int i = 0; i < 5; i++) {
			printf(" %d ",ringBuff[i]);
		}
		cout << endl;
		index++;
	}
	return 0;
}
