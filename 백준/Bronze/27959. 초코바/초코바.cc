#include <stdio.h>
 
int main() {

  int a = 0, b = 0;

  scanf("%d %d", &a, &b);
 
  if (a * 100 >= b)
  {
    printf("Yes");
  }
  else{
    printf("No");
  }

  return 0;
}
