#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void error_y_exit(char *msg,int exit_status){
perror(msg);
exit(exit_status);
}

/* Ejecuta el comando ps –u username mediante la llamada al sistema execlp */
/* Devuelve: el código de error en el caso de que no se haya podido mutar */
void muta_a_PS(char *username){
 execlp("ps", "ps", "-u", username, (char*)NULL);
 error_y_exit("Ha fallado la mutación al ps", 1);
}

void main(int argc, char* argv[]){
    int pid;
    char buffer[128];

    sprintf(buffer, "Padre: el pid del proceso es: %d \n", getpid());
    write (1, buffer, strlen(buffer));

    pid = fork();

    if (pid == 0){
        sprintf(buffer, "Hijo: soy el proceso %d y el parámetro es %s \n", getpid(), argv[1]);
        write (1, buffer, strlen(buffer));
        muta_a_PS(argv[1]);
    }

    if ((pid=fork())<0) error_y_exit("Error en fork",1);
    
    while(1);
}