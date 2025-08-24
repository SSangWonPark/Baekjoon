MOBIS = ['M', 'O', 'B', 'I', 'S']
word = input()
ans = 1
 
for i in MOBIS:
    if i not in word:
        ans = 0
        break
 
if ans:
    print('YES')
else :
    print('NO')