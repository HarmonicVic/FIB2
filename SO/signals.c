#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>

void myfunct(){}

int main(int argc, char const *argv[])
{
    sigset_t mask;
    struct sigaction sa;

    sigfillset(&mask);  //all signals to 1
    //options for sigprocmask: SIG_BLOCK / SIG_UNBLOCK / SIG_SETMASK
    //SIG_BLOCK current set and &mask set are combined to blocked
    //SIG_UNBLOCK unblocks &mask from current blocked signals
    //SIG_SETMASK &mask set is blocked signals
    sigprocmask(SIG_BLOCK, &mask, NULL); //block signals = 1    
    sa.sa_handler = myfunct;
    //sa_flags should be SA_RESTART
    sa.sa_flags = 0;
    sa.sa_mask = mask;
    //which signal is changed with the new sa parameters
    sigaction(SIGALRM, &sa, NULL);
    sigemptyset(&mask);
    //wait until a non-blocked signal arrives
    sigsuspend(&mask);
    sigemptyset(&mask);
    sigaddset(&mask, SIGALRM);
    sigdelset(&mask, SIGALRM);
}
