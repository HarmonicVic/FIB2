#include <stdio.h>
#include <string.h>
#include <unistd.h>

void main(int argc, char *argv[]){
    char buffer[512];
    sprintf(buffer, "%d is no as %d, it is %d \n", argv[1]);
    write(1,buffer, strlen(buffer));
}