#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <fcntl.h>

void procesos() {

    pid_t pid = getpid();

    pid_t ppid = getppid();

    pid_t gid = getpgid(ppid);

    pid_t sid = getsid(pid);

    struct rlimit rlim;

    getrlimit(RLIMIT_NOFILE, &rlim);

    char *path = malloc(sizeof(char)*(4096 + 1));

    char *rpath = getcwd(path, 4096 + 1);

    printf("PID: %i PPID: %i PGID: %i SID: %i LIMIT: %li PATH: %s\n", 
        pid, ppid, gid, sid, rlim.rlim_max, path);

    free (path);
}

int main(int argc, char **argv){

   if (argc < 2) {
        printf("ERROR: Introduce el comando.\n");
        return -1;
    }
    pid_t pid = fork();

    if (pid == 0){

        pid_t mi_sid = setsid();

        int f1 = open("/tmp/daemon.out",O_CREAT | O_RDWR,00777);
        int f2 = open("/tmp/daemon.err",O_CREAT | O_RDWR,00777);
        int f3 = open("/dev/null",O_CREAT | O_RDWR,00777);
        dup2(f1,1);
        dup2(f2,2);
        dup2(f3,0);

        if(execvp(argv[1], argv+1) == -1 ){
            printf("No se ha podido ejecutar el programa\n");
        }


        chdir("/tmp");

        printf("[Hijo] \n");

        procesos();

        //sleep(100);
    }
    else{

        printf("[Padre] \n");
        
        procesos();

        //sleep(100);

    }

    return 0;
}
/*
sergio:~/ASOR/practica2_3$ ./ejercicio8 ls -l
[Padre]
PID: 571 PPID: 469 PGID: 469 SID: 469 LIMIT: 4096 PATH: /home/sergio/ASOR/practica2_3
sergio:~/ASOR/practica2_3$ cat /tmp/daemon.out
total 80
-rwxr-xr-x 1 sergio sergio 16744 Dec  1 18:24 ejercicio7
-rw-r--r-- 1 sergio sergio   925 Dec  1 18:49 ejercicio7.c
-rwxr-xr-x 1 sergio sergio 16744 Dec  1 18:47 ejercicio7b
-rw-r--r-- 1 sergio sergio   915 Dec  1 18:48 ejercicio7b.c
-rwxr-xr-x 1 sergio sergio 17440 Dec  1 19:03 ejercicio8
-rw-r--r-- 1 sergio sergio  1401 Dec  1 19:03 ejercicio8.c
-rw-r--r-- 1 sergio sergio   177 Dec  1 18:01 hola
drwx------ 2 sergio sergio  4096 Dec  1 18:00 logs
*/