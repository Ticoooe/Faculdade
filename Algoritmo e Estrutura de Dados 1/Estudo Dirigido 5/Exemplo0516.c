#include <stdio.h>
#include <stdlib.h>

int metodo06(int x){
    int soma = 0;
    int par = 2;
    int z = 0;
    for(z=0; z<x; z++){
        if(par % 5 != 0){
            soma = soma+par;
        }
        par = par+2;
    }
    printf("\n A soma dos %d  primeiros pares n divisiveis por 5 eh: %d \n", x, soma);
}
int main(){

    int x = 0;
    int base = 0;

    printf("Entrar com um valor: ");
    scanf("%d", &x);

    metodo06(x);

return (0);
}
