#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(){

  char *t1 = "tuberia1";
	mkfifo(t1, 0644);

	char *t2 = "tuberia2";
  mkfifo(t2, 0644);

  char buffer[257];

  int pipe1 = open(t1, O_RDONLY | O_NONBLOCK);
  int pipe2 = open(t2, O_RDONLY | O_NONBLOCK);

  int cambios, pipeactual;

   while (cambios != -1 ) {
    fd_set conjunto;
    FD_ZERO(&conjunto);
    FD_SET(pipe1, &conjunto);
    FD_SET(pipe2, &conjunto);
    int numpipeactual;

    cambios = select((pipe1 < pipe2) ? pipe2 + 1 : pipe1 + 1, &conjunto, NULL,NULL,NULL);

    if (cambios > 0){
      if (FD_ISSET(pipe1, &conjunto)) {
        numpipeactual = 1;
        pipeactual = pipe1;
         } else if (FD_ISSET(pipe2, &conjunto)) {
        numpipeactual = 2;
        pipeactual = pipe2;
      }

      ssize_t readsize = 256;
			while (readsize == 256) {
				readsize = read(pipeactual, buffer, 256);
				buffer[readsize] = '\0';
				printf("Tuberia %i: %s", numpipeactual, buffer);
			}
      if (readsize != 256 && numpipeactual == 1) {
        close(pipe1);
        pipe1 = open(t1, O_RDONLY | O_NONBLOCK);
				if (pipe1 == -1) {
					close(pipe1);
					close(pipe2);
					return -1;
				}
      } else if(readsize != 256 && numpipeactual == 2) {
        close(pipe2);
        pipe2 = open(t2, O_RDONLY | O_NONBLOCK);
				if (pipe1 == -1) {
					close(pipe1);
					close(pipe2);
					return -1;
				}
      }
    }

  }

  close(pipe1);
  close(pipe2);

  return 0;
}
