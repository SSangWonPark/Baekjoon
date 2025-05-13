#include <stdio.h>

int heap[1500 * 1500 + 1];
int idx = 0;

void addHeap(int v){
	idx++;
	heap[idx] = v;

	int cur = idx;

	while (1)
	{
		int p = cur / 2;
		if (p == 0)
		{
			return;
		}

		if (heap[p] > heap[cur])
		{
			return;
		}
		else {
			int temp = heap[p];
			heap[p] = heap[cur];
			heap[cur] = temp;
			cur = p;
		}
	}
}

int delHeap(){
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

		if (heap[c] < heap[c + 1])
		{
			c++;
		}
		
		if (heap[cur] > heap[c])
		{
			break;
		}
		else{
			int temp = heap[cur];
			heap[cur] = heap[c];
			heap[c] = temp;
			cur = c;
		}
	}
	
    return res;
}

int main(){
	int n = 0;
	int x = 0;
	int num = 0;

	scanf("%d", &n);
	
	for (int i = 0; i < n*n; i++)
	{
		scanf("%d", &x);

		addHeap(x);
	}

	for (int i = 0; i < n; i++)
	{
		num = delHeap();
	}
	
	printf("%d", num);
	
	return 0;
}

// 최대 힙을 이용.