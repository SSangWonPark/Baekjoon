import sys
input = sys.stdin.readline

D, K = map(int, input().split())

dp = [0] * D
dp[0], dp[1] = 1, 1

for i in range(K):
    for i in range(2, D):
        dp[i] = dp[i - 1] + dp[i - 2]
    
    if dp[D - 1] == K:
        print(dp[0]) 
        print(dp[1])
        break
    elif dp[-1] < K:
        dp[1] += 1
    else:
        dp[0] += 1
        dp[1] = dp[0]

# 1일 전 + 2일 전 떡의 개수만큼 주어야 산 넘기 가능.
# 1, 2, 3, 5, 8, 13, ...

# 역으로 계산해서 넘어온 날 D, 그날 준 떡의 수 K에서 1일, 2일차에 준 떡의 개수 구하기.
# dp 느낌으로 D개의 행렬에서 줄이면서 구하기

# if 6, 41
# 2 7 9 16 25 41

# 2 3 5 8 13 21

# dp[i-2] + dp[i-1] = dp[i] 를 수행하는데, 올라가면서 보면 됨.
# 생각보다 작음. 전부 다 보자.
# N만큼 돌아서 K보다 작다면, 1일차 2일차 사이의 간격이 좁은 것이므로 2일차에 +1
# 아니고 크다면 1일차를 올리고, 2일차도 1일차로 보정. A <= B