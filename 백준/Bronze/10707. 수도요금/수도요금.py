A = int(input())
B = int(input())
C = int(input())
D = int(input())
P = int(input())



if P <= C:
    if P * A > B:
        print(B)
    else:
        print(P * A)
else:
    if P * A > B + (P - C) * D: 
        print(B + (P - C) * D)
    else:
        print(P * A)