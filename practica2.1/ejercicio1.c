#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(){

    if (setuid(2) == -1){

   	    perror("Fallo en setuid");
    }

  return 0;
}
