#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "mis_funciones.h"

int main(int argc, char *argv[]){
    char buf[128];
    int total;
    for (int i = 1; i < argc; ++i){
    //comprueba que es numero:
        if (esNumero(argv[i]) == 1) sprintf (buf, "El %s es un número válido. \n", argv[i]);
        else sprintf (buf, "No es un número válido. \n");
        write (1, buf, strlen(buf));
        //los cambia a int:
        int x = mi_atoi(argv[i]);
        sprintf (buf, "%d \n", x);
        write(1,buf,strlen(buf));
        //los suma al total:
        total += x;
    }
    sprintf (buf, "La suma es %d \n", total);
    write(1, buf, strlen(buf));
}