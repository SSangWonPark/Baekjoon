import sys
input = sys.stdin.readline

a, b = map(int, input().split())

dp = [0] * (1000)

dp[1] = 1
dp[2] = 2

for i in range(3, 1000):
  dp[i] = dp[i - 1] + dp[i - 2]

while True:

  if a == 0 and b == 0:
    break

  cnt = 0

  for i in range(1, 1000):
    if dp[i] >= a and dp[i] <= b:
      cnt += 1
    elif dp[i] > b:
      break
  
  print(cnt)

  a, b = map(int, input().split())

# 10**100 <= 이걸 정수로 받을 수가 있나?
# 피보나치 1000 <= 약 4.317e+208
# while a != 0 and b != 0: 이건 왜 0 1 이 안되지...? 