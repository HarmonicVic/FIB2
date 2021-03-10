#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
    int num;
    char buff[64];
    read(0, &num, sizeof(int));
    sprintf(buff, "%d\n", num);
    write(1, buff, strlen(buff));
}