num = int(input())
word = input()
checkword = "aiueo"
count = 0

for i in word:
  if i in checkword:
    count += 1;

print(count);