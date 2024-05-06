#include <stdio.h>
#include <stdlib.h>
#include "IO.h"
#define STR_SIZE 80
int main(){
   char palavra [STR_SIZE];
   int x = 0;
   int y = 0;
   int count = 0;
   printf("Entrar com um valor: \n");
   scanf("%d", &x);
   printf("Entrar com um valor: \n");
   scanf("%d", &y);    
   if(x < y){  
      for(count = x; count < y; count++){	
         if(count % 5 == 0){
            printf("%d eh multiplo de 5 \t");
         }
      }
   }
   printf("%c", count);
   
   return(0);
}