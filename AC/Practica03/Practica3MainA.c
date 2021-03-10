#include <stdio.h>
#include "cycle.h"
#define N 3

int v[10]={1,2,3,4,-10,-11,-12,-13,201,-150};

int OperaVec(int Vector[], int elementos);

int main(){
  int t1 = getticks();
   long int i,b;
   int a;
   // Descomentar para medir los ticks
   //ticks tick1,tick2;
   
  // Descomentar para medir los ticks
  //tick1=getticks();
   for (i=0;i<1000;i++)
     for (b=0;b<1000;b++)
       a=OperaVec(v,9);
  // Descomentar para medir los ticks
  //tick2=getticks();  
  //printf("Ciclos = %lf\n",elapsed(tick2,tick1)); 
       
   if (a==-13)
     printf("OperaVec BIEN programado.\n");
   else
     printf("OperaVec MAL programado.\n");
  int t2 = getticks();
  printf("Ciclos = %lf\n", elapsed(t2, t1));
}


//  nº instrucciones = 98.175.336
//  nº ciclos = 28.701.398
// CPI = 28701398/98175336 = 0.2923
      