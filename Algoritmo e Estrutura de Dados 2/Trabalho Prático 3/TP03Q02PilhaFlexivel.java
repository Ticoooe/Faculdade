import java.io.RandomAccessFile;
import java.util.RandomAccess;
import java.util.Scanner;
import java.lang.Math;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.File;
import java.io.InputStreamReader;
import java.io.FileInputStream;

/**
 * Classe Personagem
 * @author Lucas Bottrel Lopes de Moura
 * @version 1 06/03/2020
 */
 
class Personagem{

    // Declaracao de variáveis
    private String nome;
    private int    altura;
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
    public Personagem (){
        this.altura = 0 ; this.peso = 0;
        this.nome = this.corDoCabelo = this.corDaPele = "";
        this.corDosOlhos = this.anoNascimento = this.genero = this.homeworld = "";
        this.prox = null;
    }

    /**
    * Captura informacoes uteis da string para setar    
    * @param h altura
    * @param nome nome
    * @param p peso
    * @param cab cor do cabelo
    * @param pel cor da pele
    * @param ol cor dos olhos
    * @param ano ano de nascimento
    * @param gen genero
    * @param home homeworld
    */
    public Personagem (int h, String nome, double p, String cab, String pel, String ol, String ano, String gen, String home){
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

    public String getNome(){
        return this.nome;
    }

    public void setNome(String nome){
        this.nome = nome;
    }
    
    public int getAltura(){
        return this.altura;
    }

    public void setAltura(int h){
        this.altura = h;
    }

    public double getPeso(){
        return this.peso;
    }

    public void setPeso(double p){
        this.peso = p;
    }

    public String getcorDoCabelo(){
        return this.corDoCabelo;
    }

    public void setcorDoCabelo(String cab){
        this.corDoCabelo = cab;
    }

    public String getcorDaPele(){
        return this.corDaPele;
    }

    public void setcorDaPele(String pel){
        this.corDaPele = pel;
    }

    public String getcorDosOlhos(){
        return this.corDosOlhos;
    }

    public void setcorDosOlhos(String ol){
        this.corDosOlhos = ol;
    }

    public String getAnoNascimento(){
        return this.anoNascimento;
    }

    public void setAnoNascimento(String ano){
        this.anoNascimento= ano;
    }

    public String getGenero(){
        return this.genero;
    }

    public void setGenero(String genero){
        this.genero = genero;
    }

    public String getHomeWorld(){
        return this.homeworld;
    }

    public void setHomeWorld(String home){
        this.homeworld = home;
    }

    /**
    * Escreve atributos do objeto Personagem
    */
    public void Imprime(){

        MyIO.print(" ## " + this.nome);
        MyIO.print(" ## " + this.altura);
        if ((int)this.peso == this.peso){
            MyIO.print(" ## " + (int)this.peso);}
            else MyIO.print(" ## " + this.peso);
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
    * @param CaminhoArquivo string com caminho do arquivo.
    */
    public String Ler(String CaminhoArquivo) throws IOException{
       
        File fileDir = new File(CaminhoArquivo); 
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream(fileDir), "UTF-8"));

        String dados = in.readLine();

        in.close();

        return dados;
    }

    /**
    * Clona Personagem já criado.  
    */
    protected Personagem Clone(){
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
        clone.prox = this.prox;
        return clone;
    }    
}

/**
 * Pilha Flexivel
 * @author Lucas Bottrel Lopes de Moura
 * @version 2 14/03
 */

class Pilha {
	public Personagem topo;

	/**
	 * Construtor da classe que cria uma fila sem elementos.
	 */
	public Pilha() {
		topo = null;
	}


	/**
	 * Insere personagem na pilha
	 * @param p (Personagem) personagem a inserir.
	 */
	public void inserir(Personagem p) {
		Personagem tmp = p;
		tmp.prox = topo;
		topo = tmp;
        tmp = null;
	}


	/**
	 * Remove elemento da pilha
	 * @return (String) Nome do personagem removido.
	 * @throws Exception Se a pilha estiver vazia.
	 */
	public void remover() throws Exception {
		if (topo == null) {
			throw new Exception("Erro ao remover!");
		}

		String resp = topo.getNome();
        Personagem tmp = topo;
		topo = topo.prox;
        tmp.prox = null;
        tmp = null;
        
        MyIO.println("(R) " + resp);
	}


	/**
	 * Mostra os elementos separados por espacos, comecando do topo.
	 */
	public void mostrar() {
        
        Personagem aux[] = new Personagem[100];

        int cont = 0;
		for(Personagem i = topo; i != null; i = i.prox){
            aux[cont] = i;
            cont++;
        }

        int j = 0;
        for (int i = cont - 1; i >= 0; i--){
            MyIO.print("[" + j + "] ");
            aux[i].Imprime(); j++;
        }
    }
}

/**
 * Classe Principal
 * @author Lucas Bottrel Lopes de Moura
 * @version 1 14/03/2020
 */
class TP03Q02PilhaFlexivel {

    /**
     * Executa comandos da entrada
     * @param s           (String) com comando dado pela entrada
     * @param personagens (Pilha) valor da memoria que aponta para a lista de personagens
     */
    public static void ExecutaComandos(String s, Pilha personagens) {

        try{
        if (s.charAt(0) == 'I') { // comando Inserir

            String aux = s.substring(2, s.length());
            
            personagens.inserir(CriaPersonagem(aux));
        }

        else if (s.charAt(0) == 'R') { // comando Remover
            
            personagens.remover();
        } 
        }catch (Exception e){

        }
    }
    
    public static void SetAtributos (Personagem P1, int mod, String atrib){

        String unknown = "unknown";
        
        if (mod == 1){ // nome
            P1.setNome(atrib);
        }

        if(mod == 2){ // altura
            
            if (atrib.equals(unknown)){
                atrib = "0";
            }
            P1.setAltura(Integer.parseInt(atrib));
        }

        if(mod == 3){ // peso
            
            if (atrib.equals(unknown)){
                atrib = "0";
            }

            atrib = atrib.replaceAll(",","");

            P1.setPeso(Double.parseDouble(atrib));
        }
                

        if(mod == 4){ // Cor do cabelo
            P1.setcorDoCabelo(atrib);
        }

        if(mod == 5){ // Cor da pele
            P1.setcorDaPele(atrib); 
        }

        if(mod == 6){ // Cor dos olhos
            P1.setcorDosOlhos(atrib);
        }

        if(mod == 7){ // Ano da Nascimento
            P1.setAnoNascimento(atrib);
        }
        
        if(mod == 8){ // Genero
            P1.setGenero(atrib);
        }
        
        if(mod == 9){ // Homeworld
            P1.setHomeWorld(atrib);
        }
    }
    
    /**
    * Retira informacoes uteis da string lida do arquivo.    
    * @param P1 Objeto personagem aberto.
    * @param s String com o conteudo do arquivo
    */
    public static void retiraInformacoes(Personagem P1, String s){
    
        int j = 0;

        for (int i = 0, cont = 1; cont <= 9; i++){
            
            if (s.charAt(i) == ':'){
                String aux = "";
                j = i+3; // começo da informação

                while (s.charAt(j) != '\''){
                    aux += s.charAt(j);
                    j++;
                }
                
                SetAtributos(P1,cont,aux);
                cont++;
            }
        }
        
    }
    
    /**
    * Cria Personagem    
    * @param path String com caminho do objeto a ser criado
    * @return Personagem criado
    */
    public static Personagem CriaPersonagem(String path) throws IOException{

        Personagem P1 = new Personagem();
        String dados = P1.Ler(path);
       
        retiraInformacoes(P1,dados);

        return P1;
    }

    /**
    * Verifica se a string é o fim da leitura de dados  
    * @param s String entrada.
    */
    public static boolean isFim(String s){
        return (s.length() >= 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M');
    }
    
    public static void main (String[] args) throws IOException{
        
        MyIO.setCharset("UTF-8");
        String[] entrada = new String[1000];
        int numEntrada = 0;
        Pilha personagens = new Pilha();

        //Leitura da entrada padrao
        do {
           entrada[numEntrada] = MyIO.readLine();
        } while (isFim(entrada[numEntrada++]) == false);
        numEntrada--;   //Desconsiderar ultima linha contendo a palavra FIM
   
        //Para cada linha de entrada, cria um personagem com o caminho do arquivo
        for(int i = 0; i < numEntrada; i++){
            
            Personagem P1 = CriaPersonagem(entrada[i]);
            try{
                personagens.inserir(P1);
            }catch(Exception e){

            }
        }

        int cont = MyIO.readInt();

        String[] entradaLista = new String[cont + 1];

        for (int i = 0; i < cont; i++){
            entradaLista[i] = MyIO.readLine();
        }
        
        // Para cada linha de entrada, executa o comando lido
        for (int i = 0; i < cont; i++) {
            
            ExecutaComandos(entradaLista[i], personagens);
        }

        personagens.mostrar();
    }
    
}

