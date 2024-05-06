#include "IO.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void metodo00()
{
}
/**
printIntMatrix - Mostrar arranjo bidimensional com valores inteiros.
@param lines - quantidade de linhas
@param columns - quantidade de colunas
@param matrix - grupo de valores inteiros
*/
void printIntMatrix(int lines, int columns, int matrix[][columns])
{
   // definir dado local
   int x = 0;
   int y = 0;
   // mostrar valores na matriz
   for (x = 0; x < lines; x = x + 1)
   {
      for (y = 0; y < columns; y = y + 1)
      {
         // mostrar valor
         printf("%3d\t", matrix[x][y]);
      } // fim repetir
      printf("\n");
   } // fim repetir
} // printIntMatrix ( )
/**
Metodo01 - Mostrar certa quantidade de valores.
*/
void metodo01()
{
   // definir dado
   int matrix[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
   // identificar
   IO_id("EXEMPLO0901 - Metodo01 - v0.0");
   // executar o metodo auxiliar
   printIntMatrix(3, 3, matrix);
   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // fim metodo01 ( )

/**
readIntMatrix - Ler arranjo bidimensional com valores inteiros.
@param lines - quantidade de linhas
@param columns - quantidade de colunas
@param matrix - grupo de valores inteiros
*/
void readIntMatrix(int lines, int columns, int matrix[][columns])
{
   // definir dados locais
   int x = 0;
   int y = 0;
   int z = 0;
   chars text = IO_new_chars(STR_SIZE);
   // ler e guardar valores em arranjo
   for (x = 0; x < lines; x = x + 1)
   {
      for (y = 0; y < columns; y = y + 1)
      {
         // ler valor
         strcpy(text, STR_EMPTY);
         z = IO_readint(IO_concat(IO_concat(IO_concat(text, IO_toString_d(x)), ", "), IO_concat(IO_concat(text, IO_toString_d(y)), " : ")));
         // guardar valor
         matrix[x][y] = z;
      } // fim repetir
   }    // fim repetir
} // readIntMatrix ( )
/**
Metodo02.
*/
void metodo02()
{
   // definir dados
   int n = 2; // quantidade de valores
   int matrix[n][n];
   // identificar
   IO_id("EXEMPLO0902 - Metodo02 - v0.0");
   // ler dados
   readIntMatrix(n, n, matrix);
   // mostrar dados
   printf("\n");
   printIntMatrix(n, n, matrix);
   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // fim metodo02 ( )

/**
fprintIntMatrix - Gravar arranjo bidimensional com valores inteiros.
@param fileName - nome do arquivo
@param lines - quantidade de linhas
@param columns - quantidade de colunas
@param matrix - grupo de valores inteiros
*/
void fprintIntMatrix(chars fileName, int lines, int columns, int matrix[][columns])
{
   // definir dados locais
   FILE *arquivo = fopen(fileName, "wt");
   int x = 0;
   int y = 0;
   // gravar quantidade de dados
   fprintf(arquivo, "%d\n", lines);
   fprintf(arquivo, "%d\n", columns);
   // gravar valores no arquivo
   for (x = 0; x < lines; x = x + 1)
   {
      for (y = 0; y < columns; y = y + 1)
      {
         // gravar valor
         fprintf(arquivo, "%d\n", matrix[x][y]);
      } // fim repetir
   }    // fim repetir
        // fechar arquivo
   fclose(arquivo);
} // fprintIntMatrix ( )
/**
Metodo03.
*/
void metodo03()
{
   // definir dados
   int lines = 0;
   int columns = 0;
   // identificar
   IO_id("EXEMPLO0910 - Metodo03 - v0.0");
   // ler dados
   lines = IO_readint("\nlines = ");
   columns = IO_readint("\ncolumns = ");
   printf("\n");
   if (lines <= 0 || columns <= 0)
   {
      println("\nERRO: Valor invalido.");
   }
   else
   {
      // reservar espaco
      int matrix[lines][columns];
      // ler dados
      readIntMatrix(lines, columns, matrix);
      // mostrar dados
      printf("\n");
      printIntMatrix(lines, columns, matrix);
      // gravar dados
      printf("\n");
      fprintIntMatrix("MATRIX1.TXT", lines, columns, matrix);
   } // fim se
     // encerrar
   IO_pause("Apertar ENTER para continuar");
} // fim metodo03 ( )

/**
freadMatrixRows - Ler tamanho (linhas) da matriz com valores inteiros.
@return quantidade de linhas da matriz
@param fileName - nome do arquivo
*/
int freadMatrixRows(chars fileName)
{
   // definir dados locais
   int n = 0;
   FILE *arquivo = fopen(fileName, "rt");
   ints array = NULL;
   // ler a quantidade de dados
   fscanf(arquivo, "%d", &n);
   if (n <= 0)
   {
      println("ERRO: Valor invalido.");
      n = 0;
   } // fim se
     // retornar dado lido
   return (n);
} // freadMatrixRows ( )
/**
freadMatrixColumns - Ler tamanho (colunas) da matriz com valores inteiros.
@return quantidade de colunas da matriz
@param fileName - nome do arquivo
*/
int freadMatrixColumns(chars fileName)
{
   // definir dados locais
   int n = 0;
   FILE *arquivo = fopen(fileName, "rt");
   // ler a quantidade de dados
   fscanf(arquivo, "%d", &n);
   fscanf(arquivo, "%d", &n);
   if (n <= 0)
   {
      println("ERRO: Valor invalido.");
      n = 0;
   } // fim se
     // retornar dado lido
   return (n);
} // freadMatrixColumns ( )
/**
freadIntMatrix - Ler arranjo bidimensional com valores inteiros.
@param fileName - nome do arquivo
@param lines - quantidade de valores
@param columns - quantidade de valores
@param matrix - grupo de valores inteiros
*/
void freadIntMatrix(chars fileName, int lines, int columns, int matrix[][columns])
{
   // definir dados locais
   int x = 0;
   int y = 0;
   int z = 0;
   FILE *arquivo = fopen(fileName, "rt");
   // ler a quantidade de dados
   fscanf(arquivo, "%d", &x);
   fscanf(arquivo, "%d", &y);
   if (lines <= 0 || lines > x || columns <= 0 || columns > y)
   {
      println("ERRO: Valor invalido.");
   }
   else
   {
      // ler e guardar valores em arranjo
      x = 0;
      while (!feof(arquivo) && x < lines)
      {
         y = 0;
         while (!feof(arquivo) && y < columns)
         {
            // ler valor
            fscanf(arquivo, "%d", &z);
            // guardar valor
            matrix[x][y] = z;
            // passar ao proximo
            y = y + 1;
         } // fim repetir
           // passar ao proximo
         x = x + 1;
      } // fim repetir
   }    // fim se
} // freadIntMatrix ( )

/**
Metodo04.
*/
void metodo04()
{
   // definir dados
   int lines = 0;
   int columns = 0;
   // identificar
   IO_id("EXEMPLO0904 - Metodo04 - v0.0");
   // ler dados
   lines = freadMatrixRows("MATRIX1.TXT");
   columns = freadMatrixColumns("MATRIX1.TXT");
   if (lines <= 0 || columns <= 0)
   {
      println("\nERRO: Valor invalido.");
   }
   else
   {
      // definir armazenador
      int matrix[lines][columns];
      // ler dados
      freadIntMatrix("MATRIX1.TXT", lines, columns, matrix);
      // mostrar dados
      printf("\n");
      printIntMatrix(lines, columns, matrix);
   } // fim se
     // encerrar
   IO_pause("Apertar ENTER para continuar");
} // fim metodo04 ( )

/**
copyIntMatrix - Copiar matriz com valores inteiros.
@param lines - quantidade de valores
@param columns - quantidade de valores
@param matrix - grupo de valores inteiros
*/
void copyIntMatrix(int lines, int columns, int matrix2[][columns], int matrix1[][columns])
{
   // definir dados locais
   int x = 0;
   int y = 0;
   if (lines <= 0 || columns <= 0)
   {
      println("ERRO: Valor invalido.");
   }
   else
   {
      // copiar valores em matriz
      for (x = 0; x < lines; x = x + 1)
      {
         for (y = 0; y < columns; y = y + 1)
         {
            // copiar valor
            matrix2[x][y] = matrix1[x][y];
         } // fim repetir
      }    // fim repetir
   }       // fim se
} // copyIntMatrix ( )
/**
Metodo05.
*/
void metodo05()
{
   // definir dados
   int lines = 0;
   int columns = 0;
   // identificar
   IO_id("EXEMPLO0905 - Metodo05 - v0.0");
   // ler dados
   lines = freadMatrixRows("MATRIX1.TXT");
   columns = freadMatrixColumns("MATRIX1.TXT");
   if (lines <= 0 || columns <= 0)
   {
      println("\nERRO: Valor invalido.");
   }
   else
   {
      // definir armazenadores
      int matrix[lines][columns];
      int other[lines][columns];
      // ler dados
      freadIntMatrix("MATRIX1.TXT", lines, columns, matrix);
      // copiar dados
      copyIntMatrix(lines, columns, other, matrix);
      // mostrar dados
      printf("\nOriginal\n");
      printIntMatrix(lines, columns, matrix);
      // mostrar dados
      printf("\nCopia\n");
      printIntMatrix(lines, columns, other);
   } // fim se
     // encerrar
   IO_pause("Apertar ENTER para continuar");
} // fim metodo05 ( )

/**
transposeIntMatrix - Transpor valores inteiros em matriz.
@param lines - quantidade de valores
@param columns - quantidade de valores
@param matrix2 - grupo de valores inteiros (transposto)
@param matrix1 - grupo de valores inteiros
*/
void transposeIntMatrix(int lines, int columns, int matrix2[][lines], int matrix1[][columns])
{
   // definir dados locais
   int x = 0;
   int y = 0;
   // percorrer a matriz
   for (x = 0; x < lines; x = x + 1)
   {
      for (y = 0; y < columns; y = y + 1)
      {
         matrix2[y][x] = matrix1[x][y];
      } // fim repetir
   }    // fim repetir
} // transposeIntMatrix ( )
/**
Metodo06.
*/
void metodo06()
{
   // definir dados
   int matrix1[][2] = {{1, 0}, {0, 1}};
   int matrix2[][2] = {{0, 0}, {0, 0}};
   int matrix3[][3] = {{1, 2, 3}, {4, 5, 6}};
   int matrix4[][3] = {{1, 2, 3}, {4, 5, 6}};
   // identificar
   IO_id("EXEMPLO0906 - Metodo06 - v0.0");
   // testar dados
   println("\nMatrix1 ");
   printIntMatrix(2, 2, matrix1);
   transposeIntMatrix(2, 2, matrix2, matrix1);
   println("\nMatrix2");
   printIntMatrix(2, 2, matrix2);
   println("\nMatrix3");
   printIntMatrix(2, 3, matrix3);
   transposeIntMatrix(2, 3, matrix4, matrix3);
   println("\nMatrix4");
   printIntMatrix(3, 2, matrix4);
   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // fim metodo06 ( )

/**
isIdentity - Testar se matriz identidade.
@return - true, se todos os dados forem iguais a zero;
false, caso contrario
@param lines - quantidade de valores
@param columns - quantidade de valores
@param matrix - grupo de valores inteiros
*/
bool isIdentity(int lines, int columns, int matrix[][columns])
{
   // definir dados locais
   bool result = true;
   int x = 0;
   int y = 0;
   // testar condicao de existencia
   if (lines <= 0 || columns <= 0 || lines != columns)
   {
      printf("\nERRO: Valor invalido.\n");
   }
   else
   {
      // testar valores na matriz
      x = 0;
      while (x < lines && result)
      {
         y = 0;
         while (y < columns && result)
         {
            // testar valor
            if (x == y)
            {
               result = result && (matrix[x][y] == 1);
            }
            else
            {
               result = result && (matrix[x][y] == 0);
            } // fim se
              // passar ao proximo
            y = y + 1;
         } // fim repetir
           // passar ao proximo
         x = x + 1;
      } // fim repetir
   }    // fim se
        // retornar resposta
   return (result);
} // isIdentity ( )
/**
Metodo07.
*/
void metodo07()
{
   // definir dados
   int matrix1[][2] = {{0, 0}, {0, 0}};
   int matrix2[][3] = {{1, 2, 3}, {4, 5, 6}};
   int matrix3[][2] = {{1, 0}, {0, 1}};
   // identificar
   IO_id("EXEMPLO0907 - Metodo07 - v0.0");
   // testar dados
   println("\nMatrix1");
   printIntMatrix(2, 2, matrix1);
   printf("isIdentity (matrix1) = %d", isIdentity(2, 2, matrix1));
   println("\nMatrix2");
   printIntMatrix(2, 3, matrix2);
   printf("isIdentity (matrix2) = %d", isIdentity(2, 3, matrix2));
   println("\nMatrix3");
   printIntMatrix(2, 2, matrix3);
   printf("isIdentity (matrix3) = %d", isIdentity(2, 2, matrix3));
   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // fim metodo07 ( )

/**
Metodo08.
*/
void metodo08()
{
   // definir dados
   int matrix1[][2] = {{0, 0}, {0, 0}};
   int matrix2[][2] = {{1, 2}, {3, 4}};
   int matrix3[][2] = {{1, 0}, {0, 1}};
   // identificar
   IO_id("EXEMPLO0908 - Metodo08 - v0.0");
   // testar dados
   println("\nMatrix1");
   printIntMatrix(2, 2, matrix1);
   println("\nMatrix2");
   printIntMatrix(2, 2, matrix2);
   printf("isEqual (matrix1, matrix2) = %d", isEqual(2, 2, matrix1, matrix2));
   copyIntMatrix(2, 2, matrix1, matrix3);
   copyIntMatrix(2, 2, matrix2, matrix3);
   println("\nMatrix1");
   printIntMatrix(2, 2, matrix1);
   println("\nMatrix3");
   printIntMatrix(2, 2, matrix2);
   printf("isEqual (matrix1, matrix2) = %d", isEqual(2, 2, matrix1, matrix2));
   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // fim metodo08 ( )

/**
addIntMatrix - Somar matrizes com inteiros.
@param lines - quantidade de valores
@param columns - quantidade de valores
@param matrix3 - grupo de valores inteiros resultante
@param matrix1 - grupo de valores inteiros (1)
@param k - constante para multiplicar o segundo termo
@param matrix2 - grupo de valores inteiros (2)
*/
void addIntMatrix(int lines, int columns, int matrix3[][columns], int matrix1[][columns], int k, int matrix2[][columns])
{
   // definir dados locais
   int x = 0;
   int y = 0;
   // mostrar valores na matriz
   for (x = 0; x < lines; x = x + 1)
   {
      for (y = 0; y < columns; y = y + 1)
      {
         // somar valores
         matrix3[x][y] = matrix1[x][y] + k * matrix2[x][y];
      } // fim repetir
   }    // fim repetir
} // addIntMatrix ( )
/**
Metodo09.
*/
void metodo09()
{
   // definir dados
   int matrix1[][2] = {{1, 2}, {3, 4}};
   int matrix2[][2] = {{1, 0}, {0, 1}};
   int matrix3[][2] = {{0, 0}, {0, 0}};
   // identificar
   IO_id("EXEMPLO0909 - Metodo09 - v0.0");
   // testar dados
   println("\nMatrix1");
   printIntMatrix(2, 2, matrix1);
   println("\nMatrix2");
   printIntMatrix(2, 2, matrix2);
   // soamr matrizes
   addIntMatrix(2, 2, matrix3, matrix1, (-2), matrix2);
   println("\nMatrix3");
   printIntMatrix(2, 2, matrix3);
   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // fim metodo09 ( )

/**
mulIntMatrix - Multiplicar matrizes com inteiros.
@param lines3 - quantidade de linhas da matriz (3)
@param columns3 - quantidade de colunas da matriz (3)
@param matrix3 - grupo de valores inteiros resultante
@param lines1 - quantidade de linhas da matriz (1)
@param columns1 - quantidade de colunas da matriz (1)
@param matrix1 - grupo de valores inteiros (1)
@param lines2 - quantidade de linhas da matriz (2)
@param columns2 - quantidade de colunas da matriz (2)
@param matrix2 - grupo de valores inteiros (2)
*/
void mulIntMatrix(int lines3, int columns3, int matrix3[][columns3], int lines1, int columns1, int matrix1[][columns1], int lines2, int columns2, int matrix2[][columns2])
{
   // definir dados locais
   int x = 0;
   int y = 0;
   int z = 0;
   int soma = 0;
   if (lines1 <= 0 || columns1 == 0 || lines2 <= 0 || columns2 == 0 || lines3 <= 0 || columns3 == 0 || columns1 != lines2 || lines1 != lines3 || columns2 != columns3)
   {
      printf("\nERRO: Valor invalido.\n");
   }
   else
   {
      // percorrer valores na matriz resultante
      for (x = 0; x < lines3; x = x + 1)
      {
         for (y = 0; y < columns3; y = y + 1)
         {
            // somar valores
            soma = 0;
            for (z = 0; z < columns1; z = z + 1)
            {
               soma = soma + matrix1[x][z] * matrix2[z][y];
            } // fim repetir
              // guardar a soma
            matrix3[x][y] = soma;
         } // fim repetir
      }    // fim repetir
   }       // fim se
} // mulIntMatrix ( )
/**
Method10.
*/
void metodo10()
{
   // identificar
   IO_id("EXEMPLO0910 - Metodo10 - v0.0");
   // definir dados
   int matrix1[][2] = {{1, 2}, {3, 4}};
   int matrix2[][2] = {{1, 0}, {0, 1}};
   int matrix3[][2] = {{0, 0}, {0, 0}};
   // testar produto
   println("\nMatrix1");
   printIntMatrix(2, 2, matrix1);
   println("\nMatrix2");
   printIntMatrix(2, 2, matrix2);
   // multiplicar matrizes
   mulIntMatrix(2, 2, matrix3, 2, 2, matrix1, 2, 2, matrix2);
   println("\nMatrix3 = Matrix1 * Matrix2");
   printIntMatrix(2, 2, matrix3);
   // outro teste
   println("\nMatrix2");
   printIntMatrix(2, 2, matrix2);
   println("\nMatrix1");
   printIntMatrix(2, 2, matrix1);
   // multiplicar matrizes
   mulIntMatrix(2, 2, matrix3, 2, 2, matrix2, 2, 2, matrix1);
   println("\nMatrix3 = Matrix2 * Matrix1");
   printIntMatrix(2, 2, matrix3);
   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // fim method10 ( )

int main()
{

   int x = 0;
   do
   {
      println("Opcoes");
      println("0 - Metodo 00");
      println("1 - Metodo 01");
      println("2 - Metodo 02");
      println("3 - Metodo 03");
      println("4 - Metodo 04");
      println("5 - Metodo 05");
      println("6 - Metodo 06");
      println("7 - Metodo 07");
      println("8 - Metodo 08");
      println("9 - Metodo 09");
      println("10 - Metodo 10");

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