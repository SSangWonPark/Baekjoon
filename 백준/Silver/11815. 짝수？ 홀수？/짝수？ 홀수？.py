import math

n = int(input())
nums = list(map(int, input().split()))

result = []

for x in nums:
    root = int(math.isqrt(x))
    if root * root == x:
        result.append("1")
    else:
        result.append("0")

print(" ".join(result))

# c로 실수 부분 처리가 안되서 파이썬으로 품