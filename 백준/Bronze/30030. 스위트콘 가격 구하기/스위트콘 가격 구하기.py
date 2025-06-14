price = int(input())

for origin in range(price + 1):
    if int(origin * 1.1) == price:
        print(origin)
        break
        
# 핸드폰으로 풀지 말자. 단순 1.1로 나누는건 안규ㅣㅁ.