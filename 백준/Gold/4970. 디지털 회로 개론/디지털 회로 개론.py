import sys

input = sys.stdin.readline

def NOT(x):
    a = [2, 1, 0]
    return a[x]

def AND(x, y):
    a = [[0, 0, 0],
        [0, 1, 1],
        [0, 1, 2]]
    return a[x][y]

def OR(x, y):
    a = [[0, 1, 2],
        [1, 1, 2],
        [2, 2, 2]]
    return a[x][y]

def bracket(word, idx, v):
    c = word[idx]

    if c == '-':
        v, i = bracket(word, idx + 1, v)
        return NOT(v), i

    if c in '012PQR':
        if c in '012':
            return int(c), idx + 1
        else:
            return v[c], idx + 1

    left, i = bracket(word, idx + 1, v)

    op = word[i]

    right, k = bracket(word, i + 1, v)

    if op == '*':
        res = AND(left, right)
    elif op == '+':
        res = OR(left, right)

    return res, k + 1

x = input().strip()

while x != '.':

    count = 0
    for P in range(3):
        for Q in range(3):
            for R in range(3):
                v = {'P':P, 'Q':Q, 'R':R}
                val, no = bracket(x, 0, v)
                if val == 2:
                    count += 1

    print(count)

    x = input().strip()

# (P*Q) / P, Q, R. P, Q 2로 고정. R이 0, 1, 2인 경우 -> 따라서 3
# P, Q, R의 수많은 조합. 총 3*3*3 27. 상수 2가 주어진 경우. 만들 수 없는 경우 0 ex. 0, 1, (P*-P)

# 27가지를 돌면서 2인 경우만 체크하기. 
# 괄호를 어떻게 처리할까. 스택? 재귀? 둘 다 될 거 같은데 재귀가 편할 듯.

# 재귀로 처리해보기. 
# 연산자나 여는 괄호를 만날 때마다 깊이 들어가서 닫는 괄호를 처리하고 나와야 함.
# '-'나 상수, 변수는 괄호 밖에 있을 수 있음. 나머지는 (A * B) or (A + B) 형태. (A 연산자 B) 형태.
# '('를 만나면 그 괄호를 제외한 나머지를 다시 재귀. 피연산자일 때 나오게끔.
# 연산자의 왼쪽 오른쪽 구해서 다음 스탭으로
# ')'는 연산자로 다 계산 하고 나오면 인덱스 +1 해서 반환하기.