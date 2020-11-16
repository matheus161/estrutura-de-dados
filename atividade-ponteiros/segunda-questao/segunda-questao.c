#include<stdio.h>
#include<stdlib.h>

int maior (int v[]) {
int i = 0;
int maior = 0;
    do{
      if (v[i] > maior ){
            maior = v[i];
        }
        i++;        
    } while (i < 10);   

    printf("Maior valor do vetor: %d, seu endereco: %d \n", maior, &maior);
}

int menor (int v[]) {
int i = 0;
int menor;
    do{
      if (v[i] < menor ){
            menor = v[i];
        }
        i++;        
    } while (i < 10);   

    printf("Menor valor do vetor: %d, seu endereco: %d \n", menor, &menor);
}

// int vetor() {
// int v[10];
// int acum;
// int *ponteiroVetor = (int *)(malloc(10 * sizeof(int)));
// ponteiroVetor = &v;
//     for (int i = 0; i < 10; i++){
//         printf("Insira o elemento de numero %d \n", i + 1);
//         scanf("%d", &ponteiroVetor[i]);
//         acum += ponteiroVetor[i];
//     }
//     int * ponteiroAcum = (int *)(malloc(acum*sizeof(int)));

//     printf("Endereco da primeira posicao do vetor: %d \n", &ponteiroVetor[0]);
//     printf("Endereco da ultima posicao do vetor: %d \n", &ponteiroVetor[9]);

//     maior(ponteiroVetor);
//     menor(ponteiroVetor);
 
//     free(ponteiroVetor);
//     free(ponteiroAcum);

// return *ponteiroAcum;
// }

//Duvida como mandar um ponteiro de algumas daquelas funções pra a main? Ex: Calcular a media dentro de vetor e trazer
int main() {
    int t[10];
    int i = 0; 
    int v[10];
    float acum = 0;   
    int *ponteiroVetor = (int *)(malloc(10 * sizeof(int)));
    ponteiroVetor = &v;

    for (int i = 0; i < 10; i++){
        printf("Insira o elemento de numero %d \n", i + 1);
        scanf("%d", &ponteiroVetor[i]);
        acum = ponteiroVetor[i] + acum;
    }
    int * ponteiroAcum = (int *)(malloc(acum*sizeof(int)));
    float media = acum / 10;

    maior(ponteiroVetor);
    menor(ponteiroVetor);
    printf("Endereco da primeira posicao do vetor: %d \n", &ponteiroVetor[0]);
    printf("Endereco da ultima posicao do vetor: %d \n", &ponteiroVetor[9]);

   
    

    while (i < 10){
        if (v[i] > media){            
            t[i] = (v[i] - media);
            i++;
        } else {
            t[i] = v[i];
            i++;
        }        
    }  
    maior(t);
    menor(t);
    free(ponteiroVetor);
    free(ponteiroAcum);

return 0;
}