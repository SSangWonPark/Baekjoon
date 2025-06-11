n = int(input())

for i in range(n):
  a, b, c = map(int, input().split())
  num = sorted([a, b, c])

  print(f"Scenario #{i + 1}:")

  if num[2] ** 2 == num[0] ** 2 + num[1] ** 2:
    print("yes\n")
  else:
    print("no\n")