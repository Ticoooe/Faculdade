package client;

import java.io.*;
import java.net.*;

public class ClientConn {
    private static final String SERVIDOR_IP = "127.0.0.1";
    private static final int PORTA_DO_SERVIDOR = 9871;
    
    Socket socket;
    DataOutputStream saida;
    BufferedReader entrada;

    public ClientConn(MainInterface mi) {
        try {
            socket = new Socket(SERVIDOR_IP, PORTA_DO_SERVIDOR);
            saida = new DataOutputStream(socket.getOutputStream());
            entrada = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            
            Thread threadReceptora = new Thread(() -> {
                try {
                    String message;
                    while ((message = entrada.readLine()) != null) {
                        System.out.println("Servidor: " + message);
                        // Read Array
                        String[] list = message.split(";");
                        mi.UpdateList(list);
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            });
            threadReceptora.start();
            
            mi.createAndShowGUI();
            mi.addListeners(
                e-> { Send("A", mi.CurrentMessage().trim()); },
                e-> { Send("D", mi.CurrentMessage().trim()); }
                );

            mi.show();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void Send(String comando, String mensagem) {
        String msg = comando + ";" + mensagem + "\n";
        try {
            saida.writeBytes(msg);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}