import math
case = int(input())

for i in range(case):
    n = int(input())
    sqrt = int(math.sqrt(n))
    TF = False
    k = n

    if(n == 0 or n == 1):
        print(2)
        continue

    while k < n * n and TF == False:
        sqrt = int(math.sqrt(k))

        for j in range(2,sqrt+1):
            if k % j == 0:
                break
        else:
            print(k)
            TF = True
        k += 1

# sqrt를 이용해서 소수 판별 가능. 0이나 1인 경우 2가 나와야 함.