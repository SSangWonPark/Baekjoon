import sys
input = sys.stdin.readline

N = int(input())

data = [0] * (N)
dp = [0] * (N)

for i in range(N):
    temp = float(input())
    data[i] = temp

    if i == 0:
        dp[i] = data[0]
    else:
        dp[i] = max(dp[i - 1] * data[i], data[i])

print(f"{max(dp):.3f}")

# N개의 실수를 받으면서 가장 큰 값을 채우자.
# 연속이니까 이전꺼 * 현재꺼랑 현재꺼를 비교해서 큰 값으로 채워넣기.
# 연속을 보장할 수 있나? 연속으로 곱했는데 그 시점에 큰 거면 무조건 커져야 함. 보장함.