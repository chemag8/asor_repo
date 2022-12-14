#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/sysmacros.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {


	if (argc < 2) {
		 printf("ERROR: Falta la ruta del archivo.\n");
		 return -1;
	}

	struct stat buff;

	int statint = stat(argv[1], &buff);

	if (statint == -1) {
		printf("ERROR: No existe el directorio.\n");
		return -1;
	}

    switch (buff.st_mode & S_IFMT){

        case S_IFREG: 
            printf("%s es un archivo ordinario.\n", argv[1]);

            char* hard = malloc(sizeof(char)*(5 + strlen(argv[1])));
	        char* sym = malloc(sizeof(char)*(5 + strlen(argv[1])));

	        strcpy(hard, argv[1]);
	        strcpy(sym, argv[1]);

	        hard = strcat(hard, ".hard");
	        sym = strcat(sym, ".sym");

		if (link(argv[1],hard) == -1) {
			printf("ERROR: No se ha podido crear el enlace duro.\n");
		} else printf("Se ha creado enlace duro.\n");

		if (symlink(argv[1],sym) == -1) {
			printf("ERROR: No se ha podido crear el enlace simbólico.\n");
		} else printf("Se ha creado enlace simbólico.\n");

            break;
        default:
            printf("ERROR: La ruta introducida no es un archivo ordinario.\n");

            break;
    }
 
	return 0;
}
