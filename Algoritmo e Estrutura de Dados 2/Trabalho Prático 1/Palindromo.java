class Palindromo {
    public static boolean isPalind (String s){
        int tam = s.length() - 1,
        i = 0;

        boolean ehPalind = true;

        do {
            if (s.charAt(i) != s.charAt(tam)){
                ehPalind = false;}
            i++;
            tam--;
        }while (i < tam && ehPalind==true);

        return ehPalind;
    }
  
    public static boolean isFim(String s){
       return (s.length() >= 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M');
    }

    public static void Saida (boolean isPalind)
    {
        if (isPalind==true)
        {
            MyIO.println("SIM");
        }
        else MyIO.println("NAO");
    }
  
    public static void main (String[] args){
       String[] entrada = new String[1000];
       int numEntrada = 0;
  
       //Leitura da entrada padrao
       do {
          entrada[numEntrada] = MyIO.readLine();
       } while (isFim(entrada[numEntrada++]) == false);
       numEntrada--;   //Desconsiderar ultima linha contendo a palavra FIM
  
       //Para cada linha de entrada, gerando uma de saida contendo o numero de letras maiusculas da entrada
       for(int i = 0; i < numEntrada; i++){
            Saida(isPalind(entrada[i]));  
       }
    }
 }