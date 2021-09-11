#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#define N 10

int channel[2];

void *escribir(void *tid)
{
    char msg[15];
    long index = (long)tid;
    srand(time(NULL) ^ (index << 16));
    int num = rand() % 100;
    sprintf(msg, "[%li]: %d\n", index, num);
    write(channel[1], msg, sizeof(msg));
    return NULL;
}

void *leer(void *argc)
{
    for (int i = 0; i < N; i++)
    {
        char res[15];
        read(channel[0], &res, sizeof(res));
        printf("recibi el msg: %s", res);
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t t[N + 1];
    pipe(channel);
    for (long i = 0; i < N; i++)
    {
        pthread_create(&t[i + 1], NULL, escribir, (void *)i);
    }
    pthread_create(&t[0], NULL, leer, NULL);
    for (long i = 0; i < N; i++)
    {
        pthread_join(t[i + 1], NULL);
    }
    pthread_join(t[0], NULL);

    close(channel[0]);
    close(channel[1]);
    return 0;
}