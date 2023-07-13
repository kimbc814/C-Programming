#include <stdio.h>
////////////////////////////////day1/////////////////////////////////
////////////////////////////////test0////////////////////////////////문자열 출력하기
#include <stdio.h>
#define LEN_INPUT 1000001

int main(void) {
    char s1[LEN_INPUT];
    scanf("%s", s1);
    printf("%s",s1);
    return 0;
}
////////////////////////////////test1////////////////////////////////a와 b 출력하기
int main(void) {
    int a;
    int b;
    scanf("%d %d", &a, &b);
    printf("a = %d\nb = %d", a , b);
    return 0;
}
////////////////////////////////test2////////////////////////////////문자열 반복해서 출력하기
#include <stdio.h>
#define LEN_INPUT 11

int main(void) {
    char s1[LEN_INPUT];
    int a;
    scanf("%s %d", s1, &a);
    for(int i=0;i<a;i++)printf("%s",s1);
    return 0;
}
////////////////////////////////test3////////////////////////////////대소문자 바꿔서 출력하기
#include <stdio.h>
#define LEN_INPUT 20

int main(void) {
    char s1[LEN_INPUT];
    scanf("%s", s1);
    for(int i=0;i<LEN_INPUT;i++){
        if(s1[i]>=97&&s1[i]<=122){
            s1[i]=s1[i]-32;
        }
        else if(s1[i]>=65&&s1[i]<=90){
            s1[i]=s1[i]+32;
        }
    }
    printf("%s",s1);
    return 0;
}
////////////////////////////////test4////////////////////////////////특수문자 출력하기
#include <stdio.h>

int main(void) {
    printf("!@#$%^&*(\\'\"<>?:\;");
    return 0;
}
////////////////////////////////day2/////////////////////////////////
////////////////////////////////test1////////////////////////////////덧셈식 출력하기
#include <stdio.h>

int main(void) {
    int a;
    int b;
    scanf("%d %d", &a, &b);
    printf("%d + %d = %d",a,b, a + b);
    return 0;
}
////////////////////////////////test2////////////////////////////////문자열 붙여서 출력하기
#include <stdio.h>
#define LEN_INPUT1 11
#define LEN_INPUT2 11

int main(void) {
    char s1[LEN_INPUT1];
    char s2[LEN_INPUT2];
    scanf("%s %s", s1, s2);
    printf("%s%s",s1,s2);
    return 0;
}
////////////////////////////////test3////////////////////////////////문자열 돌리기
#include <stdio.h>
#include <string.h>
#define LEN_INPUT 10

int main(void) {
    char s1[LEN_INPUT];
    scanf("%s", s1);
    for(int j=0;j<strlen(s1);j++){
        printf("%c\n",s1[j]);
    }
    return 0;
}

////////////////////////////////test4////////////////////////////////홀짝 구분하기
#include <stdio.h>

int main(void) {
    int a;
    scanf("%d", &a);
    if(a%2==1){
        printf("%d is odd",a);
    }
    else{
        printf("%d is even",a);
    }
    return 0;
}
////////////////////////////////test5////////////////////////////////문자열 겹쳐쓰기
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, const char* overwrite_string, int s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(sizeof(char)*strlen(my_string));
    answer=my_string;
    for(int i=0;i<strlen(overwrite_string);i++){
        
        answer[s+i]=overwrite_string[i];
    }
    return answer;
}