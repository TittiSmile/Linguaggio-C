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
nodo*insordine(nodo*p,int a);
nodo*paridispari(nodo*p);     ///elimina gli elementi pari in posizione dispari
void stampa(nodo*p);

int main ()
{
    nodo*l=NULL;
    int n,dim,i=0;

    printf("grandezza lista?  ");
    scanf("%d",&dim);

    for(i=0;i<dim;i++)
    {
        printf("inserisci %d elemento: ",i+1);
        scanf("%d",&n);
        //l=insordine(l,n);
        l=incoda(l,n);
    }
    stampa(l);

    printf("\nelimino i pari in posizione dispari:\n ");
    l=paridispari(l);
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

nodo*insordine(nodo*p,int a)
{
    nodo*tmp;
    if(p==NULL || p->primo > a)
    {
        tmp=nelem(a);
        tmp->next=p;
        p=tmp;
    }
    else
    {
        p->next=insordine(p->next,a);
    }
    return p;
}

nodo*paridispari(nodo*p)
{
    if(p){
        if(p->next)
            p->next->next = paridispari(p->next->next);

        if(!(p->primo % 2)){
            nodo * toDelete = p;
            p = p->next;
            free(toDelete);
        }
    }
    return p;
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("%d ->\n",p->primo);
        p=p->next;
    }
}

