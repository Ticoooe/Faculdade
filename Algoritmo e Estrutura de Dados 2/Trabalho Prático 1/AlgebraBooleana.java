class AlgebraBooleana{
    
    public static String CriaString(int inicio, int fim, String s, char valor){

        String NovaString = "";
        
        for (int i = 0; i < inicio; i++){
             NovaString += s.charAt(i);
        }
        
        NovaString += valor;
        
        for (int i = fim + 1; i < s.length(); i++){
            NovaString += s.charAt(i);
        }

        return NovaString;
    }
    
    
    public static void ReduzExpressao (String s){
        
        int in = 0; int fi = 0; // inicio e fim da expressao

        do{
            for (int i = 0; i < s.length(); i++){
                
                if(s.charAt(i) == 'n' && s.charAt(i+1)== 'o' && s.charAt(i+2) == 't' && s.charAt(i+3) == '(' && s.charAt(i+4) == '0' && s.charAt(i+5) == ')'){ // NOT(0)
                    in = i; fi = i+5;
                    s = CriaString(in,fi,s,'1');}
                
                if(s.charAt(i) == 'n' && s.charAt(i+1)== 'o' && s.charAt(i+2) == 't' && s.charAt(i+3) == '(' && s.charAt(i+4) == '1' && s.charAt(i+5) == ')'){ // NOT(1)
                    in = i; fi = i+5;
                    s = CriaString(in,fi,s,'0');}

                if(s.charAt(i) == 'o' && s.charAt(i+1)== 'r' && s.charAt(i+2) == '(' && (s.charAt(i+3) == '0' || s.charAt(i+3) == '1')){ // OR
                    
                    in = i;
                
                    boolean is01 = true; String subString = ""; 

                    int k = i+3;

                    while(is01 == true && s.charAt(k) != ')'){

                        if(s.charAt(k) == '0'){
                            subString += '0';
                            k++;}
                        
                        if(s.charAt(k) == '1'){
                            subString += '1';
                            k++;}
                        
                        if(s.charAt(k) != '1' && s.charAt(k) != '0'){
                            is01 = false;}
                        k++;
                    }

                    fi = k;

                    if (is01 == true){

                        boolean is0 = true;

                        for (int j = 0; j < subString.length(); j++){
                            
                            if (subString.charAt(j) != '0')
                                is0 = false;
                        }

                        if (is0 == true){
                            s = CriaString(in,fi,s,'0');}
                        else{
                            s = CriaString(in,fi,s,'1');}
                    }
                }

                if(s.charAt(i) == 'a' && s.charAt(i+1)== 'n' && s.charAt(i+2) == 'd' && s.charAt(i+3) == '(' && (s.charAt(i+4) == '0' || s.charAt(i+4) == '1')){ // AND
                    
                    in = i;
                
                    boolean is01 = true; String subString = ""; 

                    int l = i+4;

                    while(is01 == true && s.charAt(l) != ')'){

                        if(s.charAt(l) == '0'){
                            subString += '0';
                            l++;}
                        
                        if(s.charAt(l) == '1'){
                            subString += '1';
                            l++;}
                        
                        if(s.charAt(l) != '1' && s.charAt(l) != '0'){
                            is01 = false;}
                        
                        l++;
                    }
                    fi = l;

                    if (is01 == true){    
                        
                        boolean is1 = true;

                        for (int j = 0; j < subString.length(); j++){
                            if (subString.charAt(j) != '1')
                                is1 = false;
                        }

                        if (is1 == true){
                            s = CriaString(in,fi,s,'1');}
                        else{
                            s = CriaString(in,fi,s,'0');}
                       
                    }
                }
                    
            }
        }while(s.length() > 1);

       MyIO.println(s);
  
    }
    
    // Troca um caracter por outro em uma String e retorna a String com a alteracao
    public static String MyReplace(String s, char letra, char novaLetra){

        String NovaString = "";

        for (int i = 0; i < s.length(); i++){
            if (s.charAt(i) == letra){
                NovaString += novaLetra;
            }
            else NovaString += s.charAt(i);
        }

        return NovaString;
    }
    
    // Troca variáveis por valores booleanos
    public static String VarreString(String s, char[] bin){
        
        for(int i = 0; i < s.length(); i++){

            if(s.charAt(i) == 'A'){
                s = MyReplace(s,'A', bin[0]);
            }
            if(s.charAt(i) == 'B'){
                s = MyReplace(s,'B', bin[1]);
            }
            if(s.charAt(i) == 'C'){
                s = MyReplace(s,'C', bin[2]);
            }
            if(s.charAt(i) == 'D'){
                s = MyReplace(s,'D', bin[3]);
            }
            if(s.charAt(i) == 'E'){
                s = MyReplace(s,'E', bin[4]);
            }
           
        }

        return s;
    }
    
    // Retira informacoes importantes da entrada
    public static void DesmembraString(String s){

        int num = Integer.parseInt(String.valueOf(s.charAt(0)));// Numero de variáveis
        char[] bin = new char[num]; int cont = 0; int a = 1;

            do{
                bin[cont] = s.charAt(a); // Valores binarios
                cont++;a++;

            }while(cont != num);
        
        String Expressao = "";
        for(int i = num+1; i < s.length(); i++){ // Reescreve apenas a expressao booleana
            Expressao += s.charAt(i);
        }
        
        ReduzExpressao(VarreString(Expressao,bin));
        
    }

    // Remove caracter passado como parametro e retorna a string sem ele
    public static String RemoveChar(String s, char c){
            
        String NovaString = "";

        for (int i = 0; i < s.length(); i++){
            if(s.charAt(i) != c){
                NovaString += s.charAt(i);
            }
        }

        return NovaString;
    }
    
    // Verifica se é o FIM
    public static boolean isFim(String s) {
        return (s.charAt(0) == 0);
    }
    public static void main (String[] args){
        String[] entrada = new String[1000];
        int numEntrada = 0;
   
        //Leitura da entrada padrao
        do {
           entrada[numEntrada] = MyIO.readLine();
        } while (isFim(entrada[numEntrada++]) == false);
        numEntrada--;   //Desconsiderar ultima linha contendo o digíto 0
        
        for (int i = 0; i < numEntrada; i++) {
            DesmembraString(RemoveChar(RemoveChar(entrada[i],','),' '));

        }
    }
}