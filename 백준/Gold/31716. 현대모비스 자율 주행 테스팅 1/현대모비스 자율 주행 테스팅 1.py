#import sys
#input = sys.stdin.readline

# min-plus 방식의 2×2 행렬 곱셈
def matmul(A, B, INF):
    R = [[INF, INF], [INF, INF]]
    for i in range(2):
        for j in range(2):
            # R[i][j] = min_k (A[i][k] + B[k][j])
            v0 = A[i][0] + B[0][j]
            v1 = A[i][1] + B[1][j]
            R[i][j] = v0 if v0 < v1 else v1
    return R

# min-plus 이항체에서 C 행렬의 K제곱 계산
# 항등원 E는 대각 0, 비대각 INF
def matpow(C, K, INF):
    R = [[0, INF], [INF, 0]]
    base = C
    while K:
        if K & 1:
            R = matmul(R, base, INF)
        base = matmul(base, base, INF)
        K >>= 1
    return R

N, K = map(int, input().split())
board = [input().strip() for _ in range(2)]
INF = 10**18

# 한 블록(2×N)에서 출발 행 a → 도착 행 b 최소 이동 횟수 저장
C = [[INF]*2 for _ in range(2)]
for start in (0, 1):
    # cost[r]: 현재 열에서 r행에 있을 때 누적 최소 이동 횟수
    cost = [INF, INF]
    # 첫 열에서 start행으로 시작 가능하면 0으로 초기화
    if board[start][0] == '.':
        cost[start] = 0
    # 열을 왼쪽에서 오른쪽으로 한 칸씩 스윕
    for c in range(N):
        # 같은 열 내에서 차선 변경 가능 여부
        if board[0][c]=='.' and board[1][c]=='.':
            c0, c1 = cost
            cost[0] = c0 if c0 < c1+1 else c1+1
            cost[1] = c1 if c1 < c0+1 else c0+1
        # 다음 열로 직진
        newcost = [INF, INF]
        for r in (0, 1):
            if board[r][c] == '.':
                nc = cost[r] + 1
                newcost[r] = nc if nc < newcost[r] else newcost[r]
        cost = newcost
    # N열(마지막 열) 도착 시 cost 기록
    C[start][0], C[start][1] = cost[0], cost[1]
# C 행렬을 K제곱한 값 계산
CK = matpow(C, K, INF)

# 시작 행/끝 행 자유이므로 네 경우 중 최솟값이 답
ans = min(CK[0][0], CK[0][1], CK[1][0], CK[1][1])
print(ans - 1 if ans < INF//2 else -1)

# 2행 N열로 이루어진 입력이 K번 반복된 형태
# 움직이는 방법은 차선 변경: 행이동. / 직진: 우측으로 이동.

# if. 예제 1
# ..#.. ..#..
# #...# #...#
# 13번. 5 * 2(직진) + 3(행이동)

# 시작, 도착 체크해서 도로있으면 
# 체킹해서 움직이게끔 추가. 직진, 장애물을 만나면 행이동.

# 2*2로 부분으로 생각하고 그 경우의 최단거리들을 계산.
# R[i][j] = min_k (A[i][k] + B[k][j])로 행렬 계산을 통해 최소 비용 행렬.