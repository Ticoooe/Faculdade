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
    private Personagem[] array;
    private int n;

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
            MyIO.print("[" + i + "]");
            array[i].Imprime();
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

class TP02Q03ListaComAlocacaoSequencial {

    /**
     * Executa comandos da entrada
     * 
     * @param s           (String) com comando dado pela entrada
     * @param personagens (Lista) valor da memoria que aponta para a lista de
     *                    personagens
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
        Lista personagens = new Lista(100);

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