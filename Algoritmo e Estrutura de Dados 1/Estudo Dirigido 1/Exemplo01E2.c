#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
   int raio = 0;
   int volume = 0;
   printf("Entrar com valor do volume: \n");
   scanf("%d", &volume);
   raio = (3 * volume * raio * raio) / (4 * M_PI);
   printf("O valor do raio eh: %d \n", raio);
   return (0);
}