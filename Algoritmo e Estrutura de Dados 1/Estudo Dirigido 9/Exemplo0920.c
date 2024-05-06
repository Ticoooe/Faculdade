/*
Paulo Ant�nio Eufr�zio Araujo
665497
AEDs1 Tarde
*/
#include "IO.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void metodo00()
{
}

void exercicio01(int linha, int coluna)
{

   int l = 0;
   int c = 0;
   double matriz[linha][coluna];

   for (l = 0; l < linha; l++)
   {
      for (c = 0; c < coluna; c++)
      {
         printf("Entrar com um valor da matriz : ");
         scanf("%2.0lf", &matriz[l][c]);
         while (matriz[l][c] <= 0)
         {
            printf(" Possui valor nulo ou negativo \n");
            printf(" Entrar com um valor positivo para a matriz: ");
            scanf("%2.0lf", matriz[l][c]);
         }
         printf("Valor da Matriz[%d][%d] = %2.0lf \n", l, c, matriz[l][c]);
      }
   }
}

void metodo01()
{
   int linha = 0;
   int coluna = 0;
   printf("Entrar com um valor de linhas  : ");
   scanf("%d", &linha);
   printf("Entrar com um valor de colunas : ");
   scanf("%d", &coluna);
   exercicio01(linha, coluna);

} // fim 1

void exercicio02(int linha, int coluna, double matriz[][coluna])
{
   int l = 0;
   int c = 0;

   FILE *arquivo = fopen("MATRIZ.TXT", "wt");

   for (l = 0; l < linha; l++)
   {
      for (c = 0; c < coluna; c++)
      {

         printf("Entrar com um valor da matriz : ");
         scanf("%2.0lf", &matriz[l][c]);

         while (matriz[l][c] <= 0)
         {

            printf(" Possui valor nulo ou negativo \n");
            printf(" Entrar com um valor positivo para a matriz: ");
            scanf("%2.0lf", matriz[l][c]);
         }
         fprintf(arquivo, "Valor da Matriz[%d][%d] = %2.0lf \n", l, c, matriz[l][c]);
      }
   }
}

void metodo02()
{
   int linha = 0;
   int coluna = 0;

   printf("Entrar com o valor de linhas: ");
   scanf("%d", &linha);
   printf("Entrar com o valor de colunas: ");
   scanf("%d", &coluna);

   double matriz[linha][coluna];

   exercicio02(linha, coluna, matriz);
} // fim 2

void exercicio03(int linha, int coluna)
{

   int l = 0;
   int c = 0;

   double matriz[linha][coluna];

   for (l = 0; l < linha; l++)
   {
      for (c = 0; c < coluna; c++)
      {

         printf("Entrar com um valor da matriz : ");
         scanf("%2.0lf", &matriz[l][c]);

         while (matriz[l][c] <= 0)
         {

            printf(" Possui valor nulo ou negativo \n");
            printf(" Entrar com um valor positivo para a matriz: ");
            scanf("%2.0lf", matriz[l][c]);
         }
      }
   }
   if (linha == coluna)
   {
      for (l = 0; l < linha; l++)
      {
         printf("Valor da diagonal principal = %2.0lf \n", matriz[l][l]);
      }
   }
   else
   {
      printf("A matriz nao eh quadrada");
   }
}

void metodo03()
{
   int linha = 0;
   int coluna = 0;

   printf("Entrar com o valor de linhas: ");
   scanf("%d", &linha);
   printf("Entrar com o valor de colunas: ");
   scanf("%d", &coluna);

   exercicio03(linha, coluna);
} // fim 3

void exercicio04(int linha, int coluna)
{

   double matriz[linha][coluna];
   int l = 0;
   int c = 0;
   int p = 0;

   if (linha == coluna)
   {
      for (l = 0; l < linha; l++)
      {
         for (c = 0; c < coluna; c++)
         {
            printf("Entrar com um valor positivo para a matriz: ");
            scanf("%2.0lf", &matriz[l][c]);

            while (matriz[l][c] <= 0)
            {
               printf("Possui valor nulo ou negativo \n");
               printf("Entrar com um valor positivo para a matriz: ");
               scanf("%2.0lf", &matriz[l][c]);
            }
         }
      }
      p = coluna - 1;

      for (l = 0; l < linha; l++)
      {
         printf("Valor da diagonal secundaria = %2.0lf \n", matriz[l][p]);
         p--;
      }
   }
   else
   {
      printf("A matriz nao eh quadrada");
   }
}

void metodo04()
{
   int linha = 0;
   int coluna = 0;

   printf("Entrar com o valor de linhas: ");
   scanf("%d", &linha);
   printf("Entrar com o valor de colunas: ");
   scanf("%d", &coluna);

   exercicio04(linha, coluna);
} // fim 4

void exercicio05(int linha, int coluna)
{

   int l = 0;
   int c = 0;
   double matriz[linha][coluna];

   if (linha == coluna)
   {
      for (l = 0; l < linha; l++)
      {
         for (c = 0; c < coluna; c++)
         {
            printf("Entrar com um valor positivo para a matriz: ");
            scanf("%2.0lf", &matriz[l][c]);

            while (matriz[l][c] <= 0)
            {
               printf("Possui valor nulo ou negativo \n");
               printf("Entrar com um valor positivo para a matriz: ");
               scanf("%2.0lf", &matriz[l][c]);
            }
            if (c < l)
            {
               printf("Os valores abaixo da diagonal sao %2.0lf \n", matriz[l][c]);
            }
         }
      }
   }
   else
   {
      printf("A matriz nao eh quadrada \n");
   }
}

void metodo05()
{

   int linha = 0;
   int coluna = 0;

   printf("\nDigite a quantidade de linhas da matriz: ");
   scanf("%d", &linha);
   printf("\nDigite a quantidade de colunas da matriz: ");
   scanf("%d", &coluna);

   exercicio05(linha, coluna);
}

void exercicio06(int linha, int coluna)
{

   double matriz[linha][coluna];
   int l = 0;
   int c = 0;

   if (linha == coluna)
   {
      for (l = 0; l < linha; l++)
      {
         for (c = 0; c < coluna; c++)
         {

            printf("Entrar com valor positivo para a matriz: ");
            scanf("%lf", &matriz[l][c]);

            while (matriz[l][c] <= 0)
            {
               printf("Valor nulo ou negativo \n");
               printf("Entrar com valor positivo para a matriz: ");
               scanf("%lf", &matriz[l][c]);
            }

            if (c > l)
            {
               printf("Os valores acima da diagonal sao %2.0lf \n", matriz[l][c]);
            }
         }
      }
   }
   else
   {
      printf("A matriz nao eh quadrada \n");
   }
}

void metodo06()
{

   int linha = 0;
   int coluna = 0;

   printf("\nDigite a quantidade de linhas da matriz: ");
   scanf("%d", &linha);
   printf("\nDigite a quantidade de colunas da matriz: ");
   scanf("%d", &coluna);

   exercicio06(linha, coluna);
}

void exercicio07(int linha, int coluna)
{

   double matriz[linha][coluna];
   int l = 0;
   int c = 0;
   int x = 0;

   x = coluna - 1;

   if (linha == coluna)
   {
      for (l = 0; l < linha; l++)
      {
         for (c = 0; c < coluna; c++)
         {

            printf("Entrar com um valor para matriz: ");
            scanf("%lf", &matriz[l][c]);

            if ((l + c) > (coluna - 1))
            {
               printf("Os valores acima da diagonal sao %2.0lf\n", matriz[l][c]);
            }
         }
      }
   }
   else
   {
      printf("A matriz nao eh quadrada \n");
   }
}

void metodo07()
{

   int linha = 0;
   int coluna = 0;

   printf("\nDigite a quantidade de linhas da matriz: ");
   scanf("%d", &linha);
   printf("\nDigite a quantidade de colunas da matriz: ");
   scanf("%d", &coluna);

   exercicio07(linha, coluna);
}

void exercicio08(int linha, int coluna)
{

   double matriz[linha][coluna];
   int l = 0;
   int c = 0;
   int x = 0;

   x = coluna - 1;

   if (linha == coluna)
   {
      for (l = 0; l < linha; l++)
      {
         for (c = 0; c < coluna; c++)
         {
            printf("Entrar com um valor para a matriz: ");
            scanf("%lf", &matriz[l][c]);

            if ((l + c) < (coluna - 1))
            {
               printf("Os valores abaixo da diagonal secundaria sao %2.0lf\n", matriz[l][c]);
            }
         }
      }
   }
   else
   {
      printf("A matriz nao eh quadrada \n");
   }
}

void metodo08()
{

   int linha = 0;
   int coluna = 0;

   printf("\nDigite a quantidade de linhas da matriz: ");
   scanf("%d", &linha);
   printf("\nDigite a quantidade de colunas da matriz: ");
   scanf("%d", &coluna);

   exercicio08(linha, coluna);
}

bool exercicio09(int linha, int coluna)
{

   bool nulo = true;

   double matriz[linha][coluna];
   int l = 0;
   int c = 0;
   int x = 0;

   if (linha == coluna)
   {
      for (l = 0; l < linha; l++)
      {
         for (c = 0; c < coluna; c++)
         {
            printf("Entrar com um valor para a matriz: ");
            scanf("%lf", &matriz[l][c]);

            if (c < l)
            {
               if (matriz[l][c] != 0)
               {
                  nulo = false;
               }
            }
         }
      }
   }
   else
   {
      printf("A matriz nao eh quadrada \n");
   }

   return (nulo);
}

void metodo09()
{

   int linha = 0;
   int coluna = 0;
   bool y = true;

   printf("\nDigite a quantidade de linhas da matriz: ");
   scanf("%d", &linha);
   printf("\nDigite a quantidade de colunas da matriz: ");
   scanf("%d", &coluna);

   y = exercicio09(linha, coluna);

   if (y == true)
   {
      printf("Os numeros abaixo da diagonal sao todos nulos ");
   }
   else
   {
      printf("Os numeros abaixo da diagonal nao sao todos nulos ");
   }
}

bool exercicio10(int linha, int coluna)
{

   bool nulo = true;

   double matriz[linha][coluna];
   int l = 0;
   int c = 0;

   if (linha == coluna)
   {
      for (l = 0; l < linha; l++)
      {
         for (c = 0; c < coluna; c++)
         {
            printf("Entrar com valor para a matriz: ");
            scanf("%lf", &matriz[l][c]);

            if (c > l)
            {
               if (matriz[l][c] != 0)
               {
                  nulo = false;
               }
            }
         }
      }
   }
   else
   {
      printf("A matriz nao eh quadrada \n");
   }

   return (nulo);
}

void metodo10()
{

   int linha = 0;
   int coluna = 0;
   bool y = true;

   printf("\nDigite a quantidade de linhas da matriz: ");
   scanf("%d", &linha);
   printf("\nDigite a quantidade de colunas da matriz: ");
   scanf("%d", &coluna);

   exercicio10(linha, coluna);

   y = exercicio10(linha, coluna);

   if (y == true)
   {
      printf("Os numeros acima da diagonal sao todos nulos ");
   }
   else
   {
      printf("Os numeros acima da diagonal nao sao todos nulos ");
   }
}

int main()
{

   int x = 0;
   do
   {
      printf("Opcoes \n");
      printf("0 - parar \n");
      printf("1 - Metodo 01 \n");
      printf("2 - Metodo 02 \n");
      printf("3 - Metodo 03 \n");
      printf("4 - Metodo 04 \n");
      printf("5 - Metodo 05 \n");
      printf("6 - Metodo 06 \n");
      printf("7 - Metodo 07 \n");
      printf("8 - Metodo 08 \n");
      printf("9 - Metodo 09 \n");
      printf("10 - Metodo 10 \n");

      printf("Entrar com uma opcao:  ");
      scanf("%d", &x);

      switch (x)
      {
      case 0:
         metodo00();
         break;
      case 1:
         metodo01();
         break;
      case 2:
         metodo02();
         break;
      case 3:
         metodo03();
         break;
      case 4:
         metodo04();
         break;
      case 5:
         metodo05();
         break;
      case 6:
         metodo06();
         break;
      case 7:
         metodo07();
         break;
      case 8:
         metodo08();
         break;
      case 9:
         metodo09();
         break;
      case 10:
         metodo10();
         break;
      default:
         IO_pause("ERRO: valor invalido ");
      }
   } while (x != 0);
   IO_pause("Apertar ENTER para terminar");
   return (0);
}