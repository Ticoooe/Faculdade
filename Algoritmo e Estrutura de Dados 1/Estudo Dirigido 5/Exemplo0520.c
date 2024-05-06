#include <stdio.h>
#include <stdlib.h>


int metodo10(int x){
   int z = 0;
   double y = 1;
   double soma = 0;
   for(z=0; z<x; z++){
      soma = soma + (1/y);
      y++;
      printf("%lf, ",soma);
   }
}

int main(){
   int x = 0;
   printf("Entrar com um valor:  \n");
   scanf("%d", &x);
   metodo10(x);
   return (0);
}

