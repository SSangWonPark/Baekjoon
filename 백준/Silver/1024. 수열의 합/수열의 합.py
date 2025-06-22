N, L = map(int, input().split())

flag = 0

for i in range(L, 101):

  temp = i * (i - 1) // 2

  if (N - temp) % i != 0:
    continue

  j = (N - temp) // i

  if j < 0:
    continue

  print(*range(j, j + i))
  flag = 1
  break

if flag == 0:
  print(-1)

# 슬라이딩 윈도우로 단순 반복 -> 시간초과
# 수식으로 정리. j + (j + 1) + ... (j + k + 1) == N
# range(n, m)는 n부터 m미만임