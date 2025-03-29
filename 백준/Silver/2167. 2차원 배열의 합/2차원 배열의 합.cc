#include <stdio.h>

int main() {
  int n = 0, m = 0;
  int num[300][300];
  int t = 0, ans = 0;
  int x1 = 0, y1 = 0;
  int x2 = 0, y2 = 0;

  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
    {
      scanf("%d", &num[i][j]);
    }
  }

  scanf("%d", &t);

  for (int i = 0; i < t; i++)
  {
    ans = 0;

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    for (int x = x1 - 1; x <= x2 - 1; x++)
    {
      for (int y = y1 - 1; y <= y2 - 1; y++)
      {
        ans = ans + num[x][y];
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}