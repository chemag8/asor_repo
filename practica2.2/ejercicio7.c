#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(){

	mode_t prev = umask(027);

  	int df = open("/home/cursoredes/Documents/prueba/test.txt", O_CREAT | O_EXCL, 0645);

  return 1;
}

//[cursoredes@localhost prueba]$ ls -ld test.txt 
//-rw-r----- 1 cursoredes cursoredes 0 Nov 21 09:45 test.txt
