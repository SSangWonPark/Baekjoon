#include <stdio.h>
#include <string.h>

int world(char *word) {
    char stack[100];
    int top = -1;

    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] == '(' || word[i] == '[') 
        {
            stack[++top] = word[i];
        } 
        else if (word[i] == ')' || word[i] == ']') 
        {
            if (top < 0) 
            {
                return 0;
            }

            if (!((stack[top] == '(' && word[i] == ')') || (stack[top] == '[' && word[i] == ']')))
            {
                return 0;
            }
                top--;
        }
    }

    return top == -1;
}

int main() {
    char word[101];

    while (1)
    {
        fgets(word, sizeof(word), stdin);
        
        word[strcspn(word, "\n")] = '\0';

        if (strcmp(word, ".") == 0)
        {
            break;
        }

        if (strlen(word) == 0) {
            continue;
        }

        if (world(word))
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

// scanf("%[^\n]s")로 받아지지 않음. -> fgets 사용(한줄씩 입력 받음. 단, 마지막에 \n도 포함함.)
// c언어에서 || 연산자가 && 연산자보다 우선순위가 높음. 고려사항.
// case 1: 여는 괄호 ->  push
// case 2: 스택이 비어있는데 닫는 괄호 -> false 바로 return 0
// case 3: 스택에 여는 괄호와 짝이 안 맞는 닫는 괄호 -> false 바로 return 0
// case 4: 스택에 여는 괄호와 짝이 맞는 닫는 괄호 -> pop
// 왠지 모르겠는데 빈 문자열이 껴있는 경우가 존재 -> 예외처리