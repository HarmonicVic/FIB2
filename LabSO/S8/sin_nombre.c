#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{
    int ret;
    char buffer[128];

    int fd[2];
    pipe(fd);
    //[0] for read, [1] for write

    ret = fork();

    if (ret == 0)
    {
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        execlp("cat", "cat", NULL);
        exit(1);
    }
    else
    {
        sprintf(buffer, "Inicio\n");
        write(fd[1], buffer, strlen(buffer));
        close(fd[1]);
        waitpid(-1, NULL, 0);
        sprintf(buffer, "Fin\n");
        write(1, buffer, strlen(buffer));
    }
}