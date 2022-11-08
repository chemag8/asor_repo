#include <time.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main (){

    time_t t = time(NULL);

    if (t == -1){
        perror("Error en time");
    }

    printf("Number of seconds since the Epoch: %ld \n", t);

    return 0;
}
