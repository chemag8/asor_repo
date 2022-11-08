#include <time.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main (){

    struct tm *t;

    time_t tiempo = time(NULL);

    if ((t = localtime(&tiempo)) == NULL){
        perror("Fallo en localtime");
    }

    printf("Estamos en el año %d \n", t->tm_year + 1900);


    return 0;
}
