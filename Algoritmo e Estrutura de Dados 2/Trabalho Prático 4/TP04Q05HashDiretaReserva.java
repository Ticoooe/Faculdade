import java.io.BufferedReader;
import java.io.IOException;
import java.io.File;
import java.io.InputStreamReader;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Date;


/**
 * Classe Hash 
 */
class Hash {
    Personagem tabela[]; // tabela propriamente dita
    int m1, // area principal
        m2, // area reserva
        m,  // area total
        reserva; // contador de reserva
    Personagem NULO = new Personagem(0, "a", 0, "a", "a", "a", "a", "a", "a");
 
    public Hash (){
       this(13, 7);
    }
 
    /**
     * Construtor da classe Hash
     * @param m1 Area principal
     * @param m2 Area reserva
     */
    public Hash (int m1, int m2){
        this.m1 = m1;
        this.m2 =  m2;
        this.m = m1 + m2;
        this.tabela = new Personagem [this.m];

        for(int i = 0; i < m; i++){
            tabela[i] = NULO;
        }

        reserva = 0;
    }
 
    /**
     * Retorna a posição na tabela
     * @param altura altura do personagem 
     * @return int posição na tabela
     */
    public int h(int altura){
       return altura % m1;
    }

    /**
     * Mostra os elementos da tabela
     */
    public void mostrar(){
        
        for (int i = 0; i < m; i++){
            tabela[i].Imprime();
        }
    }
    
    /**
     * Inserir um Personagem na tabela Hash
     * @param elemento Personagem a ser inserido
     * @return booleano confirmação de inserção
     */
    public boolean inserir (Personagem elemento){
        boolean resp = false;
 
        if(elemento.getNome() != NULO.getNome()){
 
            int pos = h(elemento.getAltura());
 
            if(tabela[pos] == NULO){
                tabela[pos] = elemento;
                resp = true;
 
            } else if (reserva < m2){
                tabela[m1 + reserva] = elemento;
                reserva++;
                resp = true;
             }
        }
 
        return resp;
    }

    /**
     * Pesquisar um nome na tabela Hash
     * @param nome Nome de pesquisa no Hash
     * @return resp booleano com resultado da busca
     */
    public boolean pesquisar (String nome){
       
        boolean resp = false;
 
        for (int i = 0; i < m; i++){
            if (tabela[i].getNome().equals(nome)){
                resp = true;
            }
        }
        
        return resp;
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

class TP04Q05HashDiretaReserva{
    
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
        Hash hash = new Hash(21,9);

        // Leitura da entrada padrao
        do {
            entrada[numEntrada] = MyIO.readLine();
        } while (isFim(entrada[numEntrada++]) == false);
        numEntrada--; // Desconsiderar ultima linha contendo a palavra FIM

        // Para cada linha de entrada, cria um personagem com o caminho lido e o insere no hash
        for (int i = 0; i < numEntrada; i++) {

            hash.inserir(CriaPersonagem(entrada[i]));
        }


        String[] pesquisa = new String[1000];
        int numpes = 0;
        
        // Leitura da entrada padrao
        do {
            pesquisa[numpes] = MyIO.readLine();
        } while (isFim(pesquisa[numpes++]) == false);
        numpes--; // Desconsiderar ultima linha contendo a palavra FIM

        for (int i = 0; i < numpes; i++) {

            MyIO.print(pesquisa[i]);
            boolean resp = hash.pesquisar(pesquisa[i]);

            if (resp == true) MyIO.print(" SIM\n");
            else MyIO.print(" N" + (char)195 + "O\n");
        }
    }
}