#include <stdio.h> // printf, gets_s 함수 사용

#define MAX_COUNT 40   // 정수의 개수는 최대 40까지 사용
#define MAX_LENGTH 128 // 문자열은 최대 128의 크기를 가짐

int ParsingValue(int *ap_num_list, int a_max_count, char *ap_str)
{
    int *p_start_pos = ap_num_list;
    int num = 0; // 정수 분리에 사용할 변수
    // 숫자 분리 상태를 기억할 변수 (0이면 진행 않됨, 1이면 음수 진행, 3이면 양수 진행)
    int state = 0;

    while (*ap_str == ' ')
        ap_str++; // 앞쪽에 추가된 공백문자를 제거함

    // 숫자를 포함한 문자열의 끝까지 체크함
    for (; *ap_str; ap_str++)
    {
        if (*ap_str != ' ')
        {
            if (state == 0)
            { // 숫자 분리가 진행되지 않은 경우!
                if (*ap_str == '-')
                {
                    state = 1; // 음수!
                    ap_str++;  // 부호 다음에 있는 수자로 이동!
                }
                else
                    state = 3; // 양수!
            }
            // 공백 문자가 아니면 해당 문자를 숫자로 변경해서 num 변수에 합산함
            num = num * 10 + *ap_str - '0';
        }
        else
        {
            if ((ap_num_list - p_start_pos) < a_max_count)
            {
                // 공백 문자라면 num에 저장된 변수의 값이 완료된 것으로
                // 생각하고 a_num_list 배열에 추가하고 분리된 정수의 개수를 증가시킴
                // 이때 state 값이 1이면 음수로 처리하기 위해 num 값에 -1을 곱해서 대입하고
                // state 값이 3이면 양수이기 때문에 num을 그대로 대입하면 됨
                *ap_num_list++ = num * (state - 2);

                // 다음 분리할 숫자를 저장하기 위해 num 변수를 0으로 초기화함
                num = 0;
                state = 0; // 숫자 분리가 완료되었음을 설정!
                while (*(ap_str + 1) == ' ')
                    ap_str++; // 공백 문제가 중복으로 사용되면 제거함
            }
            else
                return ap_num_list - p_start_pos;
        }
    }

    // 숫자를 분리 중에 반복문이 중단되었으면 해당 숫자를 배열에 추가함
    if (state)
        *ap_num_list++ = num * (state - 2);

    return ap_num_list - p_start_pos; // 분리한 정수의 개수를 반환함
}

int main()
{
    char str[MAX_LENGTH];    // 문자열을 저장할 변수
    int num_list[MAX_COUNT]; // 분리한 정수를 저장할 변수

    printf("숫자를 공백 문자로 구분해서 입력하세요\n");
    // gets_s(str, MAX_LENGTH);
    scanf_s("%[^\n]s", str, MAX_LENGTH);

    int count = ParsingValue(num_list, MAX_COUNT, str);

    if (count > 0)
    {
        printf("\n입력된 값: %d", num_list[0]);
        for (int i = 1; i < count; i++)
            printf(", %d", num_list[i]);
    }
    printf("\n");

    return 0;
}