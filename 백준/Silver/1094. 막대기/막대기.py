def sumcount(lst):
    sum = 0
    for i in lst:
        sum += i
    return sum


x = int(input())
lst = [64]

while True:
    sum = sumcount(lst)

    if x < sum:
        min = lst[0]

        for i in range(len(lst)):
            if lst[i] < min:
                min = lst[i]

        lst.remove(min)

        lst.append(min // 2)

        if sumcount(lst) < x:
            lst.append(min // 2)
    else:
        break

print(len(lst))