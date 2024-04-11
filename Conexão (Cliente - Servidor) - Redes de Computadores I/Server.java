import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

import server.TCPServerHandler;

public class Server {
    private static final int PORTA_TCP = 9871;
    public static void main(String[] args) {
        try {
            ServerSocket socketTCP = new ServerSocket(PORTA_TCP);
            System.out.println("Servidor TCP iniciado na porta " + PORTA_TCP);

            Socket clienteSocket = socketTCP.accept();
            new Thread(new TCPServerHandler(clienteSocket)).start();

            socketTCP.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.err.println("Erro ao aceitar conexão TCP: " + e.getMessage());
        }
    }
}
