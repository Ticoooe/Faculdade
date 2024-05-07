class Is {

    // Verifica se a string só possui vogais
    public static boolean isVogal(String s) {

        boolean isVogal = true;
        int i = 0;

        while (isVogal && i < s.length()) { // Enquanto estiver lendo vogais e ainda tem caracteres na string

            char c = s.charAt(i);

            if ((c != 'a') && (c != 'A') && (c != 'E') && (c != 'e') && (c != 'I') && (c != 'i') && (c != 'O')
                    && (c != 'o') && (c != 'U') && (c != 'u')) {

                isVogal = false;
            }

            i++;
        }

        return isVogal;
    }

    // Verifica se a string só tem consoantes
    public static boolean isConsoante(String s) {

        boolean isConsoante = true;
        int i = 0;

        while (isConsoante && i < s.length()) { // Enquanto estiver lendo consoantes e ainda tiver caracteres na string

            char c = s.charAt(i);
            
            if(!((c>='b' && c<='d') || (c>='f' && c<='h') || (c>='j' && c<='n') || (c>='p' && c<='t') || (c>='v' && c<='z') ||
                 (c>='B' && c<='D') || (c>='F' && c<='H') || (c>='J' && c<='N') || (c>='P' && c<='T') || (c>='V' && c<='Z')))
                
                isConsoante = false;
            
            i++;
        }
        return isConsoante;
    }

    // Verifica se a string é um número inteiro
    public static boolean isInteiro(String s) {

        boolean isInteiro = true;
        int i = 0;

        while (i < s.length() && isInteiro) // Enquanto for inteiro e existir caracteres na string
        {              
            if(!(s.charAt(i) >= '0' && s.charAt(i) <= '9'))
                isInteiro = false; 
            
            i++;
        }

        return isInteiro;
    }

    // Verifica se a string é um número real
    public static boolean isFloat(String s) {

        boolean isFloat = true;
        int ponto = 0;
        int virgula = 0;
        int i = 0;

        while(i < s.length() && isFloat){ // Enquanto for float e existir caracteres na string
            
            if(!((s.charAt(i) >= '0' && s.charAt(i) <= '9') || (s.charAt(i) == '.') || (s.charAt(i) == ','))){
                isFloat = false;
            }

            if(s.charAt(i) == '.'){ 
                ponto++;
            }

            if(s.charAt(i) == ','){ 
                virgula++;
            }

            i++;
        }

        if(ponto > 1 || virgula > 1){
            isFloat = false;
        }

        return isFloat;
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