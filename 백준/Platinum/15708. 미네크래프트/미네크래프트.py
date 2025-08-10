#import sys
#input = sys.stdin.readline

import sys, heapq

N, T, P = map(int, input().split())
K = list(map(int, input().split()))

heap = []
cnt = 0
ans = 0

for i in range(N):
    cost = T - P * i

    heapq.heappush(heap, -K[i])
    cnt += K[i]

    while cnt > cost and heap:
        trash = -heapq.heappop(heap)
        cnt -= trash

    if cnt <= cost:
        ans = max(ans, len(heap))

print(ans)

# 시간 1로 곡갱이질 1회 or 시간 P로 이웃한 바위로 이동.
# T시간동안 최대한 많은 돌을 얻기
# 해당 돌을 캐기 위한 시간은 바위 + P * (인덱스 + 1)

# if 
# 6 17 1
# 3 5 2 6 9 1            
# 3 6 4 9 13 6
# ?? 어떻게 4개를 캔거지
# 해당 칸을 캐면 자동으로 이동 가능인건가. 3 5 2 1을 3으로 캔건가?
# 단순히 인덱스를 곱하니까 비용을 두번 지불한 셈임.
# 만약 i번째까지 갔다면 그냥 한번 더 지불하면 i + 1의 위치로 이동가능.
# 왼쪽에서 오른쪽으로 움직이면서 그리디하게 먹는다면?
            
# 이동하면서 한칸씩 먹기. 이동을 중복적용하지 않기 위해서 매 반복마다 T - P * i
# 한칸 먹었는데 시간을 넘으면 가장 큰 바위 버리기.
# 매 반복마다 캘 수 있는 최대 바위 수 갱신. 
# sort()가 nlogn으로 작동하니까 가능할려나? <- 시간초과. n*nlogn이었네... 최대힙을 써야하나

# 파이썬은 기본이 최소힙으로 되어있음. 넣을 때 -를 붙이고 뺄 때 -를 붙여서 최대힙으로 사용.
# 최소힙인데 음수상태로 바꿔서 넣었기 때문에 뺄 때도 - 붙여서 빼기.