#include <stdio.h>

int gcd(long long int a, long long int b){
    int r = a % b;

    if (r == 0) {
        return b;
    }

    return gcd(b, r);
}


int main()
{
    long long int a = 0, b = 0;
    long long int temp = 0;

    scanf("%lld %lld", &a, &b);

    temp = gcd(a, b);

    printf("%lld", a * b / temp);
    
    return 0;
}

// 유클리드 호제법 : 최대공약수를 찾는 알고리즘 기법
// gcd(a, b) == gcd(b, r) if) r == 0, 최대공약수 == b
// 재귀함수로 계속 나누면서 gcd(a, b)를 gcd(c, 0)으로 만들어서 구함.