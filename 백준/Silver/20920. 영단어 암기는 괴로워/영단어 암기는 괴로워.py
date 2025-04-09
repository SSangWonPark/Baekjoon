import sys

input = sys.stdin.readline

a, b = map(int, input().split())
ans = {}

for _ in range(a):
    word = input().rstrip()

    if len(word) >= b:
        if word in ans:
            ans[word] += 1
        else:
            ans[word] = 1

# 정렬: 빈도수 내림차순 → 길이 내림차순 → 사전순 오름차순
sorted_words = sorted(ans.items(), key=lambda x: (-x[1], -len(x[0]), x[0]))

for word, count in sorted_words:
    print(word)