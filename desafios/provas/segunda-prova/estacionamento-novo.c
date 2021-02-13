#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "estacionamento-novo.h"

int * contArvBin, portaoArvbin, contLista, portaoLista, contHash, portaoHash;
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
    int cont;
    struct NO *esq;
    struct NO *dir;
    struct carro_lista carro[20];
};

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*)malloc(sizeof(ArvBin));
    if (raiz != NULL)
        *raiz = NULL;
    return raiz;
}

//Inserindo
int insere_ArvBin(ArvBin *raiz, struct carro_lista car){
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

//Removendo
int remove_ArvBin(ArvBin *raiz, struct carro_lista car){
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
int consulta_ArvBin(ArvBin *raiz, struct carro_lista car){
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    contArvBin = 0;
    while (atual != NULL){
        if (car.placa == atual->info)
        {
            contArvBin++;
            return 1;
        }
        //navega dentro da árvore
        if(car.placa > atual->info)
        {
            atual = atual->dir;
            contArvBin++;
        }
        else{
            atual = atual->esq;
            contArvBin++;
        } 
    }
    return 0;
}

/*---------- PILHA DE CARROS ----------*/ 
struct pilha{
    int qtd;
    struct carro car[MAX];
};

//Cria pilha
Pilha* cria_Pilha(){
    Pilha *pi;
    pi = (Pilha*)malloc(sizeof(Pilha));
    if(pi != NULL)
        pi->qtd = 0;
    printf("Abertura do estacionamento!\n");
    return pi;
}

//Pilha cheia
int Pilha_cheia(Pilha* pi){
    if(pi == NULL)
        return -1;
    return (pi->qtd == MAX);
}

//Insere na Pilha(Estaciona os carros)
int insere_Pilha(Pilha* pi, struct carro carro){
    if(pi == NULL) return 0;
    //Quando minha pilha estiver cheia, reinicio a qtd para subscrever os valores
    if(Pilha_cheia(pi)) pi->qtd = 0;
    pi->car[pi->qtd] = carro;
    pi->qtd++;
    return 1;
}

//Retirando os carros da pilha com os manobristas
int remove_Pilha_manobrista(Pilha* pi, Lista_func* li, int placa_posicao, struct carro car, struct funcionario func){
    int acum = 0, aux = -1;  
    if(pi == NULL)
        return 0;

    while (pi->qtd != placa_posicao )
    {        
        //Quando todos os manobristas tiverem tirado um carro, reinicio a sequencia
        if (li->qtd == 0)
        {
            li->qtd = N;
        } 
        car = pi->car[pi->qtd-1];
        func = li->func[li->qtd-1];        
        printf("Carro %c retirado pelo funcionario X%d\n", car.name, func.nome);        
        pi->qtd--; 
        li->qtd--;   
        acum++;
        aux++;
    }
    printf("Carro %c saiu! Total = %d \n",car.name, aux);  
    pi->qtd++;    
    //Retornando os carros para a pilha
    for (int i = (pi->qtd); i < MAX; i++)
    {
        car = pi->car[i];
        printf("Carro %c voltou \n", car.name);
        pi->qtd++;
    }   
    return 1;
}

/*---------- LISTA DE CARROS ----------*/ 
struct lista_carro{
    int qtd;
    struct carro_lista carro[20];
};

Lista_carro* cria_Lista_carro(){
    Lista_carro* li = (Lista_carro*)malloc(sizeof(struct lista_carro));
    if (li != NULL)
        li ->qtd=0;
    printf("Abertura do estacionamento!\n");
    return li;    
};

int insere_lista_final_carro(Lista_carro* li, struct carro_lista car){
    if(li == NULL) return 0;
    if(lista_cheia(li)) li->qtd;
    li->carro[li->qtd] = car;
    li->qtd++;
}

int remove_Lista_manobrista(Lista_carro* li_carro, Lista_func* li_func, int placa_posicao, struct carro_lista car, struct funcionario func, int var ){
    int acum = 0, aux = -1, j = 0, i = 0;  
    if(li_carro == NULL)
        return 0;
    while (li_carro->qtd != placa_posicao )
    {       
        //Quando todos os manobristas tiverem tirado um carro, reinicio a sequencia
        if (li_func->qtd == 0)
        {
            li_func->qtd = N;
        } 
        car = li_carro->carro[li_carro->qtd-1];
        func = li_func->func[li_func->qtd-1];        
        printf("Carro %c retirado pelo funcionario X%d\n", car.name, func.nome);        
        li_carro->qtd--; 
        li_func->qtd--;   
        acum++;
        aux++;
    }
    printf("Carro %c saiu! Total = %d \n",car.name, aux );  
    li_carro->qtd++;

    //Retornando os carros para a pilha
    for (i = li_carro->qtd; i < var; i++)
    {
        car = li_carro->carro[i];
        printf("Carro %c voltou \n", car.name);
        li_carro->qtd++;
    }
    return 1;
}

/*---------- FILA DE CARROS ----------*/
struct elemento{
    struct carro_lista dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

Lista* cria_lista_din(){
    Lista* li = (Lista*)malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

//Inserindo 
int insere_lista_inicio_din(Lista* li, struct carro_lista car){
    if(li == NULL) return 0;
    Elem* no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = car;
    no->prox = (*li);
    *li = no;
    return 1;
}

//Removendo 
int remove_lista_din(Lista* li, struct carro_lista car){
    if (li == NULL) return 0;
    consulta_lista_din(li, car);
    Elem *ant, *no = *li;
    while (no != NULL && no->dados.placa != car.placa)
    {
        ant->prox = no;
        no = no->prox;
    }
    if (no == NULL) return 0; // não encontrado

    if( no == *li) // Remover o primeiro
    {
        *li = no->prox;
    }
    else{ 
        ant->prox = no->prox;
    }
    free(no); 
    return 1;   
}

//Consultando
int consulta_lista_din(Lista* li, struct carro_lista car){
    if (li == NULL ) return 0;
    Elem* no = *li;
    while (no != NULL && no->dados.placa != car.placa){
        contLista++;
        no = no->prox;
    }
    // Não encontri a matricula
    if (no == NULL)
        return 0;
    else {
        car = no->dados;
        return 1;
    }

}

/*---------- TABELA HASH ----------*/
//Definição do tipo Hash
struct hash {
    int qtd, TABLE_SIZE;
    struct carro_lista **itens;
};

Hash* criaHash(int TABLE_SIZE) {
    Hash* ha = (Hash*)malloc(sizeof(Hash));
    if(ha != NULL) {
        int i;
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (struct carro_lista**)malloc(TABLE_SIZE * sizeof(struct carro_lista*)); //ponteiro para ponteiro
        if (ha->itens == NULL){
            free(ha);
            return NULL;
        }
        ha->qtd = 0;
        for (i = 0; i < ha->TABLE_SIZE; i++)//Vou percorer e em cada posição do Array itens vou colocar o NULL
            ha->itens[i] = NULL;
    }
    return ha;
}

//Tratamento Colisões
int sondagemLinear(int pos, int i, int TABLE_SIZE) {//vai pulando de um e um procurando uma posição vazia
    return ((pos + i) & 0x7FFFFFFF) % TABLE_SIZE;
}

int chaveDivisao(int chave, int TABLE_SIZE) {
    return (chave & 0x7FFFFFFF) % TABLE_SIZE; //bit-a-bit evita o overflow, eliminando o bit de sinal do valor chave
}

//Inserindo com tratamento de colisões
int insereHash_EnderAberto(Hash* ha, struct carro_lista car) {
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;
    int chave = car.placa;
    int i, pos, newPos;
    pos = chaveDivisao(chave, ha->TABLE_SIZE);
    for (i = 0; i < ha->TABLE_SIZE; i++) {
        newPos = sondagemLinear(pos, i, ha->TABLE_SIZE);//poderia ter usado qualquer outro
        if(ha->itens[newPos] == NULL) { //se naquela posição eu não tenho nenhum valor
            struct carro_lista* novo;
            novo = (struct carro_lista*)malloc(sizeof(struct carro_lista));
            if(novo == NULL)
                return 0;
            *novo = car;
            ha->itens[newPos] = novo;
            ha->qtd++;
            return 1;
        }
    }
    return 0;
}

//Buscando com tratamento de colisões
int buscaHash_EnderAberto(Hash* ha, int placa, struct carro_lista car) {
    if(ha == NULL)
        return 0;
    int i, pos, newPos;
    pos = chaveDivisao(placa, ha->TABLE_SIZE);
    for (i = 0; i < ha->TABLE_SIZE; i++) {
        contHash++;
        newPos = sondagemLinear(pos, i, ha->TABLE_SIZE);//deslocamentos
        if(ha->itens[newPos] == NULL)
            return 0;
        if(ha->itens[newPos]->placa == placa) {//Se eu encontrei algo e não é valor, vou recalcular até achar o que eu quero
            car = *(ha->itens[newPos]);
            return 1;
        }
    }
    printf("Não consegui inserir na Hash \n");
    return 0;
}

/*---------- PROGRAMA PRINCIPAL ----------*/
int main(){
    //Structs 
    struct carro car[MAX];
    struct carro_lista car2[CAR]; 
    struct funcionario fun[N];

    //Iniciando estruturas
    Pilha* pi = cria_Pilha();    
    Lista_func* li = cria_Lista();
    ArvBin* raiz = cria_ArvBin();
    Lista_carro* li_carro = cria_Lista_carro();
    Lista* li_din = cria_lista_din();
    Hash* hash = criaHash(CAR);

    //Variáveis
    int i, j, k, x = 0, qtd = 0, aux = 0, z = 1, var = 2, y;
    float acum = 0;
    srand(time(NULL));

    //Preenchendo 'struct funcionario' de forma random
    for (j = 0; j < N; j++)
    {        
        fun[j].nome = aux + (rand() % 50);
        fun[j].nome = z++;
        fun[j].idade = 18 + (rand() % 65);
        fun[j].ID = 10000 + (rand() % 99999);
        aux = fun[j].nome;
        insere_lista_final(li,fun[j]);
    }

    //Enquanto meu estacionamento não bater a meta vou adicionando carros e retirando(Sempre de 3 em 3)
    do
    {
        printf("Estacionamento vazio\n");
        //Preenchendo 'struct carro' de forma random
        for (i = 0; i < MAX; i++)
        {
            car[i].name = 'A' + (char)(rand() % 26);
            car[i].placa = 0 + (rand() % 1000);
            car[i].horas = var + 2;

            //Guardando os valores em car2 para serem utilizados no dia seguinte
            car2[x].name = car[i].name;
            car2[x].placa = car[i].placa;
            car2[x].horas = car[i].horas;

            qtd++;
            x++;
            insere_Pilha(pi,car[i]);
            printf("O carro %c entrou. Total = %d \n", car[i].name, i+1);
        }
            printf("Estacionamento lotado!\n");
        y = 0;

        for (k = 0; k < MAX; k++)
        {                      
            if (car[k].placa == car[y].placa && acum < 300)
            {                                         
                printf("Carro %c devera sair. \n", car[k].name);
                remove_Pilha_manobrista(pi,li, y, car[MAX], fun[MAX]);
                acum = (car[k].horas*12) + acum;
                printf("Valor pago %.0f\n", acum); 
                y++;                                     
            }
        }
    } while (acum < 300);
    printf("\n\nAtingimos nossa meta, construindo o segundo portao...\n\n");

    //Abrindo após a construção do portão
    y=0;//Reiniciando variaveis
    int aux2 = MAX, l = 0, m = 0, var2 = 0, teste = 3;
    float acum2 = 0;

    do {
        printf("Estacionamento vazio\n");
        var2 = 0;
        for (l; l < aux2; l++)
        {
            insere_lista_final_carro(li_carro,car2[l]);
            insere_ArvBin(raiz, car2[l]);
            insere_lista_inicio_din(li_din, car2[l]);
            insereHash_EnderAberto(hash, car2[l]);
            // printf("PLACA DO CARRO QUE ENTROU %d \n", car[l].placa);
            printf("O carro %c entrou. Total = %d \n", car2[l].name, var2 + 1); 
            var2++;
        }
            printf("Estacionamento lotado!\n");
        for (m; m < aux2; m++) {                    
            if (car2[m].placa == car2[y].placa && acum2 < 300)
            {   
                contLista = 0;                                 
                printf("Carro %c devera sair. \n", car2[m].name);
                // printf("Eu passei %d \n", car2[m].placa);
                remove_Lista_manobrista(li_carro,li, y, car2[m], fun[MAX], aux2);
                remove_ArvBin(raiz, car2[m]);
                remove_lista_din(li_din, car2[m]);
                buscaHash_EnderAberto(hash, car2[m].placa, car2[m]);
                if (contArvBin > (qtd/2))
                {
                    portaoArvbin = 2;
                } else {
                    portaoArvbin = 1;
                }
                if (contLista > (qtd/2))
                {
                    portaoLista = 2;
                } else {
                    portaoLista = 1;
                }
                if (contHash > (qtd/2))
                {
                    portaoHash = 2;
                } else {
                    portaoHash = 1;
                }
                //TESTAR AS COMPARAÇÕES
                printf("Foram feitas %d comparacao(oes) com Lista Encadeada e deve sair pelo portao: %d \n", contLista, portaoLista);
                printf("Foram feitas %d comparacao(oes) com Arvore Binaria e deve sair pelo portao: %d \n", contArvBin, portaoArvbin);
                printf("Foram feitas %d comparacao(oes) com Tabela Hash e deve sair pelo portao: %d \n", contHash, portaoHash);
                acum2 = (car2[m].horas*12) + acum2;
                printf("Valor pago %.0f\n", acum2);                                     
            }
            y++;
        }
            teste = l + 3;
            aux2 = l + 3;
    } while (acum2 < 300); 
    
    free(pi);
    free(li_carro);
    free(li);
    free(raiz);
    free(li_din);
    free(hash);

    
    return 0;
}