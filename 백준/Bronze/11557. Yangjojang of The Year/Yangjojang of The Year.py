t = int(input())

num = 0
name = []

for _ in range(t):
  n = int(input())

  for _ in range(n):
    uname, number = input().split()
    number = int(number)
      
    if num < number:
      num = number
      name = uname

  print(name)