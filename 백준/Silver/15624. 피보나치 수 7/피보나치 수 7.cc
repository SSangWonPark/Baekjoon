#include <stdio.h>
#define MOD 1000000007

long long dp[1000001];

int main() {
    int n = 0;

    scanf("%d", &n);

    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    printf("%lld", dp[n]);

    return 0;
}