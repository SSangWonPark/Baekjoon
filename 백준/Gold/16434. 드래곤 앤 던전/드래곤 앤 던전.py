import sys
input = sys.stdin.readline

import math

N, ATK = map(int, input().split())

Dungeon = [0] * N

HP = 0
cur = 0

for i in range(N):
    Dungeon[i] = list(map(int, input().split()))
    if Dungeon[i][0] == 1:
        hit = math.ceil(Dungeon[i][2] / ATK) - 1
        cur += (Dungeon[i][1] * hit)
    elif Dungeon[i][0] == 2:  
        HP = max(HP, cur)

        ATK += Dungeon[i][1]
        cur -= Dungeon[i][2]
        if cur < 0:
            cur = 0

print(max(HP, cur) + 1)

# 최대 체력, 현재 체력(<= 최대 체력), 공격력
# N개의 방, i번째를 클리어해야 i+1로 이동 가능. N번째 방에서 용을 이기는 것이 목표
# 방에는 포션 or 몬스터. 몬스터 존재 시 처치해야 이동 가능.
# 턴제 방식으로 용사 선턴 잡고 공격력만큼 몬스터 체력 깍고, 몬스터 공격력만큼 용사 체력. 몬스터 체력 0 => 다음 방.
# 포션 방. 체력 회복 가능. 단 최대값은 최대 체력.
# N번방에 존재하는 용을 이기기 위한 최소의 최대 체력을 구하라.

# 방을 순서대로 가야하니까 그냥 순서대로 움직이면 어떨까.
# 쭉 계산해서 받은 데미지를 저장하고, +1을 하면 최대 체력이 아닌가..?
# 아 최대 체력 이상으로 체력이 차지 않는 부분이 문제네...
# 하나 더 변수를 잡고, 현재 체력과 최대 체력을 따로 구분지어서 최대값을 가지도록 한다면?
# cur는 포션 먹을 때 0 아래로 가면 0으로 다시 보정하면 최대 체력 이상으로 차지 않는 부분을 보완 가능할 듯.

# 시간초과. N * 몬스터와 전투 계산하는 부분인데. 공격력이 낮고, 몬스터 체력이 클 때 너무 많은 시간이 소요됨.
# 이분 탐색..? 어떻게 값을 찾지? 탐색이 아니라 반복인데..?
"""
while Dungeon[i][2] > 0:
            Dungeon[i][2] -= ATK
            
            if Dungeon[i][2] <= 0:
                break

            cur += Dungeon[i][1]
"""
# int(Dungeon[i][2] / ATK)로 내림해서 몬스터 공격 횟수만큼 체력에 반영.
# int로 내리면 오차가 너무 커짐. ceil으로 가까운 정수값으로 바꾸고 -1.