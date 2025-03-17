#include <stdio.h>

int front = 1, back = 0;
int stack[1000000];

void push(int value) {
    back++;
    stack[back] = value;
}

void pop() {
    front++;
}

int main() {
    int n = 0;

    scanf("%d", &n);

    for (int i = 1; i < n + 1; i++)
    {
        push(i);
    }

    for (int i = 0; i < n; i++)
    {
        if (back - front == 0)
        {
            printf("%d", stack[front]);
            break;
        }

        pop();
        push(stack[front]);
        pop();
    }

    scanf("%d", &n);

    return 0;
}
