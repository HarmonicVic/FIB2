#include <stdio.h>
#include "cycle.h"
#define N 3

int v[10]={1,2,3,4,-10,-11,-12,-13,201,-150};

int OperaMat(int Matriz[N][N], int salto);

int main(){
  int t1 = getticks();
   long int i,a;
   int b;
   // Descomentar para medir los ticks
   //ticks tick1,tick2;
   
   // Descomentar para medir los ticks
   //tick1=getticks();
   for (i=0;i<1000;i++)
     for (a=0;a<1000;a++)
       b=OperaMat((int (*)[3])v,2);
   // Descomentar para medir los ticks
   //tick2=getticks();  
   //printf("Ciclos = %lf\n",elapsed(tick2,tick1)); 
       
   if (b==-612)
     printf("OperaMat BIEN programado.\n");
   else
     printf("OperaMat MAL programado.\n");
     int t2 = getticks();
     printf("Cycles = %lf\n", elapsed(t2, t1));
}

//  instructions = 103.175.336 instr
//  cycles = 34.363.392 cycles
//  CPI = 0.3331