#include <stdio.h>
#include <string.h>

int main()
{
    char string[3][10];
    char color[10][10] ={"black", "brown", "red", "orange", "yellow",
                        "green", "blue", "violet", "grey", "white"};
    long long ans = 0;

    scanf("%s\n%s\n%s", &string[0][0], &string[1][0], &string[2][0]);

    for (int i = 0; i < 10; i++)
    {
        if (strstr(string[0], color[i]) == &string[0][0])
        {
            ans = ans + i * 10;
            break;
        }
    }
    
    for (int i = 0; i < 10; i++)
    {
        if (strstr(string[1], color[i]) == &string[1][0])
        {
            ans = ans + i;
            break;
        }
    }
    
    for (int i = 0; i < 10; i++)
    {
        if (strstr(string[2], color[i]) == &string[2][0])
        {
            for (int j = 0; j < i; j++)
            {
                ans = ans * 10;
            }

            break;
        }
    }

    printf("%lld", ans);

    return 0;
}