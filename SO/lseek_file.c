#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

void usage()
{
    printf("current settings are incorrect.\n");
    exit(1);
}

void error_handler(char* msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char const *argv[])
{
    if (argc != 4)
        usage();
    char buf;
    int fd = open(argv[1], O_RDONLY);
    int end_byte = lseek(fd, 0, SEEK_END);
    int start_bit = atoi(argv[2]);
    int end_bit = atoi(argv[3]);
    if (start_bit > end_bit || start_bit >= end_byte)
        usage();

    int cur_bit = start_bit;
    lseek(fd, start_bit, SEEK_SET);
    int ret = read(fd, &buf, sizeof(char));
    while (ret > 0 && cur_bit <= end_bit)
    {
        write(1, &buf, ret);
        cur_bit++;
        read(fd, &buf, sizeof(char));
    }
    close(fd);
    printf("\n");
}
