package server;

import java.util.List;
import java.util.ArrayList;

public class TaskList {
    List<String> taskList;

    public TaskList() {
        // Inicializa o array de strings
        taskList = new ArrayList<>();
    }

    // Adiciona uma string no final do array
    public void Add(String str) {
        taskList.add(str);
    }

    // Deleta uma string do array, se existir
    public void Delete(String str) {
        taskList.remove(str);
    }

    // Retorna os elementos do array separados por ';'
    public String Read() {
        return String.join(";", taskList);
    }
}