#define MAX 3

struct carro{
    int placa;
    char name;
    int horas;
};

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

/* ---------- Árvore Binária ---------- */ 
typedef struct NO* ArvBin;

ArvBin* cria_ArvBin();

int insere_ArvBin(ArvBin *raiz, struct carro car);

int remove_ArvBin( ArvBin *raiz, struct carro car);

int consulta_ArvBin(ArvBin *raiz, struct carro car);

ArvBin* arv_buscar (ArvBin *raiz, struct carro car);

// ArvBin* arv_retirar (ArvBin* raiz, int valor);

/* ---------- Árvore AVL ---------- */ 
typedef struct NO* ArvAVL;

int insere_ArvAVL(ArvAVL *raiz, int valor);

int remove_ArvAVL(ArvAVL *raiz, int valor);

/*------------ Lista de Carros ------------ */

#define CAR 30
struct carro_lista{
    int placa;
    char name;
    int horas;
};
typedef struct lista_carro Lista_carro;

Lista_carro* cria_Lista_carro();

int insere_lista_final_carro(Lista_carro* li, struct carro_lista car);

int remove_Lista_manobrista(Lista_carro* li_carro, Lista_func* li_func, int placa_posicao, struct carro_lista car, struct funcionario func, int var );

