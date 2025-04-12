word = input()
ans = 0
num = word.split(',')
for i in range(len(num)):
  ans += int(num[i])
print(ans)