/*
Exemplo0110 - v0.1.
Author: Paulo Antonio Eufrazio Araujo
Para compilar em terminal (janela de comandos):
Linux : gcc -o exemplo0110 exemplo0110.c
Windows: gcc -o exemplo0110.exe exemplo0110.c
Para executar em terminal (janela de comandos):
Linux : ./exemplo0110
Windows: exemplo0110
*/
// dependencias
#include "io.h" // para definicoes proprias

int main(int argc, char *argv[])
{
   // definir dados
   int x = 5;                        // definir variavel com valor inicial
   double y = 3.5;                   // definir variavel com valor inicial
   char z = 'A';                     // definir variavel com valor inicial
   bool w = TRUE;                    // definir variavel com valor inicial
   chars a = IO_new_chars(STR_SIZE); // definir variavel com tamanho inicial
   chars b = IO_new_chars(STR_SIZE); // definir variavel com tamanho inicial
   chars c = IO_new_chars(STR_SIZE); // definir variavel com tamanho inicial
                                     // identificar
   IO_id("EXEMPLO0110 - Programa - v0.1");
   // concatenar (juntar) cadeias de caracteres
   strcpy(a, "abc");    // atribuir a variavel (a) o valor constante ("abc")
   strcpy(b, "def");    // OBS.: a atribuicao de cadeias de caracteres NAO usa (=)
   c = IO_concat(a, b); // melhor que a funcao nativa strcat (a,b)
   IO_printf("\nc = [%s]+[%s] = [%s]\n", a, b, c);
   strcpy(a, "c = ");
   strcpy(c, STR_EMPTY); // limpar a cadeia de caracteres
   IO_printf("%s\n", IO_concat(a, IO_toString_c(z)));
   IO_println(IO_concat(a, IO_toString_d(x)));
   IO_println(IO_concat(a, IO_toString_b(w)));
   strcpy(b, STR_EMPTY);
   IO_print(a);
   IO_print(IO_concat(b, IO_toString_f(y)));
   IO_print("\n");
   z = IO_readchar("caractere = ");
   IO_println(IO_concat(a, IO_toString_c(z)));
   y = IO_readdouble("double = ");
   IO_println(IO_concat(a, IO_toString_f(y)));
   x = IO_readint("int = ");
   IO_println(IO_concat(a, IO_toString_d(x)));
   w = IO_readbool("bool = ");
   IO_println(IO_concat(a, IO_toString_b(w)));
   b = IO_readString("chars = ");
   IO_println(IO_concat(a, b));
   b = IO_readln("line = ");
   IO_println(IO_concat(a, b));
   // encerrar
   IO_pause("Apertar ENTER para terminar");
   // chamar metodo para pausar
   return (0); // voltar ao SO (sem erros)
} // fim main( )
  /*
  ---------------------------------------------- documentacao complementar
  ---------------------------------------------- notas / observacoes / comentarios
  ---------------------------------------------- previsao de testes
  a.) a
  b.) 4.2
  c.) 10
  d.) 1
  e.) abc def
  f .) abc def
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
  0.9 01. ( OK ) identificacao de programa
  0.10 01. ( OK ) identificacao de programa
  */