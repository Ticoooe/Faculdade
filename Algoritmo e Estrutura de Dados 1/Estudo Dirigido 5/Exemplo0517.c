#include <stdio.h>
#include <stdlib.h>

int metodo07(int x){
   double soma = 0;
   double w = 2;
   int z = 0;
   for(z=0; z<x; z++){
      if((int)w % 5!=0){
         soma= soma + 1/(w);
      }
      w = w+2;
   }
   printf("%lf", soma);
}
int main(){
   int x = 0;
   int y = 0;
   printf("Entrar com um valor: \n");
   scanf("%d", &x);
   metodo07(x);
   return (0);
}
