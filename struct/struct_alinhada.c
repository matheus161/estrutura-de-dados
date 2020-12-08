#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tp_endereco{
    char rua[40];
    int numero;
    char bairro[40];
    char cidade[40];
    char estado[3];
    int cep;
};

struct tp_data_nascimento
{
    int dia;
    int mes;
    int ano;
};

struct cadastro_cliente
{
    char nome_cliente[40];
    int telefone;

    //Declarando variavel associada a struct tp_endereco
    struct tp_endereco endereco;

    //Declarando variavel associada a struct data_nascimento
    struct tp_data_nascimento data_nascimento;
}cad_cliente[2];


//Programa principal
int main(void){
int i;

//Armazenando os dados do cadastro dentro da struct cad_cliente
for (i = 0; i < 2; i++)
{
    printf("\nDigite o nome do cliente: ");
    fflush(stdin);
    gets(cad_cliente[i].nome_cliente);

    printf("\nDigite o telefone do cliente: ");
    scanf("%d", &cad_cliente[i].telefone);

    printf("\nDigite a rua: ");
    fflush(stdin);
    gets(cad_cliente[i].endereco.rua);

    printf("\nDigite o número da casa: ");
    scanf("%d", &cad_cliente[i].endereco.numero);

    printf("\nDigite o bairro da casa: ");
    fflush(stdin);
    gets(cad_cliente[i].endereco.bairro);
}

for (int k = 0; k < 2; k++)
{
    printf("\n Nome cliente: %s", cad_cliente[k].nome_cliente);
    printf("\n Telefone: %d", cad_cliente[k].telefone);
    printf("\n Rua: %s", cad_cliente[k].endereco.rua);
    printf("\n Numero: %d", cad_cliente[k].endereco.numero);
    printf("\n Bairro: %s", cad_cliente[k].endereco.bairro);
}


   
    system("pause");
    return 0;
}