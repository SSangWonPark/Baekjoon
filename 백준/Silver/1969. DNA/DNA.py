n, m = map(int, input().split())

DNA = []
temp = [[0 for z in range(m)] for y in range(4)]

for i in range(n):
    DNA.append(list(input().strip()))

    for j in range(m):
        if DNA[i][j] == 'A':
            temp[0][j] += 1
        elif DNA[i][j] == 'C':
            temp[1][j] += 1
        elif DNA[i][j] == 'G':
            temp[2][j] += 1
        elif DNA[i][j] == 'T':
            temp[3][j] += 1

ans = []
dna = "ACGT"

for i in range(m):
    count = [temp[idx][i] for idx in range(4)]
    ans.append(dna[count.index(max(count))])

cnt = 0

for i in range(n):
    for j in range(m):
        if DNA[i][j] != ans[j]:
            cnt += 1

print("".join(ans))
print(cnt)

# n 개 중에서 가장 작은 해밍 거리를 찾는 게 아님.
# 각 위치당 가장 빈도수가 높은 걸 찾아서 그 걸로 새로운 수열을 만들고 풀기
# A, C, G, T 사전순.