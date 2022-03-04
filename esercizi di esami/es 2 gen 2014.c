/*scrivere una funzione 'intersezione' che,date due liste L1 ed L2, restituisca una nuova lista L che contenga gli elementi
in comune di L1 ed L2 senza modificare le due liste.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*intesta(nodo*p,int a);
nodo*incoda(nodo*p,int a);
nodo*ricerca(nodo*p,int a);
nodo*intersezione(nodo*l1,nodo*l2);
void stampa(nodo*p);


int main ()
{
    nodo*l1=NULL;
    nodo*l2=NULL;
    nodo*l3=NULL;

    l1=incoda(l1,23);l1=incoda(l1,1);l1=incoda(l1,50);l1=incoda(l1,15);
    l2=incoda(l2,8);l2=incoda(l2,23);l2=incoda(l2,8);l2=incoda(l2,6);l2=incoda(l2,50);
    printf("\t\tL1:\n");
    stampa(l1);
    printf("\t\tL2:\n");
    stampa(l2);
    printf("\t\tL3:\n");
    l3=intersezione(l1,l2);
    stampa(l3);




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

nodo*ricerca(nodo*p,int a)
{
    nodo*trovato=NULL;
    for(;p!=NULL && trovato==NULL ;p=p->next)
    {
        if(p->primo==a)
        {
            trovato=p;
        }
    }
    return trovato;
}

nodo*intersezione(nodo*l1,nodo*l2)
{
    nodo*l3=NULL;
    if(l1!=NULL)
    {
        l3=intersezione(l1->next,l2);
        if(ricerca(l2,l1->primo))
        {
            l3=intesta(l3,l1->primo);
        }
    }
    return l3;
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("%d->\n",p->primo);
        p=p->next;
    }
    printf("   NULL");
}

