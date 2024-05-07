class PalindromoRecursivo{
    //primeira chamada recursiva
    public static boolean isPalind(String s){
        return isPalind(s, 0);
    }

    //verifica se é ou não palindromo
    public static boolean isPalind (String s, int pos){

        boolean ehPalind = true;
        int tam = s.length() - 1 - pos;//modificado aqui pra que a letra lida na direita seja a correta

        //funçao recursiva NAO NECESSITA DE estrutura de repetição
        if (pos < tam && s.charAt(pos) != s.charAt(tam))
            ehPalind = false;
            
        else if (pos < tam)
            ehPalind = isPalind(s,pos + 1);//atribuir o valor para a variavel palindromo

        return ehPalind;
    }
    
    //verifica se é o FIM
    public static boolean isFim(String s){
       return (s.length() >= 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M');
    }

    //saida padrão
    public static void Saida (boolean isPalind){
        if (isPalind == true){
            MyIO.println("SIM");
        }
        else{ 
            MyIO.println("NAO");
        }
    }
  
    public static void main (String[] args){
       String[] entrada = new String[1000];
       int numEntrada = 0;
  
       //Leitura da entrada padrao
       do{
          entrada[numEntrada] = MyIO.readLine();
       } while (isFim(entrada[numEntrada++]) == false);
       numEntrada--;   //Desconsiderar ultima linha - FIM
  
       for(int i = 0; i < numEntrada; i++){
            Saida(isPalind(entrada[i]));  
       }
    }
 }