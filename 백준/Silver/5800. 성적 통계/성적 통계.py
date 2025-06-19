n = int(input())

for i in range(n):
  data = list(map(int, input().split()))
  num, score = data[0], data[1:]
  
  sorting = sorted(score)
  gap = 0
  
  for j in range(num - 1):
    if gap < sorting[j + 1] - sorting[j]:
      gap = sorting[j + 1] - sorting[j]
  print(f"Class {i + 1}")
  print(f"Max {sorting[-1]}, Min {sorting[0]}, Largest gap {gap}")