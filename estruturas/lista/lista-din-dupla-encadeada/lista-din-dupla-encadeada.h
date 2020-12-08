/* 
    Cada elemento é tratado como um ponteiro que é alocado
    dinamicamente, a medida que os dados são inseridos.
    Para guardar o primeiro elemento, utilzamos um 
    "ponteiro para ponteiro"

    Um "ponteiro para ponteiro" pode guardar o endereço de 
    um "ponteiro".

    Assim, fica fácil mudar quem está no inicio da lista 
    mudando o "conteúdo" do "ponteiro para ponteiro"

    Acesso indireto aos elementos

    Necessidade de percorrer a lista para acesar um elemento
*/

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

// ponteiro do tipo lista, vou usar em meu programa principal
typedef struct elemento* Lista;

Lista* cria_lista();

void libera_lista(Lista* li);

int tamanho_lista(Lista* li);

int lista_vazia(Lista* li);

int insere_aluno_inicio(Lista* li, struct aluno al);

int insere_lista_final (Lista *li, struct aluno al);

int insere_lista_ordenada(Lista* li, struct aluno al);

int remove_lista_inicio(Lista *li, struct aluno al);

int remove_lista_final(Lista *li, struct aluno al);

int remove_lista(Lista *li, int matricula);

int consulta_lista(Lista* li, int pos, struct aluno *al);

int consulta_lista(Lista* li,int mat, struct aluno *al);