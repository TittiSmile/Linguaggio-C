/*date due liste ordinate di interi, scrivere una funzione ricorsiva che fonda le due liste in una nuova lista ordinata l3.
la funzione NON deve modificare le due liste ma creare una nuova lista allocando memoria dinamicamente.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;


nodo*nuovoElem(int a);
nodo*InCoda(nodo*p,int a);
nodo*casuale(nodo*p,int dim); ///mi serve per inserire numeri casuali nella lista
nodo*fondi(nodo*l1,nodo*l2);
nodo*ordina(nodo*p,nodo*tmp);
nodo*crescente(nodo*p);
void stampa(nodo*p);

int main ()
{
    nodo*l1=NULL;
    nodo*l2=NULL;
    nodo*l3=NULL;
    int dim,dim2,n;

    l1=InCoda(l1,3); l1=InCoda(l1,20); l1=InCoda(l1,25);
    l2=InCoda(l2,6); l2=InCoda(l2,15); l2=InCoda(l2,44);

    stampa(l1);
    stampa(l2);

    printf("\nunisco le due liste ordinate:  ");
    l3=fondi(l1,l2);
    stampa(l3);

    /*printf("quanto vuoi grande la lista 1?  ");
    scanf("%d",&dim);
    l1=casuale(l1,dim);
    stampa(l1);

    printf("\n\nquanto vuoi grande la lista 2?   ");
    scanf("%d",&dim2);
    l2=casuale(l2,dim2);
    stampa(l2);

    printf("\nfondo le due liste:\n");
    l3=fondi(l1,l2);
    l3=crescente(l3);
    stampa(l3);*/



    return 0;
}


nodo*nuovoElem(int a)
{
    nodo*q=(nodo*)malloc(sizeof(nodo));
    q->primo=a;
    q->next=NULL;
    return q;
}

nodo*InCoda(nodo*p,int a)  ///prefeirsco usare la forma ricorsiva
{
    if(p==NULL)
    {
        p=nuovoElem(a);
    }
    else
    {
        p->next=InCoda(p->next,a);
    }
    return p;
}

nodo*casuale(nodo*p,int dim)
{
    int i=0,n;
    srand((unsigned)time(NULL));
    for(i=0;i<dim;i++)
    {
        n=rand()%20+1;
        p=InCoda(p,n);
    }
    return p;
}

nodo*fondi(nodo*l1,nodo*l2)
{
    nodo*l3;
    if(l1==NULL)
    {
        return l2;
    }
    else if(l2==NULL)
    {
        return l1;
    }
    else if(l1->primo < l2->primo)
    {
        l3=l1;
        l3->next=fondi(l1->next,l2);
    }
    else
    {
        l3=l2;
        l3->next=fondi(l1,l2->next);
    }
    return l3;
}

nodo*ordina(nodo*p,nodo*tmp)
{
    if(p==NULL || p->primo > tmp->primo)
    {
        tmp->next=p;
        p=tmp;
    }
    else
    {
        p->next=ordina(p->next,tmp);
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
        l=ordina(l,tmp);
    }
    return l;
}



void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d->",p->primo);
        p=p->next;
    }
    printf("\tNULL");
}

