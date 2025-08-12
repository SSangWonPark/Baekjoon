#include <stdio.h>

int stack[2000001];
int up = 1000000;
int down = 1000001;

int isempty(){
    return (up < down);
}

void uppush(int v){
    up++;
    stack[up] = v;
}

void downpush(int v){
    down--;
    stack[down] = v;
}

void uppop(){
    if (!isempty())
    {
        printf("%d\n", stack[up]);
        up--;
    }
    else{
        printf("-1\n");
    }
}

void downpop(){
    if (!isempty())
    {
        printf("%d\n", stack[down]);
        down++;
    }
    else{
        printf("-1\n");
    }
}

void count(){
    printf("%d\n", up - down + 1);
}

void uppeek(){
    if (!isempty())
    {
        printf("%d\n", stack[up]);
    }
    else{
        printf("-1\n");
    }
}

void downpeek(){
    if (!isempty())
    {
        printf("%d\n", stack[down]);
    }
    else{
        printf("-1\n");
    }
}

int main() {

    int n = 0;
    int a = 0, b = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);

        if (a == 1)
        {
            scanf("%d", &b);

            uppush(b);
        }
        else if (a == 2)
        {
            scanf("%d", &b);

            downpush(b);
        }
        else if (a == 3)
        {
            uppop();
        }
        else if (a == 4)
        {
            downpop();
        }
        else if (a == 5)
        {
            count();
        }
        else if (a == 6)
        {
            if (isempty())
            {
                printf("1\n");
            }
            else {
                printf("0\n");
            }
        }
        else if (a == 7)
        {
            uppeek();
        }
        else if (a == 8)
        {
            downpeek();
        }
    }
    
    return 0;
}

// 선형 큐를 이용한 덱