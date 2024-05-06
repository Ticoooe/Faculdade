#include <stdio.h>
#include <stdlib.h>
#include "IO.h"
#include <math.h>
void exercicio04(int tamanho, int x, int count){
   if (count < tamanho){
         count++;
         exercicio04(tamanho, x+1, count);
         printf("(%d) =  %1.0lf \n", count, pow(5,x));        
   }
}

int main ( ){
   int tamanho = 0;
   printf("Entrar com valor de tamanho: ");
   scanf("%d", &tamanho);
   exercicio04(tamanho, 0, 0);
}