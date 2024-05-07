import java.io.*;
import java.net.*;

class LeituraPaginaHTML{

    // Verifica se é o FIM
    public static boolean isFim(String s) {
        return (s.length() >= 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M');
    }

    public static void main(String args[]) throws Exception{

        String[] nome = new String[1000];
        String[] endereco = new String[1000];
        int numEntrada = 0;
       
        //Leitura da entrada padrao
        do {
            nome[numEntrada] = MyIO.readLine();
            if(isFim(nome[numEntrada]) == false){
                endereco[numEntrada] = MyIO.readLine();}
        } while (isFim(nome[numEntrada++]) == false);
        numEntrada--;   //Desconsiderar ultima linha contendo a palavra FIM
       
        for(int i = 0; i < numEntrada; i++){
            
            URL pagina = new URL(endereco[i]);
            BufferedReader in = new BufferedReader(new InputStreamReader(pagina.openStream()));
    
            String inputLine;
            String[] linha = new String[1000];
            int j = 0;
    
            while ((inputLine = in.readLine()) != null){
                linha[j] = inputLine;
                j++;
            }
            MyIO.println(j);

            for(int k = 0; k < j; k++){
                MyIO.println(linha[k]);
            }

            in.close();              
        }
    }
}
