import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

dp = [0 for i in range(N)] 
minnum = [0 for i in range(N)] 
temp = [0 for i in range(N)] 

minnum[0] = A[0]

for i in range(1, N):
  minnum[i] = min(minnum[i - 1], A[i])
  temp[i] = A[i] - minnum[i]
  dp[i] = max(temp[i], dp[i - 1])

print(*dp)

# 50    100     70    110     10    100
#  0 100-50 100-50 110-50 110-50 100-10

# 해당 구간 기준 앞에서 가장 큰 값 -> 작은 값을 구하기.
# 가장 큰 값, 작은 값. 단, 큰 값 인덱스 > 작은 값 인덱스. 
# 그냥 큰 값 작은 값은 i <= j 를 만족하지 않음.
# 일단 n^2으로 가장 큰 뺄셈 찾기. -> 시간 초과

# for i in range(N):
#   for j in range(0, i + 1):
#     for k in range(j, i + 1):
#       if A[k] - A[j] >= 0:
#         dp[i] = max(dp[i], A[k] - A[j])

# 가지고 있는 최소와 추가된 값만 비교해보기.
# 추가된 값이 최소보다 작다면 이전의 값이 가장 큰 값.
# temp에 해당 시점 - 최소값을 저장하고 dp는 이전 값과 temp를 비교.

# 틀림. <- 마지막에 print(dp)를 해서 그럼 출력 맞추자.