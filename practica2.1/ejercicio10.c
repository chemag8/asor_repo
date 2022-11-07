#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>

int main (){

    printf("UID real: %d  UID efectivo: %d \n", getuid(), geteuid());

    struct passwd *a = getpwuid(getuid());

    printf("Nombre de usuario: %s \n", a->pw_name);
    printf("Directorio home: %s \n", a->pw_dir);
    printf("Descripcion del usuario: %s \n", a->pw_gecos);

    return 0;
}
