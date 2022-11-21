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
		 printf("ERROR: Se debe especeficar la ruta del archivo en los parámetros del programa.\n");
		 return -1;
	}

	struct stat buff;

	int statint = stat(argv[1], &buff);

	if (statint == -1) {
		printf("ERROR: No existe el directorio.\n");
		return -1;
	}

	mode_t mode = buff.st_mode;
    switch (buff.st_mode & S_IFMT){

        case S_IFREG: 
            printf("%s es un archivo ordinario.\n", argv[1]);

            char* hard = malloc(sizeof(char)*(5 + strlen(argv[1])));
	        char* sym = malloc(sizeof(char)*(5 + strlen(argv[1])));

	        strcpy(hard, argv[1]);
	        strcpy(sym, argv[1]);

	        hard = strcat(hard, ".hard");
	        sym = strcat(sym, ".sym");

	        printf("HARD: %s\n", hard);
	        printf("SYM: %s\n", sym);

            break;

        default:
            printf("ERROR: La ruta introducida no es un archivo ordinario.\n");

            break;
    }
 
	return 0;
}
