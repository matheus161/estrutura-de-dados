#include<stdio.h>

int main(void) {
    int x = 10;
    double y = 20.50;
    char z = 'a';

    int *pX = &x;
    double *pY = &y;
    char *pZ = &x;

    // double soma = *pX + *pY;
    int *resultado;
    resultado =  6422280;

    printf("Valor x %d\n", *resultado);
    // printf("Valor soma %f\n", soma);
    // printf("Endereco x = %d, Valor x = %d\n", pX, *pX );
    // printf("Endereco y = %d, Valor y = %f\n", pY, *pY );
    printf("Endereco z = %d, Valor z = %c\n", pZ, *pZ );

    getchar();

    return 0;
}