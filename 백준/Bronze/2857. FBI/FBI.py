word = []
for _ in range(5):
  word.append(input())

check = "FBI"
a = []

for i in range(5):
  if check in word[i]:
    a.append(str(i + 1))

if a == []:
  print("HE GOT AWAY!")
else:
  print(" ".join(a))