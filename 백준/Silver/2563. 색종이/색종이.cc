#include <stdio.h>

int main()
{
    int board[100][100] = { 0, };
    int n = 0;
    int x = 0, y = 0;
    int count = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);

        for (int j = x; j < x + 10; j++)
        {
            for (int k = y; k < y + 10; k++)
            {
                board[j][k] = board[j][k] + 1;
            }
        }
    }
    
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (board[i][j] > 0)
            {
                count = count + 1;
            }
        }
    }
    
    printf("%d", count);

    return 0;
}