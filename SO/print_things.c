#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
    int n = atoi(argv[1]);
    char buff[64];
    sprintf(buff, "HI! here's your num: %d\n", n);
    write(1, buff, strlen(buff));
}