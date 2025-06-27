n = int(input())

for _ in range(n):
  A, B, X = map(int, input().split())
  print(A * (X - 1) + B)