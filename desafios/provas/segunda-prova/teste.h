#define MAX 3

struct carro{
    int placa;
    char name;
    int horas;
};

/* ---------- Árvore Binária ---------- */ 
typedef struct NO* ArvBin;

ArvBin* cria_ArvBin();

int insere_ArvBin(ArvBin *raiz, int valor);

// int remove_ArvBin(ArvBin *raiz, int valor);

int remove_ArvBin( ArvBin *raiz, int valor);

int consulta_ArvBin(ArvBin *raiz, int valor);