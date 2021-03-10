#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int ret;
    int ret2;
    int fd[2];
    pipe(fd);   //[0] for read, [1] for write

    ret = fork();
    if (ret == 0)
    {
        close(1);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        execlp("cat", "cat", argv[1], NULL);
        exit(1);
    }
    ret2 = fork();
    if (ret2 == 0)
    {
        close(0);
        dup2(fd[0], STDIN_FILENO);
        close(fd[1]);
        waitpid(-1, NULL, 0);
        execlp("wc", "wc", "-c", NULL);
        exit(1);
    }
    close(fd[0]);
    close(fd[1]);
    while(waitpid(-1, NULL, 0) > 0);
    printf("DONE!\n");
}