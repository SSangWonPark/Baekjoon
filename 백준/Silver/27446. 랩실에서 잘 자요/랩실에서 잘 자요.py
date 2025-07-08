import sys
input = sys.stdin.readline

M, N = map(int, input().split())

dp = [0] * (M + 1) 

number = list(map(int, input().split()))
page = [0] * (M + 1) 

for i in number:
  page[i] = 1

best = 0

for i in range(1, M + 1):
  if page[i] == 0:
    dp[i] = min(dp[i - 1] + 7, 5 + 2*i + best)

  else:
    cur = 0
    dp[i] = dp[i - 1]

  best = min(best, dp[i] - 2 * i)

print(dp[M])

# M장에 대해서 1부터 N까지 중복을 포함해 페이지가 존재.
# 1부터 N까지 빈 페이지가 있다면 인쇄 -> 연속된 K장에 대해서 5 + 2K만큼 사용.
# 즉, 2장 인쇄하는 경우 1장 1장이면 7 + 7 = 14 이지만 연속인 경우 9만 사용해도 됨.
# 중복이 허용되기 때문에 정렬하고 가장 작은 빈 곳부터 큰 빈 곳까지의 값까지 중에 가장 작은 방법 찾기.
# 각각을 찾고 합할려고 했는데, 어려움. -> 누적합으로 변경.
# 연속인 경우랑 새로운 경우를 비교해서 잉크를 덜 쓰는 방향으로 누적.