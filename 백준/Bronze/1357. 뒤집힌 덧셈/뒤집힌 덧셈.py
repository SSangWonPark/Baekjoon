a,b = list(input().split())

reva = []
revb = []

ans = []

for i in range(len(a), 0, -1):
    reva += str(a[i - 1])

for i in range(len(b), 0, -1):
    revb += str(b[i - 1])

temp = int("".join(reva)) + int("".join(revb))

test = list(str(temp))

for i in range(len(test), 0, -1):
    ans += str(test[i - 1])

print(int("".join(ans)))
