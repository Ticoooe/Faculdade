import java.io.BufferedReader;
import java.io.IOException;
import java.io.File;
import java.io.InputStreamReader;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Date;

/**
 * No da arvore binaria
 * @author Max do Val Machado
 */
class No {
    public boolean cor;
    public Personagem personagem; // Conteudo do no.
	public No esq, dir;  // Filhos da esq e dir.

	/**
	 * Construtor da classe.
	 * @param p Conteudo do no.
	 */
	public No (Personagem p, boolean cor) {
        this.personagem = p;
        this.cor = cor;
        this.dir = null;
        this.esq = null;
    }
    
    /**
	 * Construtor da classe.
	 * @param p Conteudo do no.
	 */
	public No (Personagem p) {
        this.personagem = p;
        this.cor = false;
        this.dir = null;
        this.esq = null;
	}

	/**
	 * Construtor da classe.
	 * @param p Conteudo do no.
	 * @param esq No da esquerda.
	 * @param dir No da direita.
	 */
	public No(Personagem p, No esq, No dir, boolean cor) {
		this.personagem = p;
		this.esq = esq;
        this.dir = dir;
        this.cor = cor;
	}
}

/**
 * Arvore Binaria
 * 
 * @author Lucas Bottrel Lopes de Moura
 * @version 1 06/05/2020
 */
class Alvinegra{
    
    private No raiz; // Raiz da arvore.

	/**
	 * Construtor da classe.
	 */
	public Alvinegra() {
		raiz = null;
    }
    
    /**
	 * Metodo publico iterativo para pesquisar elemento.
	 * @param nome String nome que sera procurado.
	 * @return true se o elemento existir,
	 *         false em caso contrario.
	 */
	public boolean pesquisar (String nome) {
        MyIO.print(nome + " raiz ");
        return pesquisar(nome, raiz);
	}


	/**
	 * Metodo privado recursivo para pesquisar nome.
	 * @param nome String nome que sera procurado.
	 * @param i No em analise.
	 * @return true se o elemento existir,
	 *         false em caso contrario.
	 */
	private boolean pesquisar (String nome, No i) {
        
        boolean resp;

		if (i == null) {
            resp = false;

        } else if (nome.compareTo(i.personagem.getNome()) == 0) {
            resp = true;

        } else if (nome.compareTo(i.personagem.getNome()) < 0) {
            MyIO.print("esq ");
            resp = pesquisar(nome, i.esq);

        } else {
            MyIO.print("dir ");
            resp = pesquisar(nome, i.dir);
        }
        return resp;
    }
    
	/**
	 * Metodo publico iterativo para exibir elementos.
	 */
	public void mostrar() {
		mostrar(raiz);
	}

	/**
	 * Metodo privado recursivo para exibir elementos.
	 * @param i No em analise.
	 */
	private void mostrar(No i) {
		if (i != null) {
			mostrar(i.esq); // Elementos da esquerda.
			System.out.print(i.personagem.getNome() + ((i.cor) ? "(p) " : "(b) \n")); // Conteudo do no.
			mostrar(i.dir); // Elementos da direita.
		}
	}
    
    /**
	* Metodo publico iterativo para inserir elemento.
	* @param p Personagem a ser inserido.
	* @throws Exception Se o p existir.
	*/
	public void inserir(Personagem p) throws Exception {
   
        //Se a arvore estiver vazia
        if(raiz == null){
           raiz = new No(p, false);
  
        //Senao, se a arvore tiver um personagem 
        } else if (raiz.esq == null && raiz.dir == null){
            if (raiz.personagem.getNome().compareTo(p.getNome()) > 0){
                raiz.esq = new No(p, true);
    
            } else {
                raiz.dir = new No(p, true);
            }
  
        //Senao, se a arvore tiver dois elementos (raiz e dir)
        } else if (raiz.esq == null){
  
            if(raiz.personagem.getNome().compareTo(p.getNome()) > 0){
                raiz.esq = new No(p);
  
            } else if (raiz.dir.personagem.getNome().compareTo(p.getNome()) > 0){
                raiz.esq = new No(raiz.personagem);
                raiz.personagem = p;
  
            } else {
                raiz.esq = new No(raiz.personagem);
                raiz.personagem = raiz.dir.personagem;
                raiz.dir.personagem = p;
            }
  
            raiz.esq.cor = raiz.dir.cor = false;
           
        //Senao, se a arvore tiver dois elementos (raiz e esq)
        } else if (raiz.dir == null){
           
            if(raiz.personagem.getNome().compareTo(p.getNome()) < 0){
                raiz.dir = new No(p);
              
            } else if (raiz.esq.personagem.getNome().compareTo(p.getNome()) < 0){
                raiz.dir = new No(raiz.personagem);
                raiz.personagem = p;

            } else {
              raiz.dir = new No(raiz.personagem);
              raiz.personagem = raiz.esq.personagem;
              raiz.esq.personagem = p; 
            }
  
            raiz.esq.cor = raiz.dir.cor = false;
  
        //Senao, a arvore tem tres ou mais elementos
        } else {
            inserir(p, null, null, null, raiz);
        }
  
        raiz.cor = false;
    }

    /**
    * Metodo privado recursivo para inserir elemento.
    * @param p Personagem a ser inserido.
    * @param avo No em analise.
    * @param pai No em analise.
    * @param i No em analise.
    * @throws Exception Se o elemento existir.
    */
    private void inserir(Personagem p, No bisavo, No avo, No pai, No i) throws Exception {

        if (i == null) {
            if(p.getNome().compareTo(pai.personagem.getNome()) < 0){
                i = pai.esq = new No(p, true);
            } else {
                i = pai.dir = new No(p, true);
            }
            if(pai.cor == true){
                balancear(bisavo, avo, pai, i);
            }
        } else {
        //Achou um 4-no: eh preciso fragmeta-lo e reequilibrar a arvore
            if(i.esq != null && i.dir != null && i.esq.cor == true && i.dir.cor == true){
                i.cor = true;
                i.esq.cor = i.dir.cor = false;
                if(i.personagem.getNome().compareTo(raiz.personagem.getNome()) == 0){
                    i.cor = false;
                }else if(pai.cor == true){
                    balancear(bisavo, avo, pai, i);
                }
            }
        
            if (p.getNome().compareTo(i.personagem.getNome()) < 0) {
                inserir(p, avo, pai, i, i.esq);
            } else if (p.getNome().compareTo(i.personagem.getNome()) > 0) {
                inserir(p, avo, pai, i, i.dir);
            } else {
                throw new Exception("Erro inserir (elemento repetido)!");
            }
        }
    }
  
    private void balancear(No bisavo, No avo, No pai, No i){
  
        //Se o pai tambem e preto, reequilibrar a arvore, rotacionando o avo
        if(pai.cor == true){
            //4 tipos de reequilibrios e acoplamento
            if(pai.personagem.getNome().compareTo(avo.personagem.getNome()) > 0){ // rotacao a esquerda ou direita-esquerda
                if(i.personagem.getNome().compareTo(pai.personagem.getNome()) > 0){
                    avo = rotacaoEsq(avo);
                } else {
                    avo = rotacaoDirEsq(avo);
              }
  
            } else { // rotacao a direita ou esquerda-direita
                if(i.personagem.getNome().compareTo(pai.personagem.getNome()) < 0){
                    avo = rotacaoDir(avo);
                } else {
                    avo = rotacaoEsqDir(avo);
                }
            }
  
            if (bisavo == null){
                raiz = avo;
            } else {
                if(avo.personagem.getNome().compareTo(bisavo.personagem.getNome()) < 0){
                    bisavo.esq = avo;
                } else {
                    bisavo.dir = avo;
                }
            }
  
            //reestabelecer as cores apos a rotacao
            avo.cor = false;
            avo.esq.cor = avo.dir.cor = true;
           
        }
     }
  
    private No rotacaoDir(No no) {
        No noEsq = no.esq;
        No noEsqDir = noEsq.dir;
  
        noEsq.dir = no;
        no.esq = noEsqDir;
  
        return noEsq;
    }
  
    private No rotacaoEsq(No no) {
        No noDir = no.dir;
        No noDirEsq = noDir.esq;
  
        noDir.esq = no;
        no.dir = noDirEsq;
        return noDir;
    }
  
    private No rotacaoDirEsq(No no) {
        no.dir = rotacaoDir(no.dir);
        return rotacaoEsq(no);
    }
  
    private No rotacaoEsqDir(No no) {
        no.esq = rotacaoEsq(no.esq);
        return rotacaoDir(no);
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

class TP04Q04AN {
    
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
        Alvinegra arvore = new Alvinegra();

        // Leitura da entrada padrao
        do {
            entrada[numEntrada] = MyIO.readLine();
        } while (isFim(entrada[numEntrada++]) == false);
        numEntrada--; // Desconsiderar ultima linha contendo a palavra FIM

        // Para cada linha de entrada, cria um personagem com o caminho lido e o insere na lista
        for (int i = 0; i < numEntrada; i++) {

            Personagem P = CriaPersonagem(entrada[i]);
            arvore.inserir(P);
        }

        String[] pesquisa = new String[1000];
        int numpes = 0;
        
        // Leitura da entrada padrao
        do {
            pesquisa[numpes] = MyIO.readLine();
        } while (isFim(pesquisa[numpes++]) == false);
        numpes--; // Desconsiderar ultima linha contendo a palavra FIM
        
        for (int i = 0; i < numpes; i++) {

            boolean resp = arvore.pesquisar(pesquisa[i]);

            if (resp == true) MyIO.print("SIM\n");
            else MyIO.print("NAO\n");
        } 
    }
}