#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int exercicio02 (int x){

   int tamanho = 0;

   for(x = tamanho; x > 5; x--){
      if ( x > 0 ){ 
         printf("%i %i %i", x, x + 5, x + 10);
      }
   }
}

int main ( ){
   int exercicio02 (int x);
   int valor = 0;
   printf("Entrar com um valor inteiro: \n");
   scanf("%i", &valor);
   //printf("%d", valor);
      
   return (0);
}