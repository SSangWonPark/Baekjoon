#include <stdio.h>

int main() {
    int n, m;
    int num[10000];
    int start = 0, end = 0;
    int sum = 0, count = 0;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    while (end <= n) 
    {
      if (sum < m) 
      {
      sum = sum + num[end++];    
      } 
      else 
      {           
        if (sum == m) 
        {               
          count++;         
        }      

      sum = sum - num[start++];
      }
    }

    printf("%d\n", count);

    return 0;
}

// 연속되는 수열이기 때문에 선형적으로 끝점부터 마지막으로 밀면서 체크하고, 시작점은 빼면서 다시 체크