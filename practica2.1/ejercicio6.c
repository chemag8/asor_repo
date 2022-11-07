#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){

    printf("Longitud maxima de los elementos: %ld \n", sysconf(_SC_ARG_MAX));
    printf("Numero maximo de hijos: %ld \n", sysconf(_SC_CHILD_MAX));
    printf("Numero maximo de ficheros abiertos: %ld \n", sysconf(_SC_OPEN_MAX));

    return 0;
}
