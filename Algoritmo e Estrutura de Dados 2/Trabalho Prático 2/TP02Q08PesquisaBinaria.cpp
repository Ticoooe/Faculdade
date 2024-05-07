#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

/**
 * Tipo personagem
*/
typedef struct 
{
    char   nome[100];
    int    altura;
    float  peso;
    char   corDoCabelo[100];
    char   corDaPele[100];
    char   corDosOlhos[100];
    char   anoNascimento[100];
    char   genero[100];
    char   homeworld[100];

}Personagem;

/**
* Captura informacoes uteis da string para setar    
* @param dados string com conteudo do arquivo.
*/
void escreveAtributos(Personagem *p){
    
    printf(" ## %s" ,p -> nome);
    printf(" ## %i" ,p -> altura);
    printf(" ## %g" ,p -> peso);
    printf(" ## %s" ,p -> corDoCabelo);
    printf(" ## %s" ,p -> corDaPele);
    printf(" ## %s" ,p -> corDosOlhos);
    printf(" ## %s" ,p -> anoNascimento);
    printf(" ## %s" ,p -> genero);
    printf(" ## %s" ,p -> homeworld);
    printf(" ## ");
    printf("\n"); // Quebra de linha
}


Personagem *personagens[100];  // lista de personagens
int n;                         // Posicao de personagens

/**
 * Inicializacoes
 */
void start(){
   n = 0;
}

/**
 * Insere um elemento na ultima posicao da 
 * @param p Personagem elemento a ser inserido.
 */
void inserirFim(Personagem *p) {

   //validar insercao
   if(n >= 100){
      printf("Erro ao inserir!");
      exit(1);
   }
 
   personagens[n] = p;
   n++;
}


/**
 * Mostra o personagens separados por espacos.
 */
void mostrar(){
    
    for(int i = 0; i < n; i++){
      printf("[%i] ",i);
      escreveAtributos(personagens[i]);
    }
}

/**
* Aloca as informacoes para cada atributo   
* @param dados string com informacao.
* @param mod numero de controle para alocar.
*/
void setAtributos(Personagem *p,int mod, char dados[]){
    
    char unknown[] = "unknown";

    if (mod == 1){ // nome
        strcpy(p -> nome,dados);
    }

    if(mod == 2){ // altura
        int i;
        if (strcmp(unknown, dados) == 0){
            i = 0;
        }
        else i = atoi(dados);
        
        p -> altura = i;
    }

    if(mod == 3){ // peso
        float f;
        
        char aux[100];
        for (int j = 0, l = 0; j < strlen(dados); j++){
            if (dados[j] != ','){
                aux[l] = dados[j];
                l++;
            }
        }
        
        f = atof(aux);

        if (strcmp(unknown, aux) == 0){
            f = 0;
        }

        p -> peso = f;
    }
            
    if(mod == 4){ // Cor do cabelo
        strcpy(p -> corDoCabelo,dados);
    }

    if(mod == 5){ // Cor da pele
        strcpy(p -> corDaPele, dados);
    }

    if(mod == 6){ // Cor dos olhos
        strcpy(p -> corDosOlhos,dados);
    }

    if(mod == 7){ // Ano da Nascimento
        strcpy(p -> anoNascimento, dados);
    }
    
    if(mod == 8){ // Genero
        strcpy(p -> genero, dados);
    }
    
    if(mod == 9){ // Homeworld
        strcpy(p -> homeworld, dados);
    }

}

/**
* Captura informacoes uteis da string para setar    
* @param dados string com conteudo do arquivo.
*/
void varreString(Personagem *p, char dados[]){

    int in = 0; int i = 0;

    for (int pos = 0, cont = 1; cont <= 9; pos++){
        
        if (dados[pos] == ':'){
            
            in = pos+3; // começo da informação
            static char aux[100];
            
            while (dados[in] != '\''){
                aux[i] = dados[in];
                in++; i++;
            }

            setAtributos(p,cont,aux);

            memset(aux, 0, 100);
            cont++;
            i = 0;
        }
    }
}


/**
* Le conteudo de um arquivo e aloca em uma string.    
* @param caminho path do arquivo a ser lido.
*/
void leArquivo(Personagem *p, char caminho[]){
    
    char aux[1000];
    FILE *arq = fopen(caminho, "r");
    
    fscanf(arq, "%[^\n]s", aux);
    varreString(p, aux);

    fclose(arq);
}

int PesquisaBinaria(int comp, char nome[]){
    
    int ini = 0; int fim = n - 1;
    bool encontrado = false;
    int pos = 0;

    do{
        pos = (ini + fim) / 2;
        if (strcmp(nome,personagens[pos] -> nome) == 0){
            comp ++;
            encontrado = true;
        }else if (strcmp(nome,personagens[pos] -> nome) < 0 ){
            comp += 2;
            fim = pos - 1;
        } else {
            comp += 2;
            ini = pos + 1;
        }   
    }while(encontrado == false && ini <= fim);

    if (encontrado){
        comp++;
        printf("SIM\n");
    }
    else {printf("NAO\n"); comp+= 2;}

    return comp;
}

int main(){
     
    char caminho[100];int i=0;
    
    scanf(" %[^\n]s", caminho);
    Personagem *entradas[100];
    
    while(strcmp(caminho,"FIM") != 0){ // Enquanto não for fim
        
        entradas[i] = (Personagem*)malloc(sizeof(Personagem));
        leArquivo(entradas[i],caminho);
        inserirFim(entradas[i]);
        i++;

        scanf(" %[^\n]s", caminho); // Repete leitura do path
    }
    
    char nome[100];
    scanf(" %[^\n]s", nome);

    clock_t Ticks[2];
    Ticks[0] = clock();
    int comparacoes = 0;

    while (strcmp(nome,"FIM") != 0){ // Enquanto não for fim
        
        comparacoes += PesquisaBinaria(comparacoes,nome);
        
        scanf(" %[^\n]s", nome);
    }

    Ticks[1] = clock();
    long Tempo = (Ticks[1] - Ticks[0]);

    FILE *arq;
    arq = fopen("matricula_binaria.txt","w");

    fprintf(arq,"matricula: 655310\tTempo de Execução: 0,%d s\tComparacoes: %i",Tempo,comparacoes);

    fclose(arq);

    return 0;
}