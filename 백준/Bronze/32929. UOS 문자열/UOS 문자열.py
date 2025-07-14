N = int(input())

ans = N % 3

if ans == 1:
  print("U")
elif ans == 2:
  print("O")
elif ans == 0:
  print("S")