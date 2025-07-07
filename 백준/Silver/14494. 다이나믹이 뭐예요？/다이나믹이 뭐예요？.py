import sys
input = sys.stdin.readline

x, y = map(int, input().split())

dp = [[0 for _ in range(1001)] for _ in range(1001)]

for i in range(1001):
  dp[i][1] = 1
  dp[1][i] = 1

for i in range(2, 1001):
    for j in range(2, 1001):
        if dp[i][j] == 0:
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1]) % 1000000007

print(dp[x][y])


# 1001 * 1001 dp 배열을 만들고 (1, j) (i, 1)들은 1로
# dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1]) % 1000000007
# 이걸로 채우기. →, ↓, ↘ 세 방향에서 오는 값.