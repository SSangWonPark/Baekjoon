N, K = map(int, input().split())
num = list(map(int, input().split()))

count = 0
flag = 0

for i in range(0, N - 1):
  if num[i] >= num[i + 1]:
    num[i + 1] += K
    count += 1

    if num[i] >= num[i + 1]:
      flag = 1
      break

if flag:
  print(-1)
else:
  print(count)