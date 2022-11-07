#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (){

    if (setuid(2) == -1){

        printf("Error(%d) %s \n", errno, strerror(errno));
    }

    return 0;
}
