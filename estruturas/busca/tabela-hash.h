/*
    - Generalização da ideia de Array
    - Utiliza uma função para espalhar os elementos que queremos armazenar na tabela
    - O espalhamento faz com que os elementos fiquem dispersos de forma não ordenada dentro do array que define a tabela

    - Uma tabela hash permite a associação de "valoes" a "chaves"
    
    "chave": parte da informação que compõe o elemento a ser inserido ou buscado na tabela 
    "valor": é a posição (índice) onde o elemento se encontra no "array" que define a tabela

    - Assim, a partir da "chave" podemos acessar de forma rápida uma determinada posição do "array"
    - Na média, essa operação tem custo "O(1)".

    - Utiliza uma estrutura similar a uma "Lista Sequencial Estática"
    - Utiliza um "array" para armazenar os elementos
*/

struct aluno {
    int matricula;
    char nome[30];
    float n1,n2,n3;
};
typedef struct hash Hash;

Hash* criaHash(int TABLE_SIZE);

void liberaHash(Hash* ha);

int valorString(char *str);

int insereHash_SemColisao(Hash* ha, struct aluno al);

int buscaHash_SemColisao(Hash* ha, int mat, struct aluno* al);

int insereHash_EnderAberto(Hash* ha, struct aluno al);

int buscaHash_EnderAberto(Hash* ha, int mat, struct aluno* al);