#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
nodo*fondi(nodo*l1,nodo*l2);
void stampa(nodo*p);

int main()
{
    nodo*l1=NULL;
    nodo*l2=NULL;
    nodo*l3=NULL;
    int dim,i=0,n,dom,m;

    printf("\nquanti elementi nelle prima lista? ");
    scanf("%d",&dim);

    for(i=0;i<dim;i++)
    {
        printf("inserisci numero:   ");
        scanf("%d",&n);
        l1=incoda(l1,n);
    }
    stampa(l1);

      printf("\nquanti elementi nella seconda lista? ");
    scanf("%d",&dom);

    for(i=0;i<dom;i++)
    {
        printf("inserisci numero:   ");
        scanf("%d",&m);
        l2=incoda(l2,m);
    }
    stampa(l2);

    printf("\nfondo le due liste: ");
    l3=fondi(l1,l2);
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

nodo*fondi(nodo*l1,nodo*l2)
{
    nodo*l3;
    if(l1==NULL)
    {
        return l2;
    }
    else if(l2==NULL)
    {
        return l1;
    }
    else if(l1->primo < l2->primo)
    {
        l3=l1;
        l3->next=fondi(l1->next,l2);
    }
    else if(l1->primo > l2->primo)
    {
        l3=l2;
        l3->next=fondi(l1,l2->next);
    }
    return l3;
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d->",p->primo);
        p=p->next;
    }
}

