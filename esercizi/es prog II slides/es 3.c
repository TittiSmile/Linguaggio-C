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
nodo*alterna(nodo*l1,nodo*l2);


 int main ()
 {
     nodo*l1=NULL;
     nodo*l2=NULL;
     nodo*l3=NULL;
     int i=0;

     l1=incoda(l1,3);l1=incoda(l1,4);l1=incoda(l1,55);l1=incoda(l1,9);
     stampa(l1);
     printf("\n***");
     l2=incoda(l2,11);l2=incoda(l2,2);l2=incoda(l2,7);l2=incoda(l2,21);
     stampa(l2);
     printf("\nalterno le due liste");
     l3=alterna(l1,l2);
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

 nodo*alterna(nodo*l1,nodo*l2)
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
     else
     {
         l2->next=alterna(l1->next,l2->next);
         l3->next=l2;
     }
     return l3;
 }
