#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (){

    int i;

    for ( i = 0; i < 255; i++){

        printf("Error(%d) %s \n", i, strerror(i));
    }

    return 0;
}

//Del error(0) hasta el error(133), están definidos por el sistema. A partir del error(134) son errores desconocidos.
