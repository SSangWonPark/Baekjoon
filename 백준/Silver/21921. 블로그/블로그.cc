#include <stdio.h>

int array[250000];

int main(){
    int n = 0, m = 0;
    int max = 0;
    int count = 1;
    int sum = 0;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    
    for (int i = 0; i < m; i++)
    {
        sum = sum + array[i];    
    }

    max = sum;

    for (int i = m; i < n; i++)
    {       
        sum = sum - array[i - m] + array[i];

        if (sum > max)
        {
            max = sum;
            count = 1;
        }
        else if (sum == max)
        {
            count++;
        }
    }
    
    if (max == 0)
    {
        printf("SAD");
    }
    else{
        printf("%d\n%d", max, count);
    }

    return 0;
}

// 단순한 곱 = 250000 * 250000 시간초과
// 슬라이딩 윈도우 이용.
// 합을 구해두고 맨 앞의 값을 빼고 맨 뒤 값을 더하는 식으로 구성.