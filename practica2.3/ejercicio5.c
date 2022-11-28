#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/resource.h>
#include <sys/time.h>

int main() {

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

    return 0;
}


//[cursoredes@localhost asor]$ ./p
//PID: 3345 PPID: 1842 PGID: 1842 SID: 1842 LIMIT: 4096 PATH: /home/cursoredes/Documents/asor
