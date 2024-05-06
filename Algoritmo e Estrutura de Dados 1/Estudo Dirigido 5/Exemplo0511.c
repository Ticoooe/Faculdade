#include<stdio.h> 
#include<stdlib.h>

int metodo01(int x){
   int y = 0;
   int z = 0;

   for(z = 0;z < x; z++ ){
      printf("%d \n", y);
      y = y + 2;
   }
}

int main(){
   int x = 0;
   printf("Entrar com um valor: \n");
   scanf("%d", &x);
   metodo01(x);
   return(0);
}