#include <stdio.h>

int main()
{
    int num[9][9];
    int max = 0;
    int row = 1, col = 1;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &num[i][j]);

            if (max < num[i][j])
            {
                max = num[i][j];
                row = i + 1;
                col = j + 1;
            }
        }
    }
    
    printf("%d\n%d %d", max, row, col);

    return 0;
}
