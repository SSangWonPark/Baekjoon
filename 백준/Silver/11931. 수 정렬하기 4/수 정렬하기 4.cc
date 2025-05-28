#include <stdio.h>
#include <stdlib.h>

int data[1000000];

void sorting(int left, int mid, int right){
	int *temp = (int *)malloc(sizeof(int) * (right - left + 1));
	int left_idx = left;
	int right_idx = mid + 1;
	int temp_idx = 0;

	while (1)
	{
		if (left_idx <= mid && right_idx <= right)
		{
			if (data[left_idx] >= data[right_idx])
			{
				temp[temp_idx] = data[left_idx];
				temp_idx++;
				left_idx++;
			}
			else {
				temp[temp_idx] = data[right_idx];
				temp_idx++;
				right_idx++;
			}
		}
		else if (left_idx <= mid)
		{
			temp[temp_idx] = data[left_idx];
			temp_idx++;
			left_idx++;
		}
		else if (right_idx <= right)
		{
			temp[temp_idx] = data[right_idx];
			temp_idx++;
			right_idx++;
		}
		else {
			break;
		}
	}

	for (int i = 0; i < right - left + 1; i++)
	{
		data[left + i] = temp[i];
	}

	free(temp);

	return;
}

void merge(int left, int right){
	if (left >= right)
	{
		return;
	}

	int mid = (right + left) / 2;

	merge(left, mid);
	merge(mid + 1, right);
	sorting(left, mid, right);
	
	return;
}

int main(){
    int n = 0;
    int x = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
		data[i] = x;
    }

    merge(0, n - 1);

	for (int i = 0; i < n; i++)
	{
		printf("%d\n", data[i]);
	}
	
	scanf("%d", &n);

    return 0;
}

// 합병 정렬