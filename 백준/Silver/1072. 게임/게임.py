import sys
input = sys.stdin.readline

X, Y = map(int, input().split())
Z = int((Y * 100) / X)

left = 0 
right = X 
ans = 0

if Z >= 99: 
    print(-1)
else: 
    while left<=right: 
        mid = (left + right) // 2

        if (100 * (Y + mid)) // (X + mid) > Z: 
            ans = mid 
            right = mid - 1 
        else: 
            left = mid + 1
    
    print(ans)

# X 횟수에서 Y 게임을 이겼을 때의 승률 Z %에 대해 Z 값이 변하는 최소 게임수, 이때 Z는 소수점 버림.
# 99퍼보다 크면 더 커지는게 무의미함. -1 바로 출력.
# X의 최대가 1,000,000,000 이면 다 돌아가면 시간초과가 날 것. <- 이분 탐색 사용.
# 오답. <= 부동소수점 해결을 위해 (Y / X) * 100 대신 (Y * 100) / X. 먼저 100을 곱해서 오차를 줄임. 실수 연산은 부정확함.