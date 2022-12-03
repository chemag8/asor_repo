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

volatile int sigin=0;
volatile int stop=0;

void handler(int s){
if(s == SIGINT){
sigin++;
}
if(s == SIGTSTP){
stop++;
}
}

int main(int argc, char **argv){
cout << getpid() << endl;;
struct sigaction act;

sigaction(SIGINT,NULL,&act);
act.sa_handler = handler;
sigaction(SIGINT,&act,NULL);

sigaction(SIGTSTP,NULL,&act);
act.sa_handler = handler;
sigaction(SIGTSTP,&act,NULL);


while(sigin + stop < 10){

}
cout << "Senial SIGINT: " << sigin << endl;
cout << "Senial SIGTSTP: " << stop << endl;

return 0;
}
