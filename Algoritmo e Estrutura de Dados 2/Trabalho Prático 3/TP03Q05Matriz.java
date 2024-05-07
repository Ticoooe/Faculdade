class Celula 
{
   public int elemento;
   public Celula prox;
   public Celula ant;
   public Celula sup;
   public Celula inf;
   
   public Celula(){
      this(0, null, null, null, null);
   }

   public Celula (int x){
      this (x, null, null, null, null);
   }

   public Celula(int x, Celula prox, Celula ant, Celula sup, Celula inf){
      this.elemento = x;
      this.prox = prox;
      this.ant = ant;
      this.sup = sup;
      this.inf = inf;
   }

   public void set(int i){
      this.elemento = i;
   }

   public int get(){
      return this.elemento;
   }
}

class Matriz
{
   private Celula primeira = new Celula();
   private Celula ultima;
   private Celula aux;
   private Celula embaixo;
   public int linhas, colunas;


   public Matriz(){
      this(2, 2);
   }

   public Matriz (int linhas, int colunas){ 
      
      this.linhas = linhas;
      this.colunas = colunas;

      for (int i = 0; i < linhas; i++){

         for (int j = 0; j < colunas; j++){
            
            if (i == 0){
               
               if (j == 0){
                  this.primeira = new Celula();
                  aux = primeira;
                  embaixo = primeira;

               }else{
                  Celula celula = new Celula(); 
                  aux.prox = celula; 
                  aux.prox.ant = aux; 
                  aux = aux.prox; 
               }
            
            } else { 
               
               Celula celula = new Celula(); 
               aux.inf = celula; 
               celula.sup = aux; 
 
               if (j != 0){
                  aux.ant.inf.prox = celula; 
                  celula.ant = aux.ant.inf; 
               }
               if (aux.prox != null) aux = aux.prox;
            }
         } 

         if (i != 0)
         {
            embaixo = embaixo.inf;
         }

         aux = embaixo;
      }   
   }
   
   public void Set(){
      
      int elemento = 0;
      Celula coluna = new Celula();
      Celula linha = primeira;
      
      for (int i = 0; i < this.linhas; i++, linha = linha.inf)
      {
         coluna = linha;
         for (int j = 0; j < this.colunas; j++, coluna = coluna.prox)
         {
            elemento = MyIO.readInt();
            coluna.set(elemento);
         }
      } 
   }

   public int Get(int pLinha, int pColuna){
      
      int resp = 0;
      Celula i;
      Celula p = primeira;
      
      for (int l = 0; l < pLinha; p = p.inf, l++)
      {
         i = p;
         for (int j = 0; j < pColuna; i = i.prox, j++)
         {
            System.out.println (i.get());
            resp = i.get();
         }
      }

      return resp;
   }

   public void Imprimir(){
      
      Celula i;
      Celula p = primeira;
      for (int l = 0; l < linhas; p = p.inf, l++)
      {
         i = p;
         for (int j = 0; j < colunas; i = i.prox, j++)
         { 
            System.out.print(i.get() + " ");
         }

         System.out.println("");
      }
   }

   public Matriz Soma (Matriz m)
   {
      Matriz resp = new Matriz(this.linhas, this.colunas);
    
      if(this.linhas == m.linhas && this.colunas == m.colunas)
      {
         Celula A1 = this.primeira; 
         Celula A2 = A1; 
       
         Celula B1 = m.primeira; 
         Celula B2 = B1; 

         Celula C1 = resp.primeira;
         Celula C2 = C1;
         

         for (int i = 0; i < this.linhas; i++, A1 = A1.inf, B1 = B1.inf, C1 = C1.inf ){
            
            A2 = A1; B2 = B1; C2 = C1;
            
            for (int j = 0; j < this.colunas; j++, A2 = A2.prox, B2 = B2.prox, C2 = C2.prox){
               C2.elemento = A2.elemento + B2.elemento;
            }
         }
      }
   
      return resp;
   }


   public Matriz Multiplicacao(Matriz m) { 
      
      Matriz resp = new Matriz(this.linhas, this.colunas);
    
      if(this.linhas == m.linhas && this.colunas == m.colunas) {
         
         Celula A = this.primeira; 
         Celula i = A; 
       
         Celula B = m.primeira; 
         Celula j = B;         
         Celula manterB = B;  

         Celula C = resp.primeira; 
         Celula manterC = C;
         Celula aux = C;  
         
         int elemento = 0;
         
         for (int conti = 0; conti < this.linhas; A = A.inf, B = manterB, C = manterC.inf, conti++){
            
            manterB = B;
            manterC = C;
         
            for(int cont = 0; cont < this.colunas; cont++, B = B.prox, C = C.prox)
            {       
               i = A; j = B; aux = C; elemento = 0;
             
               for( ; i != null; i = i.prox, j = j.inf){
                  elemento = elemento + (i.elemento * j.elemento);
               }
          
               aux.elemento = elemento;
               aux = aux.prox;
            }
         }
      }
      return resp;
   }
   
   public void DiagonalPrincipal(){
      
      if (isQuadrada()){
         
         for (Celula i = primeira; i != null; i = i.inf){
            
            System.out.print (i.get() + " ");
            if (i.prox != null){
               i = i.prox;
            }
         }
         System.out.println ("");
      } 
   }
   
   public void DiagonalSecundaria(){
      
      if (isQuadrada()){
         
         Celula i = primeira;
         for ( ; i.prox != null; i = i.prox); 
         
         for ( ; i != null; i = i.inf){
            System.out.print (i.elemento + " ");
            
            if (i.ant != null){
               i = i.ant;
            }
         }
         System.out.println ("");
      }
   }

   public boolean isQuadrada()
   {
      return (this.linhas == this.colunas);

   }
}

class TP03Q05Matriz
{
   public static void main (String[] args)
   {
      int numeroTestes = MyIO.readInt();

      for (int i = 0; i < numeroTestes; i++)
      {
         int linhas = MyIO.readInt();
         int colunas = MyIO.readInt();
      
         Matriz matriz = new Matriz(linhas, colunas);
         matriz.Set();
      
         linhas = MyIO.readInt();
         colunas = MyIO.readInt();
      
         Matriz matriz2 = new Matriz(linhas, colunas);
         matriz2.Set();
         
         matriz.DiagonalPrincipal();
         matriz.DiagonalSecundaria();

         Matriz resp = matriz.Soma(matriz2);
         resp.Imprimir();
 
         resp = matriz.Multiplicacao(matriz2);
         resp.Imprimir();
      }
   }
}
