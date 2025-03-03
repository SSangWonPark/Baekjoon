#include <stdio.h>

long long fac(long long n){
    if (n == 0)
    {
        return 1;
    }
    else{
        return n * fac(n - 1);
    }
    
}

int main()
{
    long long n = 0;

    scanf("%d", &n);

    printf("%lld", fac(n));
    
    return 0;
}