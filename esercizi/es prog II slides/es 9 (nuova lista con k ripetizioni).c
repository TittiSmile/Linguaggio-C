///ha qualche problemino ma fa quel che deve
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
nodo*insordine(nodo*p,int a);
nodo*ordine(nodo*p,nodo*tmp);
nodo*crescente(nodo*p);
int contakripetizioni(nodo*p,int k);  ///conto le k ripetizioni di un numero in una lista
nodo*listakrip(nodo*p,int k);         ///ritorno una lista con le k ripetizioni


///l1= 1 2 3 4 5 1 7 3 2   l1=1 2 3
     ///k=2

 int main ()
 {
     nodo*l1=NULL;
     int k;

     l1=incoda(l1,1);l1=incoda(l1,2);l1=incoda(l1,3);l1=incoda(l1,4);l1=incoda(l1,1);l1=incoda(l1,7);;l1=incoda(l1,2);l1=incoda(l1,3);
     stampa(l1);
     printf("\ninserisci un numero k:  ");
     scanf("%d",&k);
    // printf("\nle ripetizioni di %d sono: %d",k,contakripetizioni(l1,k));
     printf("\nlista solo con i numeri ripetuti esattamente %d volte: ",k);
     l1=crescente(l1);
     l1=listakrip(l1,k);
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
         printf("%d->    ",p->primo);
         p=p->next;
     }
 }

nodo*insordine(nodo*p,int a)
{
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    if(p==NULL || tmp->primo > a)
    {
        tmp=nelem(a);
        tmp->next=p;
        p=tmp;
    }
    else
    {
        p->next=insordine(p->next,a);
    }
    return p;
}

nodo*ordine(nodo*p,nodo*tmp)
{
    if(p==NULL || p->primo > tmp->primo)
    {
        tmp->next=p;
        p=tmp;
    }
    else
    {
        p->next=ordine(p->next,tmp);
    }
    return p;
}

nodo*crescente(nodo*p)
{
    nodo*tmp;
    nodo*l=NULL;
    while(p!=NULL)
    {
        tmp=p;
        p=p->next;
        l=ordine(l,tmp);
    }
    return l;
}

int contakripetizioni(nodo*p,int k)
{
    int flag=0;
    while(p!=NULL)
    {
        if(p->primo==k)
        {
            flag++;
        }
        p=p->next;
    }
    return flag;
}

nodo*listakrip(nodo*p,int k)
{
    ///PROVA A RIVEDERLO!!! C'è QUALCOSA CHE SFUGGE
    //nodo*tmp=p;
    /*nodo*tmp=NULL;
    int flag=0;
    if(p!=NULL)
    {
        flag=contakripetizioni(p,p->primo);
        if(flag==k)
        {
            //p=listakrip(p->next,k);
            //free(tmp);
            tmp=incoda(tmp,p->primo);
        }
        else
        {
            p->next=listakrip(p->next,k);
        }
    }
    return tmp;*/


    nodo*tmp=NULL;
    int flag=0;
    while(p!=NULL)
    {
        flag=contakripetizioni(p,p->primo);
        if(flag==k)
        {
            tmp=incoda(tmp,p->primo);
        }
        p=p->next;
    }
    return tmp;
}


