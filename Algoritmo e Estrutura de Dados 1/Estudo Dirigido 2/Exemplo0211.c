#include <stdio.h>
#include "io.h"
int main() {
   int x = 0;
   printf("Entrar com valor inteiro: \n");
   scanf("%d", &x);
   if(x % 2 ==0){
   printf(" eh par \n");
   }
   else{
   printf(" eh impar \n");
   }
}