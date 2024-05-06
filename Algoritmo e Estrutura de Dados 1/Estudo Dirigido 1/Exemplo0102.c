/*
Exemplo0102 v0.1.
Author: Paulo Antonio Eufrazio Araujo
Para compilar em terminal (janela de comandos):
Linux : gcc -o exemplo0102 exemplo0102.c
Windows: gcc -o exemplo0102.exe exemplo0102.c
Para executar em terminal (janela de comandos):
Linux : ./exemplo0102
Windows: exemplo0102
*/
// dependencias
#include <stdio.h> // para as entradas e saidas

int main(int argc, char *argv[])
{
    // definir dado
    double x = 0.0; // definir variavel com valor inicial
    // OBS.: Definir a parte fracionaria e' util
    // identificar
    printf("%s\n", "EXEMPLO0102 - Programa - v0.1");
    printf("%s\n", "Autor: Paulo Antonio Eufrazio Araujo");
    printf("\n"); // mudar de linha
    // mostrar valor inicial
    printf("%s%lf\n", "x = ", x);
    // OBS.: O formato para double -> %lf
    // ler do teclado
    printf("Entrar com um valor real: ");
    scanf("%lf", &x);
    // OBS.: Necessario indicar o endereco -> &
    // mostrar valor lido
    printf("%s%lf\n", "x = ", x);
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
  a.) 0.5
  b.) -0.5
  c.) 1.23456789
  ---------------------------------------------- testes
  Versao Teste
  0.1 01. ( OK ) identificacao de programa
  0.2 01. ( OK ) identificacao de programa
  */