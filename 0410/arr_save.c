#include<stdio.h>


//1차원 배열
int* getNumbers1() {
    static int arr[6] = { 1,2,3,4,5,6 };
    return arr;
}
//2차원 배열 int*받고, 포인터 접근
int* getNumbers2_1() {
    static int arr[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    return (int*)arr;
}
//2차원 배열 int*받고, 인덱스 접근
int* getNumbers2_2() {
    static int arr[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    return (int*)arr;
}
//2차원 배열 void*받고, 인덱스 접근
void* getNumbers2_3() {
    static int arr[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    return (void*)arr;
}
//3차원 배열 int*받고, 포인터 접근
int* getNumbers3_1() {
    static int arr[2][2][3] = { {{1,2,3},{4,5,6}}, {{7,8,9},{10,11,12}} };
    return (int*)arr;
}
//3차원 배열 int*받고, 인덱스 접근
int* getNumbers3_2() {
    static int arr[2][2][3] = { {{1,2,3},{4,5,6}}, {{7,8,9},{10,11,12}} };
    return (int*)arr;
}
//3차원 배열 void*받고, 인덱스 접근
void* getNumbers3_3() {
    static int arr[2][2][3] = { {{1,2,3},{4,5,6}}, {{7,8,9},{10,11,12}} };
    return (void*)arr;
}

int main() {
    
    //1차원 배열
    printf("\n 차원 배열\n");
    printf("  ");
    int* nums1 = getNumbers1();
    for (int i = 0; i < 6; i++) {
        printf(" [%d] ", nums1[i]);
    }
    printf("\n\n 2차원 배열 int*받고, 포인터 접근\n  ");
    //2차원 배열 int*받고, 포인터 접근
    int* nums2_1 = getNumbers2_1();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) printf(" [%d] ", *(nums2_1 + i * 3 + j));
        printf(" | ");
    }
    printf("\n\n 2차원 배열 int*받고, 인덱스 접근\n  ");
    //2차원 배열 int*받고, 인덱스 접근
    int(*nums2_2)[3] = (void*)getNumbers2_2();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) printf(" [%d] ", nums2_2[i][j]);
        printf(" | ");
    }
    printf("\n\n 2차원 배열 void*받고, 인덱스 접근\n  ");
    //2차원 배열 void*받고, 인덱스 접근
    int(*nums2_3)[3] = getNumbers2_3();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) printf(" [%d] ", nums2_3[i][j]);
        printf(" || ");
    }
    printf("\n\n 3차원 배열 int*받고, 포인터 접근\n  ");
    //3차원 배열 int*받고, 포인터 접근
    int* nums3_1 = getNumbers3_1();
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) printf(" [%d] ", *(nums3_1 + 6 * i + 3 * j + k));
            if (j != 1) { printf(","); }
        }
        if (i == 0)printf(" || ");
    }
    printf("\n\n 3차원 배열 int*받고, 인덱스 접근\n  ");
    //3차원 배열 int*받고, 인덱스 접근
    int(*nums3_2)[2][3] = (void*)getNumbers3_2();
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) printf(" [%d] ", nums3_2[i][j][k]);
            if (j != 1) { printf(","); }
        }
        if (i == 0)printf(" || ");
    }
    printf("\n\n 3차원 배열 void*받고, 인덱스 접근\n  ");
    //3차원 배열 void*받고, 인덱스 접근
    int(*nums3_3)[2][3] = getNumbers3_3();
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) printf(" [%d] ", nums3_3[i][j][k]);
            if (j != 1) { printf(","); }
        }
        if(i==0)printf(" || ");
    }
    printf("\n");
    return 0;
}