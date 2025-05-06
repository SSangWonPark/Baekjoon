n = int(input())
ans = 0
minNum = 100

for _ in range(n):
  num = list(map(int, input().split()))
  ans = 0
  minNum = 100

  for a in num:
    if a % 2 == 0:
      ans += a

      if minNum > a:
        minNum = a
  print(ans, minNum)