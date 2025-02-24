#include <stdio.h>

int main()
{
    char string[5][16] = { NULL, };

    for (int i = 0; i < 5; i++)
    {
        scanf("%s", string[i]);
    }

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (string[j][i] != NULL)
            {
                printf("%c", string[j][i]);
            }
            
        }
        
    }

    return 0;
}