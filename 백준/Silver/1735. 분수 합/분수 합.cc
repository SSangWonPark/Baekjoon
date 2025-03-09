#include <stdio.h>

int gcd(int a, int b){
  if (b == 0)
  {
    return a;
  }
  else
  {
    return gcd(b, a % b);
  }
  
}

int main()
{
    long long int a = 0, b = 0, c = 0, d = 0;
    long long int up = 0, down = 0;

    scanf("%d %d\n%d %d", &a, &b, &c, &d);

    up = a * d + c * b;
    down = b * d;

    printf("%lld %lld", up/gcd(up, down), down/gcd(up, down));
    
    return 0;
}

// a/b + c/d == (a*d + c*b) / b*d
// 최대공배수를 곱하면 분자 분모는 서로 서로소가 됨. --> 기약분수