#include <stdio.h>
#include <stdlib.h>

void mergesort(int data[], int left, int mid, int right) {
    int *temp = (int *)malloc(sizeof(int) * (right - left + 1));
    int left_idx = left;
    int right_idx = mid + 1;
    int temp_idx = 0;

    while (1)
    {
        if (left_idx <= mid && right_idx <= right)
        {
            if (data[left_idx] < data[right_idx])
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
        data[i + left] = temp[i];
    }

    free(temp);

    return;
}

void merge(int data[], int left, int right){
    
    if (left >= right)
    {
        return;
    }

    int mid = (left + right) / 2;

    merge(data, left, mid);
    merge(data, mid + 1, right);
    mergesort(data, left, mid, right);

    return;
}

int main(void) {

	int n = 0;
    int data[1000];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }

    merge(data, 0, n - 1);

    int ans = 0;

    for (int i = 0, cnt = n; i < n; i++, cnt--)
    {
        ans = cnt * data[i] + ans;
    }

    printf("%d", ans);
    
    return 0;
}