/*
Paulo Antonio 
665497
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct arranjo1{
   int quantidade;
   int count;
}arranjo1;

arranjo1* newArranjo1( ){
   arranjo1* tmp = (arranjo1*)malloc(sizeof(arranjo1));
   tmp-> count = 0;
   tmp-> quantidade = 0;
   return tmp;
}

typedef struct matriz1{
   int linhas;
   int colunas;
   int** matriz;
}matriz1;

void Exemplo1011(int count, int quantidade, int valor, int superior, int inferior){
   FILE* arq = fopen("Exercicio01.txt","wt");

   fprintf(arq, " %d numeros aleatorios pertencentes a [%d,%d] \n", quantidade, inferior, superior);

   for (count = 0; count < quantidade; count++){
      for (count = 0; count < quantidade; count++){
         valor = inferior + rand() % (superior - inferior);
         fprintf(arq, "%d \n", valor);
      }
   }

   fclose(arq);
}

void Metodo01(){
   int inferior = 0;
   int superior = 0;
   int valor = 0;

   arranjo1 *qualquer = newArranjo1();

   printf("Entrar com um valor: \n");
   scanf("%d", &inferior);
   printf("Entrar com um valor: \n");
   scanf("%d", &superior);

   while (superior <= inferior){
      printf("Entrar com um valor: \n");
      scanf("%d", &superior);
   }

   printf("Entrar com valor: \n");
   scanf("%d", &qualquer->quantidade);

   Exemplo1011(qualquer->count, qualquer->quantidade, valor, superior, inferior);

   printf("\nDados gravados com sucesso!\n");

   free(qualquer);
}

int Exemplo1012 (int arranjo[], int count1, int quantidade, int numero, int resposta){
   for (count1 = 0; count1 < quantidade; count1++){
      if (numero == arranjo[count1]){
         resposta++;
      }
   }
   return (resposta);
}


void Metodo02 (){
   char nome_arq[80];

   printf("Digite o nome do arq a ser lido: \n");
   scanf("%s", &nome_arq);
   strcat(nome_arq,".txt");

   FILE* arq = fopen(nome_arq,"r");

   int arranjo[80];

   int numero = 0;
   int count1 = 0;
   int resposta = 0;

   arranjo1 *qualquer = newArranjo1();

   if (arq == NULL){
      printf("ERRO! arq nao existe!\n");
   }
   else{
      printf("O arq e valido\n");
      while (!(feof(arq))){
         fscanf(arq,"%d\n",&arranjo[qualquer->count]);
         qualquer->count++;
         qualquer->quantidade++;
      }
   }

   fclose(arq);

   printf("Digite o numero que vc deseja procurar no arq: \n");
   scanf("%d", &numero);

   resposta = Exemplo1012 (arranjo, count1, qualquer->quantidade, numero, resposta);

   printf(" [%d] numeros iguais a [%d] no arq ", resposta, numero);

   free(qualquer);
}

int Exemplo1013 (int arranjo1[], int arranjo2[], int count, int count2, int quantidade, int quantidade2, int teste){
   if (quantidade == quantidade2){
      while (count < quantidade){
         if (arranjo1[count] == arranjo2[count2]){
            teste++;
         }
         count++;
         count2++;
      }
   }
   else{
   
   }
   return (teste);
}


void Metodo03 (){
   char nome_arq1[80];
   char nome_arq2[80];

   arranjo1 *qualquer = newArranjo1();

   printf("Digite o nome do primeiro arq : \n");
   scanf("%s", &nome_arq1);
   strcat(nome_arq1,".txt");
   printf("Digite o nome do segundo arq : \n");
   scanf("%s", &nome_arq2);
   strcat(nome_arq2,".txt");

   FILE* arq1 = fopen(nome_arq1,"r");
   FILE* arq2 = fopen(nome_arq2,"r");
   int arranjo1[80];
   int arranjo2[80];
   int quantidade2 = 0;
   int count2 = 0;
   int teste = 0;

   if (arq1 == NULL){
      printf("ERRO! arq nao existe!\n");
   }
   else{
      printf("O primeiro arq e valido\n");
      while (!(feof(arq1))){
         fscanf(arq1,"%d\n",&arranjo1[qualquer->count]);
         qualquer->count++;
         qualquer->quantidade++;
      }
   }

   if (arq2 == NULL){
      printf("ERRO! arq nao existe!\n");
   }
   else{
      printf("O segundo arq e valido\n");
      while (!(feof(arq2))){
         fscanf(arq2,"%d\n",&arranjo2[count2]);
         count2++;
         quantidade2++;
      }
   }

   fclose(arq1);
   fclose(arq2);

   qualquer->count = 0;
   count2 = 0;

   teste = Exemplo1013 (arranjo1, arranjo2, qualquer->count, count2, qualquer->quantidade, quantidade2, teste);

   if (teste == qualquer->quantidade){
      printf("Os valores sao iguais");
   }
   else{
      printf("Os valores sao diferentes");
   }

   free(qualquer);
}

int Exemplo1014(int count, int quantidade, int arranjo3[], int count3, int arranjo1[], int valor, int arranjo2[], int count2){
   for (count = 0; count < quantidade; count++){
      arranjo3[count3] = arranjo1[count] + valor*arranjo2[count2];
      printf("%d\n", arranjo3[count3]);
      count2++;
      count3++;
   }
   return (count3);
   
}


void Metodo04 (){
   char nome_arq1[80];
   char nome_arq2[80];
   int valor = 0;

   arranjo1 *qualquer = newArranjo1();

   printf("Digite o nome do primeiro arq : \n");
   scanf("%s", &nome_arq1);
   strcat(nome_arq1,".txt");
   printf("Digite o nome do segundo arq : \n");
   scanf("%s", &nome_arq2);
   strcat(nome_arq2,".txt");

   printf("Digite um numero inteiro: \n");
   scanf("%d", &valor);

   FILE* arq1 = fopen(nome_arq1,"r");
   FILE* arq2 = fopen(nome_arq2,"r");

   int arranjo1[80];
   int arranjo2[80];
   int arranjo3[80];

   int quantidade2 = 0;
   int quantidade3 = 0;

   int count2 = 0;
   int count3 = 0;
   int teste = 0;

   if (arq1 == NULL){
      printf("ERRO! arq nao existe!\n");
   }
   else{
      printf("O primeiro arq e valido\n");
      while (!(feof(arq1))){
         fscanf(arq1,"%d\n",&arranjo1[qualquer->count]);
         qualquer->count++;
         qualquer->quantidade++;
      }
   }

   if (arq2 == NULL){
      printf("ERRO! arq nao existe!\n");
   }
   else{
      printf("O segundo arq e valido\n");
      while (!(feof(arq2))){
         fscanf(arq2,"%d\n",&arranjo2[count2]);
         count2++;
         quantidade2++;
      }
   }

   fclose(arq1);
   fclose(arq2);

   qualquer->count = 0;
   count2 = 0;
   count3 = 0;

   if (qualquer->quantidade == quantidade2){
      count3 = Exemplo1014(qualquer->count, qualquer->quantidade, arranjo3, count3, arranjo1, valor, arranjo2, count2);
   }
   else{
      printf("Os arranjos nao sao compativeis\n");
      printf("Nao e possivel fazer a operacao desejada !\n");
   }

   free(qualquer);
}

int Exemplo1015(int count, int quantidade, int arranjo[], int teste){
   for (count = 0; count < quantidade - 1; count++){
      if (arranjo[count] < arranjo[count+1]){
         teste++;
      }
   }
   return (teste);
}

void Metodo05 (){
   char nome_arq[80];

   printf("Digite o nome do arq : \n");
   scanf("%s", &nome_arq);
   strcat(nome_arq,".txt");

   FILE* arq = fopen(nome_arq,"r");

   int arranjo[80];
   int teste = 0;

   arranjo1 *qualquer = newArranjo1();

   if (arq == NULL){
      printf("ERRO! arq nao existe!\n");
   }
   else{
      printf("O arq e valido\n");
      while (!(feof(arq)))
      {
         fscanf(arq,"%d\n",&arranjo[qualquer->count]);
         qualquer->count++;
         qualquer->quantidade++;
      }
   }

   fclose(arq);

   teste = Exemplo1015(qualquer->count, qualquer->quantidade, arranjo, teste);

   if (teste == qualquer->quantidade - 1){
      printf(" esta em ordem crescente");
   }
   else{
      printf(" nao esta em ordem crescente");
   }

   free(qualquer);

}

int **Exemplo1016(matriz1 quadro,int **matriz){
   int count1;
   int count2;

   for (count1 = 0; count1 < quadro.colunas; count1++){
      for (count2 = 0; count2 < quadro.linhas; count2++){
         matriz[count1][count2] = quadro.matriz[count2][count1];
      }
   }

   return matriz;
}


void Metodo06 (){
   char nome_arq[80];
   int count1 = 0;
   int count2 = 0;
   int i;
   int j;

   printf("Digite o nome do arq : \n");
   scanf("%s", &nome_arq);
   strcat(nome_arq,".txt");

   FILE* arq = fopen(nome_arq,"r");

   matriz1 quadro;
   matriz1 q2;

   if (arq == NULL){
      printf("ERRO! arq nao existe!\n");
   }
   else{
      printf("O arq e valido\n");
      fscanf(arq,"%d\n",&quadro.linhas);
      fscanf(arq,"%d\n",&quadro.colunas);
      q2.linhas=quadro.colunas;
      q2.colunas=quadro.linhas;
   }

   quadro.matriz = (int **)malloc(quadro.linhas*sizeof(int));
   q2.matriz = (int **)malloc(q2.linhas*sizeof(int));

   for( i = 0 ; i < quadro.linhas; i++){
      quadro.matriz[i] = (int *)malloc(quadro.colunas*sizeof(int));
   }
   for( i = 0 ; i < q2.linhas; i++){
      q2.matriz[i] = (int *)malloc(q2.colunas*sizeof(int));
   }
   for (count1 = 0; count1 < quadro.linhas; count1++){
      for (count2 = 0; count2 < quadro.colunas; count2++){
         fscanf(arq, "%d", &quadro.matriz[count1][count2]);
      }
   }

   count1 = 0;
   count2 = 0;

   q2.matriz = Exemplo1016(quadro,q2.matriz);

   for (count1 = 0; count1 < q2.linhas; count1++){
      for (count2 = 0; count2 < q2.colunas; count2++){
         printf("%d ", q2.matriz[count1][count2]);
      }
      printf("\n");
   }

   fclose(arq);

   for( i = 0 ; i < quadro.linhas; i++){
      free(quadro.matriz[i]);
   }
   for( i = 0 ; i < q2.linhas; i++){
      free(q2.matriz[i]);
   }

   free(quadro.matriz);
   free(q2.matriz);
}

int Exemplo1017(matriz1 quadro, int teste){
   int count1;
   int count2;

   for (count1 = 0; count1 < quadro.linhas; count1++){
      for (count2 = 0; count2 < quadro.colunas; count2++){
         if (quadro.matriz[count1][count2] == 0){
            teste = teste + 1;
         }
      }
   }

   return teste;
}


void Metodo07 (){
   char nome_arq[80];
   int count1 = 0;
   int count2 = 0;
   int i;
   int j;
   int teste = 0;

   printf("Digite o nome do arq a ser lido: \n");
   scanf("%s", &nome_arq);
   strcat(nome_arq,".txt");

   FILE* arq = fopen(nome_arq,"r");

   matriz1 quadro;
   matriz1 q2;

   if (arq == NULL){
      printf("ERRO! arq nao existe!\n");
   }
   else{
      printf("O arq e valido\n");
      fscanf(arq,"%d\n",&quadro.linhas);
      fscanf(arq,"%d\n",&quadro.colunas);
      q2.linhas=quadro.colunas;
      q2.colunas=quadro.linhas;
   }

   quadro.matriz = (int **)malloc(quadro.linhas*sizeof(int));
   q2.matriz = (int **)malloc(q2.linhas*sizeof(int));

   for( i = 0 ; i < quadro.linhas; i++){
      quadro.matriz[i] = (int *)malloc(quadro.colunas*sizeof(int));
   }

   for( i = 0 ; i < q2.linhas; i++){
      q2.matriz[i] = (int *)malloc(q2.colunas*sizeof(int));
   }

   for (count1 = 0; count1 < quadro.linhas; count1++){
      for (count2 = 0; count2 < quadro.colunas; count2++){
         fscanf(arq, "%d", &quadro.matriz[count1][count2]);
      }
   }

   teste = Exemplo1017(quadro, teste);

   if (teste == (quadro.linhas*quadro.colunas)){
      printf("A Matriz contem todos os numeros  iguais a zero");
   }
   else{
      printf("A Matriz nao contem todos os numeros iguais a zero");
   }

   fclose(arq);

   for( i = 0 ; i < quadro.linhas; i++){
      free(quadro.matriz[i]);
   }

   for( i = 0 ; i < q2.linhas; i++){
      free(q2.matriz[i]);
   }

   free(quadro.matriz);
   free(q2.matriz);

}

int Exemplo1018(int p1, int p2, int j1, int j2, matriz1 q1, matriz1 q2, int teste){
p1 = 0;
p2 = 0;
j1 = 0;
j2 = 0;

   if (q1.linhas == q2.linhas && q1.colunas == q2.colunas){
      for (p1 = 0; p1 < q1.linhas; p1++){
         for (j1 = 0; j1 < q1.colunas; j1++){
            if (q1.matriz[p1][j1] == q2.matriz[p1][j1]){
               teste++;
            }
            else{  }
         }
      }
   }
   return teste;
}


void Metodo08 (){
   char nome_arq1[80];
   char nome_arq2[80];
   int count1 = 0;
   int count2 = 0;
   int p1 = 0;
   int j1 = 0;
   int p2 = 0;
   int j2 = 0;
   int teste = 0;

   printf("Entrar com primeiro valor: \n");
   scanf("%s", &nome_arq1);
   strcat(nome_arq1,".txt");

   printf("Entrar com segundo valor: \n");
   scanf("%s", &nome_arq2);
   strcat(nome_arq2,".txt");

   FILE* arq1 = fopen(nome_arq1,"r");
   FILE* arq2 = fopen(nome_arq2,"r");

   matriz1 q1;
   matriz1 q2;

   if (arq1 == NULL){
      printf("ERRO! Arquivo inexistente!\n");
   }
   else{
      printf(" eh valido\n");
      fscanf(arq1,"%d\n",&q1.linhas);
      fscanf(arq1,"%d\n",&q1.colunas);
   }

   if (arq2 == NULL){
      printf("ERRO! Arquivo inexistente!\n");
   }
   else{
      printf(" eh valido\n");
      fscanf(arq2,"%d\n",&q2.linhas);
      fscanf(arq2,"%d\n",&q2.colunas);
   }

   q1.matriz = (int **)malloc(q1.linhas*sizeof(int));
   q2.matriz = (int **)malloc(q2.linhas*sizeof(int));

   for( p1 = 0 ; p1 < q1.linhas; p1++){
      q1.matriz[p1] = (int *)malloc(q1.colunas*sizeof(int));
   }

   for( p2 = 0 ; p2 < q2.linhas; p2++){
      q2.matriz[p2] = (int *)malloc(q2.colunas*sizeof(int));
   }

   for (p1 = 0; p1 < q1.linhas; p1++){
      for (j1 = 0; j1 < q1.colunas; j1++){
         fscanf(arq1, "%d", &q1.matriz[p1][j1]);
      }
   }

   for (p2 = 0; p2 < q2.linhas; p2++){
      for (j2 = 0; j2 < q2.colunas; j2++){
         fscanf(arq2, "%d", &q2.matriz[p2][j2]);
      }
   }

   teste = Exemplo1018(p1, p2, j1, j2, q1, q2, teste);

   if (teste == (q1.linhas*q1.colunas)){
      printf(" Matrizes iguais");
   }
   else{
      printf(" Matrizes diferentes");
   }

   fclose(arq1);
   fclose(arq2);

   for( p1 = 0 ; p1 < q1.linhas; p1++){
      free(q1.matriz[p1]);
   }

   for( p2 = 0 ; p2 < q2.linhas; p2++){
      free(q2.matriz[p2]);
   }
   free(q1.matriz);
   free(q2.matriz);
}

int **Exemplo1019(matriz1 q1, matriz1 q2, int **matriz, int valor){
   int count1;
   int count2;

   for (count1 = 0; count1 < q1.linhas; count1++){
      for (count2 = 0; count2 < q1.colunas; count2++){
         matriz[count1][count2] = q1.matriz[count1][count2] + (valor*q2.matriz[count1][count2]);
      }
   }

   return matriz;
}


void Metodo09 (){
   char nome_arq1[80];
   char nome_arq2[80];
   int count1 = 0;
   int count2 = 0;
   int p1 = 0;
   int j1 = 0;
   int p2 = 0;
   int j2 = 0;
   int p3 = 0;
   int j3 = 0;
   int valor = 0;

   printf("Entrar com primeiro valor: \n");
   scanf("%s", &nome_arq1);
   strcat(nome_arq1,".txt");

   printf("Entrar com segundo valor: \n");
   scanf("%s", &nome_arq2);
   strcat(nome_arq2,".txt");

   printf("Digite um valor para multiplicar a matriz 2: \n");
   scanf("%d", &valor);

   FILE* arq1 = fopen(nome_arq1,"r");
   FILE* arq2 = fopen(nome_arq1,"r");

   matriz1 q1;
   matriz1 q2;
   matriz1 q3;

   if (arq1 == NULL){
      printf("ERRO! arq nao existe!\n");
   }
   else{
      printf(" eh valido\n");
      fscanf(arq1,"%d\n", &q1.linhas);
      fscanf(arq1,"%d\n", &q1.colunas);
      q3.linhas = q1.linhas;
      q3.colunas = q1.colunas;
   }

   if (arq2 == NULL){
      printf("ERRO! arq nao existe!\n");
   }
   else{
      printf("eh valido\n");
      fscanf(arq2,"%d\n", &q2.linhas);
      fscanf(arq2,"%d\n", &q2.colunas);
   }

   q1.matriz = (int **)malloc(q1.linhas*sizeof(int));
   q2.matriz = (int **)malloc(q2.linhas*sizeof(int));
   q3.matriz = (int **)malloc(q3.linhas*sizeof(int));

   for( p1 = 0 ; p1 < q1.linhas; p1++){
      q1.matriz[p1] = (int *)malloc(q1.colunas*sizeof(int));
   }

   for( p2 = 0 ; p2 < q2.linhas; p2++){
      q2.matriz[p2] = (int *)malloc(q2.colunas*sizeof(int));
   }

   for( p3 = 0 ; p3 < q3.linhas; p3++){
      q3.matriz[p3] = (int *)malloc(q3.colunas*sizeof(int));
   }

   for (count1 = 0; count1 < q1.linhas; count1++){
      for (count2 = 0; count2 < q1.colunas; count2++){
         fscanf(arq1, "%d", &q1.matriz[count1][count2]);
      }
   }

   for (count1 = 0; count1 < q2.linhas; count1++){
      for (count2 = 0; count2 < q2.colunas; count2++){
         fscanf(arq2, "%d", &q2.matriz[count1][count2]);
      }
   }

   count1 = 0;
   count2 = 0;

   q3.matriz = Exemplo1019(q1, q2, q3.matriz, valor);

   for (count1 = 0; count1 < q3.linhas; count1++){
      for (count2 = 0; count2 < q3.colunas; count2++){
         printf("%d ", q3.matriz[count1][count2]);
      }
      printf("\n");
   }

   fclose(arq1);
   fclose(arq2);

   for( p1 = 0 ; p1 < q1.linhas; p1++){
      free(q1.matriz[p1]);
   }

   for( p2 = 0 ; p2 < q2.linhas; p2++){
      free(q2.matriz[p2]);
   }

   for( p3 = 0 ; p3 < q3.linhas; p3++){
      free(q3.matriz[p3]);
   }

   free(q1.matriz);
   free(q2.matriz);
   free(q3.matriz);

}

int **Exemplo1020(matriz1 q1, matriz1 q2, int **matriz, int temp, int k1, int k2, int i){
   for (k1 = 0; k1 < q1.linhas; k1++){
      for (k2 = 0; k2 < q2.colunas; k2++){
         temp = 0;
         for (i = 0; i < q1.colunas; i++){
            temp = temp + q1.matriz[k1][i]*q2.matriz[i][k2];
         }
         matriz[k1][k2] = temp;
      }
   }

   return matriz;
}


void Metodo10 (){
   char nome_arq1[80];
   char nome_arq2[80];
   int count1 = 0;
   int count2 = 0;
   int p1 = 0;
   int j1 = 0;
   int p2 = 0;
   int j2 = 0;
   int p3 = 0;
   int j3 = 0;
   int k1 = 0;
   int k2 = 0;
   int i = 0;
   int temp = 0;

   printf("Digite o nome do primeiro arq a ser lido: \n");
   scanf("%s", &nome_arq1);
   strcat(nome_arq1,".txt");

   printf("Digite o nome do segundo arq a ser lido: \n");
   scanf("%s", &nome_arq2);
   strcat(nome_arq2,".txt");

   FILE* arq1 = fopen(nome_arq1,"r");
   FILE* arq2 = fopen(nome_arq1,"r");

   matriz1 q1;
   matriz1 q2;
   matriz1 q3;

   if (arq1 == NULL){
      printf("ERRO! arq nao existe!\n");
   }
   else{
      printf("O arq e valido\n");
      fscanf(arq1,"%d\n",&q1.linhas);
      fscanf(arq1,"%d\n",&q1.colunas);
      q3.linhas = q1.linhas;
   }

   if (arq2 == NULL){
      printf("ERRO! arq nao existe!\n");
   }
   else{
      printf("O arq e valido\n");
      fscanf(arq2,"%d\n",&q2.linhas);
      fscanf(arq2,"%d\n",&q2.colunas);
      q3.colunas = q2.colunas;
   }

   q1.matriz = (int **)malloc(q1.linhas*sizeof(int));
   q2.matriz = (int **)malloc(q2.linhas*sizeof(int));
   q3.matriz = (int **)malloc(q3.linhas*sizeof(int));

   for( p1 = 0 ; p1 < q1.linhas; p1++){
      q1.matriz[p1] = (int *)malloc(q1.colunas*sizeof(int));
   }

   for( p2 = 0 ; p2 < q2.linhas; p2++){
      q2.matriz[p2] = (int *)malloc(q2.colunas*sizeof(int));
   }

   for( p3 = 0 ; p3 < q3.linhas; p3++){
      q3.matriz[p3] = (int *)malloc(q3.colunas*sizeof(int));
   }

   for (count1 = 0; count1 < q1.linhas; count1++){
      for (count2 = 0; count2 < q1.colunas; count2++){
         fscanf(arq1, "%d", &q1.matriz[count1][count2]);
      }
   }

   for (count1 = 0; count1 < q2.linhas; count1++){
      for (count2 = 0; count2 < q2.colunas; count2++){
         fscanf(arq2, "%d", &q2.matriz[count1][count2]);
      }
   }

   count1 = 0;
   count2 = 0;

   q3.matriz = Exemplo1020(q1, q2, q3.matriz, temp, k1, k2, i);

   for (count1 = 0; count1 < q3.linhas; count1++){
      for (count2 = 0; count2 < q3.colunas; count2++){
         printf("%d ", q3.matriz[count1][count2]);
      }
      printf("\n");
   }

   fclose(arq1);
   fclose(arq2);

   for( p1 = 0 ; p1 < q1.linhas; p1++){
      free(q1.matriz[p1]);
   }

   for( p2 = 0 ; p2 < q2.linhas; p2++){
      free(q2.matriz[p2]);
   }

   for( p3 = 0 ; p3 < q3.linhas; p3++){
      free(q3.matriz[p3]);
   }

   free(q1.matriz);
   free(q2.matriz);
   free(q3.matriz);

}

int main (){
   int opcao = 0;
   do{
      printf("Opcao 0 - FINALIZAR\n");
      printf("Opcao 1 - Metodo 01 \n");
      printf("Opcao 2 - Metodo 02 \n");
      printf("Opcao 3 - Metodo 03\n");
      printf("Opcao 4 - Metodo 04 \n");
      printf("Opcao 5 - Metodo 05 \n");
      printf("Opcao 6 - Metodo 06 \n");
      printf("Opcao 7 - Metodo 07 \n");
      printf("Opcao 8 - Metodo 08 \n");
      printf("Opcao 9 - Metodo 09 \n");
      printf("Opcao 10 - Metodo 10 \n");
      printf("Entrar com um valor: \n");
   
      scanf("%i", &opcao);
   
      switch (opcao){
         case 0:
            break;
         case 1:
            Metodo01();
            break;
         case 2:
            Metodo02();
            break;
         case 3:
            Metodo03();
            break;
         case 4:
            Metodo04();
            break;
         case 5:
            Metodo05();
            break;
         case 6:
            Metodo06();
            break;
         case 7:
            Metodo07();
            break;
         case 8:
            Metodo08();
            break;
         case 9:
            Metodo09();
            break;
         case 10:
            Metodo10();
            break;
         default:
            printf("OPCAO INVALIDA\n");
      }
   }while (opcao !=0);
   
   return (0);
}
   
