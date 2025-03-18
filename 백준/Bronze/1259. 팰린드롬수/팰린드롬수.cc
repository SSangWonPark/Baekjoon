#include <stdio.h>
#include <string.h>

int main() {
    char word[6];

    while (1)
    {
        scanf("%s", word);

        if (strcmp(word, "0") == 0)
        {
            break;
        }

        int len = strlen(word);
        int flag = 1;

        for (int i = 0; i < len / 2; i++)
        {
            if (!(word[i] == word[len - i - 1]))
            {
                flag = 0;
                break;
            }
        }
        
        if (flag)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    
    return 0;
}