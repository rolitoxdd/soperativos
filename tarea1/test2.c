#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
int main()
{
    if (fork())
    {
        printf("parent of parent id %d\n", getppid());
        sleep(5);
    }
    else
    {
        printf("before kill - parent: %d\n", getppid());
        kill(getppid(), 9);
        sleep(1);
        printf("after kill - parent: %d\n", getppid());
        exit(0);
    }

    return 0;
}