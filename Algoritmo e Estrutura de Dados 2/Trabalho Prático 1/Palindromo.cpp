#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isPalind (char palavra[]){
    int tam = strlen(palavra) - 1,
        i = 0;

    bool isPalind = true;

    do{
        if (palavra [i] != palavra [tam]){
            isPalind = false;}
        i++;
        tam--;
    }while (i < tam && isPalind == true);
    return isPalind;
}

int main(){

    char frase[1000];

    scanf("%[^\n]%*c", &frase);
    
    while(strcmp(frase, "FIM") != 0){
        
        if(isPalind(frase) == true)
            printf("SIM \n");
            else printf("NAO \n");
            
            scanf("%[^\n]%*c",&frase);
    }   
    return 0;
}