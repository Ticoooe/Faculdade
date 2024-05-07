import java.io.BufferedReader;
import java.io.IOException;
import java.io.File;
import java.io.InputStreamReader;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Date;

/**
 * Lista estatica com alocacao sequencial
 * 
 * @author Lucas Bottrel Lopes de Moura
 * @version 1 09/03/2020
 */
class Lista {
    private Personagem[] array;
    private int n;

    int comp = 0;
    int mov = 0;

    /**
     * Construtor da classe.
     */
    public Lista() {
        this(6);
    }

    /**
     * Construtor da classe.
     * 
     * @param tamanho Tamanho da lista.
     */
    public Lista(int tamanho) {
        array = new Personagem[tamanho];
        n = 0;
    }

    /**
     * Insere um elemento na primeira posicao da lista e move os demais elementos
     * para o fim da lista.
     * 
     * @param p Personagem elemento a ser inserido.
     * @throws Exception Se a lista estiver cheia.
     */
    public void inserirInicio(Personagem p) throws Exception {

        // validar insercao
        if (n >= array.length) {
            throw new Exception("Erro ao inserir!");
        }

        // levar elementos para o fim do array
        for (int i = n; i > 0; i--) {
            array[i] = array[i - 1];
        }

        array[0] = p;
        n++;
    }

    /**
     * Insere um elemento na ultima posicao da lista.
     * 
     * @param p Personagem elemento a ser inserido.
     * @throws Exception Se a lista estiver cheia.
     */
    public void inserirFim(Personagem p) throws Exception {

        // validar insercao
        if (n >= array.length) {
            throw new Exception("Erro ao inserir!");
        }

        array[n] = p;
        n++;
    }

    /**
     * Insere um elemento em uma posicao especifica e move os demais elementos para
     * o fim da lista.
     * 
     * @param p   Personagem elemento a ser inserido.
     * @param pos Posicao de insercao.
     * @throws Exception Se a lista estiver cheia ou a posicao invalida.
     */
    public void inserir(Personagem p, int pos) throws Exception {

        // validar insercao
        if (n >= array.length || pos < 0 || pos > n) {
            throw new Exception("Erro ao inserir!");
        } else

        // levar elementos para o fim do array
        for (int i = n; i > pos; i--) {
            array[i] = array[i - 1];
        }

        array[pos] = p;
        n++;

    }

    /**
     * Remove um elemento da primeira posicao da lista e movimenta os demais
     * elementos para o inicio da mesma.
     * 
     * @return resp Personagem elemento a ser removido.
     * @throws Exception Se a lista estiver vazia.
     */
    public String removerInicio() throws Exception {

        // validar remocao
        if (n == 0) {
            throw new Exception("Erro ao remover!");
        }

        String resp = array[0].getNome();
        n--;

        for (int i = 0; i < n; i++) {
            array[i] = array[i + 1];
        }

        return resp;
    }

    /**
     * Remove um elemento da ultima posicao da lista.
     * 
     * @return resp Personagem elemento a ser removido.
     * @throws Exception Se a lista estiver vazia.
     */
    public String removerFim() throws Exception {

        // validar remocao
        if (n == 0) {
            throw new Exception("Erro ao remover!");
        }
        
        n--;

        return array[n].getNome();
    }

    /**
     * Remove um elemento de uma posicao especifica da lista e movimenta os demais
     * elementos para o inicio da mesma.
     * 
     * @param pos Posicao de remocao.
     * @return resp Personagem elemento a ser removido.
     * @throws Exception Se a lista estiver vazia ou a posicao for invalida.
     */
    public String remover(int pos) throws Exception {

        // validar remocao
        if (n == 0 || pos < 0 || pos >= n) {
            throw new Exception("Erro ao remover!");
        }

        String resp = array[pos].getNome();
        n--;

        for (int i = pos; i < n; i++) {
            array[i] = array[i + 1];
        }

        return resp;
    }

    /**
     * Mostra os elementos da lista separados por espacos.
     */
    public void mostrar() {
        for (int i = 0; i < n; i++) {
            // MyIO.print("[" + i + "]");
            array[i].Imprime();
        }
    }

    // Ordena dois subarrays da lista. 
    // O primeiro subarray vai de esq ate pivo 
    // O segundo subarray vai de pivo+1 ate dir
    void merge(int esq, int pivo, int dir) 
    { 
        // Tamanho dos arrays 
        int n1 = pivo - esq + 1; 
        int n2 = dir - pivo; 
  
        // Cria arrays temporarios de personagens
        Personagem L[] = new Personagem [n1]; 
        Personagem R[] = new Personagem [n2]; 
  
        // clona personagens para o array temporario
        for (int i=0; i<n1; ++i){ 
            L[i] = array[esq + i].Clone();mov++;}
        
        for (int j=0; j<n2; ++j){ 
            R[j] = array[pivo + 1+ j].Clone();mov++;}
  
  
        //Ordena array temporario
  
        //Indices inicias do primeiro e segundo arrays;
        int i = 0, j = 0; 
  
        //Indice inicial do subarray a ser ordenado
        int k = esq;
        while (i < n1 && j < n2) 
        {   comp++;
            if (L[i].getHomeWorld().compareTo(R[j].getHomeWorld()) <= 0) { 
                array[k] = L[i]; i++; mov++; 
            } else { 
                array[k] = R[j]; j++; mov++;
            } 
            k++; 
        }
        
        //Copia elementos restantes do array L[] de volta para o array 
        while (i < n1) 
        { 
            array[k] = L[i]; mov++;
            i++; 
            k++; 
        }
        
        //Copia elementos restantes do array R[] de volta para o array
        while (j < n2) 
        { 
            array[k] = R[j]; mov++;
            j++; 
            k++; 
        }
        
    } 

    /**
     * Ordenacao atraves do metodo MergeSort
     */
    public void MergeSortRec(int esq,int dir) 
    {   
        if (esq < dir) 
        { 
            // posicao do meio
            int pivo = (esq+dir)/2; 
  
            // ordena primeira e segunda metade
            MergeSortRec(esq, pivo); 
            MergeSortRec(pivo+1, dir); 
  
            // divide outras metades
            merge(esq, pivo, dir); 
        }      
    }

    /**
     * Primeira chamada para recursividade
     */
    public String MergeSort(){
        
        MergeSortRec(0,n-1);
        
        int inicio = 0; int fim = 0;

        for (int i = 0; i <= n; i++){
            comp++;
            if (i < n - 1 && array[i].getHomeWorld().equals(array[i+1].getHomeWorld())){
                inicio = i; fim = i; int j = i;
                comp++; int k = -1;
                while ((j < n-1) && array[j].getHomeWorld().equals(array[j+1].getHomeWorld())){
                    fim++; j++; k++;
                }
                if (k!=-1){
                    comp += k;
                }
                
                insercao(inicio,fim);
                i = fim;
            }
        }

        return ("COMPARACOES:" + comp + "   MOVIMENTACOES:" + mov);
    }

    /**
	 * Algoritmo de ordenacao por insercao.
	 */
	public void insercao(int inicio, int fim) {
        
        for (int i = inicio+1; i <= fim; i++) {
			Personagem tmp = array[i]; mov++;
            int j = i - 1;
            comp++; int k = -1;
            while ((j >= inicio) && (array[j].getNome().compareTo(tmp.getNome()) > 0)) {
                array[j + 1] = array[j]; k++; mov++;
                j--;
            }
            if (k!=0){
                comp += k;
            }
            array[j + 1] = tmp; mov++;
      }
	}
}

/**
 * Classe em Java
 * 
 * @author Lucas Bottrel Lopes de Moura
 * @version 1 06/03/2020
 */
class Personagem {

    // Declaracao de variáveis
    private String nome;
    private int altura;
    private double peso;
    private String corDoCabelo;
    private String corDaPele;
    private String corDosOlhos;
    private String anoNascimento;
    private String genero;
    private String homeworld;

    /**
     * Construtor sem parametros
     */
    public Personagem() {
        this.altura = 0;
        this.peso = 0;
        this.nome = this.corDoCabelo = this.corDaPele = "";
        this.corDosOlhos = this.anoNascimento = this.genero = this.homeworld = "";
    }

    /**
     * Captura informacoes uteis da string para setar
     * 
     * @param h    altura
     * @param nome nome
     * @param p    peso
     * @param cab  cor do cabelo
     * @param pel  cor da pele
     * @param ol   cor dos olhos
     * @param ano  ano de nascimento
     * @param gen  genero
     * @param home homeworld
     */
    public Personagem(int h, String nome, double p, String cab, String pel, String ol, String ano, String gen,
            String home) {
        this.nome = nome;
        this.altura = h;
        this.peso = p;
        this.corDoCabelo = cab;
        this.corDaPele = pel;
        this.corDosOlhos = ol;
        this.anoNascimento = ano;
        this.genero = gen;
        this.homeworld = home;
    }

    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getAltura() {
        return this.altura;
    }

    public void setAltura(int h) {
        this.altura = h;
    }

    public double getPeso() {
        return this.peso;
    }

    public void setPeso(double p) {
        this.peso = p;
    }

    public String getcorDoCabelo() {
        return this.corDoCabelo;
    }

    public void setcorDoCabelo(String cab) {
        this.corDoCabelo = cab;
    }

    public String getcorDaPele() {
        return this.corDaPele;
    }

    public void setcorDaPele(String pel) {
        this.corDaPele = pel;
    }

    public String getcorDosOlhos() {
        return this.corDosOlhos;
    }

    public void setcorDosOlhos(String ol) {
        this.corDosOlhos = ol;
    }

    public String getAnoNascimento() {
        return this.anoNascimento;
    }

    public void setAnoNascimento(String ano) {
        this.anoNascimento = ano;
    }

    public String getGenero() {
        return this.genero;
    }

    public void setGenero(String genero) {
        this.genero = genero;
    }

    public String getHomeWorld() {
        return this.homeworld;
    }

    public void setHomeWorld(String home) {
        this.homeworld = home;
    }

    /**
     * Escreve atributos do objeto Personagem
     */
    public void Imprime() {

        MyIO.print(" ## " + this.nome);
        MyIO.print(" ## " + this.altura);
        if ((int) this.peso == this.peso) {
            MyIO.print(" ## " + (int) this.peso);
        } else
            MyIO.print(" ## " + this.peso);
        MyIO.print(" ## " + this.corDoCabelo);
        MyIO.print(" ## " + this.corDaPele);
        MyIO.print(" ## " + this.corDosOlhos);
        MyIO.print(" ## " + this.anoNascimento);
        MyIO.print(" ## " + this.genero);
        MyIO.print(" ## " + this.homeworld);
        MyIO.print(" ## ");
        MyIO.println(""); // Quebra de linha
    }

    /**
     * Leitura do conteudo do arquivo lido
     * 
     * @param CaminhoArquivo string com caminho do arquivo.
     */
    public String Ler(String CaminhoArquivo) throws IOException {

        File fileDir = new File(CaminhoArquivo);
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream(fileDir), "UTF-8"));

        String dados = in.readLine();

        in.close();

        return dados;
    }

    /**
     * Clona Personagem já criado.
     */
    protected Personagem Clone() {
        Personagem clone = new Personagem();
        clone.nome = this.nome;
        clone.altura = this.altura;
        clone.peso = this.peso;
        clone.corDoCabelo = this.corDoCabelo;
        clone.corDaPele = this.corDaPele;
        clone.corDosOlhos = this.corDosOlhos;
        clone.anoNascimento = this.anoNascimento;
        clone.genero = this.genero;
        clone.homeworld = this.homeworld;
        return clone;
    }
}

class TP02Q17MergeSort {
    
    public static void SetAtributos(Personagem P1, int mod, String atrib) {

        String unknown = "unknown";

        if (mod == 1) { // nome
            P1.setNome(atrib);
        }

        if (mod == 2) { // altura

            if (atrib.equals(unknown)) {
                atrib = "0";
            }
            P1.setAltura(Integer.parseInt(atrib));
        }

        if (mod == 3) { // peso

            if (atrib.equals(unknown)) {
                atrib = "0";
            }

            atrib = atrib.replaceAll(",", "");

            P1.setPeso(Double.parseDouble(atrib));
        }

        if (mod == 4) { // Cor do cabelo
            P1.setcorDoCabelo(atrib);
        }

        if (mod == 5) { // Cor da pele
            P1.setcorDaPele(atrib);
        }

        if (mod == 6) { // Cor dos olhos
            P1.setcorDosOlhos(atrib);
        }

        if (mod == 7) { // Ano da Nascimento
            P1.setAnoNascimento(atrib);
        }

        if (mod == 8) { // Genero
            P1.setGenero(atrib);
        }

        if (mod == 9) { // Homeworld
            P1.setHomeWorld(atrib);
        }
    }

    /**
     * Retira informacoes uteis da string lida do arquivo.
     * 
     * @param P1 Objeto personagem aberto.
     * @param s  String com o conteudo do arquivo
     */
    public static void retiraInformacoes(Personagem P1, String s) {

        int j = 0;

        for (int i = 0, cont = 1; cont <= 9; i++) {

            if (s.charAt(i) == ':') {
                String aux = "";
                j = i + 3; // começo da informação

                while (s.charAt(j) != '\'') {
                    aux += s.charAt(j);
                    j++;
                }

                SetAtributos(P1, cont, aux);
                cont++;
            }
        }
    }

    /**
     * Cria Personagem
     * 
     * @param path String com caminho do objeto a ser criado
     * @return Personagem criado
     */
    public static Personagem CriaPersonagem(String path) throws IOException {

        Personagem P1 = new Personagem();
        String dados = P1.Ler(path);

        retiraInformacoes(P1, dados);

        return P1;
    }

    // Verifica se e ou nao o das entradas
    public static boolean isFim(String s) {
        return (s.length() >= 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M');
    }

    public static void main(String[] args) throws Exception {

        MyIO.setCharset("UTF-8");
        String[] entrada = new String[1000];
        int numEntrada = 0;
        Lista personagens = new Lista(100);

        long comeco = new Date().getTime();

        // Leitura da entrada padrao
        do {
            entrada[numEntrada] = MyIO.readLine();
        } while (isFim(entrada[numEntrada++]) == false);
        numEntrada--; // Desconsiderar ultima linha contendo a palavra FIM

        // Para cada linha de entrada, cria um personagem com o caminho lido e o insere na lista
        for (int i = 0; i < numEntrada; i++) {

            Personagem P = CriaPersonagem(entrada[i]);
            personagens.inserirFim(P);
        }

        FileWriter arq = new FileWriter("matricula_mergesort.txt");
        PrintWriter gravarArq = new PrintWriter(arq);
        
        String compmov = personagens.MergeSort();

        long fim = new Date().getTime();

        gravarArq.print("MATRICULA: 655310\tTEMPO DE EXECUCAO: " + (fim-comeco)/1000.0 + "s\t" + compmov);

        personagens.mostrar();

        arq.close();
    }
}