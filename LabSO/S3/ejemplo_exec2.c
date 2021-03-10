#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
char buffer[80];

sprintf(buffer, "Soy el proceso: %d\n", getpid());
write(1,buffer,strlen(buffer));

execlp("./ejemplo_exec1", "ejemplo_exec1", NULL);

strcpy(buffer, "Después del exec\n");
write(1,buffer,strlen(buffer));
}
