import sys

input = sys.stdin.readline

def push(h, x):
    h.append(x)
    i = len(h) - 1

    while i > 0:
        p = (i - 1) // 2
        if h[p] < h[i]:
            h[p], h[i] = h[i], h[p]
            i = p
        else:
            break

def pop(h):
    res = h[0]
    last = h.pop()

    if h:
        h[0] = last
        i = 0
        n = len(h)

        while True:
            l = 2 * i + 1 
            r = 2 * i + 2
            cur = i

            if l < n and h[l] > h[cur]:
                cur = l
            if r < n and h[r] > h[cur]:
                cur = r
            if cur == i:
                break

            h[i], h[cur] = h[cur], h[i]
            i = cur
            
    return res

N = int(input())

station = []

for _ in range(N):
    a, b = map(int, input().split())
    station.append((a, b))

L, P = map(int, input().split())

station.append((L, 0))
station.sort(key=lambda x: x[0])

heap = [] 
idx = 0 
ans = 0

while idx < len(station):

    while idx < len(station) and station[idx][0] <= P:
        push(heap, station[idx][1])
        idx += 1

    if idx < len(station) and station[idx][0] > P:

        if not heap:
            ans = -1
            break

        P += pop(heap)
        ans += 1

print(ans)

# 주유소 최대 힙쓰면 풀릴듯?
# 주유소 리스트 정렬해두고 가능한 주유소 중에 가장 많은 곳을 꺼내서 선택.
# 주유소 거리 확인해서 힙에 쭉 넣고, 못 움직이는 경우 가장 연료가 많은 곳 힙에서 뽑아오기.
# 힙이 빈 경우까지 반복.