#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "estacionamento.h"

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
    // printf("Funcionario: %c\n", func.nome);
    li->qtd++;
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

//Ordenação

int insertion_sort(Lista_func* li, struct funcionario func) {    
    for (int i = 1; i < MAX; i++){
        int ref = li->func[i].idade; 
        int j = i - 1;
        while ((j >= 0) && (ref < li->func[j].idade))
        {
            li->func[j + 1].idade = li->func[j].idade; 
            j = j -1; 
        }
    li->func[j + 1].idade = ref; 
    printf("TALVEZ EU TENHA ESTRADO AQUI\n", li->func[i].idade);
    }    
return 0;
}

//--------------------- LISTA DE CARROS
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
    //printf("Carro %c PASSOU POR AQUI\n", car.name);
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
        li_carro->qtd--; 
        li_func->qtd--;   
        acum++;
        aux++;
    }

    printf("Carro %c retirado pelo funcionario X%d\n", car.name, func.nome);
    printf("Carro %c saiu! Total = %d \n",car.name, aux );  
    li_carro->qtd++;
    
    //Retornando os carros para a pilha
    for (i = li_carro->qtd; i < var; i++)
    {
        // car = li_carro->carro[i];
        // printf("Carro %c voltou \n", car.name);
        li_carro->qtd++;
    }
    return 1;
}


//Programa principal
int main(){
    struct carro car[MAX];
    struct carro_lista car2[20]; //= {{95957, 'A', 10},{95958, 'B', 10},{95959, 'C', 5}};
    struct funcionario fun[N];//= {{1,10,1},{2,8,2},{3,15,3}};
    Pilha* pi = cria_Pilha();    
    Lista_func* li = cria_Lista();
    int i, j, k, x = 0, qtd = 0, aux = 3, z = 1, hora = 1, var = 2, y, manobras = 0;
    float acum = 0, acum2 = 0;   

    srand(time(NULL));
    
    //Preenchendo 'struct funcionario' de forma random
    for (j = 0; j < N; j++)
    {        
        fun[j].nome = aux; //+ (rand() % 50);
        fun[j].nome = z++;
        fun[j].idade = 18 + (rand() % 65);
        fun[j].ID = 10000 + (rand() % 99999);
        aux--;
        insere_lista_final(li,fun[j]);
            insertion_sort(li, fun[j]);
    }



    //Enquanto meu estacionamento não bater a meta vou adicionando carros e retirando(Sempre de 3 em 3)
    do
    {
        printf("Estacionamento vazio\n");
        //Preenchendo 'struct carro' de forma random
        for (i = 0; i < MAX; i++)
        {
            car[i].name = 'A' + (char)(rand() % 26);
            car[i].placa = 9000 + (rand() % 9999);
            car[i].horas = var + 2;
            //car[i].horas = (hora++) + (rand() % 10);
            //hora = car[i].horas; 

            //Guardando os valores em car2 para serem utilizando no dia seguinte
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
    int aux2 = MAX;
    int l = 0, m = 0;
    int var2 = 0;
    int teste = 3;
    Lista_carro* li_carro = cria_Lista_carro();
    do
    {
        printf("Estacionamento vazio\n");
        var2 = 0;
        for (l; l < aux2; l++)
        {
            insere_lista_final_carro(li_carro,car2[l]);
            printf("O carro %c entrou. Total = %d \n", car2[l].name, var2 + 1); 
            var2++;
               
        }
            printf("Estacionamento lotado!\n");

        
        for (m; m < aux2; m++)
        {                    
            if (car2[m].placa == car2[y].placa && acum2 < 300)
            {                                           
                printf("Carro %c devera sair. \n", car2[m].name);
                remove_Lista_manobrista(li_carro,li, y, car2[MAX], fun[MAX], aux2);
                acum2 = (car2[m].horas*12) + acum2;
                printf("Valor pago %.0f\n", acum2);                                     
            }
            y++;
        }
            teste = l + 3;
            aux2 = l + 3;
            //printf("Valor de L: %d, valor de aux2 %d: e valor de M: %d\n", l, aux2, m);
    } while (acum2 < 300); 
    
    free(pi);
    free(li_carro);
    free(li);

    
    return 0;
}