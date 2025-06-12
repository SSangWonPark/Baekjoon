n = int(input())
f, f_1, f_2 = 0, 0, 1
if n >= 2:
    for _ in range(n):
        f = f_1 + f_2
        f_2 = f_1
        f_1 = f
    print(f)
else:
    print(n)