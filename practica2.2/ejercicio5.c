#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){

  int df = open("/home/cursoredes/Documents/prueba/test.txt", O_CREAT, 0645);

  return 0;
}

//[cursoredes@localhost prueba]$ ls -ld test.txt 
//-rw-r--r-x 1 cursoredes cursoredes 0 Nov 21 09:29 test.txt
