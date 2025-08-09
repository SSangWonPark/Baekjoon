for _ in range(3):
    a = int(input())
    b = 0
        
    for i in range(a):
        b += int(input())
            
    if b == 0:
        print(0)
    elif b > 0:
        print("+")
    else:
        print("-")