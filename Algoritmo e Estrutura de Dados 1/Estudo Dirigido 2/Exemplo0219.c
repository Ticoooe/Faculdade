#include <stdio.h>
#include "io.h"
int main() {
   int x = 0;
   int y = 0;
   int z = 0;
   printf("Entrar com valor inteiro: \n");
   scanf("%d", &x);
   printf("Entrar com valor inteiro: \n");
   scanf("%d", &y);
   printf("Entrar com valor inteiro: \n");
   scanf("%d", &z);
   if((x > y) && (x < z)){
      printf(" esta entre eles  \n");
   }
   if((x < y) && (x > z)){
      printf(" esta entre eles  \n");
   }
   
   return(0);
}