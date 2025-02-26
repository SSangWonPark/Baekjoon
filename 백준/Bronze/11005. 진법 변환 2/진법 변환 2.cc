#include <stdio.h>

int main()
{
    int num = 0;
    int rule = 0;
    long long temp = 0, len = 0;
    char total[100] = { 0, };

    scanf("%d %d", &num, &rule);

    temp = rule;
    
    while (num >= temp)
    {
        temp = temp * rule;
        len++;
    }

    for (int i = len + 1, j = 0; i > 0; i--)
    {
        if (num % rule >= 10)
        {
            total[i - 1] = num % rule + 'A' - 10;
        }
        else{
            total[i - 1] = num % rule + '0';
        }

        num = num / rule;
    }

    printf("%s", total);

    return 0;
}

// 반례: 1000000000 16 // 해결: temp의 영역을 int -> long long으로 변경.