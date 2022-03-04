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
nodo*klista(nodo*p,int k);


int main ()
{
    nodo*l1=NULL;
    int a=0;
    l1=incoda(l1,5);l1=incoda(l1,5);l1=incoda(l1,5);l1=incoda(l1,5);l1=incoda(l1,7);l1=incoda(l1,14);l1=incoda(l1,11);
    stampa(l1);
    printf("\n\n***\n");
    l1=klista(l1,7);
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
        printf("\n->%d",p->primo);
        p=p->next;
    }
    printf("\t\tNULL");
}


nodo*klista(nodo*p,int k)
{
    nodo*tmp;
    nodo*cur=p;
    while(cur->next!=NULL)
    {
        if(cur->next->primo==k)
        {
            tmp=cur->next;
            cur->next=cur->next->next;
            free(tmp);
        }
        cur=cur->next;
    }
    if(p->primo==k)
    {
        tmp=p;
        p=p->next;
        free(tmp);
    }
    return p;
}
