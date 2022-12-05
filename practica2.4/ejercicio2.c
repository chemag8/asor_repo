#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>

int main(int argc, char** argv){

  int p_h[2];
  int h_p[2];

  pipe(p_h);
  pipe(h_p);

  int p = fork();

  char *mensaje = (char*)malloc(255 * sizeof(char));
  int rd = 0;

  switch (p) {
    case -1:
      perror("ERROR al hacerl el fork");
      return 1;
      break;
    case 0:

      close(p_h[1]);
      close(h_p[0]);
      int i = 0;

      for (i; i < 10; i++){
        rd = read(p_h[0], mensaje, 255);
        mensaje[rd] = '\0';
        printf("[HIJO] Mensaje recibido: %s", mensaje);
        sleep(1);
        char flag = 'l';
        if (i == 9) flag = 'q';
        write(h_p[1], &flag, 1);
      }

    break;
    default:

      close(p_h[0]);
      close(h_p[1]);
      char flag = 'l';
      while(flag != 'q'){
        printf("%s\n", "[PADRE] Mensaje: ");
        rd = read(0, mensaje, 255);
        mensaje[rd] = '\0';
        write(p_h[1], mensaje, 255);
        rd = read(h_p[0], &flag, 1);
      }
    wait(NULL);
    break;
  }
  return 0;
}
