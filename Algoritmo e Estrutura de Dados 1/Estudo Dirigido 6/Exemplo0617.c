#include <stdio.h>
#include <stdlib.h>
#include "IO.h"
#include <math.h>

double exercicio07(int tamanho, int x, int count){
   double soma = 0.0;

   if (count < tamanho){
      if(x % 2 != 0 && x > 0){
         count++;
         printf("(%d) = %d \n",count,x);
         
         soma = (1.0 / x ); 
         soma = soma + exercicio07(tamanho, x+1, count);
               
      } 
      else{
         soma = exercicio07(tamanho, x+1, count);      
      } 
   } 
   return(soma);

}

int main(){
   
   double soma = 0.0;
   int  tamanho = 0;
   
   printf("Entrar com um valor: ");
   scanf("%d", &tamanho);
   
   soma = exercicio07(tamanho, 3, 0);
   printf("%.4lf\n", soma);
}