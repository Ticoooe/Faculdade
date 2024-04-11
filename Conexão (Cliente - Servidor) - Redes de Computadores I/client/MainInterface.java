package client;

import java.awt.event.*;
import java.awt.*;
import javax.swing.*;  

public class MainInterface {
    private JFrame frame;

    JTextField inputArea;
    JTextArea outputArea; // update screen
    JButton addButton;
    JButton deleteButton;

    public void createAndShowGUI() {
        //Create and set up the window.
        frame = new JFrame("HelloWorldSwing");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
 
        //Add the ubiquitous "Hello World" label.
        // Configuração da JTextArea (diminuindo o número de linhas)
        outputArea = new JTextArea("this is outputArea", 6, 20);
        outputArea.setEditable(false); // Torna a área de texto somente leitura
        outputArea.setBorder(BorderFactory.createEtchedBorder()); // Adiciona uma borda

        // Configuração do JTextField para a entrada de texto
        inputArea = new JTextField("this is inputArea", 15);

        // Configuração do botão "Adicionar"
        addButton = new JButton("Adicionar");

        // Configuração do botão "Deletar"
        deleteButton = new JButton("Deletar");
        

        // Adiciona os componentes ao contentPane
        frame.getContentPane().setLayout(new BorderLayout());
        frame.getContentPane().add(new JScrollPane(outputArea), BorderLayout.CENTER);
        
        JPanel inputPanel = new JPanel(new FlowLayout()); // Usando FlowLayout para alinhar os componentes
        inputPanel.add(inputArea);
        inputPanel.add(addButton);
        inputPanel.add(deleteButton);
        frame.getContentPane().add(inputPanel, BorderLayout.SOUTH);

        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null);
    }

    public void addListeners(ActionListener addCommand, ActionListener delCommand) {
        addButton.addActionListener(addCommand);
        deleteButton.addActionListener(delCommand);
    }

    public String CurrentMessage() {
        String msg = inputArea.getText();
        inputArea.setText("");
        System.out.println("Current Message: " + msg);
        return msg;
    }

    public void show() {
        frame.pack();
        frame.setVisible(true);
    }

    public void UpdateList(String[] list) {
        outputArea.setText(String.join("\n", list)+"\r\n");
    }
}
