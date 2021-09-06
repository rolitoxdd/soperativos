#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#define K 10
#define N 5

volatile int pizza_pieces = N;

int main(int argc, char *argv[])
{
    int i = 0, k = K;
    pid_t me;
    for (i = 0; i < k; i++)
    {
        pid_t childpid = fork();
        if (childpid == 0)
        {
            me = getpid();
            if (pizza_pieces > 0)
            {
                pizza_pieces--;

                printf("%p", &me);

                printf("Proceso %d: Pepperoni rules!!!: \n", me);
            }
            else
            {
                printf("Proceso %d: Que hambre, desgraciados...\n", me);
            }
            exit(0);
        }
    }
    return 0;
}