/*esempio della funzione:
a: 1 2 3    b: 3 4 5    c: 1 2 3 4 5   (non so ancora se mettere in coda di agli elementi di b o farli uscire in una nuova lista) */
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
void stampa(nodo*p);
nodo*elduplicati(nodo*p);
nodo*concatena(nodo*l1,nodo*l2);



int main ()
{
    nodo*l1=NULL;
    nodo*l2=NULL;
    nodo*l3=NULL;

    l1=incoda(l1,1);l1=incoda(l1,2);l1=incoda(l1,3);l1=incoda(l1,3);l1=incoda(l1,3);
    l2=incoda(l2,3);l2=incoda(l2,4);l2=incoda(l2,5);
    stampa(l1);
    printf("\n\n");
    stampa(l2);
    printf("\n\nconcateno\n\n");
    l3=concatena(l1,l2);
    stampa(l3);
    printf("\n\nelimino duplicati\n\n");
    l3=elduplicati(l3);
    stampa(l3);



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


void stampa(nodo*p)
{
    while(p!=NULL)
    {
    printf("\n%d->",p->primo);
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

nodo*concatena(nodo*l1,nodo*l2)
{
    nodo*l3=l1;
    if(l1==NULL)
    {
        return l2;
    }
    else if(l2==NULL)
    {
        return l1;
    }
    while(l3->next!=NULL)
        l3=l3->next;
        l3->next=l2;
        return l1;

}
