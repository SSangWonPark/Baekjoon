#include <stdio.h>
#include <string.h>

void quicksort(int _data[], int p_idx, int left_idx, int right_idx){

  if (p_idx >= right_idx)
  {
      return;
  }

  int pivot = _data[p_idx];
  int left = left_idx;
  int right = right_idx;

  while (1)
  {
      while (pivot >= _data[left] && left < right_idx)
      {
          left++;
      }

      while (pivot <= _data[right] && right > p_idx)
      {
          right--;
      }

      if (left < right)
      {
          int temp = _data[left];
          _data[left] = _data[right];
          _data[right] = temp;
      }
      else{
          _data[p_idx] = _data[right];
          _data[right] = pivot;
          break;
      }
  }
  
  quicksort(_data, p_idx, p_idx + 1, right - 1);
  quicksort(_data, right + 1, right + 2, right_idx);
}

int main(void) {
  int n = 0;
  int num[1000];

  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &num[i]);
  }

  quicksort(num, 0, 1, n - 1);

  for (int i = 0; i < n; i++)
  {
    printf("%d ", num[i]);
  }

  scanf("%d", &n);

  return 0;
}
