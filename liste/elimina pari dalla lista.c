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
void stampa(nodo*p);
nodo*elpari(nodo*p);

int main ()
{
    int i=0,dim,n;
    nodo*l=NULL;

    printf("quanto vuoi grande la tua lista? ");
    scanf("%d",&dim);
    for(i=0;i<dim;i++)
    {
        printf("inserisci numero %d ",i+1);
        scanf("%d",&n);
        l=incoda(l,n);
    }
    stampa(l);
    printf("\nelimino i pari:\n");
    l=elpari(l);
    if(l==NULL)
    {
        printf("lista vuota!!\n");
    }
    else
    {
        stampa(l);
    }


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

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("%d->\n",p->primo);
        p=p->next;
    }
}

nodo*elpari(nodo*p)
{
    nodo*tmp=p;
    if(p!=NULL)
    {
        if(p->primo %2 ==0)
        {
            p=elpari(p->next);
            free(tmp);
        }
        else
        {
            p->next=elpari(p->next);
        }
    }
    return p;
}

