#include <stdio.h>

int main(void) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int ans = 0;

    for (int i = 1; i <= a; i++)
    {
      ans = ans + i * b + i * i * c;
    }

    printf("%d", ans);

    return 0;
}