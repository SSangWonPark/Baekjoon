word = input()
num = int(input())
count = 0

for _ in range(num):
  temp = input()
  if temp[:5] == word[:5]:
    count += 1

print(count)