#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>

int total = 50;
int h, m, s;
int current;

void signals(int s){
    char buff[256];
    if(s == SIGALRM) {
        current++;
        //sprintf(buff, "Time passed: %d\n", current);
        //write(1, buff, strlen(buff));
        
        s = current;
        if (s >= 60){ 
            m++;
            s = 0;
        }
        if (m >= 60){ 
            h++;
            m = 0;
        }
        sprintf(buff, "Clock -> %d:%d:%d\n", h, m, s);
        write(1, buff, strlen(buff));
    }
    else if(s == SIGUSR1){
        current = 0;
        sprintf(buff, "Time reset\n");
        write (1, buff, strlen(buff));
    }
}

int main(int argc, char* argv[]){
    int pid;
    struct sigaction sa;
    sigset_t mask;

    current = atoi(argv[1]);
    h = atoi(argv[2]);
    m = atoi(argv[3]);

    sigemptyset(&mask);
    sigaddset(&mask, SIGALRM);
    sigaddset(&mask, SIGUSR1);
    sigprocmask(SIG_BLOCK, &mask, NULL);

    sa.sa_handler = &signals;
    sa.sa_flags = SA_RESTART;
    sigfillset(&sa.sa_mask);

    sigaction(SIGALRM, &sa, NULL);
    sigaction(SIGUSR1, &sa, NULL);

    while (current < 100){
        alarm(1);
        sigfillset(&mask);
        sigdelset(&mask, SIGALRM);
        sigdelset(&mask, SIGUSR1);
        sigsuspend(&mask);
    }
}