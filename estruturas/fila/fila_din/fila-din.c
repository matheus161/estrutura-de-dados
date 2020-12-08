#include<stdio.h>
#include<stdlib.h>
#include "fila-din.h"

struct fila{
    struct elemento *inicio;
    struct elemento *final;
};

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

Fila* cria_Fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if (fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
    }
    return fi;
};

void libera_Fila(Fila* fi){
    if (fi != NULL){
        Elem* no;
        while (fi->inicio != NULL)
        {
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int tamanho_Fila(Fila* fi){
    if (fi == NULL) return 0;
    int cont = 0;
    Elem* no = fi->inicio;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}
// Fila dinâmica nuunca está cheia
int Fila_cheia(Fila* fi){
    return 0;
}

int Fila_vazia(Fila* fi){
    if(fi == NULL) return 1;
    if(fi->inicio == NULL)
        return 1;
    return 0;
}

int insere_Fila(Fila* fi, struct aluno al){
    if(fi == NULL) return 0;//checando se a fila foi criada
    Elem* no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL) return 0; //checando alocação
    no->dados = al;
    no->prox = NULL;
    if (fi->final == NULL)//fila vazia
    {
        fi->inicio = no;
    } else {
        fi->final->prox = no;
        fi->final = no;
        return 1;
    }
}

remove_Fila(Fila* fi){
    if(fi == NULL) return 0;//problema na criação da fila
    if(fi->inicio == NULL)//fila vazia, não consigo remover
        return 0;
    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if (fi->inicio == NULL)//fila ficou vazia
        fi->final = NULL;
    free(no);
    return 1;    
}

int consulta_Fila(Fila* fi, struct aluno *al){
    if(fi == NULL) return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    *al = fi->inicio->dados;
    return 1;
}

//programa principal 
int main(){
    Fila *fi;//ponteiro nó descritor
    fi = cria_Fila();
    libera_Fila(fi);
    int x = tamanho_Fila(fi);
    int x = Fila_cheia(fi);
    int x = Fila_vazia(fi);
    // int x = insere_Fila(fi, dados_alunos);
    int x = remove_Fila(fi);
    // int x = consulta_Fila(fi, &dados_alunos);
}