#include <stdio.h>

int heap[100001];
int idx = 0;

void addHeap(int v){

	for (int i = 1; i <= idx; i++)
	{
		if (heap[i] == v)
		{
			return;
		}
	}

	idx++;
	heap[idx] = v; // 일단 말단에 새로운 값 넣기.
	
	int cur = idx;
	
	while (cur > 1) // 이 과정을 통해 정렬. 승진시키기
	{
		int p = cur / 2; // p는 부모 노드
		
		if (heap[p] <= heap[cur]) // 올라갈만큼 올라가서 본인 자리인 경우
		{
			return;
		}
		else{ // 승진할 수 있는 경우, 두 값 바꾸기.
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
			return -999;
	}
	
	int res = heap[1];

	heap[1] = heap[idx];
	idx--;

	int cur = 1;
	while (1)
	{
			int child_idx = 2 * cur;
			if (child_idx > idx)
			{
					break;
			}

			if ((child_idx <= idx - 1) && (heap[child_idx] > heap[child_idx + 1]))
			{
					child_idx++;
			}
			if (heap[cur] <= heap[child_idx])
			{
					break;
			}
			else{
					int temp = heap[cur];
					heap[cur] = heap[child_idx];
					heap[child_idx] = temp;
					cur = child_idx;
			}    
	}
	
	return res;
}

int main(){

	int n = 0;
	int x = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);

		addHeap(x);
	}

	int temp = idx;

	for (int i = 0; i < temp; i++)
	{
		int temp = delHeap();

		printf("%d ", temp);
	}

	return 0;
}

// heap 정렬 연습