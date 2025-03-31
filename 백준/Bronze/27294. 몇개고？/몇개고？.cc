#include <stdio.h>
 
int main() {

  int a = 0, b = 0;

  scanf("%d %d", &a, &b);
 
  if (b == 0 && (a >= 12 && a <= 16))
  {
    printf("320");
  }
  else{
    printf("280");
  }
  
  return 0;
}