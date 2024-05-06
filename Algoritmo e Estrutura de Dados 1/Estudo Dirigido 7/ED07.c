#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void metodo00()
{
}

void writeInts(char *fileName, int x)
{
   FILE *arquivo;
   arquivo = fopen(fileName, "wr");
   int y = 0;

   for (y = 1; y <= x; y++)
   {
      fprintf(arquivo, "%d\n", y);
   }
   fclose(arquivo);
}

void metodo01()
{
   printf("EXEMPLO0701 - Metodo01 - v0.1");
   writeInts("DADOS.TXT", 10);

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

void metodo02()
{

   printf("EXEMPLO0702 - Metodo02 - v0.1");
   readInts("DADOS1.TXT");
   IO_pause("Apertar ENTER para continuar");
}

void writeDoubles(chars fileName, int x)
{

   FILE *arquivo;
   arquivo = fopen(fileName, "wr");
   int y = 0;
   fprintf(arquivo, "%d\n", x);
   for (y = 1; y <= x; y = y + 1)
   {
      fprintf(arquivo, "%lf\n", (0.1 * y));
   }
   fclose(arquivo);
}

void method03()
{

   IO_id("EXEMPLO0703 - Method03 - v0.");
   writeDoubles("DADOS2.TXT", 10);
   IO_pause("Apertar ENTER para continuar");
}

void readDoubles(chars fileName)
{

   FILE *arquivo;
   arquivo = fopen(fileName, "wr");
   int x = 0;
   int y = 1;
   double z = 0.0;
   fscanf(arquivo, "%d", &x);

   while (!feof(arquivo) && y <= x)
   {
      fscanf(arquivo, "%lf", &z);
      printf("%2d: %lf\n", y, z);
      y = y + 1;
   }
   fclose(arquivo);
}

void method04()
{

   IO_id("EXEMPLO0704 - Method04 - v0.1");
   readDoubles("DADOS2.TXT");
   IO_pause("Apertar ENTER para continuar");
}

void writeText(chars fileName)
{

   FILE *arquivo;
   arquivo = fopen(fileName, "wt");
   chars linha = IO_new_chars(STR_SIZE);

   IO_println("Gravar linhas (para terminar, entrar com \"PARAR\"):\n");
   do
   {
      strcpy(linha, IO_readln(""));

      fprintf(arquivo, "%s\n", linha);
   } while (strcmp("PARAR", linha) != 0);
   fclose(arquivo);
}

void method05()
{

   IO_id("EXEMPLO0705 - Method05 - v0.0");
   writeText("DADOS3.TXT");
   IO_pause("Apertar ENTER para continuar");
}

void readText(chars fileName)
{

   FILE *arquivo;
   arquivo = fopen(fileName, "wr");

   chars linha = IO_new_chars(STR_SIZE);

   strcpy(linha, IO_freadln(arquivo));

   while (!feof(arquivo) && strcmp("PARAR", linha) != 0)
   {
      printf("%s\n", linha);
      strcpy(linha, IO_freadln(arquivo));
   }
   fclose(arquivo);
}
void method06()
{

   IO_id("EXEMPLO0706 - Method06 - v0.1");
   readText("DADOS3.TXT");
   IO_pause("Apertar ENTER para continuar");
}

void copyText(chars fileOut, chars fileIn)
{

   FILE *saida;
   saida = fopen(fileOut, "wt");
   FILE *entrada;
   entrada = fopen(fileIn, "rt");
   chars linha = IO_new_chars(STR_SIZE);
   int contador = 0;

   strcpy(linha, IO_freadln(entrada));

   while (!feof(entrada))
   {
      contador++;
      if (strcmp("PARAR", linha) != 0)
      {
         fprintln(saida, linha);
      }
      strcpy(linha, IO_freadln(entrada));
   }

   printf("Lines read = %d\n", contador);

   fclose(saida);
   fclose(entrada);
}

void method07()
{

   IO_id("EXEMPLO0707 - Method07 - v0.1");
   copyText("DADOS4.TXT", "DADOS3.TXT");
   IO_pause("Apertar ENTER para continuar");
}

void appendText(chars fileName)
{

   FILE *arquivo;
   arquivo = fopen(fileName, "at");
   chars linha = IO_new_chars(STR_SIZE);
   IO_println("Gravar linhas (para terminar, entrar com \"PARAR\"):\n");
   do
   {
      strcpy(linha, IO_readln(""));
      fprintln(arquivo, linha);
   } while (strcmp("PARAR", linha) != 0);
   fclose(arquivo);
}

void method08()
{

   IO_id("EXEMPLO0708 - Method08 - v0.0");
   appendText("DADOS4.TXT");
   IO_pause("Apertar ENTER para continuar");
}

void readWords(chars fileName)
{

   FILE *arquivo;
   arquivo = fopen(fileName, "rt");
   chars linha = IO_new_chars(STR_SIZE);

   strcpy(linha, IO_fread(arquivo));
   while (!feof(arquivo) && strcmp("PARAR", linha) != 0)
   {

      printf("%s\n", linha);
      strcpy(linha, IO_fread(arquivo));
   }

   fclose(arquivo);
}

void method09()
{

   IO_id("EXEMPLO0709 - Method09 - v0.0");
   readWords("DADOS4.TXT");
   IO_pause("Apertar ENTER para continuar");
}

bool searchWord(chars fileName, chars word)
{

   FILE *arquivo;
   arquivo = fopen(fileName, "rt");
   chars linha = IO_new_chars(STR_SIZE);

   strcpy(linha, IO_fread(arquivo));

   while (!feof(arquivo) && strcmp(word, linha) != 0)
   {
      strcpy(linha, IO_fread(arquivo));
   }

   fclose(arquivo);

   return (strcmp(word, linha) == 0);
}

void method10()
{

   IO_id("EXEMPLO0710 - Method10 - v0.1");
   printf("Procurar (\"%s\") = %d\n", "pqr", searchWord("DADOS4.TXT", "pqr"));
   printf("Procurar (\"%s\") = %d\n", "pqs", searchWord("DADOS4.TXT", "pqs"));
   pause("Apertar ENTER para continuar");
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