#include <stdio.h>
#include <string.h>
#include "fila-estatica.h"

struct fila{
    int inicio, final, qtd;
    struct aluno dados[MAX];
};

Fila *fi;

Fila* cria_Fila(){
    Fila *fi = (Fila*) malloc(sizeof(struct fila));
        if(fi != NULL){
            fi->inicio = 0;
            fi->final = 0;
            fi->qtd = 0;
    }
    return fi;
}

void libera_Fila(Fila* fi){
    free(fi);
}

int tamanho_Fila(Fila* fi){
    if (fi == NULL)
        return -1;
    return fi->qtd;
}

int Fila_cheia(Fila* fi){
    if (fi == NULL) return -1;
    if (fi->qtd == MAX)
        return 1;
    else
        return 0;    
}

int Fila_vazia(Fila* fi){
    if (fi == NULL) return -1;
    if (fi->qtd == 0)
        return 1;
    else 
        return 0;
}

int insere_Fila(Fila*  fi, struct aluno al){
    if (fi == NULL) return 0;
    if(Fila_cheia(fi)) return 0;
    fi->dados[fi->final] = al;// Pego o elemento e coloca na posição final do vetor dados da fila
    fi->final = (fi -> final+1)%MAX;//Ando com o final para frente(posição vaga)
    fi->qtd++;    
}

int remove_Fila(Fila* fi){
    if (fi == NULL || Fila_vazia(fi))
    return 0;
    fi->inicio = (fi->inicio+1)%MAX;//Ando com o ponteiro
    fi->qtd--;
    return 1;    
}

//Só posso consultar elementos que estão no inicio
int consulta_Fila(Fila* fi, struct aluno *al){
    if (fi == NULL || Fila_vazia(fi))
        return 0;
    *al = fi->dados[fi->inicio];
    return 1;
}

int main(){
    Fila* fi;
    fi = cria_Fila();
    libera_Fila(fi);
    // int x = tamanho_Fila(fi);
    // int x = Fila_cheia(fi);
    // int x = Fila_vazia(fi);  
    //int x = insere_Fila(fi, dados_aluno);  
    // int x = remove_Fila(fi);
    // int x = consulta_Fila(fi, &dados_aluno);
    return 0;
}