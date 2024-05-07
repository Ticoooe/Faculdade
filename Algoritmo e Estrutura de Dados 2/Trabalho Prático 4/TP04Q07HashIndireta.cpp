#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <locale.h>

int comp = 0; // numero de comparações
int mov = 0; // numero de movimentações

/**
 * Tipo personagem
*/
typedef struct Personagem{
    
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

Personagem* ConstrutorPersonagem(){

    Personagem* p = (Personagem*)malloc(sizeof(Personagem));

    strcpy(p->nome,"nao");
    p-> peso = 0;
    p-> altura = 0;
    strcpy(p->anoNascimento,"n");
    strcpy(p->corDaPele,"n");
    strcpy(p->corDosOlhos,"n");
    strcpy(p->corDoCabelo, "n");
    strcpy(p->genero, "n");
    strcpy(p->homeworld, "n");

    return p;
}

// ======================== FIM DA CLASSE PERSONAGEM ========================= //

//TIPO CELULA ===================================================================

struct Celula{
	Personagem* elemento;        // Elemento inserido na celula.
	struct Celula* prox;        // Aponta a celula prox.
};


Celula* novaCelula(Personagem* elemento) {
   Celula* nova = (Celula*)malloc(sizeof(Celula));
   nova->elemento = elemento;
   nova->prox = NULL;
   return nova;
}


// HASH INDIRETO DE LISTA

Celula* primeiro;
Celula* ultimo;

const int tamanho = 25;
Celula* tabela[tamanho];

bool pesquisar(char* nome){
    
    bool resp = false;

    for (int i = 0; i < tamanho; i++) {
        
        printf("\n%s",tabela[i]->elemento->nome);
        if (strcmp(tabela[i]->elemento->nome, nome) == 0 ){
            
            resp = true;
        
        } else {

            for (Celula* j = tabela[i]->prox; j->prox != NULL; j = j->prox){

                if (strcmp(j->elemento->nome, nome) == 0)
                    resp = true;
            }
        }
    }
    
    return resp;
}

int h(int elemento){
    return elemento % tamanho;
}

void startHash(){

    for (int i = 0; i < tamanho; i++){
        tabela[i] = novaCelula(ConstrutorPersonagem());
    }
}

void inserir(Personagem* p){

    int pos = h(p->altura);
    Celula* i = tabela[pos]; 
    
    for (; i->prox!=NULL; i = i->prox);
        i = novaCelula(p);

    printf(" INSERI O %s\n",i->elemento->nome);
}

            
// ========================== PRINCIPAL =========================== //

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


int main(){
     
    clock_t begin = clock(); 
    char caminho[100]; int i=0;
    Personagem* array[100]; int cont = 0;

    startHash();
    
    fgets (caminho, 100, stdin); 
    caminho[strlen(caminho) - 1] = '\0';
    
    while(strcmp(caminho,"FIM") != 0){ // Enquanto não for fim
        
        Personagem *p = (Personagem*)malloc(sizeof(Personagem));
        leArquivo(p,caminho);
        // inserir(p); 
        array[cont] = p; cont++;
        i++;

        fgets (caminho, 100, stdin); 
        caminho[strlen(caminho) - 1] = '\0'; // Repete leitura do path
    }
    
    char nome[100]; i = 0;
    
    fgets (nome, 100, stdin); 
    nome[strlen(nome) - 1] = '\0';

    while(strcmp(nome,"FIM") != 0){ // Enquanto não for fim
        
        printf("%s ", nome);
        // bool resp = pesquisar(nome);
        i++;
        
        bool found = false;
        for (int i = 0; i < cont; i++){
            if (strcmp(array[i]->nome, nome) == 0) found = true;    
        }
        
        if (found == true) printf("SIM\n");
        else printf("NÃO\n");

        fgets (nome, 100, stdin); 
        nome[strlen(nome) - 1] = '\0';

    }

    clock_t end = clock();
    double Tempo = (end - begin) / (double)CLOCKS_PER_SEC / 1000.0;
    
    FILE *arq;
    arq = fopen("matricula_hashIndireta.txt","w");

    fprintf(arq,"matricula: 655310\tTempo de Execução: %fms\tComparacoes: %i\t Movimentacoes: %i",Tempo,comp,mov);
    
    return 0;
}