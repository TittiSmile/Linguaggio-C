/*scrivere una funzione che,data una lista L1 di interi, restituisca una nuova lista L2 concatenata contenente tutti gli elementi pari
della lista con condizione che L non sia modificata*/
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
nodo*pari(nodo*p);
void stampa(nodo*p);


int main ()
{
    nodo*l1=NULL;
    nodo*l2=NULL;
    nodo*l3=NULL;

    l1=incoda(l1,23);l1=incoda(l1,1);l1=incoda(l1,50);l1=incoda(l1,15);
    printf("\t\tL1:\n");
    stampa(l1);
    printf("\n\t\tL2:\n");
    l2=pari(l1);
    stampa(l2);
    printf("\nnon ho modificato L1:  ");
    printf("\n");
    stampa(l1);


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

nodo*pari(nodo*p)
{
    nodo*tmp;
    if(p==NULL)
    {
        return p;
    }
    tmp=pari(p->next);
    if(p->primo %2==0)
    {
        tmp=incoda(tmp,p->primo);
    }
    return tmp;
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

