#include<stdio.h>

// int main(void) {
//     int x;
//     x = 10;

//     int *ponteiro;
    // Declaro um ponteiro que recebe o endereço de X;
    // ponteiro = &x;

    // O ponteiro irá mostrar o valor contido no endereço 
    // que ele está referenciado
//     printf("%d", *ponteiro);

//     getchar();

//     return 0;
// }

int main(void) {
    int x = 10;
    int *ponteiro;
    ponteiro = &x;

    int y = 20;
    *ponteiro = y;

    printf("%d %d", x, y );

    getchar();

    return 0;
}