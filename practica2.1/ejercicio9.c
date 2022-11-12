#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){

   printf("UID real: %d  UID efectivo: %d \n", getuid(), geteuid());

    return 0;
}

//El setuid se utiliza para dar privilegios elevados en determinados archivos para usuarios que no lo poseen, como por ejemplo en el archivo /etc/bin/passwd. 
//Por lo tanto, el bit setuid estará activo cuando el uid sea distinto a euid.
