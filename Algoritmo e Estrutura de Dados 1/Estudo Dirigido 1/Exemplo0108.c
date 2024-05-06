/*
Exemplo0108 - v0.1. Author: Paulo Antonio Eufrazio Araujo__
Para compilar em terminal (janela de comandos):
Linux : gcc -o exemplo0108 exemplo0108.c
Windows: gcc -o exemplo0108.exe exemplo0108.c
Para executar em terminal (janela de comandos):
Linux : ./exemplo0108
Windows: exemplo0108
*/
// dependencias
#include <stdio.h>   // para as entradas e saidas
#include <stdbool.h> // para valores logicos
#include <string.h>  // para cadeias de caracteres
#include <math.h>    // para funcoes matematicas

int main(int argc, char *argv[])
{
    // definir dados
    char x[] = "abc"; // definir variavel com valor inicial
    char y[] = "def"; // definir variavel com valor inicial
    char z[80];       // definir variavel com tamanho inicial
    strcpy(z, "");    // e iniciar com vazio
    // identificar
    printf("%s\n", "EXEMPLO0108 - Programa - v0.1");
    printf("%s\n", "Autor: Paulo Antonio Eufrazio Araujo");
    printf("\n"); // mudar de linha
    // mostrar valores iniciais
    printf("%s%s\n", "x = ", x);
    printf("%s%s\n", "y = ", y);
    // OBS.: O formato para int -> %d (ou %i)
    // ler do teclado
    printf("Entrar com caracteres: ");
    scanf("%s", x);
    // OBS.: Nao indicar o endereco -> &
    printf("Entrar com outros caracteres: ");
    scanf("%s", y);
    // OBS.: Nao indicar o endereco -> &
    // operar valores
    strcpy(z, x); // copiar (x) para (z)
    strcat(z, y); // concatenar (juntar) (y) a (z)
    // OBS.: Forma mais eficiente
    // mostrar valor resultante
    printf("%s[%s]*[%s] = [%s]\n", "z = ", x, y, z); // operar valores (forma alternativa)
    strcpy(z, strcat(strdup(x), y));
    // copiar para (z)
    // o resultado de concatenar
    // a copia de (x) com (y)
    // OBS.: Se nao duplicar, o valor (x) sera' alterado.
    // mostrar valor resultante
    printf("%s[%s]*[%s] = [%s]\n", "z = ", x, y, z);
    // encerrar
    printf("\n\nApertar ENTER para terminar.");
    fflush(stdin); // limpar a entrada de dados
    getchar();     // aguardar por ENTER
    return (0);    // voltar ao SO (sem erros)
} // fim main( )
  /*
  ---------------------------------------------- documentacao complementar
  ---------------------------------------------- notas / observacoes / comentarios
  ---------------------------------------------- previsao de testes
  a.) 12 e 24
  b.) ab e cd
  c.) a e bc
  d.) ab e c
  ---------------------------------------------- testes
  Versao Teste
  0.1 01. ( OK ) identificacao de programa
  0.2 01. ( OK ) identificacao de programa
  0.3 01. ( OK ) identificacao de programa
  0.4 01. ( OK ) identificacao de programa
  0.5 01. ( OK ) identificacao de programa
  0.6 01. ( OK ) identificacao de programa
  0.7 01. ( OK ) identificacao de programa
  0.8 01. ( OK ) identificacao de programa
  */