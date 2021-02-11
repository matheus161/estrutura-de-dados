#include <stdio.h>
#include <stdlib.h>
#include "tabela-hash.h"

//Definição do tipo Hash
struct hash {
    int qtd, TABLE_SIZE;
    struct aluno **itens;
};

/*  
    Vou criar um vetor do tamanho Table_Size,
    onde em cada posição do vetor eu posso guardar
    um endereço de um elemento que fica armazenado na tabela 
*/
/*
    Apenas armazeno o endereço para a estrutura que
    contém os dados do aluno e não os dados em si
*/

Hash* criaHash(int TABLE_SIZE) {
    Hash* ha = (Hash*)malloc(sizeof(Hash));
    if(ha != NULL) {
        int i;
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (struct aluno**)malloc(TABLE_SIZE * sizeof(struct aluno*)); //ponteiro para ponteiro
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

void liberaHash(Hash* ha) {
    if(ha != NULL) {
        int i;
        for (i = 0; i < ha->TABLE_SIZE; i++){
            if(ha->itens[i] != NULL)
                free(ha->itens[i]);
        }
        free(ha->itens);
        free(ha);
    }
}

int chaveDivisao(int chave, int TABLE_SIZE) {
    return (chave & 0x7FFFFFFF) % TABLE_SIZE; //bit-a-bit evita o overflow, eliminando o bit de sinal do valor chave
}

int chaveMultiplicacao(int chave, int TABLE_SIZE) {
    float A = 0.6180339887; //constante 0 < A < 1
    float val = chave * A;
    val = val - (int) val;
    return (int) (TABLE_SIZE * val);
}

int chaveDobra(int chave, int TABLE_SIZE) {
    int num_bits = 10;
    int parte1 = chave >> num_bits;//desloco 10bits a direita
    int parte2 = chave & (TABLE_SIZE-1);
    return (parte1 ^ parte2);
}

//trabalhando com strings(utilizar a posição das letras)
int valorString(char *str) {
    int i, valor = 7;
    int tam = strlen(str);
    for(i=0; i < tam; i++)
        valor = 31 * valor + (int) str[i];//valor ASCII do caractere
    return valor;
}

int insereHash_SemColisao(Hash* ha, struct aluno al) {
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;
    int chave = al.matricula;
    //int chave = valorString(al.nome);
    int pos = chaveDivisao(chave,ha->TABLE_SIZE);
    struct aluno* novo;
    novo = (struct aluno*)malloc(sizeof(struct aluno));
    if(novo == NULL)
        return 0;
    *novo = al;
    ha->itens[pos] = novo;
    ha->qtd++;
    return 1;
}

int buscaHash_SemColisao(Hash* ha, int mat, struct aluno* al) {
    if(ha == NULL)
        return 0;
    
    int pos = chaveDivisao(mat,ha->TABLE_SIZE);
    if(ha->itens[pos] == NULL);
        return 0;
    *al = *(ha->itens[pos]);
    return 1;
}

//Tratamento Colisões
int sondagemLinear(int pos, int i, int TABLE_SIZE) {//vai pulando de um e um procurando uma posição vazia
    return ((pos + i) & 0x7FFFFFFF) % TABLE_SIZE;
}

int sondagemQuadratica(int pos, int i, int TABLE_SIZE) {//procura posições mais espalhadas
    pos = pos + 2*i + 5*i*i;
    return (pos & 0x7FFFFFFF) & TABLE_SIZE;
}

int duploHash(int H1, int chave, int i, int TABLE_SIZE) { //i representa o número de colisões
    int H2 = chaveDivisao(chave,TABLE_SIZE-1) + 1; // caso tenha colisão o H2 entra em ação
    return ((H1 + i*H2) & 0X7FFFFFFF) % TABLE_SIZE;
}

//Inserindo com tratamento de colisões
int insereHash_EnderAberto(Hash* ha, struct aluno al) {
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;
    int chave = al.matricula;
    int i, pos, newPos;
    pos = chaveDivisao(chave, ha->TABLE_SIZE);
    for (i = 0; i < ha->TABLE_SIZE; i++) {
        newPos = sondagemLinear(pos, i, ha->TABLE_SIZE);//poderia ter usado qualquer outro
        if(ha->itens[newPos] == NULL) { //se naquela posição eu não tenho nenhum valor
            struct aluno* novo;
            novo = (struct aluno*)malloc(sizeof(struct aluno));
            if(novo == NULL)
                return 0;
            *novo = al;
            ha->itens[newPos] = novo;
            ha->qtd++;
            return 1;
        }
    }
    return 0;
}

//Buscando com tratamento de colisões
int buscaHash_EnderAberto(Hash* ha, int mat, struct aluno* al) {
    if(ha == NULL)
        return 0;
    int i, pos, newPos;
    pos = chaveDivisao(mat, ha->TABLE_SIZE);
    for (i = 0; i < ha->TABLE_SIZE; i++) {
        newPos = sondagemLinear(pos, i, ha->TABLE_SIZE);
        if(ha->itens[newPos] == NULL)
            return 0;
        if(ha->itens[newPos]->matricula == mat) {//Se eu encontrei algo e não é valor, vou recalcular até achar o que eu quero
            *al = *(ha->itens[newPos]);
            return 1;
        }
    }
    return 0;
}

int main() {
    //Escolher sempre números primos e evitar valores "potência de dois"
    Hash* ha = criaHash(1427);
    liberaHash(ha);
    //int x = insereHash_SemColisao(ha,al);
    //int x = buscaHash_SemColisao(ha, mat, $al);
    //int x = insereHash_EnderAberto(ha, al);
    //int x = buscaHash_EnderAberto(ha, mat, &al);
}