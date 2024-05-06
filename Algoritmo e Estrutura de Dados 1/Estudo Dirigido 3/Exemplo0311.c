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
   for(x = 0;x <= tamanho;x++){
      if(palavra[x] >= 'A' && palavra[x] <= 'Z'){
         printf(" %c eh letra maiscula \n", palavra[x]);
         count++;
      }
   }
   return(0);
}