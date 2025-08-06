import sys
input = sys.stdin.readline

N = int(input())
S = input().rstrip()

day = 0
cnt = 0

for i in S:
    if i == '(':
        cnt += 1
    elif i == ')':
        cnt -= 1

    if abs(cnt) > day:
        day = abs(cnt)

if cnt == 0:
    print(day)
else:
    print(-1)

# 곰은 하루면 O, X를 (), )(로 만듦.
# ()()() <- OOO 1일이면 됨.
# (()))((()) <- OXO -> (O))X((O) 2일 걸림
# 괄호가 쌍이 안맞으면 불가능함. <- -1 출력
# ()를 세가면서 수가 연달아 있는 경우 체크. (( 이런 경우.
# 최종적으로 0이면 짝이 맞아서 day가 답. 아니면 -1.