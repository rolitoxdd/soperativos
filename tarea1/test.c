#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#define K 5
int main()
{
    if (!fork()) // child
    {
        // kill(getppid(), SIGSTOP);
        exit(0);
    }
    else
    {
        // zombie
        while (1)
        {
        }
    }

    return 0;
}