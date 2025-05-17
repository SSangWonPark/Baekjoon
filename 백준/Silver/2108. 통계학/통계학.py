import sys
from collections import Counter

input = sys.stdin.readline

li = [int(input()) for _ in range(int(input()))]

N = str(round(sum(li) / len(li) , 0))
if N == '-0.0' :
    print(0)
else :
    print(N[:-2])

lis = li.copy()
lis.sort()
lis.reverse()
print(lis[len(lis) // 2])

lis.reverse()
d = dict(Counter(lis))
v = list(d.values())
k = list(d.keys())

if v.count(max(v)) > 1 :
    print(sorted(filter(lambda x: d[x] == max(v), d.keys()))[1])
else :
    print(k[v.index(max(v))])

print(max(li) - min(li))
      
 # Counter로 바로 dick으로 만들 수 있음.     
 # python으로 제출 시, 입출력 함수