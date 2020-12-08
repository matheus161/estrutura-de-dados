#include <stdio.h>
#include <string.h>
#include "lista-din-dupla-encadeada.h"

struct elemento{
    struct elemento *ant;
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

Lista* cria_lista(){
    Lista* li = (Lista*)malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while ((*li) != NULL)
        {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int tamanho_lista(Lista* li){
    if(li == NULL) return 0;
    int cont = 0;
    Elem* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

lista_vazia(Lista* li){
    if(li == NULL) return 1;
    if(*li == NULL) return 1;
    return 0;
}

//------------------------- INSERIR -------------------------
// Estamos trabalhando com dois ponteiros, um prox e um ant

int insere_aluno_inicio(Lista* li, struct aluno al){
    if(li == NULL) return 0;
    Elem* no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    no->prox = (*li);
    no->ant = NULL;
    //Lista não vazia: apontar para o anterior!
    if(*li != NULL)
        (*li)->ant = no;
    *li = no;
    return 1;
}

int insere_lista_final(Lista *li, struct aluno al){
    if(li == NULL) return 0;
    Elem *no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL){//Lista vazia: insere inicio
        no->ant = NULL;
        *li = no;
    } else {
        Elem *aux = *li;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = no;
        no->ant = aux;
    }
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL) return 0;
    Elem *no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    if(lista_vazia(li)){//insere inicio
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return 1;
    } else {//procura onde inserir
        Elem *ante, *atual = *li;
        while (atual != NULL && atual->dados.matricula < al.matricula)
        {
            ante = atual;
            atual = atual->prox;
        }
        if (atual == *li)
        {
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = (*li);
            *li = no;
        } else {
            no->prox = ante->prox;
            no->ant = ante;
            ante->prox = no;
            if(atual != NULL)
                atual->ant = no;
        }
        return 1;
    }
}

// --------------------------------------------------------------------
//---------------------------- REMORÇÃO -------------------------------
int remove_lista_inicio(Lista *li, struct aluno al){
    if(li == NULL) return 0;
    if((*li) == NULL) return 0; //lista vazia

    Elem* no = *li;
    *li = no->prox;
    if(no->prox != NULL) //Mais de um elemento na lista
        no->prox->ant = NULL;
    free(no);
    return 1;
}

int remove_lista_final(Lista *li, struct aluno al){
    if(li == NULL) return 0;
    if((*li) == NULL) return 0; //lista vazia
    Elem *no = *li;
    while (no->prox != NULL){
        no = no->prox;//Andando na lista
    }
    if(no->ant == NULL)//remover o primeiro e único
        *li = no->prox;//Remover um elemento a lista fica vazia
    else 
        no->ant->prox = NULL;
    free(no);
    return 1;
}

int remove_lista(Lista *li, int mat){
    if(li == NULL) return 0;
    Elem *no = *li;
    while (no != NULL && no->dados.matricula < mat){
        no = no->prox;
    }
    if (no == NULL) return 0; // não encontrado
    if (no->ant == NULL)//remover o primeiro
        *li = no->prox;
    else 
        no->ant->prox = no->prox;
    //não é o último?
    if(no->prox != NULL)
        no->prox->ant = no->ant;
    free(no);
    return 1;
}

// --------------------------------------------------------------------
//---------------------------- CONSULTA -------------------------------
int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0) return 0;
    Elem *no = *li;
    int i = 1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    if(no == NULL)
        return 0;
    else {
        *al = no->dados;
        return 1;
    }
}

int consulta_lista_mat(Lista* li, int mat, struct aluno *al){
    if(li == NULL) return 0;
    Elem *no = li;
    while(no != NULL && no->dados.matricula != mat) {
        no = no->prox;
    }
    if(no == NULL)
        return 0;
    else {
        *al = no->dados;
        return 1;
    }
}

// --------------------------------------------------------------------
//------------------------ FUNÇÃO PRINCIPAL ---------------------------

int main(){
    Lista *li;
    li = cria_lista();
    void libera_lista(li);
    libera_lista(li);
    int x = tamanho_lista(li);
    //Lista chheia: como é dinâmica, ela nunca estará cheia, só se a memória encher
    int x = lista_vazia(li);
    //int x = insere_aluno_inicio(li, dados_aluno);
    //int x = insere_lista_final(li,dados_aluno);
    //int x = insere_lista_ordenada(li, dados_aluno);
    //int x = remove_lista_inicio(li, dados_aluno);
    //int x = remove_lista_final(li, dados_aluno);
    //int x = remove_lista(li, matricula);
    //int x = consulta_lista(li, posicao, &dados_aluno);
    //int x = consulta_lista_mat(li, posicao, &dados_aluno);
}