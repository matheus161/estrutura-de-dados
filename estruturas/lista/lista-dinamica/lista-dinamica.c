#include <stdio.h>
#include <string.h>
#include "lista-dinamica.h"

struct elemento{
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

//Como eu não sei a quantidade da lista, preciso fazer esse processo.
void libera_lista(Lista* li){
    if (li != NULL){
        Elem* no;
        while ((*li) != NULL){
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
    while (no != NULL)
    {
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0; // Retorno zero 'NÃO' está VAZIA
}

//------------------------- INSERIR -------------------------
int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL) return 0;
    Elem* no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL) return 0;
    Elem* no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    no->prox = NULL;
    if ((*li) == NULL) //Lista vaiza: Insere no inicio
    {
        *li = no;
    } else {
        Elem *aux = *li;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL) return 0;
    Elem* no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    if ((*li) == NULL){//Insere inicio
        no->prox = (*li);
        *li = no;
        return 1;
    } else { // Procura onde inserir
        Elem *ant, *atual = *li;
        while (atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        if (atual == *li){//Insere inicio
            no->prox = (*li);
            *li = no;
        } else {
            no->prox = ant->prox;
            ant->prox = no;
        }
        return 1;
    }
    
}
//-----------------------------------------------------------
//------------------------- REMOVER -------------------------
int remove_lista_inicio(Lista* li){
    if (li == NULL) return 0;
    if ((*li) == NULL) return 0; //LIsta vazia
    
    Elem *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

int remove_lista_final(Lista* li){
    if (li == NULL) return 0;
    if ((*li) == NULL) return 0; //LIsta vazia
    Elem *ant, *no = *li;
    while (no->prox != NULL){
        ant = no;
        no = no->prox;
    }
    if(no == (*li)) // remover o primeiro??(minha lista só tinha um elemento)
        *li = no->prox;
    else 
        ant->prox = no->prox;
    free(no);
    return 1;    
}

int remove_lista(Lista* li, int mat){
    if (li == NULL) return 0;
    Elem *ant, *no = *li;
    while (no != NULL && no->dados.matricula != mat)
    {
        ant->prox = no;
        no = no->prox;
    }
    if (no == NULL) return 0; // não encontrado

    if( no == *li) // Remover o primeiro
        *li = no->prox;
    else 
        ant->prox = no->prox;
    free(no); 
    return 1;   
}
//-----------------------------------------------------------
//------------------------ CONSULTA -------------------------

int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
    if (li == NULL || pos <= 0) return 0;
    Elem* no = *li;
    int i = 1;
    while (no != NULL && i < pos){
       no =  no->prox;
       i++; 
    }
    //Cheguei no final e não encontrei o elemento que eu queria
    if (no == NULL)
        return 0;
    else {
        *al = no->dados;
        return 1;
    }
}

int consulta_lista_mat(Lista* li, int mat, struct aluno *al){
    if (li == NULL ) return 0;
    Elem* no = *li;
    while (no != NULL && no->dados.matricula != mat){
        no = no->prox;
    }
    // Não encontri a matricula
    if (no == NULL)
        return 0;
    else {
        *al = no->dados;
        return 1;
    }

}

//-----------------------------------------------------------
int main(){
    Lista *li; //li é um ponteiro para o ponteiro (minha struct elemento)
    li = cria_lista();
    libera_lista(li);
    int x = tamanho_lista(li);
    int x = lista_vazia(li);
    //int x = insere_lista_inicio(li, dados_alunos);
    //int x = insere_lista_meio(li, dados_alunos);
    //int x = insere_lista_final(li ,dados_alunos);
    //int x = remove_lista_inicio(li);
    //int x = remove_lista(li, mat);
    //int x = remove_lista_final(li);
    //int x = consulta_lista_pos(li, posicao, &dados_aluno);
    //int x = consulta_lista_mat(li, matricula, &dados_aluno);
}
