import sys

input = sys.stdin.readline

n = int(input())

for _ in range(n):
    x = int(input())

    ex = 0

    while 2 ** ex < abs(x): 
        ex += 1

    if x == 0:
        print(0)
        continue
    elif x > 0:
        print(5 * 2 ** ex - 4 - (2 ** ex - x))
    else:
        print(5 * 2 ** ex - 4 + 2 ** (ex + 1) - (2 ** ex - abs(x)))

# 들어온 순서대로 움직이는게 아님.
# 각 케이스마다 0번째부터 x번째까지의 누적합.
# 빠른 입출력 사용. 시간초과. 누적합 과정이 너무 많이 반복되는 듯.
# 1 -1 2 -2 4 -4 ...... 좌표가 이렇게 반복.
# 0 1 6 15 16 ...... 거리가 이렇게 증가함.

# 수식 정리가 안되서 지피티한테 힌트를 물어봄.
# 2의 지수 구하기. 2 ** ex < abs(x) 인 동안에 ex를 1씩 증가. 2 ** expo >= abs(x)이 될때 까지.
# 0인 경우 0, 양수: 5 * 2 ** ex - 4 - (2 ** ex - x) / 음수: 5 * 2 ** ex - 4 + 2 ** (ex + 1) - (2 ** ex - abs(x))