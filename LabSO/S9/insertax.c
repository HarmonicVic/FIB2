#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int ret, pos;
    char buff[128];
    ret = open("salida.txt", O_RDWR);
    if (ret < 0)
    {
    } //error
    else
    {
        lseek(ret, -1, SEEK_END);
        pos = read(ret, buff, sizeof(char));
        lseek(ret, -1, SEEK_END);
        write(ret, "X", sizeof(char));
        write(ret, buff, pos);
    }
}