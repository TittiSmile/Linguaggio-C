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
nodo*casuale(nodo*p,int dim);
void stampa(nodo*p);
nodo*elduplicati(nodo*p);
nodo*elduplicatiric(nodo*p);

int main ()
{
    nodo*l=NULL;
    int dim,a;
    printf("grandezza lista:   ");
    scanf("%d",&dim);
    l=casuale(l,dim);
    stampa(l);
    printf("\nelimino i duplicati");
    l=elduplicatiric(l);
    stampa(l);



    return 0;
}

nodo*nelem(int a)
{
    nodo*q=(nodo*)malloc(sizeof(nodo));
    q->primo=a;
    q->next=NULL;
    return q;
    /*intesta!!!!!
    q=nelem(a);
    q->next=p;
    return q;*/
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

nodo*casuale(nodo*p,int dim)
{
    int i=0,a=0;
    srand((unsigned)time(NULL));
    for(i=0;i<dim;i++)
    {
        a=rand()%10+1;
        p=incoda(p,a);
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

nodo*elduplicati(nodo*p)  ///versione iterativa
{
    nodo*tmp;
    nodo*cur=p;
    nodo*var=p;
    while(var!=NULL)
    {
        while(cur->next!=NULL)
        {
            if(var->primo==cur->next->primo)
            {
                tmp=cur->next;
                cur->next=cur->next->next;
                free(tmp);
            }
            else
            cur=cur->next;
        }
        var=var->next;
        cur=var;
    }
    return p;
}

nodo*elduplicatiric(nodo*p)  ///versione ricorsiva
{
    nodo*tmp=p;
    nodo*cur=tmp;
    if(p==NULL)
    {
        return p;
    }
    p->next=elduplicatiric(p->next);
    while(cur->next!=NULL && cur->next->next!=NULL)
    {
        cur=cur->next;
        if(p->primo== cur->primo)
        {
            tmp=p->next;
            free(p);
        }
    }
    return tmp;
}

