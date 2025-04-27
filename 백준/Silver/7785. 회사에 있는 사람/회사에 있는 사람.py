import sys

input = sys.stdin.readline

num = int(input())
namelist = set()

for i in range(num):
  name, state = input().split()
  if state == 'enter':
    namelist.add(name)
  elif state == 'leave':
    namelist.remove(name)

for word in sorted(namelist, reverse=True):
  print(word)

# python 문제 풀이 시, 입력을 input()으로 사용하면 시간초과될 수 있음.
# list 사용 시, 시간초과, set 사용용