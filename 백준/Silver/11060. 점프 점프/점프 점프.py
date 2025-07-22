import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

dp = [10**9] * N
dp[0] = 0

for i in range(N):
    if dp[i] == 10**9:
        continue

    for j in range(1, A[i] + 1):

        if i + j < N:
            dp[i + j] = min(dp[i + j], dp[i] + 1)

if dp[N - 1] == 10**9:
    print("-1")
else:
    print(dp[N - 1])

# 전부다 돌기? 반복문으로 더해가면서 작은 것으로 남기기.
# 해당 칸이 도달할 수 없던 곳이라면 추가할 필요 없음.
# -1 출력 안해서 틀림.