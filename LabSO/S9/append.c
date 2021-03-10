#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd, ret, size;
    char buff[64];
    fd = open("file", O_RDWR);
    if (fd < 0)
    {
    } //error
    else
    {
        size = lseek(fd, 0, SEEK_END);
        int i = 0;
        int j = size;
        while (i < size)
        {
            lseek(fd, i, SEEK_SET);
            ret = read(fd, buff, sizeof(char));
            lseek(fd, j, SEEK_SET);
            write(fd, buff, ret);
            i++;
            j++;
        }
    }
}