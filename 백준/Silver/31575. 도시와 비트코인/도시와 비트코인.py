import sys
input = sys.stdin.readline
from collections import deque

n, m = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(m)]

queue = deque([(0, 0)])

while queue:
    r, c = queue.popleft()

    for i in [(0, 1), (1, 0)]:
        row = r + i[0]
        col = c + i[1]

        if 0 <= row < m and 0 <= col < n and graph[row][col] == 1:
            graph[row][col] += graph[r][c]
            queue.append((row, col))

if graph[m - 1][n - 1] + 1 == n + m:
    print('Yes')
else:
    print('No')

# BFS?? 
# deque: queue. 내부에 rear와 front 존재.
# popleft: deque의 맨 앞 값을 pop.
# 오른쪽과 아래로 움직이면서 거리를 누적.
# 마지막에 누적한 거리와 마지막 좌표의 합이 같으면 경로 존재.
# 사실 그냥 도달여부만 구하면 되는거니까 기본형으로 풀려고 했는데 dp라 누적합해봄.