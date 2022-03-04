/*Sia top una lista concatenata di interi. Scrivere in ANSI C una funzione ricorsiva,
calcolaSommaCondizionata, che calcoli la somma di tutti i numeri maggiori di un dato k,
present i nella lista top- Si dimostri per induzione la correttezza della funzione.*/
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
nodo*casuale(nodo*p,int dim);
int sommacond(nodo*p,int k);



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
     printf("\nsommo la lista: %d",sommacond(l1,k));




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

int sommacond(nodo*p,int k)
{
    /*int s=0;
    if(p==NULL)
    {
        return 0;
    }
    s=sommacond(p->next,k);
    if(p->primo >k)
    {
        return (s+p->primo,k);
    }
    else
        return s;*/
        int somma;

    if(p==0)
    return 0;
    else
    {
        somma=sommacond(p->next, k);

        if(p->primo>k)
        return (somma+p->primo);
        else
        return somma;
    }
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

