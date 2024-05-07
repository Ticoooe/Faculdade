#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

//Gera letra aleatórias
char Gerador(){
    char letra = (char)(abs((97 + rand()%26)));
    return letra;
}

//Troca as letras necessárias
char *AlteracaoAleatoriaREC(char s[], int i, char letra1, char letra2){
    if(i >= strlen(s)){
        return s;
    }
    if(s[i] == letra1){
        s[i] = letra2;
    }
    return AlteracaoAleatoriaREC(s, i+1, letra1, letra2);
}

int main(){
    srand(18);

    char frase[1000];
    char frases[1000][1000];
    int i=0;

    scanf("%[^\n]%*c", frase);

    while(strcmp(frase,"FIM") != 0){ // Le frases enquanto não é FIM

        char letra1 = Gerador();//letra a ser verificada
        char letra2 = Gerador();//letra a ser alocada no lugar da letra 1
        
        strcpy(frases[i], AlteracaoAleatoriaREC(frase, 0, letra1, letra2));
        i++;
        scanf("%[^\n]%*c", frase);
       
    }

    for(int j=0; j<i; j++){
        printf("%s\n", frases[j]);
    }

    return 0;
}