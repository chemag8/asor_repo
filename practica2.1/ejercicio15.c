#include <time.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (){

    struct tm *t;

    time_t tiempo = time(NULL);

    if ((t = localtime(&tiempo)) == NULL){
        perror("Fallo en localtime");
    }

    char s[200];

    setlocale(LC_ALL, "");

    strftime(s, 200, "%A, %d de %B de %Y, %H:%M", t);

    printf("%s \n", s);


    return 0;
}
