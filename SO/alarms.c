#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int reading = 0;

void custom_alarm()
{
    reading = 1;
}

void usage()
{
    printf("You're supposed to do it right, you idiot\n");
}

void error_handler(char *msg)
{
    perror("Error:\n");
    perror(msg);
    exit(1);
}

int main(int argc, char const *argv[])
{
    sigset_t mask;
    struct sigaction sa;

    sigfillset(&mask);
    sigprocmask(SIG_BLOCK, &mask, NULL); //blocks everything while new signal treatment is set

    sa.sa_handler = custom_alarm;
    sa.sa_mask = mask;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGALRM, &sa, NULL); //custom SIGALRM set

    sigdelset(&mask, SIGALRM);
    sigsuspend(&mask); //waits for signal SIGALRM, other signals blocked

    if (reading == 1)
    {
        int fd[2];
        //fd[0] -> used by parent, input is output of cat through fd[1]
        //fd[1] -> used by child in execlp, transformed into stdout 1
        pipe(fd);
        int restore_stdout = dup(STDOUT_FILENO);

        int ret = fork();
        if (ret == 0)
        {
            dup2(fd[1], 1);
            close(fd[1]);
            close(fd[0]);
            execlp("cat", "cat", "foo.txt", NULL);
            error_handler("error in execlp\n");
        }
        else if (ret > 0)
        {
            char buf[256];
            close(0);
            close(fd[1]);
            int bts = read(fd[0], buf, sizeof(buf));
            while (bts > 0)
            {
                sprintf(buf, "%s", buf);
                write(1, buf, bts);
                bts = read(fd[0], buf, sizeof(buf));
            }
        }
        printf("Reading done\n");
    }
    else
    {
        error_handler("Something went wrong with the alarm signal\n");
    }
}
