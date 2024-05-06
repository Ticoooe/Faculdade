/*
Exemplo0107 - v0.1.
Author: Paulo Antonio Eufrazio Araujo__
Para compilar em terminal (janela de comandos):
Linux : gcc -o exemplo0107 exemplo0107.c
Windows: gcc -o exemplo0107.exe exemplo0107.c
Para executar em terminal (janela de comandos):
Linux : ./exemplo0107
Windows: exemplo0107
*/
// dependencias
#include <stdio.h>   // para as entradas e saidas
#include <stdbool.h> // para valores logicos
#include <string.h>  // para cadeias de caracteres
#include <math.h>    // para funcoes matematicas

int main(int argc, char *argv[])
{
    // definir dados
    double x = 0.0; // definir variavel com valor inicial
    double y = 0.0; // definir variavel com valor inicial
    double z = 0.0; // definir variavel com valor inicial
    // identificar
    printf("%s\n", "EXEMPLO0107 - Programa - v0.1");
    printf("%s\n", "Autor: Paulo Antonio Eufrazio Araujo");
    printf("\n"); // mudar de linha
    // mostrar valores iniciais
    printf("%s%lf\n", "x = ", x);
    printf("%s%lf\n", "y = ", y);
    // OBS.: O formato para int -> %d (ou %i)
    // ler do teclado
    printf("Entrar com um valor real: ");
    scanf("%lf", &x);
    // OBS.: Necessario indicar o endereco -> &
    printf("Entrar com outro valor real: ");
    scanf("%lf", &y);
    // OBS.: Necessario indicar o endereco -> &
    // operar valores
    z = pow(x, y); // elevar a base (x) 'a potencia (y)
    // mostrar valor resultante
    printf("%s(%lf)*(%lf) = (%lf)\n", "z = ", x, y, z); // encerrar
    printf("\n\nApertar ENTER para terminar.");
    fflush(stdin); // limpar a entrada de dados
    getchar();     // aguardar por ENTER
    return (0);    // voltar ao SO (sem erros)
} // fim main( )
  /*
  ---------------------------------------------- documentacao complementar
  ---------------------------------------------- notas / observacoes / comentarios
  ---------------------------------------------- previsao de testes
  a.) 2.0 e 3.0
  b.) 3.0 e 2.0
  c.) -3.0 e 2.0
  d.) -2.0 e -3.0
  ---------------------------------------------- testes
  Versao Teste
  0.1 01. ( OK ) identificacao de programa
  0.2 01. ( OK ) identificacao de programa
  0.3 01. ( OK ) identificacao de programa
  0.4 01. ( OK ) identificacao de programa
  0.5 01. ( OK ) identificacao de programa
  0.6 01. ( OK ) identificacao de programa
  0.7 01. ( OK ) identificacao de programa
  */