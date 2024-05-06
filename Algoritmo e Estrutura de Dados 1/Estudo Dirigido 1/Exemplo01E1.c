#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
   int area = 0;
   int lado = 0;
   printf("Entrar com valor da area: \n");
   scanf("%d", &area);
   lado = sqrt(area);
   printf("O valor do lado eh: %d \n", lado);
   return (0);
}