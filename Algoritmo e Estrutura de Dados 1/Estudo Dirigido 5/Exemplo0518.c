#include <stdio.h>
#include <stdlib.h>

int metodo08(int x){
   int y = 1;
   int z = 0;
   int soma = 0;
   for(z=0; z<x; z++){
      soma = soma + y;
      y++;
      printf("%d, ",soma);
   }
}

int main(){
   int x = 0;
   printf("Entrar com um valor:  \n ");
   scanf("%d", &x);
   metodo08(x);
   return (0);
}

