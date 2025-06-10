#include <stdio.h>

int main(void) {

    int n = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int t = 0;
        scanf("%d", &t);

        int ans = 0;

        for (int j = 0; j < t; j++)
        {
            int x = 0;
            scanf("%d", &x);
            ans = ans + x;
        }

        printf("%d\n", ans);
    }

    return 0;
}