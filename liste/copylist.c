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
nodo*casuale(nodo*p,int dim);
nodo*incoda(nodo*p,int a);
nodo*copia(nodo*p);
void stampa(nodo*p);

int main()
{
    nodo*l1=NULL;
    nodo*l2=NULL;
    nodo*l3=NULL;
    int dim,i=0,num;
    printf("quanto e' grande la tua lista? ");
    scanf("%d",&dim);
    l1=casuale(l1,dim);
    /*l1=incoda(l1,3);l1=incoda(l1,5);l1=incoda(l1,21);l1=incoda(l1,11);
    stampa(l1)*/
    stampa(l1);

    printf("\ncopio la lista\n");
    l2=copia(l1);
    stampa(l2);

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
    int n=0;
    srand((unsigned)time(NULL));
    for(i=0;i<dim;i++)
    {
        n=rand()%30+1;
        p=incoda(p,n);
    }
    return p;
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

nodo*copia(nodo*p)
{
    nodo*copy=(nodo*)malloc(sizeof(nodo));
    if(p==NULL)
    {
        return p;
    }
    else
    {
        copy->primo=p->primo;
        copy->next=copia(p->next);
        return copy;
    }
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("%d \n\n",p->primo);
        p=p->next;
    }
}
