/*
    Tipos Rotações:
    
    "Simples":
        - O nó desbalanceado e seu filho estão no mesmo sentido da inclinação
    
    "Duplas":
        - O nó está desbalanceado e seu filho esta inclinado no sentido inverso ao pai
        - Equivale a duas rotações "simples"

        - Existem duas rotações "simples" e duas "duplas"
            - rotação a "direita" e a "esquerda"
    
    "Rotação simples à esquerda":
        - O nó C é inserido na sub-árvore "direita" da sub-árvore "direita" de "A"
        - O nó intermediário "B" deve ser escolhido para ser a raiz da árvore resultante
    
    "Rotação simples à direita":
        - O nó C é inserido na sub-árvore "esquerda" da sub-árvore "esquerda" de "A"
        - O nó intermediário "B" deve ser escolhido para ser a raiz da árvore resultante
    
    "Rotação dupla à esquerda":
        - O nó C é inserido na sub-árvore "esquerda" da sub-árvore "direita" de "A"
        - O nó C deve ser escolhido para ser a raiz da árvore resultante
    
    "Rotação dupla à direita":
        - O nó C é inserido na sub-árvore "direita" da sub-árvore da "esquerda" de "A"
        - O nó C deve ser escolhido para ser a raiz da árvore resultante
*/

typedef struct NO* ArvAVL;

int insere_ArvAVL(ArvAVL *raiz, int valor);

int remove_ArvAVL(ArvAVL *raiz, int valor);