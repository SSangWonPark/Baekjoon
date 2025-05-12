#include <stdio.h>

int abs(int n){
	if (n < 0)
	{
		return (n * -1);
	}
	return n;
}

int heap[100001];
int idx = 0;

void addHeap(int v){
	idx++;
	heap[idx] = v;
	
	int cur = idx;
	while (cur > 1)
	{
		int p = cur / 2;
		if (abs(heap[p]) < abs(heap[cur]) || 
			(abs(heap[p]) == abs(heap[cur]) && heap[p] < heap[cur]))
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

int flag = 0;

int delHeap(){
    if (idx == 0)
    {
		flag = 1;
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

        if (abs(heap[child_idx]) > abs(heap[child_idx + 1]) || 
			(abs(heap[child_idx]) == abs(heap[child_idx + 1]) && heap[child_idx] > heap[child_idx + 1]))
        {
            child_idx++;
        }
        if (abs(heap[cur]) < abs(heap[child_idx]) || 
			(abs(heap[cur]) == abs(heap[child_idx]) && heap[cur] < heap[child_idx]))
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
	int num = 0;

	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);

		if (x != 0)
		{
			addHeap(x);
		}
		else
		{
			int temp = delHeap();

			if (temp == -999 && flag == 1)
			{
				printf("0\n");
				flag = 0;
			}
			else{
				printf("%d\n", temp);
			}
		}
	}
	
	return 0;
}