#include <stdio.h>

#define SWAP(a,b)  {int t; t = a; a=b; b=t;}//a와 b를 교환


int* origin;
int on;

void QuickSort(int* base, int n);
void ViewArr(int* arr, int n);

int main(void)
{
    int arr[10] = { 9,4,3,10,5,8,7,6,2,1 };
    origin = arr;
    on = 10;
    ViewArr(arr, 10);
    QuickSort(arr, 10);
    ViewArr(arr, 10);
    return 0;
}



void PrintSpace(int n);

void QuickSort(int* base, int n)
{
    int pivot = 0; // 피벗의 위치 기억하는 변수
    int left = 0, right = 0; // 피벗보다 큰 값과 작은 값의 위치를 찾기위한 변수

    if (n <= 1)
    {
        return;
    }

    left = 0;
    right = n;

    while (1)
    {
        for (left++; (left < n) && (base[0] >= base[left]); left++);

        for (right--; (right > 0) && (base[0] < base[right]); right--);

        if (left < right)
        {
            SWAP(base[left], base[right]);
            PrintSpace(base - origin);
            ViewArr(base, n);

        }
        else
        {
            break;
        }
    }

    SWAP(base[0], base[right]);
    PrintSpace(base - origin);
    ViewArr(base, n);
    QuickSort(base, right);
    QuickSort(base + left, n - left);
}

void PrintSpace(int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("   ");
    }
}

void ViewArr(int* arr, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("%2d ", arr[i]);
    }
    printf("\n");
}
