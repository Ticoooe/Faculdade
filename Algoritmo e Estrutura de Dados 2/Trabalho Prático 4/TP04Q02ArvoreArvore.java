import java.io.BufferedReader;
import java.io.IOException;
import java.io.File;
import java.io.InputStreamReader;
import java.io.FileInputStream;

class No {
	public int elemento; // Conteudo do no.
    public No esq, dir;  // Filhos da esq e dir.
    public No2 outro;

	/**
	 * Construtor da classe.
	 * @param p Conteudo do no.
	 */
	public No (int elemento) {
        this.elemento = elemento;
        this.esq = null;
        this.dir = null;
        this.outro = null;
	}
}

class No2 {
	public String nome; // Conteudo do no.
	public No2 esq; // No da esquerda.
	public No2 dir; // No da direita.
	
   /**
	 * Construtor da classe.
	 * @param elemento Conteudo do no.
	 */
	No2(String nome) {
		this.nome = nome;
		this.esq = this.dir = null;
	}
}

/**
 * Arvore de arvore
 * @author Max do Val Machado
 */
class ArvoreArvore {
    
    private No raiz; // Raiz da arvore.

	/**
	 * Construtor da classe.
	 */
	public ArvoreArvore() {
		raiz = null;
	}

	/**
	 * Metodo publico iterativo para pesquisar elemento.
	 * @param elemento Elemento que sera procurado.
	 * @return <code>true</code> se o elemento existir,
	 * <code>false</code> em caso contrario.
	 */
	public boolean pesquisar(String p) {
		return pesquisar(raiz, p);
	}

	private boolean pesquisar(No no, String p) {
        boolean resp;
            
        if (no == null) { 
            resp = false;

        } else { 
            resp = pesquisarSegundaArvore(no.outro, p); 
            
            if (!resp){
                System.out.print(" esq");
                resp = pesquisar(no.esq, p);
                
                if (!resp){
                    System.out.print(" dir");
                    resp = pesquisar(no.dir, p);
                } 
            }
        }

        return resp;
	}

	private boolean pesquisarSegundaArvore(No2 no, String x) {
        boolean resp;
        
        if (no == null) { 
            resp = false;

        } else {
            
            if (x.equals(no.nome)) { 
            resp = true; 

            } else{
                System.out.print(" ESQ");
                resp = pesquisarSegundaArvore(no.esq, x);
                
                if (!resp){
                    System.out.print(" DIR");
                    resp = pesquisarSegundaArvore(no.dir, x); 
                }
            } 
        }
        
        return resp;
	}

    /**
     * 
     * Inserir elemento na primeira arvore
     * @param num int
     */
    public void inserir1(int num){
        raiz = inserir1 (num, raiz);
    }

    public No inserir1 (int num, No i){

        if (i == null){
            i = new No(num);
            
        } else if (num < i.elemento) {
            i.esq = inserir1(num, i.esq);

        } else if (num > i.elemento) {
            i.dir = inserir1(num, i.dir);
        } 
        
        return i;
    }


    public void inserir2 (Personagem p){
        raiz = inserir2(p, raiz);
    }

    public No inserir2(Personagem p, No i) {
        
        
        if ((p.getAltura()%15) == i.elemento){
            i.outro = inserir3 (p.getNome(), i.outro);

        } else if ((p.getAltura()%15) < i.elemento){
            i.esq = inserir2 (p, i.esq);

        } else if ((p.getAltura()%15) > i.elemento){
            i.dir = inserir2 (p, i.dir);

        } 

        return i;
    }

    private No2 inserir3 (String nome, No2 i){

        if (i == null){
            i = new No2(nome);
        } else if (nome.compareTo(i.nome) < 0) {
            i.esq = inserir3(nome, i.esq);

        } else if (nome.compareTo(i.nome) > 0) {
            i.dir = inserir3(nome, i.dir);

        } 

        return i;
    }

    /**
	 * Metodo publico iterativo para exibir elementos.
	 */
	public void mostrar() {
		System.out.print("[ ");
		mostrar(raiz);
		System.out.println("]");
	}

	/**
	 * Metodo privado recursivo para exibir elementos.
	 * @param i No em analise.
	 */
	private void mostrar(No i) {
		if (i != null) {
			mostrar(i.esq); // Elementos da esquerda.
			mostrar(i.dir); // Elementos da direita.
			System.out.print(i.elemento + " "); // Conteudo do no.
		}
	}

}

/**
 * Classe Personagem
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

class TP04Q02ArvoreArvore{
    
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
        ArvoreArvore arvore = new ArvoreArvore();

        arvore.inserir1(7); arvore.inserir1(3); arvore.inserir1(11); arvore.inserir1(1); arvore.inserir1(7); arvore.inserir1(5);
        arvore.inserir1(9); arvore.inserir1(12); arvore.inserir1(0); arvore.inserir1(2); arvore.inserir1(4); arvore.inserir1(6);
        arvore.inserir1(8); arvore.inserir1(10); arvore.inserir1(13); arvore.inserir1(14);

        // Leitura da entrada padrao
        do {
            entrada[numEntrada] = MyIO.readLine();
        } while (isFim(entrada[numEntrada++]) == false);
        numEntrada--; // Desconsiderar ultima linha contendo a palavra FIM

        // Para cada linha de entrada, cria um personagem com o caminho lido e o insere na lista
        for (int i = 0; i < numEntrada; i++) {

            Personagem P = CriaPersonagem(entrada[i]);
            arvore.inserir2(P);
        }

        String[] pesquisa = new String[1000];
        int numpes = 0;
        
        // Leitura da entrada padrao
        do {
            pesquisa[numpes] = MyIO.readLine();
        } while (isFim(pesquisa[numpes++]) == false);
        numpes--; // Desconsiderar ultima linha contendo a palavra FIM
        
        for (int i = 0; i < numpes; i++) {

            MyIO.print(pesquisa[i] + " raiz");
            boolean resp = arvore.pesquisar(pesquisa[i]);

            if (resp){
                System.out.print(" SIM\n");
            } else System.out.print(" N"+(char)195+"O\n");

        } 
    }
}