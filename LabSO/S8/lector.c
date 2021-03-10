#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{
    int fd;
    char buff[128];
    fd = open("fifo1");
    while (read(fd, buff, 100) > 0)
    {
        sprintf(buff, "%s\n", buff);
        write(1, buff, strlen(buff));
    }
    close(fd);
}