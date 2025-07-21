import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    N = int(input())
    
    Game = [0] * (N + 1)
    ans = 0

    for i in range(1, N + 1):
        Game[i] = int(input())
        
    cur = 1
    ans = 0

    while ans < N and cur != N:
        cur = Game[cur]
        ans += 1
        
    if cur == N:
        print(ans)
    else:
        print(0)

# 테스트 케이스에서 주경이를 부르는 경우, 즉 N을 말하는 경우의 순서를 출력. 없다면 0
# 잘못 생각함. 더 게임 오브 데스처럼 손가락으로 쭉 따라가서 해당 번째에 N이 나오게끔.
# 입력을 다 받고, 손가락을 따라가면서 N번 사람을 부르거나 N번 돌 때까지 수행.
# 나왔다면 ans를 카운트해서 출력. N번 돌아서 N번이 호명되지 않았다면 0.