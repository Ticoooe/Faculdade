class CiframentoRecursivo {

   //Primeira chamada recursiva
   public static String FraseCifrada(String s){
         String res = "";
         return FraseCifrada(s,0,res);
   } 
   
   //Retorna a frase Citada com recursão
   public static String FraseCifrada(String frase, int pos, String res)
    {
        int tam = frase.length();
        
        if(pos < tam){
           
            int ASC = (int)frase.charAt(pos);
            int aux = ASC + 3;
            res += (char)aux;
            res = FraseCifrada(frase, pos + 1, res);//res recebe o que retorna da recursão da função
        }
        

        return res;
    }
    
    //verifica se é o FIM
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
       numEntrada--;   //Desconsiderar ultima linha contendo a palavra FIM
  
       //Para cada linha de entrada, gerando uma de saida contendo a String já codificada da entrada
       for(int i = 0; i < numEntrada; i++){
            MyIO.println(FraseCifrada(entrada[i]));  
       }
    }
 }