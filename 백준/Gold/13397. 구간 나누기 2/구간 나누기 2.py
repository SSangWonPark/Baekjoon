import sys
input = sys.stdin.readline

N, M = map(int, input().split())
array = list(map(int, input().split()))

def check(x):
    cnt = 1
    cur_min = cur_max = array[0]
    for a in array[1:]:
        start = cur_min if cur_min < a else a
        end = cur_max if cur_max > a else a

        if end - start > x:
            cnt += 1
            cur_min = cur_max = a
        else:
            cur_min, cur_max = start, end

    return cnt

start, end = 0, max(array) - min(array)
ans = end

while start <= end:
    mid = (start + end) // 2

    if check(mid) <= M:
        ans = mid
        end = mid - 1
    else:
        start = mid + 1

print(ans)

# 구간을 M개 이하로 나누어서 구간의 점수의 최댓값을 최소로 하는 방법.
# 어떻게 구간을 나눠야 할까. 연속된 구간이니까 매 시점에서 최대와 최소를 알고 있으면 바로 차이를 구할 수 있음.
# if [1, 5, 4, 6, 2, 1, 3, 7] M = 3
# 값:   1, 5, 4, 6, 2, 1, 3, 7
# 최대: 1, 5, 5, 6, 6, 6, 6, 7
# 최소: 1, 1, 1, 1, 1, 1, 1, 1
# 최대:  , 5, 5, 6, 6, 6, 6, 7
# 최소:  , 5, 4, 4, 2, 1, 1, 1

# 이런식이면 공간이 너무 많이 필요함. 
# 2805번 나무 자르기 문제 참고. <- M = 2인 경우에 찾는 문제. 이진 탐색의 구간을 자르는 최대값을 찾는걸로 사용.

# 구간들의 최소값을 찾는 이진 탐색. 해당 값이 가능한 구간의 개수를 리턴하게끔 해서 최소 찾기.
# 현재 구간 최댓값 − 현재 구간 최솟값 <= x 를 이진 탐색하도록 구성.
# check에서 구간의 최대 - 최소의 한계 값 x를 받고 배열을 훑으며 x로 자를 수 있는 구간의 수를 체크. 이건 O(N)이면 됨.
# 이진 탐색으로 최소의 x 값 찾기. M개 이하로 나누어지면 낮추고, 안되면 x 키우기.