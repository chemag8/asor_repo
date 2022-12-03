#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/resource.h>
#include <sys/time.h>

int main(int argc, char **arg_list){

    if (argc < 2) {
        printf("ERROR: Introduce el programa\n");
        return -1;
    }

    if(execvp(arg_list[1], arg_list+1) == -1 ){
        printf("No se ha podido ejecutar el programa\n");
    }

    printf("El comando termino de ejecutarse\n");





    return 0;
}
/*

sergio@DESKTOP-EM7FA9P:~/ASOR/practica2_3$ ./ejercicio7 ls -l
total 56
-rwxr-xr-x 1 sergio sergio 16744 Dec  1 18:24 ejercicio7
-rw-r--r-- 1 sergio sergio   468 Dec  1 18:24 ejercicio7.c
-rwxr-xr-x 1 sergio sergio 16744 Dec  1 18:47 ejercicio7b
-rw-r--r-- 1 sergio sergio   915 Dec  1 18:48 ejercicio7b.c
-rw-r--r-- 1 sergio sergio   177 Dec  1 18:01 hola
drwx------ 2 sergio sergio  4096 Dec  1 18:00 logs
sergio@DESKTOP-EM7FA9P:~/ASOR/practica2_3$

*/