#include<stdio.h>
#include"IO.h"
#include<math.h>
int main (){
   int x = 0;
   int y = 0;
   printf("Entrar com valor inteiro: \n");
   scanf("%d", &x);
   printf("Entrar com valor inteiro: \n");
   scanf("%d", &y);
   if(x % 2 == 1){
   printf("eh impar \n");
   }
   else{
   printf(" nao eh impar \n");
   }
   if(y % 2 == 0){
   printf("eh par \n");
   }
   else{
   printf(" nao eh par \n");
   }

   return(0);
}