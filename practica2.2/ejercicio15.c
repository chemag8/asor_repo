#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char **argv) {

	if (argc < 2) {
		printf("ERROR: Falta la ruta del archivo.\n");
		return -1;
	}

    int fd = open(argv[1], O_CREAT | O_RDWR, 00777);
        if (fd == -1) {
            printf("ERROR: No se ha podido abrir el fichero.\n");
            return -1;
        }
    int st = lockf(fd, F_TEST,0);

    if(st == -1){
        printf("Error: el fichero esta bloqueado.\n");
        close(fd);
        return -1;
        }
        if(lockf(fd, F_TLOCK, 0) == -1){
            printf("Cerrojo bloqueado, fin de programa.\n");
            close(fd);
            return -1;

        }else{
            printf("Cerrojo desbloqueado.\n");
            time_t t;
            time(&t);
            printf("Hora actual: %s\n", ctime(&t));
            printf("Sleep de 10 sec.\n");
            sleep(10);
            printf("Termina el sleep.\n");
            lockf(fd, F_ULOCK, 0);
            printf("Fichero desbloqueado.\n");
            printf("Sleep de 10 sec.\n");
            sleep(10);
            printf("Termina el sleep.\n");  

        close(fd);
    }
    
    return 0;

}
