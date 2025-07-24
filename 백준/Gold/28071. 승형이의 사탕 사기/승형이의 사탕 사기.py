import sys
input = sys.stdin.readline

N, M, K = map(int, input().split())
A = list(map(int, input().split()))

dp = [ [-1] * K for _ in range(M + 1)]
dp[0][0] = 0

for i in range(M):
    for j in range(K):
        if dp[i][j] < 0:
            continue

        temp = dp[i][j]

        for a in A:
            nr = (j + a) % K
            nv = temp + a

            if nv > dp[i + 1][nr]:
                dp[i + 1][nr] = nv

ans = max(dp[i][0] for i in range(M + 1))
print(ans if ans > 0 else 0)

# N종류의 사탕 상자들에서 M개의 사탕 상자를 가질 수 있고, K로 나누어 떨어져야 함.
# N종류에서 M개를 선택했을 때의 조합 중 K의 가장 큰 배수가 되는 경우.
# M*K 사이즈로 만들고 모든 경우의 수?
 
# 모든 조합은 경우의 수가 너무 많음. 
# knapsack mod K dp. 냅색 문제. 배낭 문제. 참고.
# dp[i][j] <= 상자를 i개 골랐을 때 총합 % K == j 일 때 얻을 수 있는 최대값.
# i개의 상자를 고른 상태에서 나머지가 j인 칸을 처리.
# temp: i 개의 상자를 골랐을 때 총합 % K == j인 최대 총합. 이걸 기준으로 사용.
# nr: 상자의 사탕 수 a + 이전 총합의 나머지 j % K. ;새로운 총합의 나머지
# nv: 이전 총합에 a개를 더했을 때의 값. 새로운 총합. dp[i + 1][nr]과 비교해서 최대 갱신.
# 따라서 dp[i][0] 즉, 나머지가 K로 나눠서 0인 경우들 중 가장 큰 값이 정답.

# 이미 구해둔 각각의 나머지의 최대 dp[i][j] 들에 사탕 a를 더하면 dp[i+1][j] 들을 구할 수 있음.

# if 
# 3 5 3
# 1 3 5

# dp    0   1   2
# 0     0   -1  -1
# 1     3   1   5   // (nr=(0+1)%3=1, nv=0+1=1 / nr=0, nv=3 → dp[1][0]=3 / nr=2, nv=5 → dp[1][2]=5)
# 2     6   10  8
# 3     15  13  11
# 4     18  16  20
# 5     21  25  23
# 즉 0, 3, 6, 15, 18, 21 중 가장 큰 21이 정답.
