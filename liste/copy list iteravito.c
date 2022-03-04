#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*newElem(int value);
nodo*tail(nodo*p,int value);
nodo*copyList(nodo*p);
void print(nodo*p);


int main ()
{
    nodo*l=NULL;
    nodo*l2=NULL;
    int dim, i=0,value;
    l=tail(l,3); l=tail(l,2); l=tail(l,21);
    printf("stampa lista 1\n\n ");
    print(l);
    printf("copio e stampo la nuova lista:\n");
    copyList(l2);
    print(l);



    return 0;
}

nodo*newElem(int value)
{
    nodo*q=(nodo*)malloc(sizeof(nodo));
    q->primo=value;
    q->next=NULL;
    return q;
}

nodo*tail(nodo*p,int value)
{
    if(p==NULL)
    {
        p=newElem(value);
    }
    else
    {
        p->next=tail(p->next,value);
    }
    return p;
}

nodo*copyList(nodo*p)
{
    nodo*copy=(nodo*)malloc(sizeof(nodo));
    if(p==NULL){return p;}
    else
    {
    copy->primo=p->primo;
    copy->next=p->next->next;
    }
    return copy;
}

void print(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d\n",p->primo);
        p=p->next;
    }
}
