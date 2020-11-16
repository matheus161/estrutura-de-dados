#include<stdio.h>
#include<stdlib.h>


int main(void) {
//   Código 1
//   int x = 10;
//   double a = 20.5;
//   int v[5] = {1,2,3,4,5};
  
//   printf("Tamanho x: %d \n", sizeof(x));
//   printf("Tamanho a: %d  \n", sizeof(a));
//   printf("Tamanho v: %d, numero de termos: %lu  \n", sizeof(v), (sizeof(v) / sizeof(v[0])));

//============================================================================================

// Código 2
//   int x = 10, y = 20;
//   double a = 20.5, b = 35.8;
  
//   printf("End x: %d, Valor %d \n",&x,x);
//   printf("End y: %d, Valor %d \n",&y,y);
//   printf("End a: %d, Valor %.1f \n",&a,a);
//   printf("End b: %d, Valor %.1f \n",&b,b);

//=============================================================================================

//Código 3
//   int *pi = NULL;
//   double *pd = NULL;
  
//   printf("End pi: %d, Conteudo pi: %d, Tamanho: %d \n",&pi,pi, sizeof(pi));
//   printf("End pd: %d, Conteudo pd: %d, Tamanho: %d \n",&pd,pd, sizeof(pd)); 
// }

// Código 3.1
  // int x = 4;
  // pi = &x;
  
  // printf("End x: %d, Conteudo x: %d \n",&x, x);
  // Será o mesmo endereço de x, pois o ponteiro guarda um endereço
  // printf("End pi: %d, Conteudo pi: %d \n",&pi, pi); 


// Código 3.2
  // printf("Conteudo para onde pi aponta: %d \n", *pi);


// Código 3.3
// int y = 10;
// printf("Esquerdo: %d, Direito: %d \n", (*pi + 1), *(pi + 1));


//Código 3.4
// *pi = 5;
// printf("End x: %d, Conteudo x: %d \n", &x, x);
// printf("End pi: %d, Conteudo pi: %d \n", &pi, pi);

//=============================================================================================


//Código 4
// int x = 4;
// float y = 5.4;
// printf("X = %d, Y =  %d \n", &x, &y);

// O tipo da variável ponteiro não influencia na memória consumidda, apensas na interpretação da informação
// void *pi = NULL;

// pi = &x;
// printf("pi apontando para x %d \n", pi);
// printf("*pi apontando para x %d \n", *(int *)pi);
// printf("&pi apontando para x %d \n", &pi);
// printf("==================================== \n");

// pi = &y;
// printf("pi apontando para y %d \n", pi);
// printf("*pi apontando para y %f \n", *(float *)pi);
// printf("&pi apontando para y %d \n", &pi);
// printf("==================================== \n");

//=============================================================================================

// Código 5
// int vet[5] = {1,2,3,4,5};
// printf("vet %d \n", vet);
// printf("&vet %d \n", &vet);

// Código 5.1
// printf("%d %d %d %d %d \n", &vet[0], &vet[1], &vet[2], &vet[3], &vet[4]);
// printf("%d %d %d %d %d \n", *&vet[0], *&vet[1], *&vet[2], *&vet[3], *&vet[4]);

// Código 5.3
// int *pvet = vet;
// printf("")


//=============================================================================================

//Código 6 
// int pvet[][]; //Tem que fixar o tamanho dos vetores;
// int vet[5] = {1,2,3,4,5};
// int vet2[2] = {6,5};

// int *pvet[2];
// pvet[0] = vet;
// pvet[1] = vet2;
// printf("%d %d \n", pvet[0][2], pvet[1][1]);

//=============================================================================================

//Código 7
// char *nomeAux = "MATHEUS LIMA";
// printf("%s", nomeAux);

// char nome1[7] = "MATHEUS";
// char nome2[6] = "LIMAAA";
// char *nomeCompleto[2]; 
// char nomeCompleto[][]; // Tem que fixar o tamanho dos vetores
// nomeCompleto[0] = nome1;
// nomeCompleto[1] = nome2;
// printf("%c %c \n", nomeCompleto[0][0], nomeCompleto[1][5]);

//=============================================================================================

//Código 8
int tam = 20;
int *pvet = malloc(tam * sizeof(int));
// int *pvet2 = calloc(tam, sizeof(int));
// printf("%d %d \n", pvet, pvet2);
// printf("%d %d \n", pvet[0], pvet2[0]);
printf("pvet : %d %d %d %d \n", pvet, pvet[0], pvet[1], pvet[2]);

pvet[0] = 1;
pvet[1] = 2;
pvet[2] = 3;
printf("pvet : %d %d %d %d \n", pvet, pvet[0], pvet[1], pvet[2]);

//Código 8.1
// pvet = realloc(pvet, 2 * sizeof(int));
// printf("pvet : %d %d %d %d \n", pvet, pvet[0], pvet[1], pvet[2]);

// Para liberar memória após alocar;
free(pvet);
//free(pvet2);
printf("pvet : %d %d %d %d \n", pvet, pvet[0], pvet[1], pvet[2]);

}