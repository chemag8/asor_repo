#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>


int main(int argc, char **argv) {

	if (argc < 2) {
		printf("ERROR: Falta la ruta del archivo.\n");
		return -1;
	}
    DIR *directorio = opendir(argv[1]);

    if (directorio == NULL ) {
        printf("ERROR: No existe el directorio.\n");
        return -1;
    }

    struct dirent *d;
    struct stat buf;
    size_t sizePath = strlen(argv[1]);
    d = readdir(directorio);
    off_t tamTotal = 0;
    int i = 0;
    while(d != NULL){
        char *path = malloc(sizeof(char)*(sizePath + strlen(d->d_name) + 3));
        strcpy(path, argv[1]);
        strcat(path, "/");
        strcat(path, d->d_name);

        int s = stat(path, &buf);
        if (s == -1) {
		printf("ERROR: No existe el fichero o directorio.\n");
		return -1;
	    }else{
            if(S_ISLNK(buf.st_mode)){
                 //enlace simbolico
              
                char *linkname = malloc(buf.st_size + 1);
                int rc2 = readlink(path, linkname, buf.st_size + 1);
                printf("[%d]: %s -> %s \n", i, d->d_name, linkname);
                free(linkname);
            }
            else if (S_ISREG(buf.st_mode)) {
                //Fichero normal
                printf("[%d]: %s [*]\n", i, d->d_name);
                tamTotal = tamTotal + buf.st_size;

            } else if (S_ISDIR(buf.st_mode)) {
                //Directorio
                printf("[%d]: %s [/]\n",i, d->d_name);
            }
            free(path);
            d = readdir(directorio);
        }
        i++;
    }
  return 0;
}
