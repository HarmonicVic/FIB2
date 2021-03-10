#include <stdio.h>
#include <string.h>
#include <unistd.h>

int esNumero (char *str){
    int MAX_SIZE = 8;
    if (str != NULL && strlen(str) <= MAX_SIZE) return 1;
    else return 0;
}

int main(int argc, char *argv[]){
    char buf[80];
    if (esNumero(argv[1]) == 1) sprintf (buf, "Es un número válido. \n");
    else sprintf (buf, "No es un número válido. \n");
    write (1, buf, strlen(buf));
}