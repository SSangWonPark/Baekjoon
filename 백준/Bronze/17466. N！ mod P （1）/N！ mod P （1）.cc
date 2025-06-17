#include <stdio.h>

int main(void) {
    int a = 0, b = 0;
    scanf("%d %d", &a, &b);

    long long ans = 1;
    for (int i = 1; i <= a; i++) {
        ans = (ans * i) % b;
    }

    printf("%lld", ans);
    return 0;
}

// 펙토리얼 구하고 하기엔 너무 큼. => 매번 모듈러 연산