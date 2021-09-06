#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int main()
{
    int x = 0;
    if (fork())
    {
        // x = 0
        printf("[PADRE] ");
        x++; // x = 1
        printf("%p\t%d\n", &x, x);
    }
    else
    {
        //x = 0
        printf("[HIJO]  ");
        x++; //x = 1
        printf("%p\t%d\n", &x, x);
    }
}