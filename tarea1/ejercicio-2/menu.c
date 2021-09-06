#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    int x = -1;
    // while (1)
    // {

    printf("MENU:\n\t1 - canal 1\n\t2 - canal 2\n\t3 - canal 3\n\t0 - Apagar televisor\nElija una opcion: ");
    scanf("%d", &x);
    printf("%d", x);
    if (x == 1)
    {
        printf("hola");
        execlp("./canal1", "", NULL);
    }
    else if (x == 2)
    {
        execlp("./canal2", "", NULL);
    }
    else if (x == 3)
    {
        execlp("./canal3", "", NULL);
    }
    else if (x == 0)
    {
        exit(0);
    }
    else
    {
        printf("Elija una opción correcta");
    }
    // }
}