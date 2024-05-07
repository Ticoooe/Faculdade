import java.io.BufferedReader;
import java.io.IOException;
import java.io.File;
import java.io.InputStreamReader;
import java.io.FileInputStream;

/**
 * Lista estatica com alocacao sequencial
 * 
 * @author Lucas Bottrel Lopes de Moura
 * @version 1 09/03/2020
 */
class Lista {
    private Personagem primeiro;
    private Personagem ultimo;

    /**
     * Construtor da classe.
     */
    public Lista() {
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

        tmp.prox = primeiro.prox;
        primeiro.prox = tmp;

        if (primeiro == ultimo){
            ultimo = tmp;
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
        ultimo = ultimo.prox;
    }

    /**
     * Insere um elemento em uma posicao especifica e move os demais elementos para o fim da lista.
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
            tmp.prox = i.prox;
            i.prox = tmp;
            tmp = i = null;
        }
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
        if (primeiro == ultimo) {
            throw new Exception("Erro ao remover! (vazia)");
        }

        Personagem tmp = primeiro;
        primeiro = primeiro.prox;

        String resp = primeiro.getNome();
        tmp.prox = null;
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
        
        Personagem i;
        for (i=primeiro; i.prox != ultimo; i = i.prox);

        String resp = ultimo.getNome();
        ultimo = i;
        i = ultimo.prox = null;

        return resp;
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

        String resp ="";
        int tamanho = tamanho();

        if (primeiro == ultimo){
            throw new Exception("Erro ao remover (vazia)!");
        } else if (pos == 0){
            resp = removerInicio();
        } else if (pos == tamanho-1){
            resp = removerFim();
        } else {
            Personagem i = primeiro;
            for (int j = 0; j < pos; j++, i = i.prox);

            Personagem tmp = i.prox;
            resp = tmp.getNome();
            i.prox = tmp.prox;
            tmp.prox = null;
            i = tmp = null;
        }

        return resp;
    }

    /**
     * Mostra os elementos da lista separados por espacos.
     */
    public void mostrar() {
        int j = 0;
        for (Personagem i = primeiro.prox; i != null; i=i.prox) {
            System.out.print("[" + j + "]"); 
            i.Imprime(); j++;
        }
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

    /**
     * Construtor sem parametros
     */
    public Personagem() {
        this.altura = 0;
        this.peso = 0;
        this.nome = this.corDoCabelo = this.corDaPele = "";
        this.corDosOlhos = this.anoNascimento = this.genero = this.homeworld = "";
        this.prox = null;
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

class TP03Q01ListaFlexivel {

    /**
     * Executa comandos da entrada
     * 
     * @param s           (String) com comando dado pela entrada
     * @param personagens (Lista) valor da memoria que aponta para a lista de personagens
     */
    public static void ExecutaComandos(String s, Lista personagens) {

        try{
        if (s.charAt(0) == 'I' && s.charAt(1) == 'I') { // comando Insere no Inicio

            String aux = s.substring(3, s.length());
            
            personagens.inserirInicio(CriaPersonagem(aux));
        }

        else if (s.charAt(0) == 'I' && s.charAt(1) == 'F') { // comando Insere no Final

            String aux = s.substring(3, s.length());
                
            personagens.inserirFim(CriaPersonagem(aux));
        } 

        else if (s.charAt(0) == 'I' && s.charAt(1) == '*') { // comando Insere na posição x

            String num = "";
            int n = 3;
            for (; s.charAt(n) != ' '; n++) {
                num += s.charAt(n);
            }

            int x = Integer.valueOf(num);
            String aux = s.substring(n + 1, s.length());

            personagens.inserir(CriaPersonagem(aux), x);
        }

        else if (s.charAt(0) == 'R' && s.charAt(1) == 'I') { // comando Remove no inicio

            String nome = personagens.removerInicio();

            MyIO.println("(R) " + nome);
        }

        else if (s.charAt(0) == 'R' && s.charAt(1) == 'F') { // comando Remove no Final

            String nome = personagens.removerFim();

            MyIO.println("(R) " + nome);
        }

        else if (s.charAt(0) == 'R' && s.charAt(1) == '*') { // comando Remove na posição x

            
            String num = "";

            for (int i = 3; i < s.length(); i++) {
                num += s.charAt(i);
            }

            int x = Integer.valueOf(num);

            String nome = personagens.remover(x);

            MyIO.println("(R) " + nome);
        }
        
        } catch (Exception e){

        }
    }

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
        Lista personagens = new Lista();

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

        int n = MyIO.readInt();

        String[] entradaLista = new String[n + 1];

        for (int i = 0; i < n; i++){
            entradaLista[i] = MyIO.readLine();
        }
        
        // Para cada linha de entrada, executa o comando lido
        for (int i = 0; i < n; i++) {
            
            ExecutaComandos(entradaLista[i], personagens);
        }

        personagens.mostrar();
    }
}