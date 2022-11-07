#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){

   printf("UID real: %d  UID efectivo: %d \n", getuid(), geteuid());

    return 0;
}
