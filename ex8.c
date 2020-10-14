#include <stdio.h>
#include <stdlib.h>

typedef struct st_lista
{
    int c;
    struct st_lista * prox;
}lista;

lista *buscar(lista *cabeca, int x)
{
    lista *pl=cabeca;
    while(pl!=NULL)
    {
        if(pl->c==x)
            return pl;
        pl=pl->prox;
    }
    return NULL;
}
void inserir(lista **cabeca, int x)
{
    lista *pl=*cabeca;
    lista *plant=NULL;
    while(pl!=NULL)
    {
        plant=pl;
        pl=pl->prox;
    }
    pl=malloc(sizeof(lista));
    pl->c=x;
    pl->prox=NULL;
    if(plant!=NULL)
        plant->prox=pl;
    else
        *cabeca=pl;
}
void remover(lista **cabeca, lista *r)
{
    lista *pl=*cabeca;
    lista *plant=NULL;
    if(r==NULL)
        return;
    while(pl!=NULL && pl!=r)
    {
        plant=pl;
        pl=pl->prox;
    }
    if(pl==NULL)
        return;
    if(plant!=NULL)
        plant->prox=pl->prox;
    else
        *cabeca=pl->prox;
    free(pl);
    return;
}

lista *anterior(lista *cabeca, lista *r)
{
    lista *pl=cabeca, *plant=NULL;
    if(r==NULL)
        return NULL;
    while(pl!=NULL && pl!=r)
    {
        plant=pl;
        pl=pl->prox;
    }
    return plant;
}

void imprimir(lista *cabeca)
{
    lista *pl=cabeca;
    while(pl!=NULL)
    {
        printf("%d->", pl->c);
        pl=pl->prox;
    }
    printf("NULL\n");
}
int main(void)
{
    lista *l1=NULL, *b=NULL, *a=NULL;

    inserir(&l1, 1);
    imprimir(l1);
    inserir(&l1, 2);
    imprimir(l1);
    inserir(&l1, 3);
    imprimir(l1);
    b=buscar(l1, 3);
    if(b!=NULL)
        printf("b->c; %d\n", b->c);
    a=anterior(l1, b);
    if(a!=NULL)
        printf("a->c; %d\n", a->c);
    b=buscar(l1, 1);
    remover(&l1, b);
}
