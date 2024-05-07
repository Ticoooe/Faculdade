import java.util.Random;

class AlteracaoAleatoria {

    //Gera e retorna letra minuscula aleatória
    public static char Aleatorio(Random gerador){
        char letra = (char)('a' + Math.abs(gerador.nextInt()) % 26);
        return letra;
    }
    
    //Retorna a frase com as alterações feitas
    public static String FraseRandomizada(String s, Random gerador){

        char letra1 = Aleatorio(gerador);
        char letra2 = Aleatorio(gerador);
        String frase = "";

        for (int i = 0; i < s.length(); i++){
            if (s.charAt(i) == letra1){
                frase += letra2;
            }
            else{
                frase += s.charAt(i);
            }
        }
        return frase;
    }
    
    //Verifica se é o FIM
    public static boolean isFim(String s){
       return (s.length() >= 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M');
    }

    public static void main (String[] args){
       String[] entrada = new String[1000];
       int numEntrada = 0;
  
       //Leitura da entrada padrao
       do {
          entrada[numEntrada] = MyIO.readLine();
       } while (isFim(entrada[numEntrada++]) == false);
       numEntrada--; 
  
        Random gerador = new Random();
        gerador.setSeed(4);
       
       //Para cada linha de entrada, gerando uma de saida contendo o numero de letras maiusculas da entrada
       for(int i = 0; i < numEntrada; i++){
            MyIO.println(FraseRandomizada(entrada[i],gerador));  
       }
    }
 }