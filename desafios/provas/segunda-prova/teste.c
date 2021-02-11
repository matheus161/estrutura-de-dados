#include <stdio.h>
#include <stdlib.h>
#include "teste.h"

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

//Inserindo
int insere_ArvBin(ArvBin *raiz, int valor){
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
        if(valor > ant->info)
            ant->dir = novo;
        else 
            ant->esq = novo;
    }
    // printf("Pelo amor de DEUS funciona\n");
    return 1;
}

int remove_ArvBin( ArvBin *raiz, int valor) {
    if (raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    struct NO* ant = atual;
    //Pesquisar nó
    if(atual->info > valor)
        atual->esq = remove_ArvBin(atual->esq, valor); 
    else
        atual->dir = remove_ArvBin(atual->dir, valor);
    //Nó sem filhos
    if(atual->esq == NULL && atual->dir == NULL) {
        free(atual);
        atual = NULL;
    } else if (atual->esq == NULL){
        //Nó com filho à direita
        ant = atual;
        atual = atual->dir;
        free(ant);
    } else if (atual->dir == NULL) {
        //Nó com filho à esqerda
        ant = atual;
        atual = atual->esq;
        free(ant);
    } else {
        ant = atual->esq;
        while (ant->dir != NULL)
        {
            ant = ant->dir;
        }
        atual->info = ant->info; //trocar informações
        ant->info = valor;
        atual->esq = remove_ArvBin(atual->esq, valor);    
    }
    printf("Foi removido \n");
    return 1;
}

//Programa principal 
int main(){
    ArvBin* raiz = cria_ArvBin();
    struct carro car[MAX];
    int acum = 0, var = 2;

    do
    {
        for (int i = 0; i < MAX; i++)
        {
            car[i].name = 'A' + (char)(rand() % 26);
            car[i].placa = 9000 + (rand() % 9999);
            car[i].horas = var + 2;
            printf("O carro %c entrou. Total = %d \n", car[i].name,  i + 1);
            insere_ArvBin(raiz,car[i].placa);
        }
        printf("Estacionamento lotado! \n");
        int y = 0;
        for (int k = 0; k < MAX; k++)
        {
            if (car[k].placa == car[y].placa && acum < 300)
            {
                printf("Carro %c devera sair. \n", car[k].name);
                //remove_ArvBin(raiz, car[MAX].placa);
                // printf("Carro %c retirado pelo funcionario X\n", car[k].name);
                acum = (car[k].horas*12) + acum;
                printf("Valor pago %d\n", acum); 
                y++;                              
            }   
        }
    } while (acum < 300);

    // insere_ArvBin(raiz, 10);
    // remove_ArvBin(raiz, 10);

    free(raiz);   

}