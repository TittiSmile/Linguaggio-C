#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
int sommamaxk(nodo*p,int k);
void stampa(nodo*p);

int main ()
{
    nodo*l1=NULL;
    int k=0;
    l1=incoda(l1,4);l1=incoda(l1,6);l1=incoda(l1,12);l1=incoda(l1,21);l1=incoda(l1,8);l1=incoda(l1,7);l1=incoda(l1,18);
    stampa(l1);
    printf("\ninserisci un numero k:  ");
    scanf("%d",&k);
    printf("\nla somma di tutti i numeri maggiori di %d: %d ",k,sommamaxk(l1,k));


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

int sommamaxk(nodo*p,int k)
{
    int sum=0;
    ///ricorsiva
    /*if(p==NULL)
    {
        return 0;
    }
    else
    {
        sum=sommamaxk(p->next,k);
        if(p->primo > k)
        {
            sum+=p->primo;
        }
        return sum;
    }*/

    ///iterativa
    while(p!=NULL)
        {
            if(p->primo > k)
            {
               sum+=p->primo;
            }
              p=p->next;
        }
        return sum;

}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d->",p->primo);
        p=p->next;
    }

}
