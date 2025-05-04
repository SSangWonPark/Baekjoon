a = 0
day = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
week = ["SUN", "MON","TUE", "WED", "THU", "FRI", "SAT"]
x, y = map(int,input().split()) 
for i in range(x - 1):
    a = a + day[i]
a = (a + y) % 7
print(week[a])