#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

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

/**
 * Fila Circular
 */

Personagem *personagens[6];    // Fila de personagens
int   primeiro;                // Primeira posição Fila
int   ultimo;                  // Posicao de personagens
float somaAltura;              // Soma de alturas
int   quant;                   // Quantidade de Personagens na fila

void start(){
   primeiro = ultimo = somaAltura = quant = 0;
}

/**
 * Mostra os Personagens da Fila
 */
void mostrar (){

    int temp = 0;

    for(int i = primeiro; i != ultimo; i = ((i + 1) % 6)) {
      printf("[%i] ",temp);
      escreveAtributos(personagens[i]);
      temp++;
    }
}

/**
 * Remove um elemento da ultima posicao da fila 
 * Printa na tela o nome do Personagem removido
 */
char* remover() {

   //validar remocao
   if (primeiro == ultimo) {
      printf("Erro ao remover!");
      exit(1);
   }
   quant--;
   somaAltura -= personagens[primeiro] -> altura;

   static char resp[20];
   sprintf(resp,"(R) %s",personagens[primeiro] -> nome);

   primeiro = (primeiro + 1) % 6;

   return resp;
}

/**
 * Insere um elemento na ultima posicao da fila
 * @param p Personagem elemento a ser inserido.
 */
void inserir(Personagem *p) {

    //validar insercao
    if (((ultimo + 1) % 6) == primeiro){
        remover();
    }
    
    somaAltura += p -> altura;
    quant++;

    printf("%i\n",(int)round(somaAltura/quant));
    mostrar();
    
    personagens[ultimo] = p; 
    ultimo = (ultimo + 1) % 6;
}

/**
 * Retorna um bool indicando se a fila esta vazia
 * @return bool indicando se a fila esta vazia
 */
bool isVazia() {
   return (primeiro == ultimo); 
}

//----------------- FIM LISTA --------------------//

//----------------- PRINCIPAL ------------------//


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
     
    char caminho[100];
    start();

    scanf("%[^\n]s", caminho);
    
    while(strcmp(caminho,"FIM") != 0){ // Enquanto não for fim
        
        Personagem *p = (Personagem*)malloc(sizeof(Personagem));
        leArquivo(p,caminho);
        inserir(p);

        scanf(" %[^\n]s", caminho); // Repete leitura do path
    }

    int n;
    scanf("%i",&n);
    
    char comando[50];

    for (int j = 0; j < n; j++){

        scanf(" %[^\n]s", comando);

        if (comando[0] == 'I'){ // Insere 

            char path[40];
        
            int l = 2;
            for (int i = 0; l < strlen(comando); i++,l++){
                path [i] = comando[l];
                path [i + 1] = '\0';
            }

            Personagem *p = (Personagem*)malloc(sizeof(Personagem));
            leArquivo(p, path);
            inserir(p);
        }
        else 
            printf("%s\n",remover());
    }
    
    mostrar();

    return 0;
}