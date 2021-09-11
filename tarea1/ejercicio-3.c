#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    int fd[2];
    char readbuffer[80];
    pid_t parent_pid = getpid();
    pipe(fd);
    for (int i = 0; i < 5; i++)
    {
        if (!fork())
        {
            char mensaje[80];
            char pid[100];
            close(fd[0]);
            sprintf(pid, "%d", getpid());
            fgets(mensaje, sizeof(mensaje), stdin);
            // scanf("%s", mensaje);
            // if ((strlen(mensaje) > 0) && (mensaje[strlen(mensaje) - 1] == '\n'))
            // mensaje[strlen(mensaje) - 1] = '\0'; // remueve salto de linea
            strcat(pid, ": ");
            strcat(pid, mensaje);
            write(fd[1], pid, sizeof(pid));
            exit(0);
        }
        else
        {

            read(fd[0], readbuffer, sizeof(readbuffer));
            printf("[PADRE] %d - MENSAJE DESDE HIJO %s \n", getpid(), readbuffer);
            read(fd[0], readbuffer, sizeof(readbuffer));
        }
    }
    close(fd[1]);

    return 0;
}