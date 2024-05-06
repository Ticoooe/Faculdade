#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void metodo00()
{
}

void printIntArray(int n, int array[])
{
   int x = 0;
   for (x = 0; x < n; x = x + 1)
   {
      printf("%2d: %d\n", x, array[x]);
   }
}
void metodo01()
{

   int array[] = {1, 2, 3, 4, 5};
   IO_id("EXEMPLO0810 - Metodo01 - v0.1");
   printIntArray(5, array);
   IO_pause("Apertar ENTER para continuar");
}
void readInts(char *fileName)
{

   FILE *arquivo;
   arquivo = fopen(fileName, "wr");

   int x = 0;
   fscanf(arquivo, "%d", &x);

   while (!feof(arquivo))
   {
      printf("%d \n", x);
      fscanf(arquivo, "%d", &x);
   }
   fclose(arquivo);
}

void readIntArray(int n, int array[])
{

   int x = 0;
   int y = 0;
   chars text = IO_new_chars(STR_SIZE);

   for (x = 0; x < n; x = x + 1)
   {

      strcpy(text, STR_EMPTY);
      y = IO_readint(IO_concat(
          IO_concat(text, IO_toString_d(x)), " : "));

      array[x] = y;
   }
}

void metodo02()
{

   int n = 5;
   int array[n];

   IO_id("EXEMPLO0802 - Metodo02 - v0.1");

   readIntArray(n, array);

   printf("\n");
   printIntArray(n, array);

   IO_pause("Apertar ENTER para continuar");
}

void fprintIntArray(chars fileName, int n, int array[])
{

   FILE *arquivo;
   arquivo = fopen(fileName, "wr");
   int x = 0;

   fprintf(arquivo, "%d\n", n);

   for (x = 0; x < n; x = x + 1)
   {

      fprintf(arquivo, "%d\n", array[x]);
   }
   fclose(arquivo);
}

void metodo03()
{

   int n = 5;
   int array[n];

   IO_id("EXEMPLO0803 - Metodo03 - v0.0");

   readIntArray(n, array);

   printf("\n");
   fprintIntArray("ARRAY1.TXT", n, array);

   IO_pause("Apertar ENTER para continuar");
}

int freadArraySize(chars fileName)
{

   int n = 0;
   FILE *arquivo = fopen(fileName, "rt");

   fscanf(arquivo, "%d", &n);
   if (n <= 0)
   {
      println("ERRO: Valor invalido.");
      n = 0;
   }

   return (n);
}

void freadIntArray(chars fileName, int n, int array[])
{

   int x = 0;
   int y = 0;
   FILE *arquivo = fopen(fileName, "rt");

   fscanf(arquivo, "%d", &x);
   if (n <= 0 || n > x)
   {
      println("ERRO: Valor invalido.");
   }
   else
   {

      x = 0;
      while (!feof(arquivo) && x < n)
      {

         fscanf(arquivo, "%d", &y);

         array[x] = y;

         x = x + 1;
      }
   }
}

void metodo04()
{

   int n = 0;

   IO_id("EXEMPLO0804 - Metodo04 - v0.1");

   n = freadArraySize("ARRAY1.TXT");
   if (n <= 0)
   {
      printf("\nERRO: Valor invalido.\n");
   }
   else
   {

      int array[n];

      freadIntArray("ARRAY1.TXT", n, array);

      printf("\n");
      printIntArray(n, array);
   }
   IO_pause("Apertar ENTER para continuar");
}

void copyIntArray(int n, int copy[], int array[])
{

   int x = 0;
   int y = 0;
   if (n <= 0)
   {
      println("ERRO: Valor invalido.");
      n = 0;
   }
   else
   {

      for (x = 0; x < n; x = x + 1)
      {

         copy[x] = array[x];
      }
   }
}

void metodo05()
{

   int n = 0;

   IO_id("EXEMPLO0805 - Metodo05 - v0.1");

   n = freadArraySize("ARRAY1.TXT");
   if (n <= 0)
   {
      printf("\nERRO: Valor invalido.\n");
   }
   else
   {

      int array[n];
      int outro[n];

      freadIntArray("ARRAY1.TXT", n, array);

      copyIntArray(n, outro, array);
      printf("\nOriginal\n");
      printIntArray(n, array);

      printf("\nCopia\n");
      printIntArray(n, outro);
   }

   IO_pause("Apertar ENTER para continuar");
}

int sumIntArray(int n, int array[])
{

   int soma = 0;
   int x = 0;

   for (x = 0; x < n; x = x + 1)
   {

      soma = soma + array[x];
   }
   return (soma);
}

void metodo06()
{

   int n = 0;

   IO_id("EXEMPLO0805 - Metodo06 - v0.1");

   n = freadArraySize("ARRAY1.TXT");
   if (n <= 0)
   {
      printf("\nERRO: Valor invalido.\n");
   }
   else
   {

      int array[n];
      freadIntArray("ARRAY1.TXT", n, array);
      printf("\nSoma = %d\n", sumIntArray(n, array));
   }
   IO_pause("Apertar ENTER para continuar");
}

bool isAllZeros(int n, int array[])
{

   bool resultado = true;
   int x = 0;
   x = 0;
   while (x < n && resultado)
   {

      resultado = resultado && (array[x] == 0);
      x = x + 1;
   }
   return (resultado);
}

void metodo07()
{

   int n = 5;
   int array1[] = {0, 0, 0, 0, 0};
   int array2[] = {1, 2, 3, 4, 5};
   int array3[] = {1, 2, 0, 4, 5};

   IO_id("EXEMPLO0807 - Method07 - v0.0");

   println("\nArray1");
   printIntArray(n, array1);
   printf("isAllZeros (array1) = %d", isAllZeros(n, array1));
   println("\nArray2");
   printIntArray(n, array2);
   printf("isAllZeros (array2) = %d", isAllZeros(n, array2));
   println("\nArray3");
   printIntArray(n, array3);
   printf("isAllZeros (array3) = %d", isAllZeros(n, array3));

   IO_pause("Apertar ENTER para continuar");
}

void addIntArray(int n, int array3[], int array1[], int k, int array2[])
{

   int x = 0;

   for (x = 0; x < n; x = x + 1)
   {

      array3[x] = array1[x] + k * array2[x];
   }
}

void metodo08()
{

   int n = 0;

   IO_id("EXEMPLO0808 - Metodo08 - v0.1");

   n = freadArraySize("ARRAY1.TXT");
   if (n <= 0)
   {
      printf("\nERRO: Valor invalido.\n");
   }
   else
   {

      int array[n];
      int outro[n];
      int sum[n];

      freadIntArray("ARRAY1.TXT", n, array);

      copyIntArray(n, outro, array);

      printf("\nOriginal\n");
      printIntArray(n, array);

      printf("\nCopia\n");
      printIntArray(n, outro);

      addIntArray(n, sum, array, (-2), outro);

      printf("\nSoma\n");
      printIntArray(n, sum);
   }

   IO_pause("Apertar ENTER para continuar");
}

bool isEqual(int n, int array1[], int array2[])
{

   bool resultado = true;
   int x = 0;

   x = 0;
   while (x < n && resultado)
   {

      resultado = resultado && (array1[x] == array2[x]);

      x = x + 1;
   }
   return (resultado);
}

void metodo09()
{

   int n = 0;
   IO_id("EXEMPLO0809 - Metodo09 - v0.1");

   n = freadArraySize("ARRAY1.TXT");
   if (n <= 0)
   {
      printf("\nERRO: Valor invalido.\n");
   }
   else
   {

      int array[n];
      int outro[n];

      freadIntArray("ARRAY1.TXT", n, array);

      copyIntArray(n, outro, array);

      printf("\nOriginal\n");
      printIntArray(n, array);

      printf("\nCopia\n");
      printIntArray(n, outro);

      printf("\nIguais = %d\n", isEqual(n, array, outro));

      outro[0] = (-1) * outro[0];

      printf("\nCopia alterada\n");
      printIntArray(n, outro);

      printf("\nIguais = %d\n", isEqual(n, array, outro));
   }

   IO_pause("Apertar ENTER para continuar");
}

bool searchArray(int n, int array[], int valor)
{

   bool resultado = false;
   int x = 0;

   x = 0;
   while (x < n && !resultado)
   {

      resultado = (valor == array[x]);

      x = x + 1;
   }
   return (resultado);
}

void metodo10()
{

   int n = 0;
   int valor = 0;

   IO_id("EXEMPLO0810 - Metodo10 - v0.1");

   n = freadArraySize("ARRAY1.TXT");
   if (n <= 0)
   {
      printf("\nERRO: Valor invalido.\n");
   }
   else
   {

      int array[n];

      freadIntArray("ARRAY1.TXT", n, array);

      printf("\nOriginal\n");
      printIntArray(n, array);

      valor = array[0];
      printf("\nProcurar por (%d) = %d\n",
             valor, searchArray(n, array, valor));
      valor = array[n / 2];
      printf("\nProcurar por (%d) = %d\n",
             valor, searchArray(n, array, valor));
      valor = array[n - 1];
      printf("\nProcurar por (%d) = %d\n",
             valor, searchArray(n, array, valor));
      valor = (-1);
      printf("\nProcurar por (%d) = %d\n",
             valor, searchArray(n, array, valor));
   }
   IO_pause("Apertar ENTER para continuar");
}

int main()
{

   int x = 0;
   do
   {
      printf("Opcoes");
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

      printf("Entrar com uma opcao: ");
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