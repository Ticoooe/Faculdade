#include <stdio.h>
#include <stdlib.h>
#include "IO.h"
#define STR_SIZE 80
int main(){
   char palavra [STR_SIZE];
   int count = 0;
   double x = 0;
   double y = 0;
   double parteFrac = 0;
   int parteInteira = (int)x; 
   x = parteInteira + parteFrac;
   printf("Entrar com um valor: \n");
   scanf("%d", &x);
   printf("Entrar com um valor: \n");
   scanf("%d", &y);    
   if(x < y){  
      for(count = x; count < y; count++){	
         if(parteInteira % 2 == 1){
            printf("%d a parte inteira eh impar \t");
         }
      }
   }
   
   return(0);
}