#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define MAX 20
typedef struct LISTA
{
int primo;
struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
void stampa(nodo*p);
nodo*concatena(nodo*l1,nodo*l2);

int main ()
{
    nodo*l1=NULL;
    nodo*l2=NULL;
    nodo*l3=NULL;

    l1=incoda(l1,2);l1=incoda(l1,34);l1=incoda(l1,9);l1=incoda(l1,9);l1=incoda(l1,9);
    l2=incoda(l2,55);l2=incoda(l2,5);l2=incoda(l2,31);
    stampa(l1);
    printf("\n\n");
    stampa(l2);
    l3=concatena(l1,l2);
    printf("\n\n");
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


void stampa(nodo*p)
{
    while(p!=NULL)
    {
    printf("\n%d->",p->primo);
    p=p->next;
    }
}

nodo*concatena(nodo*l1,nodo*l2)
{
    /*nodo*l3=l1;        ///è corretta ma ha problemi sull'output della lista 1l
    if(l1==NULL)
    {
        return l2;
    }
    else if(l2==NULL)
    {
        return l1;
    }
    else
    {
        if(l3->next!=NULL)
        {
            l3=l3->next;
            l3->next=l2;

        }
    }return l1;*/


    nodo*l3=l1;                          ///FUNZIONA BENEEEE
    if(l1==NULL)
    {
        return l2;
    }
    else if(l2==NULL)
    {
        return l1;
    }
    while(l3->next!=NULL)
       {
           l3=l3->next;
       }
        l3->next=l2;
        return l1;
}
