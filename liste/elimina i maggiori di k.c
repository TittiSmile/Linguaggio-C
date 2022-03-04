#include <stdio.h>
#include <malloc.h>
typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;

nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
nodo*eliminak(nodo*p,int k);
void stampa(nodo*p);

int main ()
{
    nodo*l=NULL;
    int k,dim,i,n;
    printf("quanto vuoi grande la tua lista? ");
    scanf("%d",&dim);
    for(i=0;i<dim;i++)
    {
        printf("\ninserisci numero nella lista:  ");
        scanf("%d",&n);
        l=incoda(l,n);
    }
    stampa(l);
    printf("\ninserisci un numero k:  ");
    scanf("%d",&k);
    l=eliminak(l,k);
    printf("\nelimino tutti i numeri maggiori di %d ",k);
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

nodo*eliminak(nodo*p,int k)
{
    nodo*tmp;
    if(p==NULL)
    {
     return p;
    }
    else
    {
        p->next=eliminak(p->next,k);
        if(p->primo>k)
        {
            tmp=p;
            p=p->next;
            free(tmp);
        }
    }
    return p;

}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d\n",p->primo);
        p=p->next;
    }
}

