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
int contaposizionedispari(nodo*p);
int contaposizionepari(nodo*p);

 int main ()
 {
     nodo*l1=NULL;
     int i=0;

     l1=incoda(l1,3);l1=incoda(l1,4);l1=incoda(l1,55);l1=incoda(l1,9);l1=incoda(l1,3);
     stampa(l1);
     printf("\ni numeri di posizione dispari sono: %d",contaposizionedispari(l1));
     printf("\ni numeri di posizione pari sono: %d",contaposizionepari(l1));


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

 int contaposizionedispari(nodo*p)
 {
     if(p==NULL)
        return 0;
    if(p->next==NULL)
        return 1;
    return 1 + contaposizionedispari(p->next->next);
 }

 int contaposizionepari(nodo*p)
 {
     if(p==NULL)
        return 0;
    if(p->next->next==NULL)
        return 1;
    return 1 + contaposizionedispari(p->next->next->next);
 }
