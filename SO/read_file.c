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
    char buf[4];
    close(0);
    int fd = open("foo.txt", O_RDONLY);
    int ret = read(fd, buf, sizeof(buf));
    while (ret > 0)
    {
        sprintf(buf, "%s", buf);
        write(1, buf, ret);
        ret = read(fd, buf, sizeof(buf));
    }
}
