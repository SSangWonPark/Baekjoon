n = int (input())
num = list(map(int, input().split()))

upcount = 0
downcount = 0
count = 1
ans = 1

for i in range(0, n - 1):
  
  if num[i] < num[i + 1]:
    
    if upcount == 0: 
      upcount = 1
      count += 1
      downcount = 0
    else:
      upcount = 1
      count = 2
      downcount = 0

  elif num[i] > num[i + 1]:
    
    if downcount == 0:
      downcount = 1
      count += 1
      upcount = 0
    else:
      downcount = 1
      count = 2
      upcount = 0

  else:
    count = 2
    upcount = 0
    downcount = 0
  
  if ans < count:
    ans = count

print(ans)

# 한글자가 들어오는 경우도 생각. ans = 1
# 1 1 1 이 들어온 경우, 2개 출력되어야 함.