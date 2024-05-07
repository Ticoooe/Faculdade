import java.util.*;
import java.io.Console;
import java.lang.String;

public class AlgebraBooleanaREC {

    //Função que converte de char para booleano
    private static boolean to_bool(char v){
        if(v == '0'){
            return false;
        }
        return true;
    }

    //Funçõ que transforma as expressoes booleanas em inteiros -> facilita pra guardar
    private static int to_int(String exp){
        if(exp.equals("and")){
            return 1;
        }else if(exp.equals("or")){
            return 2;
        }
        return 3;
    }

    //Função que recebe cada linha do input e imprime a saida
    private static int get_valor(String in_string){
        //Pilha que vai armazenar as expressoes
        Stack<Integer> p_expressoes = new Stack<Integer>();
        p_expressoes.push(0);
        //Pilha p armazenar os resultados das expressoes
        Stack<Boolean> p_resultados = new Stack<Boolean>();
        p_resultados.push(false);
        //Pilha com o numero de elementos em cada expressao
        Stack<Integer> p_num_el = new Stack<Integer>();
        p_num_el.push(0);
        //Converte o primeiro numero de char para int
        int num_entradas = Character.getNumericValue(in_string.charAt(0));
        //Cria um vetor de booleanos com o numero de entradas passado e seus respectivos valores
        Boolean[] vet_bool = new Boolean[num_entradas];
        //Itera pegando os valores 
        int i=2;
        for(int j=0; j<num_entradas; j++){
            vet_bool[j] = to_bool(in_string.charAt(i));
            i+=2;
        }
        //string auxiliar
        String aux = new String("");
        int exp;
        Boolean[] val = new Boolean[10];
        int num_el = 0;
        boolean res;
        //Enquanto i não atingir o ultimo elemento da string
        while(i < in_string.length()){
            //Se encontrar um prenteses abrindo ele empilha a expressao na pilha de expressoes
            if(in_string.charAt(i) == '('){
                //Empilha aquela expressão na pilha de expressoes
                p_expressoes.push(to_int(aux));
                //Limpa a string auxiliar
                aux = "";
                //Empilha o numero de elementos na pilha
                p_num_el.push(num_el);
                num_el = 0;
            //Se encontrar um dos valores empilha ele na pilha de valores
            }else if(in_string.charAt(i) == 'A'){
                //Empilha na pilha de resultados
                p_resultados.push(vet_bool[0]);
            }else if(in_string.charAt(i) == 'B'){
                //Empilha na pilha de resultados
                p_resultados.push(vet_bool[1]);
            }else if(in_string.charAt(i) == 'C'){
                //Empilha na pilha de resultados
                p_resultados.push(vet_bool[2]);
            //Se encontrar um parenteses fechando é pq chegou no fim de uma expressao
            }else if(in_string.charAt(i) == ')'){
                //Desempilha a ultima expressão adicionada na pilha de expressoes
                exp = p_expressoes.pop();
                //Recupera os elementos daquela expressao
                for(int k=0; k<num_el+1; k++){
                    val[k] = p_resultados.pop(); 
                }
                res = val[0];
                //Se a expressão for and
                if(exp == 1){
                    for(int k=1; k<num_el+1; k++){
                        res = res && val[k];
                    }
                //Se a expressao for or
                }else if(exp == 2){
                    for(int k=1; k<num_el+1; k++){
                        res = res || val[k];
                    }
                //Se a expressao for not       
                }else{
                    res = !res;
                }
                //Empilha o novo valor do resultado
                p_resultados.push(res);
                //Desempilha a quantidade de elementos da expressão anterior
                num_el = p_num_el.pop();
            //Se for uma virgula soma 1 ao numero de lementos naquela expressão -> o numero de elementos é o numero de virgulas + 1
            }else if(in_string.charAt(i) == ','){
                num_el++;
            //Se for um espaço pula para o proximo elemento
            }else if(in_string.charAt(i) == ' '){
            }else{
                //Armazena o char da expressão na string auxiliar
                aux += in_string.charAt(i);
            }
            //Incrementa o contador
            i++;
        }
        res = p_resultados.pop();
        //Desempilha o resultado final da pilha de resultados
        if(p_resultados.isEmpty()){
            System.out.println("----------------------");
            System.out.printf(in_string);
            System.out.println("----------------------");
        }
        else if(p_expressoes.isEmpty()){
            System.out.println("----------------------");
            System.out.printf(in_string);
            System.out.println("----------------------");
        }
        else if(p_num_el.isEmpty()){
            System.out.println("----------------------");
            System.out.printf(in_string);
            System.out.println("----------------------");
        }
        if(res){
            return 1;
        }else{
            return 0;
        }
    }

    public static void main(String[] args){
        Console cnsl = System.console();
        String tst = cnsl.readLine();
        Integer[] res = new Integer[1000];
        int i=0;
        while(!tst.equals("FIM")){
            res[i] = get_valor(tst);
            tst = cnsl.readLine();
            i++;
        }
        for(int j=0;j<i;j++){
            System.out.println(res[j]);
        }
    }
}