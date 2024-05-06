/*
Exemplo0104 - v0.1.
Author: Paulo Antonio Eufrazio Araujo
Para compilar em terminal (janela de comandos):
Linux : gcc -o exemplo0104 exemplo0104.c
Windows: gcc -o exemplo0104.exe exemplo0104.c
Para executar em terminal (janela de comandos):
Linux : ./exemplo0104
Windows: exemplo0104
*/
// dependencias
#include <stdio.h>   // para as entradas e saidas
#include <stdbool.h> // para valores logicos

int main(int argc, char *argv[])
{
    // definir dado
    bool x = false; // definir variavel com valor inicial
    // OBS.: Indispensavel usar minusculas
    // identificar
    printf("%s\n", "EXEMPLO0104 - Programa - v0.1");
    printf("%s\n", "Autor: Paulo Antonio Eufrazio Araujo");
    printf("\n"); // mudar de linha
    // mostrar valor inicial
    printf("%s%d\n", "x = ", x);
    // OBS.: O formato para equivalente inteiro -> %d
    // ler do teclado
    printf("Entrar com um valor logico: ");
    scanf("%d", &x);
    // OBS.: Usar equivalente inteiro -> 0 = false
    // mostrar valor lido
    printf("%s%d\n", "x = ", x); // encerrar
    printf("\n\nApertar ENTER para terminar.");
    fflush(stdin); // limpar a entrada de dados
    getchar();     // aguardar por ENTER
    return (0);    // voltar ao SO (sem erros)
} // fim main( )
  /*
  ---------------------------------------------- documentacao complementar
  ---------------------------------------------- notas / observacoes / comentarios
  ---------------------------------------------- previsao de testes
  a.) 1
  b.) 0
  c.) true
  ---------------------------------------------- testes
  Versao Teste
  0.1 01. ( OK ) identificacao de programa
  0.2 01. ( OK ) identificacao de programa
  0.3 01. ( OK ) identificacao de programa
  0.4 01. ( OK ) identificacao de programa
  */