n,m = map(int, input().split())

dict1 = []
dict2 = []

for i in range(n):
  dict1.append(input())

for i in range(m):
  dict2.append(input())

ans = set(dict1) & set(dict2)

print(len(ans))

result = sorted(ans)

for i in result:
  print(i)