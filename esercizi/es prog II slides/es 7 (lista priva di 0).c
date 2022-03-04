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
nodo*elimina0(nodo*p);

 int main ()
 {
     nodo*l1=NULL;
     nodo*l2=NULL;
     nodo*l3=NULL;
     int i=0;

     l1=incoda(l1,3);l1=incoda(l1,0);l1=incoda(l1,55);l1=incoda(l1,0);
     stampa(l1);
     printf("\n***");
    printf("\nelimino gli 0: ");
    l1=elimina0(l1);
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

nodo*elimina0(nodo*p)
{
    nodo*tmp;
    if(p==NULL)
    {
        return p;
    }
    p->next=elimina0(p->next);
    if(p->primo==0)
    {
        tmp=p;
        p=p->next;
        free(tmp);
    }
    return p;
}
