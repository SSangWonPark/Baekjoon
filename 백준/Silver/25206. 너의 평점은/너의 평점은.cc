#include <stdio.h>
#include <string.h>

int main()
{
    char string[20][51];
    float n[20];
    char m[20][10];
    float total = 0;
    float count = 0;

    for (int i = 0; i < 20; i++)
    {
        scanf("%s %f %s", &string[i][0], &n[i], &m[i][0]);

        if (strstr(m[i], "A+"))
        {
            total = total + n[i] * 4.5;
            count = count + n[i];
        }
        else if (strstr(m[i], "A"))
        {
            total = total + n[i] * 4.0;
            count = count + n[i];
        }
        else if (strstr(m[i], "B+"))
        {
            total = total + n[i] * 3.5;
            count = count + n[i];
        }
        else if (strstr(m[i], "B"))
        {
            total = total + n[i] * 3.0;
            count = count + n[i];
        }
        else if (strstr(m[i], "C+"))
        {
            total = total + n[i] * 2.5;
            count = count + n[i];
        }
        else if (strstr(m[i], "C"))
        {
            total = total + n[i] * 2.0;
            count = count + n[i];
        }
        else if (strstr(m[i], "D+"))
        {
            total = total + n[i] * 1.5;
            count = count + n[i];
        }
        else if (strstr(m[i], "D"))
        {
            total = total + n[i] * 1.0;
            count = count + n[i];
        }
        else if (strstr(m[i], "F"))
        {
            total = total + n[i] * 0.0;
            count = count + n[i];
        }
    }

    printf("%f", total/count); 

    int a = 0;
    scanf("%d", &a);

    return 0;
}