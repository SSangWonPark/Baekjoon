#include <stdio.h>
#include <string.h>

int front = 0, back = -1;
int stack[10000];

void push(int value) {
    stack[back] = value;
    back++;
}

void pop() {
    front++;
}

int main() {
    int n = 0;
    char string[6];
    int x = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", string);

        if (strcmp(string, "push") == 0)
        {
            scanf("%d\n", &x);

            push(x);
        }
        else if (strcmp(string, "pop") == 0)
        {
            if (back < front)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", stack[front - 1]);
                pop();
            }
        }
        else if (strcmp(string, "size") == 0)
        {
            printf("%d\n", back - front + 1);
        }
        else if (strcmp(string, "empty") == 0)
        {
            if (back < front)
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
            
        }
        else if (strcmp(string, "front") == 0)
        {
            if (front > back)
            {
                printf("-1\n");
            }

            else
            {
                printf("%d\n", stack[front - 1]);
            }
        }
        else if (strcmp(string, "back") == 0)
        {
            if (front > back)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", stack[back - 1]);
            }
        }
    }

    return 0;
}
