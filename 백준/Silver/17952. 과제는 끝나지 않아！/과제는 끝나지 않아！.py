import sys
input = sys.stdin.readline

n = int(input())

stack = []
ans = 0

for _ in range(n):
  data = list(map(int, input().split()))

  if data[0] == 1:
    stack.append([data[1], data[2]])

  if stack:
    stack[-1][1] -= 1
    
    if stack[-1][1] == 0:
      ans += stack[-1][0]
      stack.pop()

print(ans)

# python 에서 stack 사용 시, append로 push, pop으로 pop
# 입력을 줄단위로 받기 때문에 time, task, m = map(int, input().split())로 받으면 1개 입력인 경우가 생겨서 안됨.
# 하나로 받고 쪼개자.
# 시간초과. -> 빠른 입출력으로 바꿔보자.