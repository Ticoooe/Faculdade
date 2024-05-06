#include <stdio.h>
#include "io.h"
int main() {
   int x = 0;
   printf("Entrar com valor inteiro: \n");
   scanf("%d", &x);
   if(x % 2 == 0){
      printf(" eh par \n");
      if(x > 100){
         printf(" eh maior q 100 e par \n");
      }
      if(x < -100){
         printf(" eh menor q -100 e par \n");
      }
   }
   if(x % 2 == 1){
      printf(" eh impar \n");
      if(x > 100){
         printf(" eh maior q 100 e impar \n");
      }
      if(x < -100){
         printf(" eh menor q -100 e impar \n");
      }
   
   }
    return(0);   
}