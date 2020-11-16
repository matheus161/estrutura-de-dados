#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
    char **paragrafo, resposta;
    int quant_paragrafos, i, j, t, p, tamanho, tamanho1;   

    printf("Digite a quantidade de paragrafos \n");
    scanf("%d",&quant_paragrafos);
    setbuf(stdin, NULL);

    // Alocando a quantidade de paragráfos
    paragrafo = (char **)(malloc((int)quant_paragrafos*sizeof(char)));

    printf("Digite SAIR para sair. \n");
    for (t = 0; t < quant_paragrafos; t++){        
        // Alocando espaço para a minha dimensão 'j'
        paragrafo[t] = (char *)(malloc(100000*sizeof(char)));           
        printf("Digite o paragrafo %d \n", t + 1);
        scanf("%s", paragrafo[t]);
        tamanho1 = strlen(paragrafo);
        char ** realloc_1_paragrafo = (char **)(realloc(paragrafo[t],tamanho1*sizeof(char)));
        // paragrafo[t] = realloc_1_paragrafo;
        // free(realloc_1_paragrafo);

        // Se encontrar comnando sair, sai.
        if(!strcmp(paragrafo[t], "SAIR")) break;       
        
    }       

    for (i = 0; i < t; i++){
       printf("\n");
       for (j = 0; paragrafo[i][j]; j++)
       {           
           putchar(paragrafo[i][j]);
       }
       
    }


    printf("\n Deseja alterar algum paragrafo ? ");
    scanf("%s", &resposta);
    if (resposta == 'N' || resposta == 'n')
    {
        exit(0);
    }
    
    
    do{
        printf(" Qual paragrafo deseja editar ? ");
        scanf("%d", &p);
        
        while (p > t)
        {
            printf("Digite um paragrafo valido: ");
            scanf("%d", &p);
        }    
               
        printf("Edite o paragrafo %d \n ", p );
        scanf("%s", paragrafo[p- 1]);
        tamanho = strlen(paragrafo[p - 1]);

        // Realocando a memoria do paragrafo
        char * realloc_paragrafo = (char *)(realloc(paragrafo[p - 1],tamanho*sizeof(char)));   

        if (realloc_paragrafo != NULL)
        {
            paragrafo[p - 1] = realloc_paragrafo;
        }        

        printf(" Deseja alterar mais algum paragrafo ? ");
        scanf("%s", &resposta);  
    }while (resposta != 'n');
    
    for (i = 0; i < t; i++){
        printf("\n");
    for (j = 0; paragrafo[i][j]; j++)
       {           
           putchar(paragrafo[i][j]);
       }
       
    }
    
free(paragrafo);



return 0;
}

