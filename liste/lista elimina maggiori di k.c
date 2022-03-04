#include <stdio.h>
#include <malloc.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
nodo*eliminak(nodo*p,int k);
void stampa(nodo*p);

int main()
{
    nodo*l=NULL;
    int i,dim,n,k;

    printf("quanti numeri vuoi nella lista? ");
    scanf("%d",&dim);
    for(i=0;i<dim;i++)
    {
        printf("inserisci numero  ");
        scanf("%d",&n);
        l=incoda(l,n);
    }
    stampa(l);
    printf("\ninserisci un numero k:  ");
    scanf("%d",&k);
    printf("\nelimino tutti i numeri maggiori di %d: ",k);
    l=eliminak(l,k);
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
    /*nodo*tmp=NULL;
    if(p==NULL)
    {
       return p;
    }
    else
    {
        tmp->next=eliminak(tmp->next,k);
        if(p->primo>k)
        {
            tmp=p;
            p=p->next;
            free(tmp);
        }
    }
    return p;*/          ///ricorsiva

///iterativa
    nodo*tmp;
    nodo*l1=p;
    while(l1->next!=NULL)
    {
        if(l1->next->primo >k)
        {
            tmp=l1->next;
            l1->next=l1->next->next;
            free(tmp);
        }
        else
        {
            l1=l1->next;
        }
    }
    if(p->primo >k)
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
        printf("\n%d\n",p->primo);
        p=p->next;
    }
}
