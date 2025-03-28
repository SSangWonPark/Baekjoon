#include <stdio.h>

int main() {
    int n = 0, m = 0;
    int num[100000];
    int s = 0, d = 0;
    int ans = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    
    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {
        ans = 0;

        scanf("%d %d", &s, &d);

        for (int i = s - 1; i <= d - 1; i++)
        {
            ans = ans + num[i];
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
