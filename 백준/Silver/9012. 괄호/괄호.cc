#include <stdio.h>
#include <string.h>

int top = -1;

void push() {
    top++;
}

void pop() {
    top--;
}

int main() {
    int n = 0;
    char string[51];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        top = -1;

        scanf("%s", string);

        for (int j = 0; j < strlen(string); j++)
        {
            if (string[j] == '(')
            {
                push();
            }
            else if (string[j] == ')')
            {
               pop();
            }

            if (top < -1)
            {
                break;
            }
            
        }

        if (top == -1) {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}