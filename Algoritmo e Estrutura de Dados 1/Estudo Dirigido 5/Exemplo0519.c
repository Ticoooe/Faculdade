#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int metodo09(int x){

   int y = 1;
   int z = 0;
   int soma = 0;
   for(z=0; z<x; z++){
      soma = soma + pow(y,2);
      y++;
      printf("%d, ",soma);
   }
}

int main(){
   int x = 0;
   printf("Entrar com um valor:  \n ");
   scanf("%d", &x);
   metodo09(x);
   return (0);
}

