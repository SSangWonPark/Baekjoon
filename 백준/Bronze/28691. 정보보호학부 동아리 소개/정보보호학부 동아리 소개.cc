#include <stdio.h>

int main() {
  char n = 0;

  scanf("%c", &n);

  if (n == 'M')
  {
    printf("MatKor");
  }
  else if (n == 'W')
  {
    printf("WiCys");
  }
  else if (n == 'C')
  {
    printf("CyKor");
  }
  else if (n == 'A')
  {
    printf("AlKor");
  }
  else if (n == '$')
  {
    printf("$clear");
  }

  return 0;
}

