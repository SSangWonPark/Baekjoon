#include <stdio.h>

int main()
{
    int num[5] = { 0, };
    int sum = 0;
    int temp = 0;

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &num[i]);
        sum = sum + num[i];
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (num[j] > num[j + 1])
            {
                temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }
    

    printf("%d\n%d", sum/5, num[2]);

    return 0;
}