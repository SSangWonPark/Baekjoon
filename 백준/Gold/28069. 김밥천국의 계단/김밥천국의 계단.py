import sys
input = sys.stdin.readline

N, K = map(int, input().split())

if N <= K:
    print("minigimbob")
    exit(0)

dp = [0] * (N + 1)
dp[0] = 0
dp[1] = 1

for i in range(2, N + 1):
    dp[i] = dp[i - 1] + 1

    if i % 3 != 2:
        dp[i] = min(dp[i], dp[i - int(i / 3)] + 1)

if dp[N] > K:
    print("water")
else:
    print("minigimbob")

# 2가지 중 한 행동을 K번 행동해서 K번째에 N층에 도달하기.
# 2가지 행동: 한 칸 오르기. +1 / 순간이동. i + i/2로 이동.
# 도달 가능 시, minigimbob. 불가능하면 water.

# 행동은 무조건 커짐. 즉 N < K 라면 불가능함. <- 아님 0에서 시작하면 순간이동을 해도 0임. 
# 그렇다면 N < K이면 무조건 가능.
# dp로 채우면서 1 이전 값이나 내림 i/2인 값 중 작은 값을 고르기. 
# 최종적으로 dp[N]이 K보다 작으면 성공. 0에서 순간이동으로 숫자 올릴 수 있음. 
# -> 50퍼에서 틀림.

# 순간이동을 i/2인 값으로 정의하면 안됨.
# i + i/2라면 현재 위치에서 3/4. 이라고 정의할 수는 없음.
# 순간이동이 불가능한 경우. i시점에서 i % 3 == 2인 경우. ex) 5, 8, 11, ...