#include <stdio.h>
#include <stdlib.h>
#include "teste.h"

/*---------- LISTA DE FUNCIONÁRIOS ----------*/ 
//Lista de funcionários
struct lista_func{
    int qtd;
    struct funcionario func[N];
};

//Cria Lista
Lista_func* cria_Lista(){
    Lista_func* li = (Lista_func*)malloc(sizeof(struct lista_func));
    if (li != NULL)
        li ->qtd=0;
    return li;    
};

//Lista Cheia
int lista_cheia(Lista_func* li){
    if (li == NULL)
        return -1;
    return (li->qtd == N);    
}

//Inserindo Lista no inicio
int insere_lista_final(Lista_func* li, struct funcionario func){
    if(li == NULL) return 0;
    if(lista_cheia(li)) return 0;
    li->func[li->qtd] = func;
    li->qtd++;
}

/*---------- ÁRVORE BINÁRIA ----------*/ 
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
int insere_ArvBin(ArvBin *raiz, struct carro car){
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*)malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->info = car.placa;
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
            if(car.placa == atual->info) {
                free(novo);
                return 0; //elemento já existe 
            }
            if(car.placa > atual->info)
                atual = atual->dir;
            else 
                atual = atual->esq;
        }
        //Insere como filho desse nó folha
        if(car.placa > ant->info)
            ant->dir = novo;
        else 
            ant->esq = novo;
    }
    return 1;
}

// //tratamento da remoção(são 3 tipos)
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
}

int remove_ArvBin(ArvBin *raiz, struct carro car){
    if(raiz == NULL) return 0;
    consulta_ArvBin(raiz, car);
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    //quando achar nó a ser removido. Tratar o lado da remoção
    while (atual != NULL) {
        if(car.placa == atual->info) {
            if(atual == *raiz)
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
        //troco meu atual por outro valor a depender do que eu estou buscando 
        ant = atual;
        if(car.placa > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq; 
    }
    return 0;
}

//Consultando
int consulta_ArvBin(ArvBin *raiz, struct carro car){
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    int acum = 0;
    while (atual != NULL){
        if (car.placa == atual->info)
        {
            acum++;
            printf("Foram feitas %d comparacao(oes) com Arvore Binaria e o numero e: %d \n", acum, car.placa);
            return 1;
        }
        //navega dentro da árvore
        if(car.placa > atual->info){
            atual = atual->dir;
        }
        else{
            atual = atual->esq;
        }
        acum++;
    }
    return 0;
}

/*---------- TABELA HASH ----------*/ 


//Programa principal 
int main(){
    ArvBin* raiz = cria_ArvBin();
    struct carro car[MAX];
    int var = 0, acum = 0, x = 0;
    //struct carro car[MAX] = {{100, 'A', 2},{200, 'B', 4},{59, 'C', 8},{67, 'D', 12},{89, 'E', 4},{300, 'F', 7},{450, 'G',2},{25, 'H', 7},{76, 'I', 4},{250, 'J', 8}};
    int array[10] = {100,200,59,67,89,300,450, 25,76,250};

    do
    {
        for (int i = 0; i < MAX; i++)
        {
            car[i].name = 'A' + (char)(rand() % 26);
            car[i].placa = array[x];
            car[i].horas = var + 2;
            printf("O carro %c entrou. Total = %d \n", car[i].name,  i + 1);
            insere_ArvBin(raiz,car[i]);
            x++;
        }
        printf("Estacionamento lotado! \n");
        int y = 0;
        for (int k = 0; k < MAX; k++)
        {
            if (car[k].placa == car[y].placa && acum < 300)
            {
                printf("Carro %c devera sair. \n", car[k].name);
                remove_ArvBin(raiz, car[k]);
                printf("Estou passando: %d \n", car[k].placa);
                acum = (car[k].horas*12) + acum;
                printf("Valor pago %d\n", acum); 
                y++;                              
            }   
        }
    } while (acum < 300);

    // for (int i = 0; i < 10; i++)
    // {
    //     printf("placa %d \n", array[i]);
    //     insere_ArvBin(raiz, array[i]);
    // }
    // for (int k = 9; k >= 0; k--)
    // {
    //     // printf("placa %d \n", car[k].placa);
    //     remove_ArvBin(raiz, array[k]);
    // }
    

    free(raiz);   

}