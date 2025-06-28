n = int(input())
a = list(map(int, input().split()))

if n < 3:
    print(n)
    exit()

ans = 2
tmp = 2

for i in range(n - 2):
    x, y, z = a[i], a[i + 1], a[i + 2]

    if (x <= y <= z) or (x >= y >= z):
        tmp = 2
    else:
        tmp += 1

    ans = max(ans, tmp)

print(ans)

# 한글자가 들어오는 경우도 생각. ans = 1
# 1 1 1 이 들어온 경우, 2개 출력되어야 함.
# 부분 성공: 33점

# 뭐가 문제일까
# 1 3 5 2 이면 2가 아니라 3이 나와야 하나? 이것도 아님.
# 3개씩 보면서 갈까. 1개면 무조건 1, 2개면 무조건 2, 3개인 경우만 처리