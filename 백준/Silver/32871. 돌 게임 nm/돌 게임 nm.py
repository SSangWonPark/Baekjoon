import sys
input = sys.stdin.readline

N = int(input())

for _ in range(N):
    n, m = map(int, input().split())

    if min(n, m) == 1:
        print("YES")
    else:
      if (n + m) % 2 == 1:
        print("YES")
      else:
        print("NO")

# n*m 격자, 찬우 선, 선택한 행 혹은 열의 돌을 모두 가져가는데, 가져갈 돌이 없으면 실패. 
# 1*2 인 경우 찬우가 1행 가져가면 찬우 승
# 2*2 인 경우 찬우 패
# n혹은 m이 1이면 무조건 찬우 승.
# n + m 이 홀수면 찬우 승. 짝수면 패
# 2*3 <= 승 3*3 <= 패