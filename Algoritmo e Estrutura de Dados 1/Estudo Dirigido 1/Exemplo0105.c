/*
Exemplo0105 - v0.1.
Author: Paulo Antonio Eufrazio Araujo__
Para compilar em terminal (janela de comandos):
Linux : gcc -o exemplo0105 exemplo0105.c
Windows: gcc -o exemplo0105.exe exemplo0105.c
Para executar em terminal (janela de comandos):
Linux : ./exemplo0105
Windows: exemplo0105
*/
// dependencias
#include <stdio.h>   // para as entradas e saidas
#include <stdbool.h> // para valores logicos
#include <string.h>  // para cadeias de caracteres

int main(int argc, char *argv[])
{
    // definir dado
    char x[] = "abc"; // definir variavel com valor inicial
    // identificar
    printf("%s\n", "EXEMPLO0105 - Programa - v0.1");
    printf("%s\n", "Autor: Paulo Antonio Eufrazio Araujo");
    printf("\n"); // mudar de linha
    // mostrar valor inicial
    printf("%s%s\n", "x = ", x);
    // OBS.: O formato para caracteres -> %s
    // ler do teclado
    printf("Entrar com uma cadeia de caracteres: ");
    scanf("%s", x);
    // OBS.: Nao dever ser usado o endereco dessa vez !
    // mostrar valor lido
    printf("%s%s\n", "x = ", x);
    // encerrar
    printf("\n\nApertar ENTER para terminar.");
    fflush(stdin); // limpar a entrada de dados
    getchar();     // aguardar por ENTER
    return (0);    // voltar ao SO (sem erros)
} // fim main( )
  /*
  --------------------------------------- ------- documentacao complementar
  ---------------------------------------------- notas / observacoes / comentarios
  ---------------------------------------------- previsao de testes
  a.) def
  b.) d e f
  c.) d_e_f
  ---------------------------------------------- testes
  Versao Teste
  0.1 01. ( OK ) identificacao de programa
  0.2 01. ( OK ) identificacao de programa
  0.3 01. ( OK ) identificacao de programa
  0.4 01. ( OK ) identificacao de programa
  0.5 01. ( OK ) identificacao de programa
  */