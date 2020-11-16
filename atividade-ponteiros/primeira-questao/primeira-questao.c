#include<stdio.h>
#include<stdlib.h>

int main(void) {
    int x = 0, y = 0, *p, u;
    p = &y;
    x = *p;
    // y++;
    // (*p)++;
    // (*p) += x;
    x = p + 3;

    // Endereço de y = 6422292
    printf("p: %d \n", p);
    printf("y: %d \n", y);
    printf("x: %d \n", x);
    printf("*p: %d \n", *p);


}