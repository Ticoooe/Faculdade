class Ciframento {

    public static String isCiframento(String s){
        String cifra = "";
        
        for (int i = 0; i < s.length(); i++){
               int ASC = (int)s.charAt(i);
               int aux = ASC + 3;
               cifra += (char)aux;
            }
        return cifra;
    }
    
    public static boolean isFim(String s){
       return (s.length() >= 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M');
    }

    public static void main (String[] args){
       String[] entrada = new String[1000];
       int numEntrada = 0;
  
       //Leitura da entrada padrao
       do{
          entrada[numEntrada] = MyIO.readLine();
       } while (isFim(entrada[numEntrada++]) == false);
       numEntrada--;   //Desconsiderar a palavra FIM
  
       for(int i = 0; i < numEntrada; i++){
         MyIO.println(isCiframento(entrada[i]));  
       }
    }
 }