import java.io.RandomAccessFile;

class ArquivoJava {

    public static void main(String args[]) throws Exception{

        int n = MyIO.readInt(); // Numero de entradas

        RandomAccessFile file = new RandomAccessFile("resultado.txt", "rw"); //abertura de aquivo padraão
        file.seek(0); // Começar a escrever na posição 0 do arquivo

        for(int i = 0; i < n; i++){
            
            file.writeDouble(MyIO.readDouble()); // Escreve numero lido no arquivo
        }
        
        file.close();

        RandomAccessFile file2 = new RandomAccessFile("resultado.txt", "rw"); // abertura de arquivo padrão
        int pos = n*8; // Vai começar a ler na última posição (n) * quantidade de bits de um float (8)
        
        for (; n > 0; n--){
            
            file2.seek(pos - 8); // Muda a linha de pesquisa para a ultima posicao do arquivo
            pos = pos - 8;    
            double aux = file2.readDouble(); // Leitura de float padrão
            
            if(aux == (int)aux) // Se for inteiro, printa ele como inteiro
            {
                MyIO.println((int)aux);
            }
            else 
                MyIO.println(aux); // Se não, printa ele como float
        }

        file2.close();
    }
}