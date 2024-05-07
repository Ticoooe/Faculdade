#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool ehPalindREC (char word[], int pos){
    int tam = strlen(word) - 1 - pos;
    bool ehPalind = true;

    if (word [pos] != word [tam] && pos < tam){
            ehPalind = false;
    }
    else if (pos < tam){
        ehPalind = ehPalindREC(word,pos + 1);
    }
    return ehPalind;
}

bool ehPalind(char palavra[]){
    return ehPalindREC(palavra,0);
}

int main(){

    char frase[1000];

    scanf("%[^\n]%*c",&frase);
    
    while(strcmp(frase,"FIM") != 0){
        if(ehPalind(frase)==true)
            printf("SIM\n");
        else printf("NAO\n");
            
        scanf("%[^\n]%*c",&frase);
    }
    return 0;
}