num = []
ans = 0

for i in range(10):
  num.append(int(input()))

for i in range(10):
  if abs(ans - 100) >= abs(ans + num[i] - 100): 
    ans += num[i]
  else:
    break
  
print(ans)