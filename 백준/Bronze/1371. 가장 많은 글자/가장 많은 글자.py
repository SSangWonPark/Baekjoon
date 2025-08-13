import sys
input = sys.stdin.read

word = input().replace("\n","").replace(" ","")
alpha = [0] * 26
for i in word:
    alpha[ord(i) - 97] += 1
    
maxa = max(alpha)
r = []
for i in range(26):
    if alpha[i] == maxa:
        r.append(chr(i + 97))
        
r.sort()
print(*r,sep="")