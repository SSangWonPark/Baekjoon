#include <stdio.h>
 
int main() {

  int n = 0;
  int a = 0, b = 0;

  scanf("%d", &n);
 
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &a, &b);

    printf("Case %d: %d\n", i + 1, a + b);
  }

  return 0;
}