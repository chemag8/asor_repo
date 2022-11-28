#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/resource.h>
#include <sys/time.h>

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

int main(){

    pid_t pid = fork();

    if (pid == 0){

        pid_t mi_sid = setsid();

        chdir("/tmp");

        printf("[Hijo] \n");

        procesos();

        //sleep(100);
    }
    else{

        printf("[Padre] \n");
        
        procesos();

        sleep(100);

    }

    return 0;
}

-----------------------------------------------------------------------
  
[cursoredes@localhost asor]$ ./p
[Padre]
PID: 3496 PPID: 1842 PGID: 1842 SID: 1842 LIMIT: 4096 PATH: /home/cursoredes/Documents/asor
[Hijo]
PID: 3497 PPID: 1 PGID: 1 SID: 3497 LIMIT: 4096 PATH: /tmp


¿Qué pasa si el padre termina antes que el hijo?
El hijo se queda huérfano y el ppid lo recoge la shell o init.

¿Qué pasa si el hijo termina antes que el padre?
El proceso se queda en espera hasta que hace el sleep(100).
