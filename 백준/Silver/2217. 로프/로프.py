N = int(input())
M = []

for i in range(N):
    M.append(int(input()))
   
M.sort(reverse=True)
ans = []

for i in range(N):
    ans.append(M[i] * (i + 1))
    
print(max(ans))

# if 27, 23, 15, 11, 3 
# 1개 27 * 1 = 27 
# 2개 23 * 2 = 46 <= 최대
# 3개 15 * 3 = 45
# 4개 11 * 4 = 44
# 5개 3  * 5 = 15

# 정렬하고 그리디하게 풀면 정답