#include <error.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void Usage()
{
    error(1, 0, "Invalid argument.\nCorrect usage: an argument giving the id\n");
}

void error_handler(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int id, minutes = 0;
    char s[80];

    if (argc != 2)
        Usage();

    id = atoi(argv[1]);

    sprintf(s, "Hijo1[id=%02d pid=%5d] created\n", id, getpid());
    if (write(2, s, strlen(s)) < 0)
        error(1, errno, "write");

    while (1)
    {
        /*int x;      //binary number
        int n;      //x converted into decimal system
        int ret = read(0, &x, sizeof(int));
        while (x > 0){
            n = x % 10;
        }*/

        //temporary: imagine input is decimal instead of binary
        int n;
        char c;
        int ret = read(0, &n, sizeof(int));
        if (ret < 0)
            error_handler("Error: read() failed\n");
        int fd = open("input.txt", O_RDONLY); //reading only because we won't modify the file
        if (fd < 0)
            error_handler("Error: open() failed\n");
        lseek(fd, n, SEEK_SET);
        ret = read(fd, &c, sizeof(char));
        if (ret < 0)
            error_handler("Error: read() failed\n");
        sprintf(s, "Hijo1[id=%02d pid=%5d], caracter: %c\n", id, getpid(), c);
        if (write(1, s, strlen(s)) < 0)
            error(1, errno, "write");
        sprintf(s, "\n");
        if (write(1, s, strlen(s)) < 0)
            error_handler("Error: write() failed\n");

        //original code below:
        // sleep(60);

        // minutes++;
        // sprintf(s, "Hijo1[id=%02d pid=%5d] minutes=%d\n", id, getpid(),
        //         minutes);
        // if (write(1, s, strlen(s)) < 0)
        //     error(1, errno, "write");
    }
}
