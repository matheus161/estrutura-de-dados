#include <stdio.h>
#include <string.h>
#include "lista-estatica.h"

struct lista{
    int qtd;
    struct aluno dados[MAX];
};

Lista* cria_lista(){
    Lista *li;
    li = (Lista*)malloc(sizeof(struct lista));
    if (li != NULL)
        li ->qtd=0;
    return li;    
}

void libera_lista(Lista* li){
    free(li);
}

int tamanho_lista(Lista *li){
    if(li == NULL)
        return -1;
    else 
        return li->qtd;
}

int lista_cheia(Lista* li){
    if (li == NULL)
        return -1;
    return (li->qtd == MAX);    
}

int lista_vazia(Lista* li){
    if (li == NULL)
        return -1;
    return (li->qtd == 0); 
}

// ---------------------------- INSERÇÃO -------------------------------
int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    if(lista_cheia(li))
        return 0;
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL) return 0;
    if(lista_cheia(li)) return 0;
    int i;
    for(i=li->qtd; i>=0; i--)
        li->dados[i+1] = li->dados[i];
    li->dados[0] = al;
    li->qtd++;
}

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL) return 0;
    if(lista_cheia(li)) return 0;
    int k,i = 0;
    // Se a matricula que eu tenho for menor que a do novo aluno
    while (i<li->qtd && li->dados[i].matricula < al.matricula){
        i++;
    }
    for (k=li->qtd-1; k >= i; k--){
        li->dados[k+1] = li->dados[k];
    }
    li->dados[i] = al;
    li->qtd++;
    return 1;    
}
// --------------------------------------------------------------------
//---------------------------- REMORÇÃO -------------------------------
int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
        li->qtd--;
        return 1;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    int k = 0;
    for(k=0; k < li->qtd-1; k++)
        li->dados[k] = li->dados[k+1];
    li->qtd--;
    return 1;
}

int remove_lista(Lista* li, int mat){
    if(li == NULL) return 0;
    if(li->qtd == 0) return 0;
    int k,i = 0;
    while (i<li->qtd && li->dados[i].matricula != mat){
        i++;
    }
    //Elemento não encontrado
    if (i == li->qtd)
        return 0;
    for (k=i; k >= li->qtd-1; k++)
    {
        li->dados[k] = li->dados[k+1];
    }
    li->qtd--;   
}
// --------------------------------------------------------------------
//---------------------------- CONSULTA -------------------------------
int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0 || pos > li->qtd)
        return 0;
    *al = li->dados[pos-1];
    return 1;
}

int consulta_lista_mat(Lista* li, int mat, struct aluno *al){
    if (li == NULL)
        return 0;
    int i = 0;
    while(i<li->qtd && li->dados[i].matricula != mat)
        i++;
    // Se eu não encontrar nenhum
    if(i == li->qtd) return 0;
    *al = li->dados[i];
    return 1;
}

// --------------------------------------------------------------------
//------------------------ FUNÇÃO PRINCIPAL ---------------------------

int main(){
    Lista *li;
    li = cria_lista();
    libera_lista(li);
    int x = tamanho_lista(li);
    int x = lista_cheia(li);
    int x = lista_vazia(li);
    // int x = insere_lista_final(li, dados_aluno);
    // int x = insere_lista_inicio(li, dados_aluno);
    // int x = insere_lista_ordenada(li, dados_alunos);
    // int x = remove_lista_final(li);
    // int x = remove_lista_inicio(li);
    // int x = remove_lista(li, matricula_aluno);
    // int x = constula_lista_pos(li, posicao, &dados_aluno);
    // int c = consulta_lista_mat(li, posicao, &dados_aluno);
}

