#include <sys/utsname.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){

    struct utsname a;

    if (uname(&a) == -1){
        perror("Fallo en uname");
        return -1;
    }

    printf("Sysname: %s \n", a.sysname);
    printf("Nodename: %s \n", a.nodename);
    printf("Release: %s \n", a.release);
    printf("Version: %s \n", a.version);
    printf("Machine: %s \n", a.machine);
    

    return 0;
}
