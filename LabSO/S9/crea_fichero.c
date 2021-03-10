#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int ret;
    char text[] = "ABCD";
    ret = creat("salida.txt", S_IRUSR | S_IWUSR);
    if (ret < 0)
    {
    } //error
    else
    {
        write(ret, text, strlen(text));
        close(ret);
    }
}