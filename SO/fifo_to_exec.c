#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

/* Uses print_things.c to print a number passed, which in this case is the pid of each child created
    the result is passed through a FIFO instead of STDIN / STDOUT */

void Usage()
{
    char buff[256];
    sprintf(buff, "Usage: El programa requiere sólo 1 parámetro n>1.\n");
    write(1, buff, strlen(buff));
    exit(0);
}

void error_n_exit(char* msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char const *argv[])
{
    int n = atoi(argv[1]);
    if (argc > 2 || n < 1)
        Usage();
    mkfifo("mypipe", 0777);

    int backup_stdout = dup(1);
    close(0);
    for (int i = 0; i < n; ++i)
    {
        int ret = fork();
        if (ret < 0) error_n_exit("Fork failed");
        if (ret == 0)
        {
            //child
            printf("Child beginning:\n");
            int fd = open("mypipe", O_WRONLY);
            if (fd == -1)error_n_exit("opening FIFO failed");
            //closes STDOUT for you
            dup2(fd, STDOUT_FILENO);
            char numbr[64];
            sprintf(numbr, "%d", getpid());
            execlp("print_things.v", "print_things.v", numbr, NULL);
            error_n_exit("execlp failed");
        }
        else if (ret > 0)
        {
            //parent
            dup2(backup_stdout, 1);
            int fd2 = open("mypipe", O_RDONLY);
            if (fd2 == -1) error_n_exit("opening FIFO failed");
            char buf[1024];
            while (read(fd2, buf, strlen(buf)))
            {
                sprintf(buf, "%s", buf);
                write(1, buf, strlen(buf));
            }
            close(fd2);
        }
    }
}