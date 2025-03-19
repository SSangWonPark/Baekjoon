#include <stdio.h>
#include <string.h>

int stack[100];
int top = -1;

void push(int n){
    stack[++top] = n;
}

void pop(){
    top--;
    top--;
}

int main() {
    char num[101];

    scanf("%s", num);

    int len = strlen(num);

    for (int i = 0; i < len; i++)
    {
        if (num[i] >= '0' && num[i] <= '9')
        {
            num[i] = num[i] - '0';
            push(num[i]);
        }
        else if (num[i] == '+')
        {
            int tmep = stack[top - 1] + stack[top];
            pop();
            push(tmep);
        }
        else if (num[i] == '-')
        {
            int tmep = stack[top - 1] - stack[top];
            pop();
            push(tmep);
        }
        else if (num[i] == '*')
        {
            int tmep = stack[top - 1] * stack[top];
            pop();
            push(tmep);
        }
        else if (num[i] == '/')
        {
            int tmep = stack[top - 1] / stack[top];
            pop();
            push(tmep);
        }
    }
    
    printf("%d", stack[top]);
    
    return 0;
}

// 후위 표기법.
// 스택을 이용해 풀이.