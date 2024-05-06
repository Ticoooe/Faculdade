#include "IO.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void metodo00()
{
}
/**
Metodo01a - Mostrar certa quantidade de valores recursivamente.
@param x - quantidade de valores a serem mostrados
*/
void metodo01a(int x)
{
   // repetir enquanto valor maior que zero
   if (x > 0)
   { // mostrar valor
      printf("%s%d\n", "Valor = ", x);
      // passar ao proximo
      metodo01a(x - 1); // motor da recursividade
   }                    // fim se
} // fim metodo01a( )
/**
Metodo01 - Mostrar certa quantidade de valores.
*/
void metodo01()
{
   // definir dado
   int quantidade = 0;
   int valor = 0;
   int controle = 0;
   // identificar
   IO_id("EXEMPLO0610 - Metodo01 - v0.1");
   // executar o metodo auxiliar
   metodo01a(5); // motor da recursividade
   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // fim metodo01 ( )

/**
Metodo02a - Mostrar certa quantidade de valores recursivamente.
@param x - quantidade de valores a serem mostrados
*/
void metodo02a(int x)
{
   // repetir enquanto valor maior que zero
   if (x > 0)
   {
      // passar ao proximo
      metodo02a(x - 1); // motor da recursividade
      // mostrar valor
      printf("%s%d\n", "Valor = ", x);
   } // fim se
} // fim metodo02a( )
/**
Metodo02.
*/
void metodo02()
{
   // identificar
   IO_id("EXEMPLO0610 - Metodo02 - v0.0");
   // executar o metodo auxiliar
   metodo02a(5); // motor da recursividade
   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // fim metodo02 ( )

/**
Metodo03a - Mostrar certa quantidade de valores recursivamente.
@param x - quantidade de valores a serem mostrados
*/
void metodo03a(int x)
{
   // repetir enquanto valor maior que zero
   if (x > 1)
   {
      // passar ao proximo
      metodo03a(x - 1); // motor da recursividade
      // mostrar valor
      printf("%s%d\n", "Valor = ", x);
   }
   else
   { // base da recursividade
      // mostrar o ultimo
      printf("%s\n", "Valor = 1");
   } // fim se
} // fim metodo03a( )
/**
Metodo03.
*/
void metodo03()
{
   // identificar
   IO_id("EXEMPLO0610 - Metodo03 - v0.0");
   // executar o metodo auxiliar
   metodo03a(5); // motor da recursividade
   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // fim metodo03 ( )

/**
Metodo04a - Mostrar certa quantidade de valores recursivamente.
@param x - quantidade de valores a serem mostrados
*/
void metodo04a(int x)
{
   // repetir enquanto valor maior que zero
   if (x > 1)
   {
      // passar ao proximo
      metodo04a(x - 1); // motor da recursividade
      // mostrar valor
      printf("%s%d\n", "Valor = ", 2 * (x - 1));
   }
   else
   { // base da recursividade
      // mostrar o ultimo
      printf("%s\n", "Valor = 1");
   } // fim se
} // fim metodo04a( )
/**
Metodo04.
*/
void metodo04()
{
   // identificar
   IO_id("EXEMPLO0610 - Metodo04 - v0.0");
   // executar o metodo auxiliar
   metodo04a(5); // motor da recursividade
   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // fim metodo04 ( )

/**
Metodo05a - Mostrar certa quantidade de valores recursivamente.
@param x - quantidade de valores a serem mostrados
*/
void metodo05a(int x)
{
   // repetir enquanto valor maior que zero
   if (x > 1)
   {
      // passar ao proximo
      metodo05a(x - 1); // motor da recursividade
      // mostrar valor
      printf("%d: %d/%d\n", x, (2 * (x - 1)), (2 * (x - 1) + 1));
   }
   else
   { // base da recursividade
      // mostrar o ultimo
      printf("%d; %d\n", x, 1);
   } // fim se
} // fim metodo05a( )
/**
Metodo05.
*/
void metodo05()
{
   // identificar
   IO_id("EXEMPLO0610 - Metodo05 - v0.0");
   // executar o metodo auxiliar
   metodo05a(5); // motor da recursividade
   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // fim metodo05 ( )

/**
somarFracoes - Somar certa quantidade de fracoes recursivamente.
@return soma de valores
@param x - quantidade de valores a serem mostrados
*/
double somarFracoes(int x)
{
   // definir dado local
   double soma = 0.0;
   // repetir enquanto valor maior que zero
   if (x > 1)
   {
      // separar um valor e passar ao proximo (motor da recursividade)
      soma = (2.0 * (x - 1)) / (2.0 * (x - 1) + 1) + somarFracoes(x - 1);
      // mostrar valor
      printf("%d: %lf/%lf\n", x, (2.0 * (x - 1)), (2.0 * (x - 1) + 1));
   }
   else
   {
      // base da recursividade
      soma = 1.0;
      // mostrar o ultimo
      printf("%d; %lf\n", x, 1.0);
   } // fim se
   // retornar resultado
   return (soma);
} // fim somarFracoes ( )
/**
Metodo06.
*/
void metodo06()
{
   // definir dado
   double soma = 0.0;
   // identificar
   IO_id("EXEMPLO0610 - Metodo06 - v0.0");
   // chamar a funcao e receber o resultado
   soma = somarFracoes(5);
   // mostrar resultado
   printf("soma = %lf\n", soma);
   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // fim metodo06 ( )

/**
somarFracoes2 - Somar certa quantidade de fracoes recursivamente.
@return soma de valores
@param x - quantidade de valores a serem mostrados
*/
double somarFracoes2(int x)
{
   // definir dado local
   double soma = 0.0;
   // repetir enquanto valor maior que zero
   if (x > 1)
   {
      // separar um valor e passar ao proximo (motor da recursividade)
      soma = (2.0 * (x - 1) + 1) / (2.0 * (x - 1)) + somarFracoes2(x - 1);
      // mostrar valor
      printf("%d: %lf/%lf\n", x, (2.0 * (x - 1) + 1), (2.0 * (x - 1)));
   }
   else
   {
      // base da recursividade
      soma = 1.0;
      // mostrar o ultimo
      printf("%d; %lf\n", x, 1.0);
   } // fim se
   // retornar resultado
   return (soma);
} // fim somarFracoes2 ( )
/**
Metodo07.
*/
void metodo07()
{
   // definir dado
   double soma = 0.0;
   // identificar
   IO_id("EXEMPLO0610 - Metodo07 - v0.0");
   // chamar a funcao e receber o resultado
   soma = somarFracoes2(5);
   // mostrar resultado
   printf("soma = %lf\n", soma);
   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // fim metodo07 ( )

/**
contarDigitos - Contar digitos recursivamente.
@return quantidade de digitos
@param x - numero cuja quantidade de digitos sera' calculada
*/
int contarDigitos(int x)
{
   // definir dado
   int resposta = 1; // base
   // testar se contador valido
   if (x >= 10)
   {
      // tentar fazer de novo com valor menor
      resposta = 1 + contarDigitos(x / 10); // motor 1
   }
   else
   {
      if (x < 0)
      {
         // fazer de novo com valor absoluto
         resposta = contarDigitos(-x); // motor 2
      }                                // fim se
   }                                   // fim se
   // retornar resposta
   return (resposta);
} // fim contarDigitos ( )
/**
Metodo08.
*/
void metodo08()
{
   // identificar
   IO_id("EXEMPLO0610 - Metodo08 - v0.0");
   // mostrar resultado
   printf("digitos (%3d) = %d\n", 123, contarDigitos(123));
   printf("digitos (%3d) = %d\n", 1, contarDigitos(1));
   printf("digitos (%3d) = %d\n", -10, contarDigitos(-10));
   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // fim metodo08 ( )

/**
fibonacci - Gerador de numero de Fibonacci.
@return numero de Fibonacci
@param x - numero de ordem cujo valor sera' calculado
*/
int fibonacci(int x)
{
   // definir dado
   int resposta = 0;
   // testar se contador valido
   if (x == 1 || x == 2)
   {
      // primeiros dois valores iguais a 1
      resposta = 1; // bases
   }
   else
   {
      if (x > 1)
      {
         // fazer de novo com valor absoluto
         resposta = fibonacci(x - 1) + fibonacci(x - 2);
      } // fim se
   }    // fim se
   // retornar resposta
   return (resposta);
} // fim fibonacci ( )
/**
Metodo09.
*/
void metodo09()
{
   // identificar
   IO_id("EXEMPLO0610 - Metodo09 - v0.0");
   // calcular numero de Fibonacci
   printf("fibonacci (%d) = %d\n", 1, fibonacci(1));
   printf("fibonacci (%d) = %d\n", 2, fibonacci(2));
   printf("fibonacci (%d) = %d\n", 3, fibonacci(3));
   printf("fibonacci (%d) = %d\n", 4, fibonacci(4));
   printf("fibonacci (%d) = %d\n", 5, fibonacci(5));
   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // fim metodo09 ( )

/**
contarMinusculas - Contador de letras minusculas.
@return quantidade de letras minusculas
@param x - cadeia de caracteres a ser avaliada
*/
int contarMinusculas(chars cadeia, int x)
{
   // definir dado
   int resposta = 0;
   // testar se contador valido
   if (0 <= x && x < strlen(cadeia))
   {
      // testar se letra minuscula
      if (cadeia[x] >= 'a' &&
          cadeia[x] <= 'z')
      {
         // fazer de novo com valor absoluto
         resposta = 1;
      } // fim se
      resposta = resposta + contarMinusculas(cadeia, x + 1);
   } // fim se
   // retornar resposta
   return (resposta);
} // fim contarMinusculas ( )
/**
Metodo10.
*/
void metodo10()
{
   // identificar
   IO_id("EXEMPLO0610 - Metodo10 - v0.0");
   // contar minusculas em cadeias de caracteres
   printf("Minusculas (\"abc\",0) = %d\n", contarMinusculas("abc", 0));
   printf("Minusculas (\"aBc\",0) = %d\n", contarMinusculas("aBc", 0));
   printf("Minusculas (\"AbC\",0) = %d\n", contarMinusculas("AbC", 0));
   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // fim metodo10 ( )
int main()
{

   int x = 0;
   do
   {
      IO_println("Opcoes");
      IO_println("0 - parar");
      IO_println("1 - Questao 01");
      IO_println("2 - Questao 02");
      IO_println("3 - Questao 03");
      IO_println("4 - Questao 04");
      IO_println("5 - Questao 05");
      IO_println("6 - Questao 06");
      IO_println("7 - Questao 07");
      IO_println("8 - Questao 08");
      IO_println("9 - Questao 09");
      IO_println("10 - Questao 10");

      x = IO_readint("Entrar com uma opcao: ");

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