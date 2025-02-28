#include <stdio.h>

int main()
{
    int num[4] = { 0, };
    int count = 0;

    for (int i = 0; i < 3; i++)
    {
        count = 0;

        scanf("%d %d %d %d", &num[0], &num[1], &num[2], &num[3]);

        for (int j = 0; j < 4; j++)
        {
            if (num[j] == 1)
            {
                count++;
            }
            
        }
    
        if (count == 1)
        {
            printf("C\n");
        }
        else if (count == 2)
        {
            printf("B\n");
        }
        else if (count == 3)
        {
            printf("A\n");
        }
        else if (count == 4)
        {
            printf("E\n");
        }
        else if (count == 0)
        {
            printf("D\n");
        }    
    }
    
    return 0;
}