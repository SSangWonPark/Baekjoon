#include <stdio.h>

int main()
{
    int n = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int money = 0;

        scanf("%d", &money);

        int quarter = 0, dime = 0, nickel = 0, penny = 0;

        while (money - 25 > -1)
        {
            money = money - 25;
            quarter++;
        }
        while (money - 10 > -1)
        {
            money = money - 10;
            dime++;
        }
        while (money - 5 > -1)
        {
            money = money - 5;
            nickel++;
        }
        while (money - 1 > -1)
        {
            money = money - 1;
            penny++;
        }

        printf("%d %d %d %d\n", quarter, dime, nickel, penny);
    }

    return 0;
}