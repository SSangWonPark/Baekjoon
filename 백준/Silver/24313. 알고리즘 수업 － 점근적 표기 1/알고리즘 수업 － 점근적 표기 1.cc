#include <stdio.h>

int main()
{
    int a = 0, b = 0; 
    int c = 0, n = 0;

    scanf("%d %d", &a, &b);

    scanf("%d\n%d", &c, &n);
    
    if (c >= a && a * n + b <= c * n)
    {
        printf("1");
    }
    else {
        printf("0");
    }

    return 0;
}

// 빅오 조건 : f(n) <= c⋅g(n)   (n≥n0)
// c는 상수 배율(특정하진 않음. 조건에 맞기만 하면 됨.)
// g(n)은 빅오 O(g(n))에서 g(n)
// omg 문제에 1차함수만 주어짐. n차항으로 고려했던 것들 삭제.