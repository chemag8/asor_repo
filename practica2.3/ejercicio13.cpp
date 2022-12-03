#include <iostream>
using namespace std;
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <string>
#include <fcntl.h>
#include <signal.h>

volatile bool borrar=false;

void handler(int s){
if(s == SIGINT){
borrar=true;
}

}

int main(int argc, char **argv){
if(argc < 2){
cout << "Escribe los segundos\n";
return -1;
}
int sec;
sscanf(argv[1],"%d",&sec);

cout << getpid() << endl;;
struct sigaction act;

sigaction(SIGUSR1,NULL,&act);
act.sa_handler = handler;
sigaction(SIGUSR1,&act,NULL);

cout << "Empieza la cuentra atras para el borrado del fichero" << endl;
sleep(sec);

if(borrar){
cout << "El fichero sera borrado" << endl;
unlink(argv[0]);
}else{
cout << "El fichero *NO* sera borrado" << endl;
}

return 0;
}
