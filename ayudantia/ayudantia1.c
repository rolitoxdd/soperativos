#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    pid_t my_id = getpid();
    pid_t parent_id = getppid();
    printf("Proceso actual: %d\nProceso padre: %d\n", my_id, parent_id);
    if (fork())
    {

        my_id = getpid();
        parent_id = getppid();
        printf("[entro a if] Proceso hijo: %d Proceso padre: %d\n", my_id, parent_id);
    }
    else
    {
        sleep(1);
        my_id = getpid();
        parent_id = getppid();
        printf("[entro a else] Proceso hijo: %d Proceso padre: %d\n", my_id, parent_id);
    }

    return 0;
}