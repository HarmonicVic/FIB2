#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

void error_handler(char *msg);

void Usage()
{
    char buf[256];
    sprintf(buf, "The program has to be executed with the number of children requested\n");
    int res = write(1, buf, strlen(buf));
    if (res == -1)
        error_handler("Error: write() failed\n");
    exit(1);
}

void error_handler(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
        Usage();
    int n = atoi(argv[1]);
    int *pids = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
    {
        pids[i] = fork();
        if (pids[i] < 0) //error with fork
            error_handler("Error: fork execution failed\n");
        else if (pids[i] == 0)
        { //child code
            char order[4];
            sprintf(order, "%d", n);
            execlp("hijo1.v", "hijo1.v", order, NULL);
            error_handler("Error: execlp execution failed\n"); //code shouldn't get this far if exec works
        }
        else
        { //parent code
        }
    }

    /*while (1)
    { //active waiting
        for (int i = 0; i < n; i++)
        {
            if (waitpid(pids[i], NULL, 0))
            {
                pids[i] = fork();
                if (pids[i] < 0) //error with fork
                    error_handler("Error: fork execution failed\n");
                else if (pids[i] == 0)
                { //child code
                    char order;
                    sprintf(&order, "%d", n);
                    execlp("hijo1.v", "hijo1.v", order, NULL);
                    error_handler("Error: execlp execution failed\n"); //code shouldn't get this far if exec works
                }
                else
                { //parent code
                }
            }
        }
    }*/

    //passive waiting: wait for SIGCHLD
    while (1)
    {
        sigset_t mask;
        sigfillset(&mask);
        sigdelset(&mask, SIGCHLD);
        sigsuspend(&mask);
        int ret = fork();
        if (ret < 0)
            error_handler("Error: fork execution failed\n");
        else if (ret == 0)
        {
            execlp("hijo1.v", "hijo1.v", (char)42, NULL);
            error_handler("Error: execlp execution failed\n"); //code shouldn't get this far if exec works
        }
    }
    free(pids);
}
