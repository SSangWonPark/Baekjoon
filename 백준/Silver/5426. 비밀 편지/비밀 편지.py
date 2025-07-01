import math

n = int(input())

for _ in range(n):
    letter = list(input().strip())
    lenth = math.isqrt(len(letter))

    for i in range(lenth):
        for j in range(lenth):
            print(letter[j * lenth + (lenth - 1 - i)], end='')
    print()

# 5 * 5 기준 20 15 10 5 0 / 21 16 11 ... 4 출력 