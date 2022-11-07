#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){

    if (pathconf("/home/", _PC_LINK_MAX) == -1 || pathconf("/home/",_PC_PATH_MAX) == -1 || 
        pathconf("/home/", _PC_NAME_MAX) == -1){
        perror("Fallo en pathconf");
    }


    printf("Numero maximo de enlaces: %ld \n", pathconf("/home/", _PC_LINK_MAX));
    printf("Tamano maximo de una ruta: %ld \n", pathconf("/home/", _PC_PATH_MAX));
    printf("Tamano maximo de un nombre de un fichero: %ld \n", pathconf("/home/", _PC_NAME_MAX));

    

    return 0;
}
