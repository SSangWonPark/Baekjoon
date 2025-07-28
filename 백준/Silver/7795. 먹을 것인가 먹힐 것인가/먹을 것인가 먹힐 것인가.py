import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    N, M = map(int, input().split())
    A = map(int, input().split())
    B = map(int, input().split())
    A = sorted(A)
    B = sorted(B)

    ans = 0
    cnt = 0
    for i in range(N):
        while cnt < M:
            if A[i] <= B[cnt]:
                break
            cnt += 1

        ans += cnt

    print(ans)

# B를 20000짜리 배열에 하나씩 넣으면서 가면?
# if 3을 넣는다면, 0 0 0 1 1 1 1 1... dp[3]부터 1이도록. 
# 보다 큰 값이기 때문에 B[n] + 1일 때, n을 늘려서 카운팅
# 대충 2 * 20000 * T 정도의 속도

# 아.. A의 크기가 정해진게 아니었구나.. 인덱스 에러.

'''
dp = [0 for _ in range(1000001)]
    
    n = 0
    for i in range(1000001):
        if n < M and i == B[n] + 1:
            n += 1
            
        dp[i] = n

    ans = 0
    for i in A:
        ans += dp[i]
'''
# 그냥 A * B 번 돌기. 속도 대략 N * M * T <- 시간 초과
# A도 정렬되어있으면 앞에꺼보다 뒤에는 무조건 크니까 이전은 무시하고 더하는 식으로? <= 틀림.
# 반복문 조건 수정 M <= cnt or 로 묶는게 아니라 아예 빼버림