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
nodo*elk(nodo*p,int k);
void stampa(nodo*p);

int main ()
{
    int k,i=0,dim,n;
    nodo*l=NULL;

    printf("quanto vuoi grande la tua lista?  ");
    scanf("%d",&dim);
    for(i=0;i<dim;i++)
    {
        printf("inserisci %d elemento:  ",i+1);
        scanf("%d",&n);
        l=incoda(l,n);
    }
    stampa(l);

    printf("\ninserisci numero k da eliminare: ");
    scanf("%d",&k);
    l=elk(l,k);
    stampa(l);

    return 0;
}

nodo*nelem(int a)
{
    nodo*q=(struct LISTA*)malloc(sizeof(struct LISTA));
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

nodo*elk(nodo*p,int k)
{
    nodo*tmp;
    if(p)
    {
        if (p->primo==k)
        {
            tmp=p;
            p=p->next;
            free(tmp);
        }
        else
        {
            p->next=elk(p->next,k);
        }
    }
    return p;
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d",p->primo);
        p=p->next;
    }
}

