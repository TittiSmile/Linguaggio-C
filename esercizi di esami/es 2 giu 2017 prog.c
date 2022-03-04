/*data una lista concatenata di interi l,scrivere una funzione iterativa in c che restituisca una lista l invertita modificando
la lista originaria senza allocare memoria.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*casuale(nodo*p,int dim); ///mi scoccio di dare numeri da tastiera
nodo*intesta(nodo*p,int a);
nodo*incoda(nodo*p,int a);
nodo*inverti(nodo*p);
void stampa(nodo*p);

int main ()
{
    nodo*l=NULL;
    int i=0,dim,n;

    printf("grandezza lista?  ");
    scanf("%d",&dim);
    l=casuale(l,dim);
    stampa(l);
    printf("\ninverto la lista (NON è IL SOLITO REVERSE): ");
    l=inverti(l);
    stampa(l);




    return 0;
}


nodo*nelem(int a)
{
    nodo*q=(nodo*)malloc(sizeof(nodo));
    q->primo=a;
    q->next=NULL;
    return q;
}

nodo*casuale(nodo*p,int dim)
{
    int i=0;
    int a=0;
    srand((unsigned)time(NULL));
    for(i=0;i<dim;i++)
    {
        a=rand()%100+1;
        p=incoda(p,a);
    }
    return p;
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

nodo*inverti(nodo*p)
{
    nodo*curr;  ///nodo attuale
    nodo*succ;  ///nodo successivo
    nodo*prev;  ///nodo precedente
    curr=p;
    prev=NULL;
    while(curr!=NULL)
    {
        succ=curr->next;
        curr->next=prev;
        prev=curr;
        curr=succ;
    }
    p=prev;
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
