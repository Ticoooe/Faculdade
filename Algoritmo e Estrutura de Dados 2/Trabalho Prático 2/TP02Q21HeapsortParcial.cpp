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

int mov = 0;
int comp = 0;

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
 * Insere um elemento na primeira posicao da lista e move os demais
 * elementos para o fim 
 * @param p Personagem elemento a ser inserido.
 */
void inserirInicio(Personagem *p) {

   //validar insercao
   if(n >= 100){
      printf("Erro ao inserir!");
      exit(1);
   }

   //levar elementos para o fim do personagens
   for(int i = n; i > 0; i--){
      personagens[i] = personagens[i-1];
   }

   personagens[0] = p;
   n++;
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
 * Insere um elemento em uma posicao especifica e move os demais
 * elementos para o fim da 
 * @param p Personagem elemento a ser inserido.
 * @param pos Posicao de insercao.
 */
void inserir(Personagem *p, int pos) {
   int i;

   //validar insercao
   if(n >= 100 || pos < 0 || pos > n){
      printf("Erro ao inserir!");
      exit(1);
   }

   //levar elementos para o fim do personagens
   for(i = n; i > pos; i--){
      personagens[i] = personagens[i-1];
   }

   personagens[pos] = p;
   n++;
}


/**
 * Remove um elemento da primeira posicao da lista e movimenta 
 * os demais elementos para o inicio da mesma.
 * @return resp int elemento a ser removido.
 */
char* removerInicio() {

   //validar remocao
   if (n == 0) {
      printf("Erro ao remover!");
      exit(1);
   }

   static char resp[20];
   strcpy(resp,"(R) "); 
   strcat(resp,personagens[0] -> nome);
   n--;

   for(int i = 0; i < n; i++){
      personagens[i] = personagens[i+1];
   }

   return resp;
}


/**
 * Remove um elemento da ultima posicao da 
 * @return resp Personagem elemento a ser removido.
 */
char* removerFim() {

    //validar remocao
    if (n == 0) {
      printf("Erro ao remover!");
      exit(1);
    }
    
    static char resp[20];
    n--; 
    strcpy(resp,"(R) ");
    strcat(resp,personagens[n] -> nome);
    
    return resp;
}

/**
 * Remove um elemento de uma posicao especifica da lista e 
 * movimenta os demais elementos para o inicio da mesma.
 * @param pos Posicao de remocao.
 * @return resp Personagem elemento a ser removido.
 */
char* remover(int pos) {
   
   //validar remocao
   if (n == 0 || pos < 0 || pos >= n) {
      printf("Erro ao remover!");
      exit(1);
   }

    static char resp[20];
    strcpy(resp,"(R) "); 
    strcat(resp,personagens[pos] -> nome);
    n--;

   for(int i = pos; i < n; i++){
      personagens[i] = personagens[i+1];
   }

   return resp;
}

/**
 * Mostra o personagens separados por espacos.
 */
void mostrar(){
    
    for(int i = 0; i < 10; i++){
    //   printf("[%i] ",i);
      escreveAtributos(personagens[i]);
    }
}
/**
 * Troca personagens de lugar 
 */
void swap(int i, int j) {
   Personagem *temp = personagens[i];
   personagens[i] = personagens[j];
   personagens[j] = temp; mov++;
}

void constroi(int tamHeap){
      for(int i = tamHeap; i > 1 && personagens[i] -> altura > personagens[i/2] -> altura; i /= 2){
         swap(i, i/2); comp++;
      }
}

void reconstroi(int tamHeap){
   int i = 1, filho;
   while(i <= (tamHeap/2)){
      comp++;
      if (personagens[2*i] -> altura > personagens[2*i+1] -> altura || 2*i == tamHeap){
         filho = 2*i;
      } else {
         filho = 2*i + 1;
      }
      comp++;
      if(personagens[i] -> altura < personagens[filho] -> altura){
         swap(i, filho);
         i = filho;
      }else{
         i = tamHeap;
      }
   }
}

/**
* Algoritmo de ordenacao por insercao.
*/
void insercao(int inicio, int fim) {
      
      for (int i = inicio+1; i <= fim; i++) {
      Personagem *tmp = personagens[i]; mov++;
         int j = i - 1;
         comp++; int k = -1;
         while ((j >= inicio) && strcmp(personagens[j] -> nome, tmp -> nome) > 0) {
               personagens[j + 1] = personagens[j]; k++; mov++;
               j--;
         }
         if (k!=0){
               comp += k;
         }
         personagens[j + 1] = tmp; mov++;
   }
}


// Algoritmo de ordenacao
void heapsort() {
   
   //Alterar o vetor ignorando a posicao zero
   for(int i = n; i > 0; i--){
      personagens[i] = personagens[i-1]; mov++;
   }

   //Contrucao do heap
   for(int tamHeap = 1; tamHeap <= n; tamHeap++){
      constroi(tamHeap);
   }

   //Ordenacao propriamente dita
   int tamHeap = n;
   while(tamHeap > 1){
      swap(1, tamHeap--);
      reconstroi(tamHeap);
   }

   //Alterar o vetor para voltar a posicao zero
   for(int i = 0; i < n; i++){
      personagens[i] = personagens[i+1]; mov++;
   }

   int inicio = 0; int fim = 0;

        for (int i = 0; i <= n; i++){
            comp++;
            if (i < n - 1 && personagens[i] -> altura == personagens[i+1] -> altura){
                inicio = i; fim = i; int j = i;
                comp++; int k = -1;
                while (personagens[j] -> altura == personagens[j+1] -> altura){
                    fim++; j++; k++;
                }
                if (k!=-1){
                    comp += k;
                }
                
                insercao(inicio,fim);
                i = fim;
            }
        }
}


//////////////////// FIM LISTA //////////////////////

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
    
    scanf("%[^\n]s", caminho);
    Personagem *entradas[100];
    
    while(strcmp(caminho,"FIM") != 0){ // Enquanto não for fim
        
        entradas[i] = (Personagem*)malloc(sizeof(Personagem));
        leArquivo(entradas[i],caminho);
        inserirFim(entradas[i]);
        i++;

        scanf(" %[^\n]s", caminho); // Repete leitura do path
    }
    
    heapsort();

    clock_t end = clock();
    double Tempo = (end - begin) / (double)CLOCKS_PER_SEC / 1000.0;
    
    FILE *arq;
    arq = fopen("matricula_heapsortparcial.txt","w");

    fprintf(arq,"matricula: 655310\tTempo de Execução: %fms\tComparacoes: %i\t Movimentacoes: %i",Tempo,comp,mov);
    
    mostrar();
    
    return 0;
}