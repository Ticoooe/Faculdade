#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int exercicio01 (int x){

   int tamanho = 0;

   for(x = 5; x < tamanho; x++){
      if ( x % 2 == 1 ){ 
         printf("%i %i ", x);
      }
   }
}

int main ( ){
   int exercicio01 (int x);
   int valor = 0;
   printf("Entrar com um valor inteiro: \n");
   scanf("%i", &valor);
   //printf("%d", valor);
   
   return (0);
}

