#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    char buf[64];
    int pd[2];
    pipe(pd);
    int ret = fork();
    if (ret == 0)
    {
        dup2(pd[0], 0);
        close(pd[0]);
        close(pd[1]);
        execlp("cat", "cat", NULL);
    }
    else
    {
        close(pd[0]);
        sprintf(buf, "Un saludo\n");
        write(pd[1], buf, strlen(buf));
        close(pd[1]);
        sprintf(buf, "Final del programa\n");
        write(1, buf, strlen(buf));
    }
}
