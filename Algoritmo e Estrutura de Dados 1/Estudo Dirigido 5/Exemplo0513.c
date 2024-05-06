#include<stdio.h> 
#include<stdlib.h>

int metodo03(int x){
   int y = 0;
   int z = 0;
   for(z = 0;z < x; z++ ){
      if(x % 2 == 1){
         y = y + 3;
      }
   }
   y = y - 3;
   for(z = x;z > 0; z-- ){
      if(x % 2 == 1){
         printf("%d \n", y);
         y = y - 3;
      }
   }

}
int main(){
   int x = 0;
   printf("Entrar com um valor: \n");
   scanf("%d", &x);
   metodo03(x);
   return(0);
}