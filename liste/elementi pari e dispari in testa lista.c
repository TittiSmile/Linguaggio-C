///non credo faccia quel che deve ma funziona
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct LISTA
 {
     int primo;
     struct LISTA*next;
 }nodo;

 nodo*nelem(int a);
 nodo*incoda(nodo*p,int a);
 nodo*intesta(nodo*p,int a);
 nodo*casuale(nodo*p,int dim);
 nodo*PariInTesta(nodo*p);
 nodo*DispariInTesta(nodo*p);
 void stampa(nodo*p);

 int main ()
 {
     nodo*l1=NULL;
     nodo*l2=NULL;
     int i=0,n,dim;

     printf("quanto vuoi grande la tua lista?  ");
     scanf("%d",&dim);

     l1=casuale(l1,dim);
     stampa(l1);

     printf("\nmetto in testa i numeri pari: ");
     l2=PariInTesta(l1);
     stampa(l2);


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

nodo*casuale(nodo*p,int dim)
{
    int i=0;
    int a;
    srand((unsigned)time(NULL));
    for(i=0;i<dim;i++)
    {
        a=rand()%20+1;
        p=incoda(p,a);
    }
    return p;
}

nodo*PariInTesta(nodo*p)
{
    nodo*tmp;
    if(p==NULL)
    {
        return p;
    }
    tmp=PariInTesta(p->next);
    if(p->primo%2==0)
    {
        tmp=intesta(tmp,p->primo);
    }
    return tmp;

}

nodo*DispariInTesta(nodo*p)
{
    nodo*tmp;
    if(p==NULL)
    {
        return p;
    }
    tmp=PariInTesta(p->next);
    if(p->primo%2!=0)
    {
        tmp=intesta(tmp,p->primo);
    }
    return tmp;
}


void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d->",p->primo);
        p=p->next;
    }
}
