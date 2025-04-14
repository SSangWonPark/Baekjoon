#include <stdio.h>
#include <stdlib.h>

struct node
{
    int n;
    struct node *next;
};

struct node *head = 0;

int n = 0, m = 0;
int flag = 0;

void enqueue(int v){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->n = v;
    newnode->next = 0;
    
    if (head == 0)
    {
        head = newnode;
    }
    else{
        struct node *cur = head;

        while (cur->next != 0)
        {
            cur = cur->next;
        }
        
        cur->next = newnode;
    }

    if (newnode->n == n)
    {
        newnode->next = head;
    }
    
    return;
}

void dequeue(){
    struct node *cur = head;
    struct node *back = head;

    if (flag == 0){
        for (int i = 0; i < m - 1; i++)
        {
            back = head;
            head = head->next;
            cur = head;
        }

        flag++;
    }
    else{
        for (int i = 0; i < m; i++)
        {
            back = head;
            head = head->next;
            cur = head;
        }
    }

    printf("%d", head->n);
    back->next = head->next;
    head = back;
    free(cur);
    
    return;
}

int main(){

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        enqueue(i);
    }

    printf("<");
    for (int i = 0; i < n; i++)
    {
        dequeue();
        if (i < n - 1)
        {
            printf(", ");
        }
    }
    printf(">");

    return 0;
}

// SLL을 이용한 큐