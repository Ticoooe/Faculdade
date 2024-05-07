import java.io.BufferedReader;
import java.io.IOException;
import java.io.File;
import java.io.InputStreamReader;
import java.io.FileInputStream;

/**
 * Lista Dupla com alocação dinâmica
 * 
 * @author Lucas Bottrel Lopes de Moura
 * @version 1 20/04/2020
 */


class ListaDupla {
    private Personagem primeiro;
    private Personagem ultimo;
    public int mov = 0;
    public int comp = 0;

    /**
     * Construtor da classe.
     */
    public ListaDupla() {
        primeiro = new Personagem();
        ultimo = primeiro;
    }

    /**
	 * Calcula e retorna o tamanho, em numero de elementos, da lista.
	 * @return resp int tamanho
	 */
    public int tamanho() {
        
        int tamanho = 0;

        for(Personagem i = primeiro; i != ultimo; i = i.prox, tamanho++);
        
        return tamanho;
 }

    /**
     * Insere um elemento na primeira posicao da lista e move os demais elementos
     * para o fim da lista.
     * 
     * @param p Personagem elemento a ser inserido.
     */
    public void inserirInicio(Personagem p){

        Personagem tmp = p;

        tmp.ant = primeiro;
        tmp.prox = primeiro.prox;
        primeiro.prox = tmp;

        if (primeiro == ultimo){
            ultimo = tmp;
        } else {
            tmp.prox.ant = tmp;
        }

        tmp = null;
    }

    /**
     * Insere um elemento na ultima posicao da lista.
     * 
     * @param p Personagem elemento a ser inserido.
     */
    public void inserirFim(Personagem p){

        ultimo.prox = p;
        ultimo.prox.ant = ultimo;
        ultimo = ultimo.prox;
    }

    /**
     * Insere um elemento em uma posicao especifica 
     * 
     * @param p   Personagem elemento a ser inserido.
     * @param pos Posicao de insercao.
     * @exception PosicaoInvalida posicao menor que 0 ou maior que tamanho
     */
    public void inserir(Personagem p, int pos) throws Exception{

        int tamanho = tamanho();

        if (pos < 0 || pos > tamanho){
            throw new Exception("Erro ao inserir posicao (" + pos + " / tamanho = " + tamanho + ") invalida!");
        } else if (pos==0){
            inserirInicio(p);
        } else if (pos == tamanho){
            inserirFim(p);
        } else {
            Personagem i = primeiro;
            for (int j = 0; j < pos; j++, i = i.prox);

            Personagem tmp = p;
            tmp.ant = i;
            tmp.prox = i.prox;
            tmp.ant.prox = tmp.prox.ant = tmp;
            tmp = i = null;
        }
    }

    /**
     * Remove um elemento da primeira posicao da lista.
     * 
     * @return (String) Nome do personagem a ser removido.
     * @throws Exception Se a lista estiver vazia.
     */
    public String removerInicio() throws Exception {

        // validar remocao
        if (primeiro == ultimo) {
            throw new Exception("Erro ao remover! (vazia)");
        }

        Personagem tmp = primeiro;
        primeiro = primeiro.prox;

        String resp = primeiro.getNome();
        tmp.prox = primeiro.ant = null;
        tmp = null;

        return resp;
    }

    /**
     * Remove um elemento da ultima posicao da lista.
     * 
     * @return resp Personagem elemento a ser removido.
     * @throws Exception Se a lista estiver vazia.
     */
    public String removerFim() throws Exception {

        if (primeiro == ultimo){
            throw new Exception("Erro ao remover (vazia)!");
        }

        String resp = ultimo.getNome();
        ultimo = ultimo.ant;
        ultimo.prox.ant = null;
        ultimo.prox = null;

        return resp;
    }

    /**
     * Remove um elemento de uma posicao especifica da lista
     * 
     * @param pos Posicao de remocao.
     * @return resp Personagem elemento a ser removido.
     * @throws Exception Se a lista estiver vazia ou a posicao for invalida.
     */
    public String remover(int pos) throws Exception {

        String resp ="";
        int tamanho = tamanho();

        if (primeiro == ultimo){
            throw new Exception("Erro ao remover (vazia)!");
        } else if (pos == 0){
            resp = removerInicio();
        } else if (pos == tamanho-1){
            resp = removerFim();
        } else {
            Personagem i = primeiro.prox;
            for (int j = 0; j < pos; j++, i = i.prox);

            i.ant.prox = i.prox;
            i.prox.ant = i.ant;
            resp = i.getNome();
            i.prox = i.ant = null;
            i = null;
        }

        return resp;
    }

    /**
     * Mostra os elementos da lista separados por espacos.
     */
    public void mostrar() {

        for (Personagem i = primeiro.prox; i != null; i=i.prox) { 
            i.Imprime(); 
        }
    }

    /**
     * Consulta a posição do Personagem na ListaDupla a partir de um numero inteiro
     * @param i (Personagem) 
     * @return Personagem na posicai (i)
     */
    Personagem posicao(int i){
        Personagem p = primeiro.prox;
        
        for (int a = 0; a < i; p = p.prox,a++);

        return p;
    }

    /**
     * Troca o conteudo dos personagens
     * 
     * @param i (Personagem)    
     * @param j (Personagem)
     */
    void swap(Personagem i, Personagem j){
        
        Personagem tmp = i.Clone();
        i.Clone(j);
        j.Clone(tmp);

    }

    /**
	 * Algoritmo de ordenacao por insercao.
	 */
	public void insercao(int inicio, int fim) {

        for (int i = inicio+1; i <= fim; i++) {
			Personagem tmp = posicao(i).Clone(); mov++;
            int j = i - 1;
            comp++; int k = -1;
            while ((j >= inicio) && (posicao(j).getNome().compareTo(tmp.getNome()) > 0)) {
                posicao(j + 1).Clone(posicao(j)); k++; mov++;
                j--;
            }
            if (k!=0){
                comp += k;
            }
            posicao(j + 1).Clone(tmp); mov++;
        }
	}

    /**
	 * Algoritmo de ordenacao Quicksort.
	 */
	public void quicksort() {
        int n = tamanho();
        
        quicksort(0, n - 1);
        
        int inicio = 0; int fim = 0;
        
        for (int i = 0; i < n; i++){
            comp++;
    
            if (i < n-1 && posicao(i).getcorDoCabelo().compareTo(posicao(i+1).getcorDoCabelo()) == 0){
                
                inicio = i; fim = i;int j = i; int k = -1; comp++;
    
                while ( j + 1 < n && posicao(j).getcorDoCabelo().compareTo(posicao(j+1).getcorDoCabelo()) == 0){
                    fim++; k++;j++;
                }
    
                if (k!= -1) comp+=k;
                i = fim;
            }
            insercao(inicio,fim);
        }       
    }

    /**
    * Algoritmo de ordenacao Quicksort.
    * @param int esq inicio da lista a ser ordenada
    * @param int dir fim da lista a ser ordenada
    */
    public void quicksort(int esq, int dir) {
        int i = esq, j = dir;

        Personagem pivo = posicao((dir+esq)/2).Clone();
        while (i <= j) {
            while (posicao(i).getcorDoCabelo().compareTo(pivo.getcorDoCabelo()) < 0) i++;
            while (posicao(j).getcorDoCabelo().compareTo(pivo.getcorDoCabelo()) > 0) j--;
            if (i <= j) {
                swap(posicao(i), posicao(j));
                i++; j--;
            }
          }
          if (esq < j)  quicksort(esq, j);
          if (i < dir)  quicksort(i, dir);
    }
}

/**
 * Classe Personagem em Java
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
    public Personagem prox;
    public Personagem ant;

    /**
     * Construtor sem parametros
     */
    public Personagem() {
        this.altura = 0;
        this.peso = 0;
        this.nome = this.corDoCabelo = this.corDaPele = "";
        this.corDosOlhos = this.anoNascimento = this.genero = this.homeworld = "";
        this.prox = null; this.ant = null;
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
    public Personagem(int h, String nome, double p, String cab, String pel, String ol, String ano, String gen, String home) {
        this.nome = nome;
        this.altura = h;
        this.peso = p;
        this.corDoCabelo = cab;
        this.corDaPele = pel;
        this.corDosOlhos = ol;
        this.anoNascimento = ano;
        this.genero = gen;
        this.homeworld = home;
        this.prox = null;
        this.ant = null;
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

    /**
     * Clona Personagem já criado.
     */
    protected void Clone(Personagem p) {
        
        this.nome = p.nome;
        this.altura = p.altura;
        this.peso = p.peso;
        this.corDoCabelo = p.corDoCabelo;
        this.corDaPele = p.corDaPele;
        this.corDosOlhos = p.corDosOlhos;
        this.anoNascimento = p.anoNascimento;
        this.genero = p.genero;
        this.homeworld = p.homeworld;
        
    }

    
}

class TP03Q04QuickSortListaDupla {

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
        ListaDupla personagens = new ListaDupla();

        // Leitura da entrada padrao
        do {
            entrada[numEntrada] = MyIO.readLine();
        } while (isFim(entrada[numEntrada++]) == false);
        numEntrada--; // Desconsiderar ultima linha contendo a palavra FIM

        // Para cada linha de entrada, cria um personagem com o caminho lido e o insere
        // na lista
        for (int i = 0; i < numEntrada; i++) {

            Personagem P = CriaPersonagem(entrada[i]);
            personagens.inserirFim(P);
        }

        personagens.quicksort();
        personagens.mostrar();
    }
}