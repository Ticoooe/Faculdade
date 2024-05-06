#include <stdio.h>
#include <stdlib.h>

int metodo04(int x){
    int y = 0;
    int z = 0;
    for( z=0; z<x; z++){
        y= y +2;
        printf("1/%d, ",y);
    }
}
int main(){
    int x = 0;
    printf("Entrar com um valor: ");
    scanf("%d", &x);
    metodo04(x);
return (0);
}
