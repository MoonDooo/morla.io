#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>   

int strcmp(char *x, char *y);
int main()
{
    char* st_str= (char*)malloc(sizeof(char) * 10);
    char* nd_str = (char*)malloc(sizeof(char) * 10);

    printf("첫번째 문자열을 입력하십시요. : ");
    scanf("%s", st_str);
    printf("두번째 문자열을 입력하십시오. : ");
    scanf("%s", nd_str);
    int result = strcmp(st_str,nd_str);

    if (result == 1) {
        printf("두 문자열은 같습니다.");
    }
    else
    {
        printf("두 문자열은 같지 않습니다.");
    }
    free(st_str);    
    free(nd_str);
    return 0;
}
int strcmp(char *x, char *y) {
    int i = 0;
    for (i = 0; x[i] != NULL || y[i] != NULL; ++i) {
        if (x[i] != y[i])
            return 0;
    }
    return 1;
}
