#include <stdio.h>

int main()
{
    int n = 0;
    int ans = 2;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        ans = ans + (ans -  1);
    }

    printf("%d", ans*ans);
    
    return 0;
}