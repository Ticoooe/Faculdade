#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int comp=0;
int mov=0;


/**
 * Tipo personagem
*/
typedef struct Personagem
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
    
    struct Personagem* prox;
    struct Personagem* ant;


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

/**
 * Clona um Personagem passado como paramêtro e retorna o novo personagem
 * @param (Personagem*) p Personagem a ser clonado
 * @return (Personagem*) novo personagem;
 */
Personagem* Clone(Personagem *p){
    
    Personagem *novo = (Personagem*)malloc(sizeof(Personagem));
    strcpy(novo->nome,p->nome);
    novo->altura = p->altura;
    novo->peso = p->peso;
    strcpy(novo->anoNascimento,p->anoNascimento);
    strcpy(novo->corDaPele,p->corDaPele);
    strcpy(novo->corDoCabelo,p->corDoCabelo);
    strcpy(novo->corDosOlhos,p->corDosOlhos);
    strcpy(novo->genero,p->genero);
    strcpy(novo->homeworld,p->homeworld);

    return novo;
}

/**
 * @param (Personagem*) p1 Personagem a receber a copia
 * @param (Personagem*) p2 Personagem a ser copiado
 */
void CloneCopy(Personagem* p1, Personagem* p2){
    strcpy(p1->nome,p2->nome);
    p1->altura = p2->altura;
    p1-> peso = p2->peso;
    strcpy(p1->anoNascimento,p2->anoNascimento);
    strcpy(p1->corDaPele,p2->corDaPele);
    strcpy(p1->corDoCabelo,p2->corDoCabelo);
    strcpy(p1->corDosOlhos,p2->corDosOlhos);
    strcpy(p1->genero,p2->genero);
    strcpy(p1->homeworld,p2->homeworld);
}

//LISTA PROPRIAMENTE DITA =======================================================
Personagem* primeiro;
Personagem* ultimo;


/**
 * Cria uma lista dupla sem elementos (somente no cabeca).
 */
void start () {
   primeiro = (Personagem*)malloc(sizeof(Personagem));
   ultimo = primeiro;
}


/**
 * Insere um elemento na ultima posicao da lista.
 * @param x Personagem personagem a ser inserido.
 */
void inserirFim(Personagem* x) {
   ultimo->prox = x;
   ultimo->prox->ant = ultimo;
   ultimo = ultimo->prox;
}


/**
 *  Calcula e retorna o tamanho, em numero de elementos, da lista.
 *  @return resp int tamanho
 */
int tamanho() {
   int tamanho = 0; 
   Personagem* i;
   for(i = primeiro; i != ultimo; i = i->prox, tamanho++);
   return tamanho;
}

/**
 * Mostra os elementos da lista separados por espacos.
 */
void mostrar() {
    Personagem* i;

    int j = 0;
    for (i = primeiro->prox; i != NULL ; i = i->prox, j++) {
      
        escreveAtributos(i);
    }
}

/////         FIM LISTA DUPLA              //////

///////////////// MAIN /////////////////////////

/**
 * Consulta a posição do Personagem na ListaDupla a partir de um numero inteiro
 * @param i (Personagem) 
 * @return Personagem na posicai (i)
 */
Personagem* posicao(int i){
    Personagem *p = primeiro->prox;
    
    for (int a = 0; a < i; p = p->prox,a++);

    return p;
}


/**
 * Algoritmo de ordenacao por insercao.
 */
void insercao(int inicio, int fim) {

    for (int i = inicio+1; i <= fim; i++) {
        Personagem* tmp = Clone(posicao(i)); mov++;
        int j = i - 1;
        
        comp++; int k = -1;
        while ((j >= inicio) && (strcmp(posicao(j)->nome,tmp->nome) > 0)) {
            CloneCopy(posicao(j + 1),posicao(j)); k++; mov++;
            j--;
        }
        
        if (k!=-1) comp += k;

        CloneCopy(posicao(j + 1),tmp); mov++;
    }
}

/**
* Troca o conteudo dos personagens
* 
* @param i (Personagem)    
* @param j (Personagem)
*/
void swap(Personagem* i, Personagem* j){
    
        Personagem* tmp = Clone(i);
        CloneCopy(i,j);
        CloneCopy(j,tmp);
}

/**
* Algoritmo de ordenacao Quicksort.
*/
void quicksortRec (int esq, int dir) {
    int i = esq, j = dir;
    Personagem* pivo = Clone(posicao((dir+esq)/2));
    while (i <= j) {
        while (strcmp(posicao(i)->corDoCabelo,pivo->corDoCabelo) < 0){ i++; comp++;}
        while (strcmp(posicao(j)->corDoCabelo,pivo->corDoCabelo) > 0){ j--; comp++;} 
        if (i <= j) {
            swap(posicao(i), posicao(j)); mov++;
            i++; j--;
        }
    }
    if (esq < j)  quicksortRec(esq, j);
    if (i < dir)  quicksortRec(i, dir);
    
}

/**
* Algoritmo de ordenacao Quicksort.
* @param int esq inicio da lista a ser ordenada
* @param int dir fim da lista a ser ordenada
*/
void quicksort() {
   int n = tamanho();

   quicksortRec(0, n-1);

   int inicio = 0; int fim = 0;
        
        for (int i = 0; i < n; i++){
    
            comp++;
            if (i < n-1 && strcmp(posicao(i)->corDoCabelo,posicao(i+1)->corDoCabelo) == 0){
                
                inicio = i; fim = i;int j = i; int k = -1; comp++;
    
                while ( j + 1 < n && strcmp(posicao(j)->corDoCabelo,posicao(j+1)->corDoCabelo) == 0){
                    fim++; k++;j++;
                }

                if (k!=-1) comp+=k;
    
                i = fim;
            }
            insercao(inicio,fim);
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

int main(){
     
    clock_t begin = clock();
    char caminho[100];int i=0;
    start();
    
    scanf("%[^\n]s", caminho);
    Personagem *entradas[100];
    
    while(strcmp(caminho,"FIM") != 0){ // Enquanto não for fim
        
        entradas[i] = (Personagem*)malloc(sizeof(Personagem));
        leArquivo(entradas[i],caminho);
        inserirFim(entradas[i]);
        i++;

        scanf(" %[^\n]s", caminho); // Repete leitura do path
    }

    quicksort();

    clock_t end = clock();
    double Tempo = (end - begin) / (double)CLOCKS_PER_SEC / 1000.0;
    
    FILE *arq;
    arq = fopen("matricula_quicksortListaDupla.txt","w");

    fprintf(arq,"matricula: 655310\tTempo de Execução: %fms\tComparacoes: %i\t Movimentacoes: %i",Tempo,comp,mov);

    mostrar();
    
    return 0;
}