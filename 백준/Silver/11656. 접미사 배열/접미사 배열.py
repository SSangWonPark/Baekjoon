word = input()
li = []

for i in range(len(word)):
  li.append(word[i:])

ans = sorted(li)
for s in ans:
  print(s)