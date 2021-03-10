#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

void main(){
    char buff[256];
    int x = 0;
    while(x < 10){
        sprintf(buff, "Hellooo %d\n", x);
        write(1, buff, strlen(buff));
        x++;
        sleep(1);
    }
}