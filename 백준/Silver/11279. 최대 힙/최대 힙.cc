#include <stdio.h>
int heap[100001];
int idx = 0;

void addHeap(int v){
	idx++;
	heap[idx] = v;
	
	int cur = idx;
	while (cur > 1)
	{
		int p = cur / 2;
		if (heap[p] >= heap[cur])
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

        if ((child_idx <= idx - 1) && (heap[child_idx] < heap[child_idx + 1]))
        {
            child_idx++;
        }
        if (heap[cur] >= heap[child_idx])
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

		if (x > 0)
		{
			addHeap(x);
		}
		else if (x == 0)
		{
			int temp = delHeap();

			if (temp == -999)
			{
				printf("0\n");
			}
			else{
				printf("%d\n", temp);
			}
		}
	}
	
	return 0;
}