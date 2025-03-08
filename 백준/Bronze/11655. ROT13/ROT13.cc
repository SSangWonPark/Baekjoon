#include <stdio.h>
#include <string.h>

int main()
{
  char string[101];

  scanf("%[^\n]s", string);

  int n = strlen(string);

  for (int i = 0; i < n; i++)
  {
    if (string[i] >= 'a' && string[i] <= 'z' - 13 || string[i] >= 'A' && string[i] <= 'Z' - 13) 
    {
      
      string[i] = string[i] + 13;
    }
    else if (string[i] <= 'z' && string[i] >= 'z' - 13 || string[i] <= 'Z' && string[i] >= 'Z' - 13)
    {
      string[i] = string[i] - 13;
    }
    
    printf("%c", string[i]);
  }

    return 0;
}

// char이기 때문에 127이 넘으면 오버플로우되서 -로 바뀜.