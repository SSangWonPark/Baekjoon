import sys
input = sys.stdin.readline

N, M = map(int, input().split())

board = [list(input().strip()) for _ in range(N)]

state = [[0]*M for _ in range(N)]
dirs = {'U':(-1, 0),'D':(1, 0),'L':(0, -1),'R':(0, 1)}
ans = 0

def dfs(r, c):
    global ans
    state[r][c] = 1
    dr, dc = dirs[board[r][c]]
    nr, nc = r + dr, c + dc

    if state[nr][nc] == 0:
        dfs(nr, nc)
    elif state[nr][nc] == 1:
        ans += 1

    state[r][c] = 2

for i in range(N):
    for j in range(M):
        if state[i][j] == 0:
            dfs(i, j)

print(ans)

# 방향에 맞추어 움직이면서 가장 끝부분에 세이프 존을 만들어야 함.
# dfs 영역 찾기 문제와 동일.
# 스택쓰기 귀찮으니 재귀로 풀이.
# 0은 아직 방문 x -> 재귀로 들어가기.
# 1은 지금 탐색 경로 -> 정답 추가
# 2는 종료된 길.

# cf) 딕셔너리로 방향 체크하니 편함. 
# cf) python은 위에서 전역변수로 선언해도 함수에서 global로 안쓰면 인식을 못함.
#     함수 내에서 ans += 1 처럼 사용되는 순간 함수 내의 로컬 변수로 인식해서 그럼.