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

nodo*ricerca(nodo*p,int a);
nodo*diffsimm(nodo*l1,nodo*l2,nodo*l3);
nodo*eliminadup(nodo*p);
nodo*eliminal2(nodo*l3,nodo*l2);
///il programma deve ritornare gli elem di l1 non appartenenti ad l2. per questo creo una funzione dove mi elimina da l3 gli elem di l2

 int main ()
 {
     nodo*l1=NULL;
     nodo*l2=NULL;
     nodo*l3=NULL;
     int i=0;

     l1=incoda(l1,1);l1=incoda(l1,2);l1=incoda(l1,3);l1=incoda(l1,4);l1=incoda(l1,4);l1=incoda(l1,4);
     stampa(l1);
     printf("\n\t***");
     l2=incoda(l2,1);l2=incoda(l2,2);l2=incoda(l2,7);l2=incoda(l2,8);
     stampa(l2);
     printf("\n\t____");
     l3=diffsimm(l1,l2,l3);
     l3=eliminadup(l3);
     stampa(l3);

     printf("\n\t-----");
     l3=eliminal2(l3,l2);
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

nodo*ricerca(nodo*p,int a)
{
    nodo*trovato=NULL;
    for(;p!=NULL && trovato==NULL;p=p->next)
    {
        if(p->primo==a)
        {
            trovato=p;
        }
    }
    return trovato;
}

nodo*diffsimm(nodo*l1,nodo*l2,nodo*l3)
{
    if(l1==NULL && l2==NULL)
    {
        return l3;
    }
    else if(l1==NULL)
    {
        l3=incoda(l3,l2->primo);
        return diffsimm(l1,l2->next,l3);
    }
    else if(l2==NULL)
    {
        l3=incoda(l3,l1->primo);
        return diffsimm(l1->next,l2,l3);
    }
    else if(l1->primo < l2->primo)
    {
        l3=incoda(l3,l1->primo);
        return diffsimm(l1->next,l2,l3);
    }
    else if(l1->primo > l2->primo)
    {
        l3=incoda(l3,l2->primo);
        return diffsimm(l1,l2->next,l3);
    }
    return diffsimm(l1->next,l2->next,l3);
}

nodo*eliminadup(nodo*p)
{
    nodo*cur=p;
    nodo*tmp=p;
    if(p==NULL)
    {
        return p;
    }
    p->next=eliminadup(p->next);
    while(cur!=NULL && cur->next!=NULL)
    {
        cur=cur->next;
        if(p->primo==cur->primo)
        {
            tmp=p->next;
            free(p);
        }
    }
    return tmp;
}

nodo*eliminal2(nodo*l3,nodo*l2)
{
    nodo*tmp;
    if(l3==NULL)
    {
        return l3;
    }
    l3->next=eliminal2(l3->next,l2->next);    ///ho messo anche l2->next perchè devo scorrere anche l'altra lista
    if(l3->primo==l2->primo)
    {
        tmp=l3;
        l3=l3->next;
        free(tmp);
    }
    return l3;
}
