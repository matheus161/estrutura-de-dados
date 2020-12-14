/*------------ PILHA ------------ */
#define MAX 3
struct carro{
    int placa;
    char name;
    int horas;
};
typedef struct pilha Pilha;

Pilha* cria_Pilha();

int Pilha_cheia(Pilha* pi);

int insere_Pilha(Pilha* pi, struct carro carro);

int remove_Pilha(Pilha* pi, int placa);

/*------------ FILA ------------ */
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


// -------------- Pilha de carros

int remove_Pilha_manobrista(Pilha* pi, Lista_func* li, int placa_posicao,struct carro car,struct funcionario func );

// void ponto_funcionario(struct funcionario fun);

int insertion_sort(Lista_func* li, struct funcionario func);



// -------------- lista de carros
struct carro_lista{
    int placa;
    char name;
    int horas;
};
typedef struct lista_carro Lista_carro;

Lista_carro* cria_Lista_carro();

int insere_lista_final_carro(Lista_carro* li, struct carro_lista car);

int remove_Lista_manobrista(Lista_carro* li_carro, Lista_func* li_func, int placa_posicao, struct carro_lista car, struct funcionario func, int var );