#include <unistd.h>
#include <string.h>
#include <stdio.h>

void main(int argc, char* argv[]){
    int pid;
    char buffer[128];

    sprintf(buffer, "Padre: el pid del proceso es: %d \n", getpid());
    write (1, buffer, strlen(buffer));

    pid = fork();

    if (pid == 0){
        sprintf(buffer, "Hijo: soy el proceso %d y el parámetro es %s \n", getpid(), argv[1]);
        write (1, buffer, strlen(buffer));
    }
    while(1);
}