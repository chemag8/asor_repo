#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char **argv){

  if (argc < 2) {
    printf("ERROR: Es necesario un argumento.\n");
    return -1;
  }

  int fd = open("tub_name",O_WRONLY);

  write(fd, argv[1], strlen(argv[1]));

	close(fd);

  return 0;
}
