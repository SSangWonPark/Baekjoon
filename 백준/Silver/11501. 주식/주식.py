import sys

input = sys.stdin.readline

n = int(input())

for _ in range(n):
    t = int(input())
    num = list(map(int, input().split()))
    lenth = len(num)    
    ans = [0 for _ in range(lenth)]
    cur = -1
        
    for i in range(lenth - 1, -1, -1):
        ans[i] = cur

        if num[i] > cur:
            cur = num[i]

    total = 0
    
    for i in range(lenth):
        temp = ans[i] - num[i]
        if temp > 0:
            total += temp

    print(total)

# 현 시점 기준(t)으로 미래시점(t+n)과 비교해서 차이가 가장 큰 경우가 최대 수익률
# 즉, t - (t+n) 중 가장 큰 경우. 5초니까 반복해도 될려나? -> 시간초과

# 뒤에서부터 계산하면서 뒤에서부터 각 시점에 최댓값을 구하고 계산
# 6 5 1 이라면 0 0 0 이라서 합은 0
# 1 1 3 1 2이라면 2 2 0 1 0 이라서 합은 5 <= 각 시점에서 나온 최댓값 - 현 위치의 값