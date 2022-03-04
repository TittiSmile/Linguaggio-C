///funziona ma usa numeri distanziati tra loro di poco!!!
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
nodo*riempi(nodo*p);
void stampa(nodo*p);

int main ()
{
    nodo*l1=NULL;

    l1=incoda(l1,1);l1=incoda(l1,4);
    stampa(l1);
    printf("\n\n");
    l1=riempi(l1);
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

nodo*riempi(nodo*p)
{
    ///versione RICORSIVA
    nodo*tmp;
    if(p==NULL || p->next==NULL)
    {
       return p;
    }
    if(p->primo+1!= p->next->primo)
    {
        tmp=nelem(p->primo+1);
        tmp->next=p->next;
        p->next=tmp;
    }
    p->next=riempi(p->next);
    return p;

    /*nodo*cur=p;
    nodo*tmp;
    if(p!=NULL && p->next!=NULL)
    {
        while(cur->next!=NULL)
        {
            if(cur->primo+1!= cur->next->primo)
            {
                tmp=nelem(cur->primo+1);
                tmp->next=cur->next;
                cur->next=tmp;
            }
            cur=cur->next;
        }
    }
    return p;*/

}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d->",p->primo);
        p=p->next;
    }
}
