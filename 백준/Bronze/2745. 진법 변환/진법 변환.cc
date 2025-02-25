#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    char num[100];
    int rule = 0;
    int total = 0;

    scanf("%s %d", num, &rule);

    int n = strlen(num);
    int power = 0;

    for (int i = n; i > 0; i--)
    {
        if (num[i - 1] >= 'A')
        {
            total = total + (num[i - 1] - 'A' + 10) * (int)pow(rule,power);
        }
        else{
            total = total + (num[i - 1] -'0') * (int)pow(rule,power);
        }

        power++;
    }

    printf("%d", total);

    return 0;
}
