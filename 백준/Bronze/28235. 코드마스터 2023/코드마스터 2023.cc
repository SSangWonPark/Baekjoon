#include <stdio.h>
#include <string.h>

int main(void) {

  char school[10];
  scanf("%s", school);

  if (strcmp(school, "SONGDO") == 0)
  {
    printf("HIGHSCHOOL");
  }
  else if (strcmp(school, "CODE") == 0)
  {
    printf("MASTER");
  }
  else if (strcmp(school, "2023") == 0)
  {
    printf("0611");
  }
  else if (strcmp(school, "ALGORITHM") == 0)
  {
    printf("CONTEST");
  }

  return 0;
}