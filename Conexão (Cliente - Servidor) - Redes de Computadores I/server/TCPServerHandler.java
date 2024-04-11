package server;

import java.io.*;
import java.net.*;

public class TCPServerHandler implements Runnable {
    private Socket clienteSocket;

    public TCPServerHandler(Socket clienteSocket) {
        this.clienteSocket = clienteSocket;
    }

    public void run() {
        try {
            PrintWriter saida = new PrintWriter(clienteSocket.getOutputStream(), true);
            BufferedReader entrada = new BufferedReader(new InputStreamReader(clienteSocket.getInputStream()));

            String linhaDeEntrada;
            TaskList tl = new TaskList();
            while ((linhaDeEntrada = entrada.readLine()) != null) {
                System.out.println("Cliente TCP: " + linhaDeEntrada);
                String[] entradas = linhaDeEntrada.split(";");
                if (entradas.length == 2) {
                    if (entradas[0].equals("A")) tl.Add(entradas[1]);
                    else if (entradas[0].equals("D")) tl.Delete(entradas[1]);
                    
                    saida.println(tl.Read());
                }
            }

            clienteSocket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}