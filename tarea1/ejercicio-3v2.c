#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#define N 5

int channel[2];

void *escribir(void *argc)
{
    srand(time(NULL) ^ (getpid() << 16));
    int num = rand() % 100;
    write(channel[1], &num, sizeof(num));
    return NULL;
}

void *leer(void *argc)
{
    int index = *(int *)argc;

    int res;
    read(channel[0], &res, sizeof(res));

    printf("[%d] recibi el msg: %d\n", index, res);
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t t[N + 1];
    pipe(channel);
    for (int i = 0; i < N; i++)
    {
        int idx = i + 1;
        pthread_create(&t[0], NULL, leer, (void *)&idx);
        pthread_create(&t[i + 1], NULL, escribir, NULL);
        pthread_join(t[i + 1], NULL);
        pthread_join(t[0], NULL);
    }

    close(channel[0]);
    close(channel[1]);
    return 0;
}