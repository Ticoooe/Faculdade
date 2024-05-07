#include <stdio.h>
#include <stdlib.h>

void leValores (FILE *arq, int n){
    float valor;
    int pos = -4;
    
    for(int i = 0; i < n; i++){
        
        fseek(arq,pos,SEEK_END);
        fread(&valor,sizeof(float),1,arq);
        printf("%g\n",valor);
        pos -= 4;
    }
}

void escreveValores(FILE *arq, int n){ 
    float valor;

    for (int i = 0; i < n; i++){
        
        scanf("%f",&valor);
        fwrite(&valor,sizeof(float),1,arq);
    }
}

int main(){
    FILE *arq;

    arq = fopen("resultado.dat","w");
    int n;
    scanf("%i",&n);

    escreveValores(arq, n);
    fclose(arq);

    arq = fopen("resultado.dat","rb");
    leValores(arq, n);
    fclose(arq);

    return 0;
} 