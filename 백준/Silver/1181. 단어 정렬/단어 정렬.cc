#include <stdio.h>
#include <string.h>

char temp[20001][51];
char ans[20001][51];
int sorted[20001];

void merge(int list[], int left, int mid, int right){
    int i = left, j = mid + 1, k = left;

    // 두 부분에서 작은 것을 골라 삽입.
  while(i <= mid && j <= right){
    if(list[i] < list[j] || list[i] == list[j] && strcmp(temp[j], temp[i]) > 0){
        sorted[k] = list[i];
        strcpy(ans[k], temp[i]);
        i++;
    }
    else{
        sorted[k] = list[j];
        strcpy(ans[k], temp[j]);
        j++;
    }
    k++;
  }

  // 왼쪽이 먼저 끝난 경우. 오른쪽 나머지 삽입.
  if(i > mid){
    for(int l = j; l <= right; l++){
      sorted[k] = list[l];
      strcpy(ans[k], temp[l]);
      k++;
    }
  }
  else{
    for(int l = i; l <= mid; l++){
      sorted[k] = list[l];
      strcpy(ans[k], temp[l]);
      k++;
    }
  }

  // 데이터를 저장했던 임시 배열에서 원 배열로 복사.
  for(int l = left; l <= right; l++){
    list[l] = sorted[l];
    strcpy(temp[l], ans[l]);
  } 

}

void mergeSort(int list[], int left, int right){
    int mid = 0;

    // 크기가 1이 될 때까지 분할. 
    if(left < right){
        mid = (left+right) / 2;
        mergeSort(list, left, mid);
        mergeSort(list, mid + 1, right);
        merge(list, left, mid, right);
      }
}

int main()
{
    int t = 0, count = 0;
    char string[20000][51];
    int num[20000];

    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        scanf("%s", &string[i][0]);
        
        int n = 0;

        for (int j = 0; j < i; j++)
        {
            if (strcmp(string[i], string[j]) == 0)
            {
                n++;
            }
        }

        if (n == 0)
        {
            strcpy(temp[count], string[i]);
            num[count] = strlen(temp[count]);
            count++;
        }
    }

    mergeSort(num, 0, count - 1);
    
    for (int i = 0; i < count; i++)
    {
        printf("%s\n", temp[i]);
    }

    return 0;
}

// 시간 2초. 버블정렬 시간초과. 합병 정렬 공부. O(N * lonN)
// 1이 될 때까지 분할 -> 2부분씩 정렬 -> 결합.
// 장) 항상 O(N * lonN) / 단) 메모리 사용. 추가적인 배열 필요.
// ans 배열로 출력하면 문자열이 하나만 들어온 경우 출력 불가. temp 배열로 출력.