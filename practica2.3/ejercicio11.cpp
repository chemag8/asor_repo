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


int main(int argc, char **argv){

if(argc < 1){
cout << "Error: se debe escribir los segundos\n";
return -1;
}
int sec;
sscanf(argv[1],"%d",&sec);
sigset_t sg;
sigemptyset(&sg);
sigaddset(&sg,SIGINT);
sigaddset(&sg,SIGTSTP);
sigprocmask(SIG_BLOCK,&sg,NULL);
cout << getpid() << endl;;

cout<<"Me voy a dormir\n";
sleep(sec);
cout<<"Ya me he despertado\n";

sigset_t pendiente;
sigpending(&pendiente);

if(sigismember(&pendiente,SIGINT)){
cout << "SIGINT ha sido recibida\n";
}else{
cout << "SIGINT *NO* ha sido recibida\n";
}
if(sigismember(&pendiente,SIGTSTP)){
cout << "SIGTSTP ha sido recibida\n";
}else{
cout << "SIGTSTP *NO* ha sido recibida\n";
}

sigprocmask(SIG_UNBLOCK,&sg,NULL);

cout<<"Me voy a dormir\n";
sleep(sec);
cout<<"Ya me he despertado\n";
return 0;
}
