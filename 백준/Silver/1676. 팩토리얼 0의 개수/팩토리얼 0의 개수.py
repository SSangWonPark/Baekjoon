def factorial(n):
  if n <= 1:
    return 1

  return n * factorial(n - 1)

num = int(input())

cnt = 0

ans = factorial(num)

while(ans > 0):
  if ans % 10 == 0:
    cnt += 1
  else:
    break

  ans = ans // 10

print(cnt);