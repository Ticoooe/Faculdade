#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "IO.h"

int exercicio06(int tamanho, int x, int count){
   int soma = 0;
   
   if(count < tamanho){
      if(x % 2 != 0 && x > 0){         
         count++;
         printf("(%d) = %d \n", count, x);
         soma = x + exercicio06(tamanho, x+1, (count));    
      }
      else{
         soma = exercicio06(tamanho, x+1, (count));
      }
   } 
   
   return(soma);
}

int main(){
   int soma = 0;
   int  tamanho = 0;
   
   printf("Entrar com um valor: ");
   scanf("%d", &tamanho);
   
   soma = exercicio06(tamanho, 3, 0);
   printf("%d \n", soma);
   return(0);
}