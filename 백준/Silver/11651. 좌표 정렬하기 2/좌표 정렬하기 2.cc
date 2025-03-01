#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int num[100000][2] = { 0, };

void swap(int *a, int *b, int *c, int *d){
    int temp = *a;
    *a = *b;
    *b = temp;

    temp = *c;
    *c = *d;
    *d = temp;
}

void quickSort(int start, int end) {
    if (start >= end) return;

    int pivot = start + rand() % (end - start + 1);
    swap(&num[start][0], &num[pivot][0], &num[start][1], &num[pivot][1]);

    int key = start, i = start + 1, j = end;

    while (i <= j) {
        while (i <= end && (num[i][1] < num[key][1] || 
            (num[i][1] == num[key][1] && num[i][0] < num[key][0]))) {
            i++;
        }

        while (j > start && (num[j][1] > num[key][1] || 
            (num[j][1] == num[key][1] && num[j][0] > num[key][0]))) {
            j--;
        }
        
        if (i >= j) {
            swap(&num[key][0], &num[j][0], &num[key][1], &num[j][1]);
        }
        else {
            swap(&num[i][0], &num[j][0], &num[i][1], &num[j][1]);
        }
    }
    
    quickSort(start, j - 1);
    quickSort(j + 1, end); 
}

int main()
{
    int t = 0;

    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &num[i][0], &num[i][1]);
    }

    srand(time(NULL));

    quickSort(0, t - 1);

    for (int i = 0; i < t; i++)
    {
        printf("%d %d\n", num[i][0], num[i][1]);
    }
    
    return 0;
}

// 랜덤 피벗 퀵 정렬. 이전의 좌표 정렬하기 문제와 동일.