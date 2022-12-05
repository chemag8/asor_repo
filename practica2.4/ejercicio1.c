#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>

#define PIPE_W 1
#define PIPE_R 0

int main(int argc, char** argv){

  if (argc < 2) {
    printf("Error: Introduce los comandos\n");
  }

  int fd[2];

  int pip = pipe(fd);

  int p = fork();

  switch (p) {
    case -1:
      perror("ERROR al hacerl el fork");
      return 1;
      break;
    case 0:
      dup2(fd[PIPE_R],0); 
      close(fd[PIPE_W]);
      close(fd[PIPE_R]);
      char *newargv[] = {argv[3],argv[4],NULL};
      execvp(newargv[0],newargv);
    break;
    default:
      dup2(fd[PIPE_W],1);
      close(fd[PIPE_W]);
      close(fd[PIPE_R]);
      char *newargv2[] = {argv[1],argv[2],NULL};
      execvp(newargv2[0],newargv2);
    break;
  }
  return 0;
}
