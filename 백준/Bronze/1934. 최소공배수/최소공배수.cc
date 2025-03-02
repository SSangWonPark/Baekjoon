#include <stdio.h>

int gcd(int a, int b){
    int r = a % b;

    if (r == 0) {
        return b;
    }

    return gcd(b, r);
}


int main()
{
    int t = 0;
    int a = 0, b = 0;
    int temp = 0;

    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &a, &b);

        printf("%d\n", a * b / gcd(a, b));
    }
    
    return 0;
}

// 유클리드 호제법 : 최대공약수를 찾는 알고리즘 기법
// gcd(a, b) == gcd(b, r) if) r == 0, 최대공약수 == b
// 재귀함수로 계속 나누면서 gcd(a, b)를 gcd(c, 0)으로 만들어서 구함.
// 최소공약수 == a * b / 최대공배수