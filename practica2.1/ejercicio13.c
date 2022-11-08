#include <time.h>
#include <sys/time.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main (){

    int i, t1, t2, start, end;

    struct timeval tv;

    if (t1 = gettimeofday(&tv, NULL) == -1){
        perror("Fallo en gettimeofday");
    }

    start = tv.tv_usec;    

    for (i = 0; i < 1000000; i++){}

    if (t2 = gettimeofday(&tv, NULL) == -1){
        perror("Fallo en gettimeofday");
    }

    end = tv.tv_usec; 

    printf("El bulce ha tardado %d ms en incrementar la variable un millon de veces. \n", end - start);

    return 0;
}
