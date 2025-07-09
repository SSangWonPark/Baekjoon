import sys
input = sys.stdin.readline

N = int(input())

dp = [0] * (N + 1)
T = [0] * (N + 1)
P = [0] * (N + 1)

for i in range(N):
  t, p = map(int, input().split())

  T[i] = t
  P[i] = p

for i in range(N - 1, -1, -1):
  if i + T[i] > N:
    dp[i] = dp[i + 1]
  else:
    dp[i] = max(dp[i + 1], P[i] + dp[i + T[i]])
  
print(dp[0])

# 뒤에서부터 생각하는게 편할듯?
# N + 1일에 퇴사니까 마지막날에 1일짜리가 아니면 수행 못함.
# 따라서 해당 일에 최대는 뒤이거나 현 시점과 i + T[i] 시점의 합 중 최대.

# if
# T: 3   5   1   1   2   4   2
# P: 10  20  10  20  15  40  200
# dp:45  45  45  35  15  0   0

# dp[1]은 1인 시점에서의 최선. dp[0]가 진짜 모든 날짜에 대한 최선의 수