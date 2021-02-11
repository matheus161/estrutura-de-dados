#include <stdio.h>
#include <stdlib.h>
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 
typedef struct no{
    int info;
    struct no * esq, *dir;
}NoArv;
 
NoArv* arv_criavazia (void)
{
 return NULL;
}
 
 
 
NoArv* arv_libera (NoArv* a){
 if (!arv_vazia(a)){
    arv_libera(a->esq); /* libera sae */
    arv_libera(a->dir); /* libera sad */
    free(a); /* libera raiz */
 }
 return NULL;
}
 
int arv_vazia (NoArv* a)
{
 return a==NULL;
}
 
NoArv* arv_buscar (NoArv* r, int v)
{
 if (r == NULL)
    return NULL;
 else if (r->info > v)
    return arv_buscar (r->esq, v);
 else if (r->info < v)
    return arv_buscar (r->dir, v);
 else return r;
}
 
void arv_preordem (NoArv* a)
{
 if (!arv_vazia(a)){
    printf("%d ",a->info); /* mostra raiz */
    arv_preordem(a->esq); /* mostra sae */
    arv_preordem(a->dir); /* mostra sad */
 }
}
 
 
void arv_emordem (NoArv* a)
{
 if (a != NULL) {
    arv_emordem(a->esq);
    printf("%d ",a->info);
    arv_emordem(a->dir);
 }
}
 
void arv_posordem (NoArv* a)
{
 if (!arv_vazia(a)){
    arv_posordem(a->esq); /* mostra sae */
    arv_posordem(a->dir); /* mostra sad */
    printf("%d ",a->info); /* mostra raiz */
 }
}
 
NoArv* arv_inserir (NoArv* a, int v)
{
 // se for folha faz a insercao
 if (a==NULL) {
    a = (NoArv*)malloc(sizeof(NoArv));
    a->info = v;
    a->esq = a->dir = NULL;
 }
 else if (v < a->info) // se for menor sub arvore da esquerda
    a->esq = arv_inserir(a->esq,v);
 else if (v > a->info) // se for maior sub arvore da direita
    a->dir = arv_inserir(a->dir,v);
 return a;
}
 
NoArv* arv_retirar (NoArv* r, int v)
{
 if (r == NULL)
    return NULL;
 else if (r->info > v)
    r->esq = arv_retirar(r->esq, v);
 else if (r->info < v)
    r->dir = arv_retirar(r->dir, v);
 else { /* achou o nó a remover */
 /* nó sem filhos */
    if (r->esq == NULL && r->dir == NULL) {
       free (r);
       r = NULL;
    }
    /* nó só tem filho à direita */
    else if (r->esq == NULL) {
       NoArv* t = r;
       r = r->dir;
       free (t);
    }
    /* só tem filho à esquerda */
    else if (r->dir == NULL) {
       NoArv* t = r;
       r = r->esq;
       free (t);
    }
    /* nó tem os dois filhos */
    else {
       NoArv* f = r->esq;
       while (f->dir != NULL) {
          f = f->dir;
       }
       r->info = f->info; /* troca as informações */
       f->info = v;
       r->esq = arv_retirar(r->esq,v);
    }
 }
return r;
}
 
int main(int argc, char *argv[]) {
 NoArv* a;
 a=arv_criavazia();
 a=arv_inserir(a, 6);
 a=arv_inserir(a, 4);
 a=arv_inserir(a, 8);
 a=arv_inserir(a, 2);
 a=arv_inserir(a, 1);
 a=arv_inserir(a, 3);
 a=arv_inserir(a, 5);
 a=arv_inserir(a, 9);
 a=arv_inserir(a, 7);
 printf("\nEm Ordem... ");
 arv_emordem(a);
 printf("\nPre Ordem... ");
 arv_preordem(a);
 printf("\nPos Ordem... ");
 arv_posordem(a);
 return 0;
}