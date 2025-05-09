t = int(input())

for j in range(0,t):
    sum = 0
    csum = 0
    n = int(input())
    for i in range(0,n):
        c, g = map(float, input().split())
        csum += c
        sum += c*g

    print(int(csum), round(sum / csum, 1))