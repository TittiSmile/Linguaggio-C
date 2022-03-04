///funziona ma c'è qualcosa da PERFEZIONARE
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
//nodo*findmin(nodo*p);
int findmin(nodo*p);
//nodo*elimina(nodo*p);
nodo*elimina(nodo*p);
void stampa(nodo*p);

int main ()
{
    nodo*l1=NULL;

    l1=incoda(l1,54);l1=incoda(l1,31);l1=incoda(l1,22);l1=incoda(l1,7);
    stampa(l1);
    printf("\n\n");
    printf("\n minimo:  %d",findmin(l1));

    l1=elimina(l1);
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

int findmin(nodo*p)
{
    nodo*tmp;
   // nodo*min=p;
    int min=INT_MAX;

    while(p!=NULL)
    {
        if(p->primo<min)
        {
          min=p->primo;
        }
        p=p->next;
    }
    return min;
}

nodo*elimina(nodo*p)
{
    nodo*tmp;
    int min=findmin(p);
    /*if(p!=NULL)
    {
        if(p->primo == min)
        {
            p=elimina(p->next);
            free(tmp);
        }
        else
        {
            p->next=elimina(p->next);
        }
    }*/

    if(p==NULL)
    {
        return p;
    }
    p->next=elimina(p->next);
    if(p->primo == min)
    {
        tmp=p;
        p=p->next;
        free(tmp);
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
