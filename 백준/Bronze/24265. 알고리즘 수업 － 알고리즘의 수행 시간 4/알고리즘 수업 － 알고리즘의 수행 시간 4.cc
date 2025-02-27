#include <stdio.h>

int main()
{
    long long n = 0;

    scanf("%d", &n);

    printf("%ld\n2", n * (n - 1) / 2);

    return 0;
}

// for문이 두개 시간은 (n-1)*n O(n^2)
// i ~ n ==> n / 2