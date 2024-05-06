#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "IO.h"

int exercicio08(int valor){
   
   int resto = 0;

   if (valor == 1 || valor == 2){
      resto = 1;
   }
   else{
      if (valor > 2){
         resto = exercicio08(valor - 1) + exercicio08(valor - 2);
      }
   }

   return(resto);
}

int main( ){
   int valor = 0;

   printf("\nEntrar com valor de fibonacci: ");
   scanf("%d", &valor);
   
   printf(" Finonnaci eh %d \n", exercicio08(valor));

   return(0);
}