#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
    FILE* fp; //파일 포인터

    fp = fopen("/Users/Hoon/Develope/3-1/File_Processing/exampleFile.txt", "wt");
    float num1;
    float num2;
    printf("1. 숫자 입력 : ");
    scanf("%f", &num1);
    printf("2. 숫자 입력 : ");
    scanf("%f", &num2);


    if(fp == NULL)
    {
        printf("실패 - 종료\n");
        return 1;
    }

    fprintf(fp, "사칙계산 파일처리 연습\n");
    fprintf(fp, "더하기 결과 값 : %f\n", num1+num2);
    fprintf(fp, "빼기 결과 값 : %f\n", num1-num2);
    fprintf(fp, "나누기 결과 값 : %f\n", num1/num2);
    fprintf(fp, "곱하기 결과 값 : %f\n", num1*num2);

    fclose(fp);

    printf("완료");
    return 0;
}