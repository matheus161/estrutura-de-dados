#include <stdio.h>
#include <stdlib.h>
#include "arvore-binaria.h"
/*
    - Cada vértice pode possuir 0 ou duas sub-árvores
    - O número de nós de uma árvore completa é: 2^h-1
    onde 'h' é a altura da árvore
*/

/* Alocação estática(Muito bom quando eu sei o tamanho dela e ela é binária completa)
    - Uso de um array 
    - Usa 2 funções para retornar a posição 
    (Filhos à esquerda e à direita de um pai)
    {
        FILHO_ESQ(PAI) = 2 * PAI + 1
        FILHO_DIR(PAI) = 2 * PAI + 2
    }
*/

/* Alocação Dinâmica(lista encadeada)
    - Cada nó é tratado como um ponteiro e alocado dinamicamente
    - Para guardar o primeiro nó, utilizaremos "ponteiro para ponteiro"
*/

/* 
    Todos os valores da sub-árvore a esquerda são menores do que o nó pai
    Todos os valores da sub-árvore a direita são maiores do que o nó pai
*/

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*)malloc(sizeof(ArvBin));
    if (raiz != NULL)
        *raiz = NULL;
    return raiz;
}

// Liberando sempre os nós começado pela esquerda
void libera_NO(struct NO* no){
    if (no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if (raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada nó
    free(raiz);//libera raiz
}

int estaVazia_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 1;
    if (*raiz == NULL)
        return 1;
    return 0;
}

int altura_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else 
        return (alt_dir + 1);
}

int totalNo_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));
    return (alt_esq + alt_dir + 1);
}

//pre ordem
void preOrdem_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return;
    if (*raiz != NULL)
    {
        printf("%d\n", (*raiz)->info);
        preOrdem_Arvbin(&((*raiz)->esq));
        preOrdem_Arvbin(&((*raiz)->dir));
    }
        
}

//em ordem
void emOrdem_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return;
    if (*raiz != NULL)
    {
        emOrdem_Arvbin(&((*raiz)->esq));
        printf("%d\n", (*raiz)->info);  
        emOrdem_Arvbin(&((*raiz)->dir));
    }
}

//pos ordem
void posOrdem_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return;
    if (*raiz != NULL)
    {
        posOrdem_Arvbin(&((*raiz)->esq));
        posOrdem_Arvbin(&((*raiz)->dir));
        printf("%d\n", (*raiz)->info);  
    }
}

//Inserindo
int insere_ArvBinO(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*)malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    //procurar onde inserir
    //navego até chegar em um nó folha
    if(*raiz == NULL)
        *raiz = novo;
    else {
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        //Enquanto ele não achar uma folha NULL
        while (atual != NULL){
            ant = atual;
            if(valor == atual->info) {
                free(novo);
                return 0; //elemento já existe 
            }
            if(valor > atual->info)
                atual = atual->dir;
            else 
                atual = atual->esq;
        }
        //Insere como filho desse nó folha
        if(valor > atual->info)
            ant->dir = novo;
        else 
            ant->esq = novo;
    }
    return 1;
}

//Removendo
int remove_ArvBin(ArvBin *raiz, int valor){
    if(raiz = NULL) return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    //quando achar nó a ser removido. Tratar o lado da remoção
    while (atual != NULL)
    {
        if(valor = atual->info)
            *raiz = remove_atual(atual);
        else {
            if(ant->dir == atual)
                ant->dir = remove_atual(atual);
            else 
                ant->esq = remove_atual(atual);
        }
        return 1;
    }
    //continua andando na árvore a procura do nó a ser removido 
    ant = atual;
    if(valor > atual->info)
        atual = atual->dir;
    else 
        atual = atual->esq;
    
}
//tratamento da remoção(são 3 tipos)
struct NO* remove_atual(struct NO* atual) {
    struct NO *no1, *no2;
    //Sem filho na esquerda, aponta para o filho da direita(trata nó folha e nó com 1 filho) 
    if(atual->esq == NULL) { 
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    //Procura filho mais a direita na sub-arvore da esquerda 
    no1 = atual;
    no2 = atual->esq;
    //Vou descendo mais a direita até achar um null
    while (no2->dir != NULL)
    {
        no1 = no2;
        no2 = no2->dir;
    }
    //Copia filho mais a direita na sub-árvore esquerda para o lugar do nó removido
    if (no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }    
    no2->dir = atual->dir;
    free(atual);
    return no2;    
};

//Conulta
int consulta_ArvBin(ArvBin *raiz, int valor){
    if(raiz = NULL)
        return 0;
    struct NO* atual = *raiz;
    while (atual != NULL){
        if (valor == atual->info)
        {
            return 1;
        }
        //navega dentro da árvore
        if(valor > atual->info)
            atual = atual->dir;
        else 
            atual = atual->esq;
    }
    return 0;
}

//Programa principal 
int main(){
    ArvBin*  raiz; //ponteiro para ArvBin(ponteiro para ponteiro)
    ArvBin* raiz = cria_ArvBin();
    libera_ArvBin(raiz);
    int x = estaVazia_ArvBin(raiz);
    if(estaVazia_ArvBin(raiz));
    int x = altura_ArvBin(raiz);
    int x = totalNO_ArvBin(raiz);
    preOrdem_Arvbin(raiz);
    emOrdem_Arvbin(raiz);
    //int x = insere_ArvBin(raiz, valor);
    //int x = remove_ArvBin(raiz, valor);
    //int x = consulta_ArvBin(raiz, valor);
}