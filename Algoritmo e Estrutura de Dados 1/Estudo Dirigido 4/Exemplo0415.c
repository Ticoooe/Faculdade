#include "IO.h"
#include <stdio.h>
#include <stdlib.h>
void metodo00 ( ){
}
void metodo01 ( ){ 
   double x=0; 
   int count=0;
   double y=0;
   double z=0;
   printf("\nDigite um numero: ");
   scanf("%d", &z);
   printf("\nDigite um numero: ");
   scanf("%d", &y); 
   printf("\nDigite um numero: ");
   scanf("%d", &x);
   
   for (x=z; x<=y; x++)
   {
      if((x>=y && x<=z)||(x>=z && x<=y))
      {
         count++;
         printf(" esta no intervalo : \n", x);
      }
      else
      {
         printf("Nao esta no intervalo : \n", x);
      }
   }
}

void metodo02 ( ){
   char palavra [80];
   int x = 0;
   int count = 0;
   int tamanho = 0;
   printf("Entrar com palavra: ");
   scanf("%s", palavra[x]);
   tamanho = strlen(palavra);
   for(x = 0; x < tamanho; x++){
      if(palavra[x] >= 'A' && palavra[x] <= 'Z'){
         printf(" %c eh letra maiuscula \n", palavra[x]);
         count++;
      }
      else{
         printf("%c eh caracter",palavra[x]);
      }
   }
   printf("%c \n", count);
}
void metodo03 ( ){
   char palavra [80];
   int x = 0;
   int tamanho = 0;
   int count = 0;
   printf("Entrar com uma palavra: \n");
   scanf("%s", &palavra);
   tamanho = strlen(palavra);
   for(x = 0;x <= tamanho;x++){
      if(palavra[x] >= 'A' && palavra[x] <= 'Z'){
         printf("eh letra maiscula %c \n", palavra[x]);
         count++;
      }
   }
   printf("%d", count);

} 
void metodo04 ( ){
   char palavra [80];
   int x = 0;
   int tamanho = 0;
   int count = 0;
   printf("Entrar com uma palavra: \n");
   scanf("%s", &palavra);
   tamanho = strlen(palavra);
   for(x = 0;x <= tamanho;x++){
      if(palavra[x] >= 'A' && palavra[x] <= 'Z'){
         printf("eh letra maiscula %c \n", palavra[x]);
         count++;
      }
   }
   printf("%d", count);

}
void metodo05 ( )
{
char palavra [80];
   int x = 0;
   int tamanho = 0;
   int count = 0;
   printf("Entrar com uma palavra: \n");
   scanf("%s", &palavra);
   tamanho = strlen(palavra);
   for(x = 0;x <= tamanho;x++){
      if(palavra[x] >= 'A' && palavra[x] <= 'Z'){
         printf("eh letra maiscula %c \n", palavra[x]);
         count++;
      }
      if(palavra[x] >= 'a' && palavra[x] <= 'z'){
         printf("eh letra minuscula %c \n", palavra[x]);
         count++;
   }
   printf("%d", count);

}
void metodo06 ( )
{

}
void metodo07 ( )
{

}
void metodo08 ( )
{

}
void metodo09 ( )
{

}
void metodo10 ( )
{

}
int main(){

   int x = 0;
   do{
      IO_println("Opcoes");
      IO_println("0 - parar");
      IO_println("1 - mostrar intervalo");
      IO_println("2 - mostrar letra maiuscula");
      IO_println("3 - contar letras maiusculas");
      IO_println("4 - separar letras maiusculas");
      IO_println("5 - contra letras");
      IO_println("6 - separar as letras");
      IO_println("7 - mostrar digitos");
      IO_println("8 - mostrar simbolos");
      IO_println("9 - separar simbolos alfanumericos");
      IO_println("10 - contar simbolos alfanumericos");
   
      x =IO_readint("Entrar com uma opcao: ");
   
   
      switch(x){
         case 0:
            metodo00 ();
            break;
         case 1:
            metodo01 ();
            break;
         case 2:
            metodo02 ();
            break;
         case 3:
            metodo03 ();
            break;
         case 4:
            metodo04 ();
            break;
         case 5: 
            metodo05 ();
            break;
         case 6: 
            metodo06 ();
            break;
         case 7: 
            metodo07 ();
            break;
         case 8: 
            metodo08 ();
            break;
         case 9: 
            metodo09 ();
            break;
         case 10: 
            metodo10 ();
            break;
         default:
            IO_pause("ERRO: valor invalido ");
      }
   }
   while (x != 0);
   IO_pause("Apertar ENTER para terminar");
   return (0);
}