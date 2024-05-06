#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IO.h"

int exercicio09 (char* palavra, int x){
   int tamanho = 0;
   int count = 0;
   
   tamanho = strlen(palavra);
   
   if(x < tamanho){
      if(palavra[x] % 2 == 0){
         count++;
         count = count + exercicio09(palavra, x+1);
      }         
   }
   else{
      count = exercicio09(palavra, x+1);
   }
   return(count); 
}

int main(){
   
   int x = 0;
   int count = 0;
   char palavra [80];
   
   printf("Entrar com uma cadeia de caracteres: ");
   scanf("%s", palavra[x]);
   
   count = exercicio09(palavra, 0);
   printf("%d \n", count);

   return(0);
}