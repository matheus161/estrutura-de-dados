#include<stdio.h>
#include<stdlib.h>

int insertion_sort(int quant_elementos, int p[]) {
    for ( int i = 1; i < quant_elementos; i++){
        int ref = p[i]; 
        int j = i - 1; 

        while ((j >= 0) && (ref < p[j]))
        {
            p[j + 1] = p[j]; 
            j = j -1; 
        }
    p[j + 1] = ref; 
    }
return 0;
}

int printed(int quant_elementos, int p[]) {
    printf("O vetor em ordem decrescente e: ");
    int i;
    for (i = (quant_elementos - 1); i >= 0; i--)
    {
        printf(" %d ", p[i]);
    }
return 0;       
}

int main() {
    int *p;
    int i, quant_elementos;

    printf("Digite a quantidade de elementos do vetor \n");
    scanf("%d", &quant_elementos);


    p = (int *)(malloc(quant_elementos * sizeof(int)));
    if (p == NULL)
    {
        printf("\nError de alocacao de memoria");
        exit(1);
    }

    for (i = 0; i < quant_elementos; i++)
    {
        printf("Insira o valor de indice [%d] \n", (i + 1) );
        scanf("%d", &p[i]);
    }    

    insertion_sort(quant_elementos, p);
    printed(quant_elementos, p);

    
    
return 0;
}