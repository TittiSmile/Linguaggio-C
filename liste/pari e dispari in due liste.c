///non è propriamente corretta. l2 deve avere quelli di posizione dispari ed l1 deve avere quelli di posizione pari
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
nodo*elimina(nodo*p,int a);  ///elimina occorrenza
nodo*posizione(nodo*p);

 int main ()
 {
     nodo*l1=NULL;
     nodo*l2=NULL;
     nodo*l3=NULL;
     int i=0;

     l1=incoda(l1,22);l1=incoda(l1,1);l1=incoda(l1,5);l1=incoda(l1,3);l1=incoda(l1,15);l1=incoda(l1,28);
     stampa(l1);
     printf("\n***\n\n");
     l2=posizione(l1);
     stampa(l2);
     printf("\n***\n\n");
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

nodo*elimina(nodo*p,int a)
{
    ///versione alternativa!!!!!
    nodo*tmp=p;
    if(p!=NULL)
    {
        p->next=elimina(p->next,a);
        if(p->primo==a)
        {
            p=elimina(p->next,a);
            free(tmp);
        }
    }
    return p;

    /*if(p)
    {
        if(p->primo==a)
        {
            p=elimina(p->next,a);
            free(tmp);
        }
        p->next=elimina(p->next,a);
    }*/

    /*if(p==NULL)
    {
        return p;
    }
    p->next=elimina(p->next,a);
    if(p->primo==a)
    {
        tmp=p;
        p=p->next;
        free(tmp);
    }*/
}

 nodo*posizione(nodo*p)
 {
     nodo*tmp=NULL;
     nodo*cur=p;
     int cont=0;
     while(cur!=NULL)
     {
         if(cont%2==0)
         {
             tmp=incoda(tmp,cur->primo);
             p=elimina(p,cur->primo);
         }
         cont++;
         cur=cur->next;
     }
     return tmp;

     ///non propriamente corretta
     /*nodo*tmp=NULL;
     nodo*cur=p;
     int cont=0;
     while(p!=NULL)
     {
         if(cont%2==0)
         {
             tmp=incoda(tmp,p->primo);
             p=elimina(p->next,p->primo);
         }
         cont++;
         p=p->next;
     }
     return tmp;*/
 }
