import sys
input = sys.stdin.readline

N = int(input())
Top = list(map(int, input().split()))

ans = [0] * N
stack = []

for i, h in enumerate(Top):
    while stack and stack[-1][0] <= h:
        stack.pop()
    
    if stack:
        ans[i] = stack[-1][1] + 1
    else:
        ans[i] = 0
    
    stack.append((h, i))

print(*ans)
# N개의 장치가 서로의 높이보다 큰 친구에게 가장 먼저 닿을 때 해당 순서.
# 6 9 5 7 4
# 불가 불가 9 9 7
# 0 0 2 2 4
# 1.5초면 단순 반복으로 될려나? 시간초과.

# 두 번 보지 말고 그냥 한번에 왼쪽에서 오른쪽으로 보면서 체크할까.
# 그냥 리스트로 체크하기에는 애매한데.
# 왼쪽에서 오른쪽으로 가면서 스택보다 크면 빼면서 채워주기.
# 현 시점보다 큰 경우가 바로 처음 만난 더 높은 탑이니까 그걸 넣기.

# 현재 탑보다 낮거나 같은 건 의미 없음 -> 팝
# 남아 있으면 그게 왼쪽에서 처음 만나는 더 높은 탑
# 현재 탑을 후보로 스택에 추가
# 이걸 반복하기
# 이렇게 하면 시간 복잡도는 O(N)