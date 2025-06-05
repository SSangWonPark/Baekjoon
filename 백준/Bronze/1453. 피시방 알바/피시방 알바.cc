#include <stdio.h>

int main(void) {

    int n = 0;
    int num[101] = { 0, };
    int cnt = 0;

    scanf("%d", &n);

    int x = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);

        if (num[x] == 1)
        {
            cnt++;
        }
        else {
            num[x] = 1;
        }
    }

    printf("%d", cnt);

    return 0;
}