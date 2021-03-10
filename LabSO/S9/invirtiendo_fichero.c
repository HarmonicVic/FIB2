#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd, ret, fdsal, size;
    char buff[64];
    char name[64];
    sprintf(name, "%s.inv", argv[1]);
    fd = open(name, O_RDWR);
    fdsal = creat(name, S_IRUSR | S_IWUSR);
    fdsal = open(name, O_RDWR);
    if (fd < 0)
    {
    } //error
    else
    {
        size = lseek(fd, 0, SEEK_END);
        // int i = 0;
        int j = size-1;
        lseek(fd, j, SEEK_SET);    //last char
        while (j != -1)
        {
            ret = read(fd, buff, sizeof(char));
            write(fdsal, buff, ret);
            lseek(fd, -2, SEEK_CUR);
            j--;
        }
    }
}