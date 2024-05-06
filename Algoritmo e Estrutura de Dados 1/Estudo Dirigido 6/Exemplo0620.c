#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IO.h"
 
int exercicio09(char* palavra,int x){
   int  tamanho = 0;
   int  count = 0;
  
   tamanho = strlen( palavra );
   
  if(x < tamanho){
       count = exercicio09(palavra, x+1);
            
       if(palavra[x] >= 'A' && palavra[x] <= 'Z'){                  
          count++;
       }  
  }
      return(count);
}

int main(){
   int count = 0;
   char palavra [80]; 
   
   printf("Entrar com palavra: ");
   scanf("%s", palavra);
   
   count = exercicio09(palavra, 0);
   printf("Sao %d maiusculas \n", count);

   return(0);
}