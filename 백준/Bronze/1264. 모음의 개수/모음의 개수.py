while True:
    n = input()
    if n == "#":
        break
        
    cnt = 0
    for i in n:
        if i in "aeiouAEIOU":
            cnt += 1
            
    print(cnt)