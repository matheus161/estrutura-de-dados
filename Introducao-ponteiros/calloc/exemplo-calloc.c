#include<stdio.h>
#include<stdlib.h>

int main() {
    int *p;
    p = (int *) calloc(5, sizeof(int));
    if (p == NULL)
    {
        printf("Erro: Sem Memória \n");
        exit(1);
    }

    int i;
    for (i = 0; i < 5; i++)
    {
        printf("Digito p[%d]:", i);
        scanf("%d", &p[i]);
    }
    
    //libere memória alocada 
    free(p);
}