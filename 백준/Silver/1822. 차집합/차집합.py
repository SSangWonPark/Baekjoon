n, m = map(int, input().split())
a = set(map(int, input().split()))
b = set(map(int, input().split()))
c = a - b

if len(c) >= 0:
    print(len(c))
    ans = sorted(list(c))
    for i in range(len(c)):
        print(ans[i], end=' ')
else:
    print(0)