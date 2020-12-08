#include<stdio.h>
int main(void){

    struct ficha_aluno //tipo de dado
    {
        char nome[40];
        int numero;
        float nota;
    };//definição da struct

    struct ficha_aluno aluno; //Criando uma variável

    printf("\n------- Cadastro de aluno ---------\n\n\n");

    printf("\nDigite o nome do aluno ");
    fgets(aluno.nome, 40, stdin);// Quero armazenar 40 caracteres que virão do teclado

    printf("\nDigite o numero do aluno ");
    scanf("%d", &aluno.numero);

    printf("\nDigite a nota do aluno ");
    scanf("%f", &aluno.nota);
    
    printf("\nLendo os dados da struct ");
    printf("\nNome: %s", aluno.nome);
    printf("\nNumero: %d", aluno.numero);    
    printf("\nNota: %.2f", aluno.nota);

    return 0;
}