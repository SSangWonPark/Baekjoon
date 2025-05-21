#include <stdio.h>

int heap[200001] = { 0, };
int idx = 0;

void addedge(int v){
	idx++;
	heap[idx] = v;

	int cur = idx;

	while (cur > 1)
	{
		int p = cur / 2;

		if (heap[p] < heap[cur])
		{
			return;
		}
		else{
			int temp = heap[p];
			heap[p] = heap[cur];
			heap[cur] = temp;
			cur = p;
		}
	}
}

int delheap(){
	if (idx == 0)
	{
		return 0;
	}

	int res = heap[1];

	heap[1] = heap[idx];
	idx--;
	
	int cur = 1;

	while (1)
	{
		int c = cur * 2;

		if (c > idx)
		{
			break;
		}

		if (c + 1 <= idx && heap[c] > heap[c + 1])
		{
			c++;
		}

		if (heap[c] > heap[cur])
		{
			break;
		}
		else{
			int temp = heap[c];
			heap[c] = heap[cur];
			heap[cur] = temp;
			cur = c;
		}
	}
	return res;
}

int main(){

	int n = 0;
	int x = 0;
	int ans = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);

		addedge(x);
	}

	if (n == 1)
	{
		printf("0");
		return 0;
	}

	while (idx > 0)
	{
		int a = delheap();
		int b = delheap();
		int c = a + b;

		ans = ans + c;

		if (idx == 0)
		{
			break;
		}
		
		addedge(c);
	}
	
	printf("%d", ans);

	return 0;
}

// 최소힙
// 탈출조건과 예외를 잘 생각하자