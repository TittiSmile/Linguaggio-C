/// quella ricorsiva è una semplice stampa al contrario ._.
#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
nodo*invertiR(nodo*p);       ///versione ricorsiva
nodo*invertiI(nodo*p);       ///versione iterativa
void stampa(nodo*p);

int main ()
{
    nodo*l=NULL;
    l=incoda(l,5);l=incoda(l,7);l=incoda(l,1);l=incoda(l,8);
    stampa(l);
    printf("\n\n");
    l=invertiI(l);
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

nodo*invertiR(nodo*p)
{                      ///questa è solo una stampa al contrario wtf
    if(p==NULL)
        return 0;
    invertiR(p->next);
    printf("\n%d",p->primo);
}

nodo*invertiI(nodo*p)
{
   ///ITERATIVA
    /*nodo*cur=p;
    nodo*var;
    p=NULL;
    while(cur!=NULL)
    {
        var=cur;
        cur=cur->next;
        var->next=p;
        p=var;
    }
    return p;*/
///versione alternativa
    nodo*cur=p;
    nodo*prev=NULL;
    nodo*suc;
    while(cur!=NULL)
    {
        suc=cur->next;
        cur->next=prev;
        prev=cur;
        cur=suc;
    }
    p=prev;
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
