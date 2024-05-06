#include <stdio.h>
#include "io.h"
#include <math.h>
int main() {
   int x = 0;
   printf("Entrar com valor inteiro: \n");
   scanf("%d", &x);
      if ((x >= 25) && (x <= 45)){
         printf(" esta no primeiro intervalo \n");
      }
      if((x >= 33) && (x <= 99)){
         printf(" esta no segundo intervalo \n");
      }
      if((x>= 33) && (x <= 45)){
      printf(" esta em ambos intervalos \n");
      }
      if((x < 25) && (x > 99)){
      printf("nao esta em nenhum intervalo");
      }
   return(0);
}