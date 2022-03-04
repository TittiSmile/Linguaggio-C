/*
Data una lista semplicemente concatenata di interi L ed un valore k, scrivere una funzione iterativa in ANSI C che
restituisca una nuova lista doppiamente concatenata T contenente tutti i valori di L maggiori di K

Esempio: L -> 24 -> 10 -> 30 -> 5 -> NIL k=20;
Lista restituita: T-> 24 <-> 30 -> NIL
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;

typedef struct LISTA_DOPPIA
{
    int info;
    struct LISTA_DOPPIA *prev;
    struct LISTA_DOPPIA *next;
}nodo2;


nodo*nelem(int a);
nodo2*nelem2(int a2);
nodo*incoda(nodo*p,int a);
nodo2*incoda2(nodo2*p2,int a);
void stampa(nodo*p);
void stampa2(nodo2*p2);
nodo2*doppiamente(nodo*p,nodo2*p2,int k);

int main ()
{
    int dim=0,num=0,i=0,k;
    nodo*l=NULL;
    nodo2*l2=NULL;

    printf("quanto vuoi grande la tua lista?  ");
    scanf("%d",&dim);

    printf("inserisci elementi nella lista: \n");
    for(i=0;i<dim;i++)
    {
        printf("elemento %d:   ",i+1);
        scanf("%d",&num);
        l=incoda(l,num);
    }
    printf("inserire un numero k:  ");
    scanf("%d",&k);

    printf("la lista e':\n");
    stampa(l);

    printf("\nritorno tutti i valori maggiori di %d in una lista doppiamente concatenata.\n ",k);
    l2=doppiamente(l,l2,k);
    stampa2(l2);

return 0;
}

nodo*nelem(int a)
{
    nodo*q=(struct LISTA*)malloc(sizeof(struct LISTA));
    q->primo=a;
    q->next=NULL;
    return q;
}

nodo2*nelem2(int a2)
{
    nodo2*flag=(struct LISTA_DOPPIA*)malloc(sizeof(struct LISTA_DOPPIA));
    flag->prev=NULL;
    flag->info=a2;
    flag->next=NULL;
    return flag;
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

nodo2*incoda2(nodo2*p2,int a)
{
    nodo2*tmp;
    nodo2*var;
    var=nelem2(a);
    if(p2!=NULL)
    {
        for(tmp=p2;tmp->next!=NULL;tmp=tmp->next)
        {
            tmp->next=var;
            (tmp->next)->prev=tmp;
        }
    }
    else
        //{
            p2=var;
        //}
    return p2;
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d\n",p->primo);
        p=p->next;
    }
}


void stampa2(nodo2*p2)
{
    while(p2!=NULL)
    {
        printf("\n%d ",p2->info);
        p2=p2->next;
    }
    printf("  ->NULL");
}

nodo2*doppiamente(nodo*p,nodo2*p2,int k)
{
    nodo*l=p;
    nodo2*l2=p2;
    for(l=p;l!=NULL;l=l->next)
    {
        if(l->primo>k)
        //{
            p2=incoda2(p2,l->primo);
        //}
    }
   return p2;
}
