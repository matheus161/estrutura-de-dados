#include<stdio.h>
#include<stdlib.h>

int main() {
    /* Serve  alocar ou realocar memória
     Você pode mudar o tamanho dele 
     Ela faz o pedido de memória ao computador
     e retorna um ponteiro com o endereço do 
     início do espaço de emória alocado. */ 

     /*Recebe por paramêtro
        - ponteiro para um bloco de memória já alocado
        - a quantidade de bytes a ser alocadda e retorna
        - NULL: no caso de erro;
        - ponteiro para a primeira posição do array */

    /* Exemplo:
    * Cria um array de 50 inteiros (200 bytes)
        int * v = (int *) malloc(200);
    * Aumenta a memória alocada para
        v = (int *) realloc(v, 400);  
    */

    /*Para alocar memória com o realloc:
        p = (int *) realloc(NULL, 50*sizeof(int)); 
    * Equivale a 
        p = (int *) malloc(50*sizeof(int));
    */
    
    /*O realloc também pode liberar memória da mesma forma 
    como a função free()
        p = (int *) realloc(p,0);
    * Equivale a
        free(p);  
    */

   /*Aumentando a posição de um ponteiro 
        int *p = (int *) malloc(5*sizeof(int)) - Alocando com 5 posições
    * Preciso de mais espaço:
        int *p1 = (int *) realloc(p,15*sizeof(int)) -- Copia dos dados p p/ p1
    if(p1 != NULL){
        p = p1;
    }
    free(p);
    */
}