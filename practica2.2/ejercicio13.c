#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv) {

	if (argc < 2) {
		printf("ERROR: Falta la ruta del archivo.\n");
		return -1;
	}

    int fd = open(argv[1], O_CREAT | O_RDWR, 00777);
    if (fd == -1) {
        printf("ERROR: No se ha podido abrir/crear el fichero.\n");
        return -1;
    }

	int fd3 = dup2(fd,2);
    int fd2 = dup2(fd, 1);

    printf("La salida ha sido redirigida %s\n", argv[1]);

	char *s;
	if (setuid(0) == -1){
		 perror(s);
	}

    dup2(fd2, fd);
	dup2(fd3,fd);

  return 0;
}

//ls > dirlist 2>&1: Redirecciona la salida estándar a dirlist y luego la salida de errores la redirecciona a la 1 que corresponde a dirlist. 
//Por lo tanto, ambas salidas se van a ver en dirlist.

//ls 2>&1 > dirlist: Redirecciona la salida de error a la salida estándar y la salida estándar a dirlist, por lo tanto los errores se van a ver 
//por pantalla y la salida normal en el fichero dirlist.
