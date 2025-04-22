#include <stdio.h>
#include <stdlib.h>

struct node{
  int v;
  struct node *next;
};

struct node *head;

struct node *tail;

void enqueue(int n){
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->v = n;
  newnode->next = 0;
  
  if (head == 0) 
  {
    head = newnode;
    tail = newnode;
    newnode->next = head;
  } 
  else 
  {
    tail->next = newnode;
    tail = newnode;
    tail->next = head;
  }

  return;
}

int dequeue(int k) {
  struct node *prev = tail;
  struct node *cur = head;

  for (int i = 0; i < k - 1; i++) 
  {
    prev = cur;
    cur = cur->next;
  }

    int val = cur->v;

  if (cur == head) 
  {
    head = head->next;
  }

  if (cur == tail) 
  {
    tail = prev;
  }

  prev->next = cur->next;
  free(cur);

  head = prev->next;

  return val;
}

int main(void) {

  int n = 0, m = 0;

  scanf("%d %d", &n, &m);

  for (int i = 1; i <= n; i++)
  {
    enqueue(i);
  }
  
  printf("<");
  for (int i = 0; i < n; i++)
  {
    int ans = dequeue(m);

    if (i < n - 1)
    {
      printf("%d, ", ans);
    }
    else {
      printf("%d", ans);
    }
  }
  printf(">");

  return 0;
}

