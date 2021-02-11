#include <stdio.h>
#include <stdlib.h>
#include "arvore-AVL.h"

/*
    Permite o rebalanceamento local
        - Apenas a parte afetada pela inserção ou remoção é rebalanceada
        - Uso de rotações simples e duplas na etapa de balanceamento
    
    Fator de Balanceamento 
        - Diferença nas alturas das sub-árvores "esquerda" e "direita"
            -Se uma delas não existir, sua altura será -1 
        Se "fb < -1" ou "fb > +1" a árvore deve ser balanceada
*/

struct NO{
    int info;
    int alt;
    struct NO *esq;
    struct NO *dir;
};

//Calcula a altura de um nó
int alt_NO(struct NO* no) {
    if(no == NULL)
        return -1;
    else 
    return no->alt;
}

//Calcula o fator de balanceamento de um nó
int fatorBalanceamento_NO(struct NO* no) {
    return labs(alt_NO(no->esq) - alt_NO(no->dir));
}

//Calcula o maior valor
int maior(int x, int y) {
    if(x > y)
        return x;
    else
        return y;
}

//Rotação 
void RotacaoLL(ArvAVL *raiz) {
    struct NO *no;
    no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir = *raiz;
    (*raiz)->alt = maior(alt_NO((*raiz)->esq),alt_NO((*raiz)->dir)) + 1;
    no->alt = maior(alt_NO(no->esq),(*raiz)->alt) + 1;
    *raiz = no;
}

void RotacaoRR(ArvAVL *raiz) {
    struct NO *no;
    no = (*raiz)->dir;
    (*raiz)->dir = no->esq;
    no->esq = (*raiz);
    (*raiz)->alt = maior(alt_NO((*raiz)->esq),alt_NO((*raiz)->dir)) + 1;
    no->alt = maior(alt_NO(no->dir),(*raiz)->alt) + 1;
    (*raiz) = no;
}

void RotacaoLR(ArvAVL *raiz) {
    RotacaoLR(&(*raiz)->esq);
    RotacaoLL(raiz);
}

void RotacaoRL(ArvAVL *raiz) {
    RotacaoLL(&(*raiz)->esq);
    RotacaoRR(raiz);
}


//Inserção
int insere_ArvAVL(ArvAVL *raiz, int valor) {
    int res;
    if (*raiz == NULL){ //Árvore vazia ou nó folha
        struct NO *novo;
        novo = (struct NO*)malloc(sizeof(struct NO));
        if(novo == NULL)
            return 0;
        
        novo->info = valor;
        novo->alt = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }
    struct NO *atual = *raiz;
    if(valor < atual->info) {
        if((res = insere_ArvAVL(&(atual->esq), valor)) == 1) { //Se a inserção funcionou
            if(fatorBalanceamento_NO(atual) >= 2) { //Faço balanceamento se for >= 2
                if (valor < (*raiz)->esq->info ){
                    RotacaoLL(raiz);
                } else {
                    RotacaoLR(raiz);
                }
                
            }
        }
    } else {
        if(valor > atual->info) {
            if((res = insere_ArvAVL(&(atual->dir), valor)) == 1) {
                if(fatorBalanceamento_NO(atual) >= 2) {
                    if((*raiz)->dir->info < valor) { //Se o atual for menor do que o anteior, ele é uma folha a direita total
                        RotacaoRR(raiz);
                    } else {
                        RotacaoLR(raiz);
                    }
                }
            }
        } else {
            printf("Valor Duplicado!!\n");
            return 0;
        }
    }
    atual->alt = maior(alt_NO(atual->esq), alt_NO(atual->dir)) + 1;
    printf("ok");
    return res;
}

struct NO* procuraMenor(struct NO* atual){
    struct NO *no1 = atual;
    struct NO *no2 = atual->esq;
    while (no2 != NULL) //Procura pelo nó mais a esquerda
    {
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;    
}

int remove_ArvAVL(ArvAVL *raiz, int valor) {
    if(*raiz == NULL) {// valor não existe
        printf("valor não existe!!\n");
        return 0;
    }
    int res;
    if (valor < (*raiz)->info){
        if((res=remove_ArvAVL(&(*raiz)->esq, valor)) ==1 )
            if (fatorBalanceamento_NO(*raiz) >= 2){//Se a altura for maior que 2 em alguns desses lugares
                if(alt_NO((*raiz)->dir->esq) <= alt_NO((*raiz)->dir->dir))//Compara as alturas dos filhos da esquerda e direita
                    RotacaoRR(raiz);
                else
                    RotacaoLR(raiz);        
        }
    }
    if ((*raiz)->info < valor){
        if((res=remove_ArvAVL(&(*raiz)->dir, valor)) == 1)
            if(fatorBalanceamento_NO(*raiz) >= 2){
                if(alt_NO((*raiz)->esq->esq) <= alt_NO((*raiz)->esq->esq))
                    RotacaoLL(raiz);
                else
                    RotacaoLR(raiz);
        }
    }
    if ((*raiz)->info == valor){
        if (((*raiz)->esq == NULL || (*raiz)->dir == NULL)){ //Nó Pai tem um filho ou nenhum
            struct NO *oldNode = (*raiz);
            if((*raiz)->esq != NULL)
                *raiz = (*raiz)->esq;
            else
                *raiz = (*raiz)->dir;
            free(oldNode);
        } else { //Se não for NULL, nó tem 2 filhos
            struct NO* temp = procuraMenor((*raiz)->dir);
            (*raiz)->info = temp->info;
            remove_ArvAVL(&(*raiz)->dir, (*raiz)->info);
            if(fatorBalanceamento_NO(*raiz) >= 2) {
                if(alt_NO((*raiz)->esq->dir) <= alt_NO((*raiz)->esq->esq))
                    RotacaoLL(raiz);
                else 
                    RotacaoLR(raiz);
            }
        }
        return 1;
    }
    return res;
}


int main() {
    ArvAVL* raiz; //ponteiro para ponteiro
    insere_ArvAVL(raiz, 10);
    //int x = remove_ArvAVL(raiz, valor);
}
