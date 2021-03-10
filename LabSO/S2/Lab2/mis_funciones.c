#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include "mis_funciones.h"

//comprueba si un char es un número.
int esNumero (char *str){
    int MAX_SIZE = 8;
    if (str != NULL && strlen(str) <= MAX_SIZE) return 1;
    else return 0;
}

//convierte un char en un int. 
unsigned int char2int (char c){
    return (unsigned int)c;
}

//convierte un string en un int a través de un bucle usando char2int
int mi_atoi(char *s){
	int num = 0;
	int i = 0;
	while (s[i]){
		num = num * 10 + (s[i] - '0');
		i++;
	}
    if (s[0] == '-') num = num - (2 * num);
	return num;
}
