#include <stdio.h>

struct person{
    char name[16];
    int day, month, year;
};

int main(void) {
    int n = 0;
    scanf("%d", &n);

    struct person x;
    struct person min;
    struct person max;

    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d", &x.name, &x.day, &x.month, &x.year);
        
        if (i == 0)
        {
            max = min = x;
            continue;
        }
        
        if (max.year < x.year)
        {
            max = x;
        }
        else if (max.year == x.year && max.month < x.month)
        {
            max = x;
        }
        else if (max.month == x.month && max.day < x.day)
        {
            max = x;
        }

        if (min.year > x.year)
        {
            min = x;
        }
        else if (min.year == x.year && min.month > x.month)
        {
            min = x;
        }
        else if (min.month == x.month && min.day > x.day)
        {
            min = x;
        }
    }

    printf("%s\n%s", max.name, min.name);

    return 0;
}

// heap으로 풀었었지만 시간초과 실패. 그냥 갱신하는 걸로 변경