#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/resource.h>
#include <sys/time.h>

int main(int argc, char **argv){

    if (argc < 2) {
        printf("ERROR: Introduce el programa\n");
        return -1;
    }

  
  

    if (system(argv[1]) == -1) {
    printf("No se ha podido ejecutar el programa.\n");
    }


    printf("El comando termino de ejecutarse\n");





    return 0;
}

/*
sergio:~/ASOR/practica2_3$ ./ejercicio7b "ls -l"
total 56
-rwxr-xr-x 1 sergio sergio 16744 Dec  1 18:24 ejercicio7
-rw-r--r-- 1 sergio sergio   468 Dec  1 18:24 ejercicio7.c
-rwxr-xr-x 1 sergio sergio 16744 Dec  1 18:47 ejercicio7b
-rw-r--r-- 1 sergio sergio   454 Dec  1 18:46 ejercicio7b.c
-rw-r--r-- 1 sergio sergio   177 Dec  1 18:01 hola
drwx------ 2 sergio sergio  4096 Dec  1 18:00 logs
El comando termino de ejecutarse
sergio:~/ASOR/practica2_3$

*/