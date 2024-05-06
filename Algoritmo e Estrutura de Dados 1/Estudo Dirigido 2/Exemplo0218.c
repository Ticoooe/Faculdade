#include <stdio.h>
#include "io.h"
int main() {
   int x = 0;
   int y = 0;
   printf("Entrar com valor inteiro: \n");
   scanf("%d", &x);
   printf("Entrar com valor inteiro: \n");
   scanf("%d", &y);
   if(x == y){
   printf(" sao iguais \n");
   }
   if(x > y){
   printf(" o primeiro eh maior \n");
   }
   if(x < y){
   printf(" o primeiro eh menor \n");
   }
   return(0);
}