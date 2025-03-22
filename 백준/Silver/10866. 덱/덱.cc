#include <stdio.h>
#include <string.h>

int deque[20001];
int up = 10000, down = 10001;

void push_front(int value){
    up++;
    deque[up] = value;
}

void push_back(int value){
    down--;
    deque[down] = value;
}

int isempty(){
    return (up < down);
}

void pop_front(){
    if (isempty())
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", deque[up]);
        up--;
    }
}

void pop_back(){
    if (isempty())
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", deque[down]);
        down++;
    }
}

int main() {
    int n = 0;
    char string[15];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", string);

        if (strcmp(string, "push_front") == 0)
        {
            int n = 0;

            scanf("%d", &n);

            push_front(n);
        }
        else if (strcmp(string, "push_back") == 0)
        {
            int n = 0;

            scanf("%d", &n);
            
            push_back(n);
        }
        else if (strcmp(string, "pop_front") == 0)
        {
            pop_front();
        }
        else if (strcmp(string, "pop_back") == 0)
        {
            pop_back();
        }
        else if(strcmp(string, "size") == 0)
        {
            printf("%d\n", up - down + 1);
        }
        else if(strcmp(string, "empty") == 0)
        {
            if (isempty())
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
            if (isempty())
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", deque[up]);
            }
        }
        else if (strcmp(string, "back") == 0)
        {
            if (isempty())
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", deque[down]);
            }
        }
    }
    
    return 0;
}

// 덱 구현. 선형 덱.
// 원형 덱이 아니라 메모리적으로 비효율적이지만 그냥 풀긴 쉬움.