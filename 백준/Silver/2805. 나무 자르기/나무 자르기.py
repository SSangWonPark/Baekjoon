import sys
input = sys.stdin.readline

N, M = map(int, input().split())

tree = list(map(int, input().split()))
ans = 0

def check(cut):
  global tree
  cnt = 0
  for wood in tree:
    if wood > cut:
      cnt += wood - cut
  return cnt
  
def binary_search(start, end):
  global ans
  if start > end:
    return 
  mid = (start + end) // 2
  cnt = check(mid)
  if cnt >= M:
    ans = mid
    return binary_search(mid + 1, end)
  else:
    return binary_search(start, mid - 1)

binary_search(0, max(tree))
print(ans)