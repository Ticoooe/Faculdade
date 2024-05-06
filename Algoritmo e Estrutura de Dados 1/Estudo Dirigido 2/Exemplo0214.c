#include <stdio.h>
#include "io.h"
#include <math.h>
int main() {
   int x = 0;
   printf("Entrar com valor inteiro: \n");
   scanf("%d", &x);
   if ((x >= 20) && (x <= 60)){
      printf(" esta no intervalo \n");
   }
   else{
   printf(" nao esta no intervalo \n");
   }
   return(0);
}