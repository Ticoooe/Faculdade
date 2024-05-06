#include <stdio.h>
#include "io.h"
int main() {
   int x = 0;
   printf("Entrar com valor inteiro: \n");
   scanf("%d", &x);
   if(x > 20){
      printf(" esta no intervalo \n");
   }
   if(x < 60){
   printf(" esta no intervalo \n");
   }
   return(0);
}