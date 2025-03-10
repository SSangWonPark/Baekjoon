#include <stdio.h>

int top = -1;
int stack[1000000];

void push(int value) {
    top++;
    stack[top] = value;
}

void pop() {
    stack[top--];
}

int main() {
    int n = 0;
    int x = 0, num = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);

        if (x == 1)
        {
            scanf("%d", &num);
            push(num);
        }
        else if (x == 2)
        {
            if (top < 0)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", stack[top]);
                pop();
            }
        }
        else if (x == 3)
        {
            printf("%d\n", top + 1);
        }
        else if (x == 4)
        {
            if (top < 0)
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
        }
        else if (x == 5)
        {
            if (top <= -1)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", stack[top]);
            }
        }
    }

    scanf("%d", &n);

    return 0;
}
