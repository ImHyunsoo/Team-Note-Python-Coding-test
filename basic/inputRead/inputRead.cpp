// 문자열 한 줄 읽어서  공백기준으로 나눠서 정수로 읽기
//    51    0  37  20  -2  9  33
// 51, 0, 37, 20, -2, 9, 33,
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], *s;
    int num[100], i, cnt = 0;

    // gets(str);
    scanf_s("%[^\n]", str, 100);

    for (s = strtok(str, " "); s; s = strtok(NULL, " "))
        if (sscanf(s, "%d", &num[cnt]) > 0)
            cnt++;

    for (i = 0; i < cnt; i++)
        printf("%d, ", num[i]);
    printf("\n");
}