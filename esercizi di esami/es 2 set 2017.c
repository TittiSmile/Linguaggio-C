/*scrivere  una funzione che abbia come argomento un puntatore l alla testa di una lista di interi. tale funzione
deve restituire una lista doppiamente concatenata con elemento fittizio contenente gli stessi numeri presenti in l.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct LISTA
{
int primo;
struct LISTA*next;
}nodo;

typedef struct LISTA_DOPPIA
{
int primo;
struct LISTA_DOPPIA*prev;
struct LISTA_DOPPIA*next;
}doppia;

nodo*nelem(int a);
nodo*intesta(nodo*p,int a);
nodo*incoda(nodo*p,int a);
nodo*casuale(nodo*p,int dim);
void stampa(nodo*p);
doppia*nelem2(doppia*tmp2,nodo*p);
doppia*ritdop(nodo*p);
void stampa2(doppia*p2);

int main ()
{
    nodo*l1=NULL;
    doppia*d1=NULL;
    int dim,i,n;

    printf("quanto vuoi grande la tua lista?  ");
    scanf("%d",&dim);
    l1=casuale(l1,dim);
    stampa(l1);

    printf("\nritorno la lista doppiamente concatenata: ");
    d1=ritdop(l1);
    stampa2(d1);



    return 0;
}

nodo*nelem(int a)
{
    nodo*q=(nodo*)malloc(sizeof(nodo));
    q->primo=a;
    q->next=NULL;
    return q;
}

nodo*intesta(nodo*p,int a)
{
    nodo*q=nelem(a);
    q->next=p;
    return q;
}

nodo*incoda(nodo*p,int a)
{
    if(p==NULL)
    {
        p=nelem(a);
    }
    else
    {
        p->next=incoda(p->next,a);
    }
    return p;
}

nodo*casuale(nodo*p,int dim)
{
    int i=0,n;
    srand((unsigned)time(NULL));
    for(i=0;i<dim;i++)
    {
        n=rand()%20+1;
        p=incoda(p,n);
    }
    return p;
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d->",p->primo);
        p=p->next;
    }
}

doppia*nelem2(doppia*tmp2,nodo*p)
{
    doppia*flag=(doppia*)malloc(sizeof(doppia));
    flag->prev=NULL;
    flag->primo=p->primo;
    flag->next=tmp2;
    return flag;
}

doppia*ritdop(nodo*p)
{
    doppia*tmp2=NULL;
    if(p!=NULL)
    {
        tmp2=ritdop(p->next);
        tmp2=nelem2(tmp2,p);
        if(p->next!=NULL)
        {
            tmp2->next->prev=tmp2;
        }
    }
    return tmp2;
}

void stampa2(doppia*p2)
{
    while(p2!=NULL)
    {
        printf("\n<->%d<->",p2->primo);
        p2=p2->next;
    }
}
