#include <stdio.h>
#include <stdlib.h>
#include "IO.h"
#define STR_SIZE 80
int main(){
   char palavra [STR_SIZE];
   int x = 0;
   int tamanho = 0;
   int count = 0;
   printf("Entrar com uma palavra: \n");
   scanf("%s", &palavra);
   tamanho = strlen(palavra);
   for(x = 0;x <= strlen(palavra);x++){
      if (!(palavra[x] >= 'A' && palavra[x] <= 'Z')){
      printf("nao eh digito ou letra %c \n", palavra[x]);
      }
      if (!(palavra[x] >= 'a' && palavra[x] <= 'z')){
      printf("nao eh digito ou letra %c \n", palavra[x]);
      } 
      if (!(palavra[x] >= '0' && palavra[x] <= '9')){
      printf("nao eh digito ou letra %c \n", palavra[x]);
      }
      
   }
    printf("%c", count);
   
   return(0);
}