#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct LISTA
 {
     int primo;
     struct LISTA*next;
 }nodo;

nodo*nelem(int a);
nodo*intesta(nodo*p,int a);
nodo*incoda(nodo*p,int a);
void stampa(nodo*p);
nodo*minmaxk(nodo*p,int k);
nodo*casuale(nodo*p,int dim);



 int main ()
 {
     nodo*l1=NULL;
     int i=0,k,dim;

     //l1=incoda(l1,3);l1=incoda(l1,1);l1=incoda(l1,2);l1=incoda(l1,5);l1=incoda(l1,4);
     printf("quanto vuoi grande la tua lista?  ");
     scanf("%d",&dim);
     l1=casuale(l1,dim);
     stampa(l1);
     printf("\ninserisci un numero k:  ");
     scanf("%d",&k);
     l1=minmaxk(l1,k);
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
         printf("\n%d->",p->primo);
         p=p->next;
     }
 }

nodo*minmaxk(nodo*p,int k)
{
    ///questa funzione è corretta MA ti ritorna un'altra lista (sobsob)
    /*nodo*tmp;
    if(p==NULL || p->next==NULL)
    {
        return p;
    }
    tmp=minmaxk(p->next,k);
    if(p->primo<k)
    {
        tmp=intesta(tmp,p->primo);
    }
    else if(p->primo > k)
    {
        tmp=incoda(tmp,p->primo);
    }
    return tmp;*/

    ///versione alternativa  un po' meh
    nodo*tmp;
    if(p)
    {
        p->next=minmaxk(p->next,k);
        if(p->primo >k)
        {
            tmp=p;
            p=incoda(p->next,tmp->primo);
        }
    }
    return p;
}

nodo*casuale(nodo*p,int dim)
{
    int n=0;
    int i=0;
    srand((unsigned)time(NULL));
    for(i=0;i<dim;i++)
    {
        n=rand()%20+1;
        p=incoda(p,n);
    }
    return p;
}

