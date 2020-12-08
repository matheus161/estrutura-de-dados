#include <stdio.h>
#include <string.h>
#include "pilha-estatica.h"

struct pilha{
    int qtd;
    struct aluno dados[MAX];
};

Pilha* cria_Pilha(){
    Pilha *pi;
    pi = (Pilha*)malloc(sizeof(struct pilha));
    if(pi != NULL)
        pi->qtd = 0;
    return pi;
}

void libera_Pilha(Pilha* pi){
    free(pi);
}

int tamanho_Pilha(Pilha* pi){
    if(pi == NULL)
        return -1;
    else 
        return pi->qtd;
}

int Pilha_cheia(Pilha* pi){
    if(pi == NULL)
        return -1;
    return (pi->qtd == MAX);
}

int Pilha_vazia(Pilha* pi){
    if(pi == NULL)
        return -1;
    return (pi->qtd == 0);
}

int insere_Pilha(Pilha* pi, struct aluno al){
    if(pi == NULL) return 0;
    if(Pilha_cheia(pi)) return 0;
    pi->dados[pi->qtd] = al;
    pi->qtd++;
    return 1;
}

int remove_Pilha(Pilha* pi){
    if(pi == NULL || pi->qtd == 0)
        return 0;
    pi->qtd--;
    return 1;
}

int consulta_topo_Pilha(Pilha* pi, struct aluno *al){
    if(pi == NULL || pi->qtd == 0)
        return 0;
    *al = pi->dados[pi->qtd-1];
}

int main(){
    Pilha *pi;
    pi = cria_Pilha();
    libea_Pilha(pi);
    int x = tamanho_Pilha(pi);
    int x = Pilha_cheia(pi);
    int x = Pilha_vazia(pi);
    //int x = insere_Pilha(pi, dados_aluno);
    //int x = remove_Pilha(pi);
    //int x = consulta_topo_pilha(pi, dados_alunos);
}