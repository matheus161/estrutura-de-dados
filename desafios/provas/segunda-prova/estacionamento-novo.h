
/*------------ Lista de Funcionários ------------ */
#define N 3
struct funcionario
{
    int nome;
    int ID;
    int idade;
};
typedef struct lista_func Lista_func;

Lista_func* cria_Lista();

int Lista_cheia(Lista_func* li);

int insere_lista_inicio(Lista_func* li, struct funcionario func);

/*------------ Pilha de carros ------------ */
#define MAX 3
struct carro{
    int placa;
    char name;
    int horas;
};

#define CAR 30
struct carro_lista{
    int placa;
    char name;
    int horas;
};
typedef struct lista_carro Lista_carro;

typedef struct pilha Pilha;

Pilha* cria_Pilha();

int Pilha_cheia(Pilha* pi);

int insere_Pilha(Pilha* pi, struct carro carro);

int remove_Pilha(Pilha* pi, int placa);

int remove_Pilha_manobrista(Pilha* pi, Lista_func* li, int placa_posicao,struct carro car,struct funcionario func );

int insertion_sort(Lista_func* li, struct funcionario func);


/*------------ Lista de Carros ------------ */

Lista_carro* cria_Lista_carro();

int insere_lista_final_carro(Lista_carro* li, struct carro_lista car);

int remove_Lista_manobrista(Lista_carro* li_carro, Lista_func* li_func, int placa_posicao, struct carro_lista car, struct funcionario func, int var );


/*------------ Árvore Binária ------------ */
typedef struct NO* ArvBin;

ArvBin* cria_ArvBin();

int insere_ArvBin(ArvBin *raiz, struct carro_lista car);

int remove_ArvBin(ArvBin *raiz, struct carro_lista car);

int consulta_ArvBin(ArvBin *raiz, struct carro_lista car);


/*------------ Fila de Carros ------------ */
typedef struct elemento* Lista;

Lista* cria_lista_din();

int insere_lista_inicio_din(Lista* li, struct carro_lista car);

int remove_lista_din(Lista* li, struct carro_lista car);

int consulta_lista_din(Lista* li, struct carro_lista car);

/*---------- TABELA HASH ----------*/
typedef struct hash Hash;

Hash* criaHash(int TABLE_SIZE);

int insereHash_EnderAberto(Hash* ha, struct carro_lista car);

int buscaHash_EnderAberto(Hash* ha, int placa, struct carro_lista car);
