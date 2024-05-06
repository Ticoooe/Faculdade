#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int metodo05(int x, int y){

    int count = 0;
    int denominador = 0;
    for(int i=0; i<x; i++){
        denominador = pow(y,count);
        printf("1/%d, ", denominador);
        count++;
    }
}
int main(){
    int x = 0;
    int y = 0;
    printf("Entrar com um valor de resultados: ");
    scanf("%d", &x);
    printf("Entrar com um valor: ");
    scanf("%d", &y);
    metodo05(x, y);

return (0);
}
