#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

typedef struct LISTA_DOPPIA
{
    int primo;
    struct LISTA_DOPPIA*prev;
    struct LISTA_DOPPIA*next;
}doppia;

nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
void stampa(nodo*p);
///
doppia*nelem2(doppia*tmp2,nodo*p);
doppia*ritdop(nodo*p);
void stampa2(doppia*p2);

int main ()
{
    nodo*l=NULL;
    doppia*l2=NULL;
    int n,dim,i=0;

    printf("quanto vuoi grande la tua lista: ");
    scanf("%d",&dim);

    for(i=0;i<dim;i++)
    {
        printf("aggiungi %d elemento:  ",i+1);
        scanf("%d",&n);
        l=incoda(l,n);
    }
    stampa(l);

    printf("\nfaccio diventare l doppiamente concatenata:\n ");
    l2=ritdop(l);
    stampa2(l2);


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

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d->\n",p->primo);
        p=p->next;
    }
}

doppia*nelem2(doppia*tmp2,nodo*p)
{
    doppia*flag=(struct LISTA_DOPPIA*)malloc(sizeof(struct LISTA_DOPPIA));
    flag->prev=NULL;
    flag->primo=p->primo;
    flag->next=tmp2;
    return flag;
}

doppia*ritdop(nodo*p)
{
    doppia*tmp2=NULL;
    if(p!=NULL)
    {
        tmp2=ritdop(p->next);
        tmp2=nelem2(tmp2,p);
        if(p->next!=NULL)
        {
            tmp2->next->prev=tmp2;
        }
    }
    return tmp2;
}

void stampa2(doppia*p2)
{
    while(p2!=NULL)
    {
        printf("<-> %d <->\n",p2->primo);
        p2=p2->next;
    }
}
