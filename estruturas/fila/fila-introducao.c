#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

//Declarando um nó
typedef struct NO {
    int dado;
    struct NO *prox;
}NO;

// Declarando a fila
typedef struct FILA{
    NO *ini;
    NO *fim;
}FILA;

void iniciliza_fila(FILA *f){
    f->ini = NULL;
    f->fim = NULL;
}

//Efileira recebe o dado e a fila(que possui ini e fim)
void enfileira(int dado, FILA *f){
    // Ponteiro recebe um novo no
    NO *ptr = (NO*) malloc(sizeof(NO));
    if (ptr == NULL){
        printf("Erro de alocaçãoo.\n");
        return;
    } else {
        // Fila estando vazia
        // Preciso inicialar o nó
        ptr->dado = dado;
        ptr->prox = NULL;
        if (f->ini == NULL){
            // Se ini for NULL, estou inserindo o primeiro dos nós
            // Então faço ele apontar pro novo nó
            f->ini = ptr;
        } else {
            // Se eu não estiver inserindo o primeiro elemento
            // Preciso apontar o fim para o novo elemento 
            f->fim->prox = ptr;
        }
        f->fim = ptr;
        return;
    }    
}

// Para desenfileirar eu preciso que meu inicio aponte para
// o próximo elemento da fila
// Faço o nó apontar para NULL
// Retorno para quem deseja ser desenfileirado
// Elimino o nó(Usando free)

//Digo de qual fila eu quero desenfileirar
int desenfileira(FILA *f){
    NO *ptr = f->ini;
    int dado;
    if (ptr != NULL){
        // Se for != de NULL, ele tem algum elemento para remover
        f->ini = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        if (f->ini == NULL){
            f->fim = NULL;
        }
        return dado;
    } else {
        printf("Fila vazia. \n");
        return;
    }    
}

void imprime_fila(FILA *f){
    NO *ptr = f->ini;
    if (ptr != NULL){
        while (ptr != NULL){
            printf("%d ", ptr->dado);
            ptr = ptr->prox;
        }        
    } else {
        printf("Fila vazia. \n");
        return;
    }    
}

int main(){
    FILA *f1 = (FILA*) malloc(sizeof(FILA));
    if (f1 == NULL){
        printf("Erro de alocacao. \n");
        exit(-1);
    } else {
        iniciliza_fila(f1);

        enfileira(10, f1);
        enfileira(20, f1);
        enfileira(30, f1);

        imprime_fila(f1);

        printf("\nTentando desenfileirar - resultado: %d \n",desenfileira(f1));
        imprime_fila(f1);
        printf("\nTentando desenfileirar - resultado: %d \n",desenfileira(f1));
        imprime_fila(f1);
        printf("\nTentando desenfileirar - resultado: %d \n",desenfileira(f1));
        imprime_fila(f1);
        
    }    
}