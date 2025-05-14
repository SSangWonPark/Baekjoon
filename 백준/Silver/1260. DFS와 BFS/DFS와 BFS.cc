#include <stdio.h>

int graph[1001][1001] = { 0, };
int n = 0;

int Svisited[1001] = { 0, };

int stack[10000001];
int top = -1;

void push(int v){
	top++;
	stack[top] = v;
}

int pop(){
	if (top == -1)
	{
		return -999;
	}
	
	int res = stack[top];
	top--;
	return res;
}

void dfs(int start){
	push(start);

	while (top > -1)
	{
		int temp = pop();
		if (Svisited[temp] == 0)
		{
			Svisited[temp] = 1;
			printf("%d ", temp);
		}

		for (int i = n; i > 0; i--)
		{
			if (Svisited[i] == 0 && graph[temp][i])
			{
				push(i);
			}
		}
	}
}

int Qvisited[1001] = { 0, };

int queue[1001];
int rear = 0;
int front = 0;

void enqueue(int v){
	queue[rear] = v;
	rear++;
}

int dequeue(){
	if (rear < front)
	{
		return -999;
	}

	int res = queue[front];
	front++;
	return res;
}

void bfs(int start){
	enqueue(start);
	Qvisited[start] = 1;

	while (rear > front)
	{
		int temp = dequeue();
		printf("%d ", temp);
		
		for (int i = 1; i <= n; i++)
		{
			if (Qvisited[i] != 1 && graph[temp][i] == 1)
			{
				enqueue(i);
				Qvisited[i] = 1;
			}
		}
	}
}

int main(){
	
	int m = 0, v = 0;

	scanf("%d %d %d", &n, &m, &v);

	for (int i = 0; i < m; i++)
	{
		int a = 0, b = 0;

		scanf("%d %d", &a, &b);
		graph[a][b] = graph[b][a] = 1;
	}
	
	dfs(v);
	printf("\n");
	bfs(v);

	return 0;
}

// dfs, bfs 연습
// 스택 중복을 처리하기위해 배열 크게 설정