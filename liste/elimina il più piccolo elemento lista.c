///funzione che elimina l'elemento più piccolo della lista scorrendola solo UNA volta.
#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
nodo*elmin(nodo*p);
void stampa(nodo*p);

int main ()
{
    nodo*l1=NULL;

    l1=incoda(l1,4);l1=incoda(l1,1);l1=incoda(l1,2);l1=incoda(l1,7);
    stampa(l1);
    printf("\n\n");
    l1=elmin(l1);
    stampa(l1);



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

nodo*elmin(nodo*p)
{
    nodo*min=p;
    nodo*cur=p;
    nodo*prev=p;
    nodo*tmp;
    while(cur->next!=NULL)
    {
        if(cur->primo < min->primo)
        {
            min=cur;
            tmp=prev;
        }
        prev=cur;
        cur=cur->next;
    }
        if(min==p)
        {
            p=p->next;
            free(min);
        }
            else
            {
                tmp->next=min->next;
                free(min);
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
