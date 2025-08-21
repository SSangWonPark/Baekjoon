word = input()

if word[1] == '0':
    print(10 + int(word[2:]))
else:
    print(int(word[0]) + int(word[1:]))    