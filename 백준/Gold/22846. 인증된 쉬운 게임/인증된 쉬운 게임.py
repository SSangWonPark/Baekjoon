import sys
input = sys.stdin.readline

K = int(input())

divisor = [[] for _ in range(K + 1)]

for i in range(1, K+1):
  for j in range(1, int(i**0.5)+1):
    
    if i % j == 0:
      divisor[i].append(j)
      
      if j*j != i:
        divisor[i].append(i // j)

dp = [0] * (K + 1)

for i in range(K, 0, -1):
  for d in divisor[i]:
    ans = i + d

    if ans <= K and dp[ans] != 1:
      dp[i] = 1
      break

if dp[1]:
  print("Kali")
else:
  print("Ringo")

# K를 받고 K를 초과하는 사람이 패배.
# 사용할 수 있는 수 = K의 약수. <= nono. 모니터에 쓰인 값의 약수. 
# 칼리부터 시작.

# if. 2. 1 or 2. 칼리 2. 링고 뭘해도 초과.
# ...?? 약수는 본인을 포함하는데, 이러면 무조건 먼저하는 사람이 필승 아님? <= 모니터에 1이 쓰여 있음.

# if 2 <= 1 1 / 3가 되면서 칼리 승.
# if 3 <= 1 1 1 / 4이 되면서 링고 승.

# 제곱근을 이용해서 약수 구하기.
# 1부터 K까지 본인이 쓸 수 있는 약수들을 구해두고 사용.

# 전이식으로 큰 쪽부터 작은쪽으로 계산.
# i번째 순서에서 어떤 약수 d를 선택했을 때, i + d가 <= K 이고 dp가 아직 0이면 이기는 수.
# dp[i] == 0, 상대가 최선의 수를 두어도 지는 상태.
# 약수를 순회하면서 dp[i+d] == 0인 첫번째 약수를 고르면 됨.

# if K == 5
# i /   d     /   i + d   / 가능한 수
# 5 / 1, 5    / 6, 10     / no
# 4 / 1, 2, 4 / 5, 6, 8   / 5
# 3 / 1, 3    / 4, 6      / 4
# 2 / 1, 2    / 3, 4      / 3, 4
# 1 / 1       / 2         / 2
# dp[5] == 0
# dp[4] == 1
# dp[3] == 0 / dp[4]가 1이기 때문에 불가능
# dp[2] == 1 / dp[3] == 0이니까 가능
# dp[1] == 0 <= 따라서 링고 승