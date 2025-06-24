n = int (input())

for _ in range(n):
  a = list(map(str, input().split()))
  
  if a[1] == '*':
    if int(a[0]) * int(a[2]) == int(a[4]):
      print('correct')
    else:
      print('wrong answer')
  
  elif a[1] == '+':
    if int(a[0]) + int(a[2]) == int(a[4]):
      print('correct')
    else:
      print('wrong answer')

  elif a[1] == '-':
    if int(a[0]) - int(a[2]) == int(a[4]):
      print('correct')
    else:
      print('wrong answer')

  elif a[1] == '/':
    if int(a[0]) / int(a[2]) == int(a[4]):
      print('correct')
    else:
      print('wrong answer')