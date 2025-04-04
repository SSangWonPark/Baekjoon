#include <stdio.h>
#include <string.h>

int main(void) {

  char school[10];
  scanf("%s", school);

  if (strcmp(school, "NLCS") == 0)
  {
    printf("North London Collegiate School");
  }
  else if (strcmp(school, "BHA") == 0)
  {
    printf("Branksome Hall Asia");
  }
  else if (strcmp(school, "KIS") == 0)
  {
    printf("Korea International School");
  }
  else if (strcmp(school, "SJA") == 0)
  {
    printf("St. Johnsbury Academy");
  }

  return 0;
}