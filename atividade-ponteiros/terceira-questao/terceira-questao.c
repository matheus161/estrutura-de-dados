#include<stdio.h>
#include<stdlib.h>

int main() {
    char palavra;
    char *ponteiro = (char *)(malloc(15*sizeof(char)));
    int i = 0;

    printf("Digite a palavra que sera verificada \n");
    while ((palavra = getchar()) != '\n'){
        ponteiro[i] = palavra;
        i++;       
    }       
    
    for (int j = 0; j < i; j++)
    {
        if (ponteiro[j] == 'a' || ponteiro[j] == 'e' || ponteiro[j] == 'i'
            || ponteiro[j] == 'o' || ponteiro[j] == 'u')
        {
            printf("%c", ponteiro[j]);
        }       
        
    }

    free(ponteiro); 
    
return 0;
}