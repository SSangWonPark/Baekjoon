#include <stdio.h>
#include <string.h>

int goodword(char *word) {
    char stack[100000];
    int top = -1;

    for (int i = 0; word[i] != '\0'; i++) {
        if (top >= 0 && stack[top] == word[i]) 
        {
            top--;
        } 
        else 
        {
            stack[++top] = word[i];
        }
    }

    return (top == -1);
}

int main() {
    int n, ans = 0;
    char word[100001];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", word);
        if (goodword(word)) {
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}

// 스택으로 쌓아 올려서 짝지어 사라지게 하기.
// 교차하는 순간 스택 제거 불가. 스택이 0이면 성공.