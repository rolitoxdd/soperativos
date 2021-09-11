#include <stdio.h>
int main()
{
    int xd[3][2];
    for (int i = 0; i < 3; i++)
    {
        xd[i][0] = 1;
        xd[i][1] = 2;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d\n", xd[i][j]);
        }
    }
    return 0;
}