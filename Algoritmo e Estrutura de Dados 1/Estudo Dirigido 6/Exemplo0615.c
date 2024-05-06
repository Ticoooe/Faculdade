#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "IO.h"

void exercicio05(char* palavra, int x){
   int  y = 0;
   y = strlen(palavra);
   if(x < y){
     printf("%c \n", palavra[x]);
     exercicio05(palavra, x+1); 
   }
}

int main(){
int x = 0;
   char palavra [80]; 
   printf("Entrar com uma palavra: ");
   scanf("%s", palavra[x]);
   exercicio05(palavra, 0);
   return(0);
}