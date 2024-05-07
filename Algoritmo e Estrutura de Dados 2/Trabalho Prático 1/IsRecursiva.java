class IsRecursiva {

    // Primeira chamada recursiva, retornando contador e booleano definido
    public static boolean isVogal(String s){
        boolean vogal = true;
        return isVogal(s,0,vogal);
    }
    
    // Verifica se a string só possui vogais
    public static boolean isVogal(String s, int i, boolean vogal) {

        if (i < s.length()) { 

            char c = s.charAt(i);

            if ((c != 'a') && (c != 'A') && (c != 'E') && (c != 'e') && (c != 'I') && (c != 'i') && (c != 'O')
                    && (c != 'o') && (c != 'U') && (c != 'u')) {

                vogal = false;
            }

            vogal = isVogal(s, i + 1, vogal); // Chamada recursiva 
        }
         
        return vogal;
    }

    // Primeira chamada recursiva, retornando contador e booleano definido
    public static boolean isConsoante (String s){
        boolean consoante = true;
        return isConsoante(s,0,consoante);
    }
    
    // Verifica se a string só tem consoantes
    public static boolean isConsoante(String s, int i, boolean consoante) {

        if (i < s.length()) {

            char c = s.charAt(i);
            
            if(!((c>='b' && c<='d') || (c>='f' && c<='h') || (c>='j' && c<='n') || (c>='p' && c<='t') || (c>='v' && c<='z') ||
                 (c>='B' && c<='D') || (c>='F' && c<='H') || (c>='J' && c<='N') || (c>='P' && c<='T') || (c>='V' && c<='Z'))){
                
                consoante = false;
            }
            
            consoante = isConsoante(s, i + 1, consoante); // Chamada recursiva
        }
        
        return consoante;
    }

    // Primeira chamada recursiva, retornando contador e booleano definido
    public static boolean isInteiro (String s){
        boolean inteiro = true;
        return isInteiro(s,0,inteiro);
    }

    // Verifica se a string é um número inteiro
    public static boolean isInteiro(String s, int i, boolean inteiro) {

        if (i < s.length()) 
        {              
            if(!(s.charAt(i) >= '0' && s.charAt(i) <= '9')){
                inteiro = false;
            }
            
            inteiro = isInteiro(s,i+1,inteiro); // Chamada recursiva
            
        }
        return inteiro;
    }

    // Primeira chamada recursiva, retornando contador e booleano definido
    public static boolean isFloat (String s){
        boolean real = true;
        int ponto = 0;
        int virgula = 0;
        return isFloat(s,0,real,ponto,virgula);
    }

    // Verifica se a string é um número real
    public static boolean isFloat(String s, int i, boolean real, int ponto, int virgula) {

        if(i < s.length()){
            
            if(!((s.charAt(i) >= '0' && s.charAt(i) <= '9') || (s.charAt(i) == '.') || (s.charAt(i) == ','))){
                real = false;
            }

            if(s.charAt(i) == '.'){ 
                ponto++;
            }

            if(s.charAt(i) == ','){ 
                virgula++;
            }

            real = isFloat(s, i + 1, real, ponto, virgula);

        }

        if(ponto > 1 || virgula > 1){
            real = false;
        }

        return real;
    }

    // Verifica se é o FIM
    public static boolean isFim(String s) {
        return (s.length() >= 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M');
    }

    public static void main(String args[]) {

        String[] entrada = new String[1000];
        int numEntrada = 0;

        // Leitura da entrada padrao
        do {
            entrada[numEntrada] = MyIO.readLine();
        } while (isFim(entrada[numEntrada++]) == false);

        numEntrada--;

        for (int i = 0; i < numEntrada; i++) {

            if (isVogal(entrada[i])) // Testa se é composto apenas por vogais
                MyIO.print("SIM ");
            else
                MyIO.print("NAO ");

            if (isConsoante(entrada[i])) // Testa se é composto apenas por consoantes
                MyIO.print("SIM ");
            else
                MyIO.print("NAO ");

            if(isInteiro(entrada[i])) //Testa se é um número inteiro
                MyIO.print("SIM ");
            else 
                MyIO.print("NAO ");

            if(isFloat(entrada[i])) // Testa se é um número real
                MyIO.print("SIM");
            else 
                MyIO.print("NAO");
            
            MyIO.print("\n"); // Quebra de linha padrão

        }

    }
}