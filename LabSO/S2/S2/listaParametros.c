#include <stdio.h>
#include <unistd.h>
#include <string.h>

void Usage(char *buf){
	sprintf (buf, "Usage: listaParametros arg1, arg2 ... argn \n Este programa escribe por su salida la lista de argumentos que recibe \n");
	write (1, buf, strlen(buf));
}

void main(int argc,char *argv[])
{
char buf[128];
	if (argc > 0){
	for (int i=0;i<argc;i++){
		if (i==0){
			sprintf(buf,"El argumento %d es %s (es el nombre del ejecutable)\n",i,argv[i]);
		}else{
			sprintf(buf,"El argumento %d es %s\n",i,argv[i]);
		}
		write(1,buf,strlen(buf));
	}
	}
	else Usage(buf);
}
