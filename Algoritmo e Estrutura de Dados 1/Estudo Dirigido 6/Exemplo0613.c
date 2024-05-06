#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "IO.h"

void exercicio03 (int tamanho, int x, int count){

   if(count < tamanho){
      if(x != 0){
         count++;
         exercicio03(tamanho, x+1, count);
         printf("(%d) = %d \n", count, x * 5);
      }
      else{
         exercicio03(tamanho, x+1, count);
      }
   }   
}

int main (){
   
   int tamanho = 0;
   
   printf("Entrar com valor de Tamanho: ");
   scanf("%d", &tamanho);
   
   exercicio03(tamanho, 1, 0);
   
   return(0);
}