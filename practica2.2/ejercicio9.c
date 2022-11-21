#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/sysmacros.h>
#include <time.h>

int main(int argc, char *argv[]){

    if (argc < 2) {
		 printf("ERROR: Falta la ruta del archivo.\n");
		 return -1;
	}

	struct stat buf;

	int s = stat(argv[1], &buf);

	if (s == -1) {
		printf("ERROR: No existe el directorio.\n");
		return -1;
	}

    printf("MAJOR: %li\n", (long) minor(buf.st_dev));

	printf("MINOR: %li\n", (long) major(buf.st_dev));

	printf("INODO: %li\n", buf.st_ino);

	mode_t mode = buf.st_mode;

	if (S_ISLNK(mode)){

		printf("TIPO: %s es un enlace simbólico.\n", argv[1]);

	} else if (S_ISREG(mode)) {

		printf("TIPO: %s es un archivo ordinario.\n", argv[1]);

	} else if (S_ISDIR(mode)) {

		printf("TIPO: %s es un directorio.\n", argv[1]);
	}

	printf("ULTIMO ACCESO: %s\n", ctime(&buf.st_atime));    

    return 0;
}


//st_mtime es la última modificación del fichero.
//st_ctime es el último cambio de estado del fichero.
