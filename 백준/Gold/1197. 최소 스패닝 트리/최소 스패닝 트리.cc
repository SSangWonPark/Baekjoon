#include <stdio.h>

struct Node{
	int a;
	int b;
	int w;
};

// int graph[10000][10000] = { 0, };
struct Node heap[100001];
int idx = 0;

int graphtype[10001] = { 0, };

void addedge(int a, int b, int w){
	idx++;
	heap[idx].a = a;
	heap[idx].b = b;
	heap[idx].w = w;

	int cur = idx;

	while (cur > 1)
	{
		int p = cur / 2;

		if (heap[p].w < heap[cur].w)
		{
			return;
		}
		else{
			struct Node temp = heap[p];
			heap[p] = heap[cur];
			heap[cur] = temp;
			cur = p;
		}
	}
}

struct Node delheap(){
	struct Node res = heap[1];

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

		if (c + 1 <= idx && heap[c].w > heap[c + 1].w)
		{
			c++;
		}

		if (heap[c].w > heap[cur].w)
		{
			break;
		}
		else{
			struct Node temp = heap[c];
			heap[c] = heap[cur];
			heap[cur] = temp;
			cur = c;
		}
	}
	return res;
}

int find(int x) {
    return graphtype[x] == x ? x : (graphtype[x] = find(graphtype[x]));
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) graphtype[b] = a;
}

int main(){

	int v = 0, e = 0;
	scanf("%d %d", &v, &e);

	int a = 0, b = 0, w = 0;
	int ans = 0;

	for (int i = 1; i <= v; i++)
	{
		graphtype[i] = i;
	}

	for (int i = 0; i < e; i++)
	{
		scanf("%d %d %d", &a, &b, &w);

		addedge(a, b, w);
	}

	for (int i = 0; i < v - 1; i++)
	{
		while (1)
		{
			struct Node tmp = delheap();

			if (find(tmp.a) != find(tmp.b))
			{
                unite(tmp.a, tmp.b);
                ans = ans + tmp.w;
				break;
			}
		}
	}
	
	printf("%d", ans);

	return 0;
}

// 크루스칼 MST, union-find 구조 공부하기. 경로 압축.