#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;

int casuale(int a); ///**********************************
nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
int occorrenza(nodo*p,int a);
nodo*elocc(nodo*p,int a);
void stampa(nodo*p);
nodo*multiplo(nodo*l1,nodo*l2);  /// questa funzione ritorna solo gli elementi di p che sono multipli di 3


int main ()
{
    nodo*l=NULL;
    nodo*l2=NULL;
    int i=0,n,dim,a;
    srand((unsigned) time (NULL));

    printf("quanti elementi?  ");
    scanf("%d",&dim);

    for(i=0;i<dim;i++)
    {
        //a=casuale(a);    ///mi dà lo stesso numero.
        a=rand()%100+1;  ///N.B. non so perchè,ma adesso,senza motivo,funziona! una vita intera a non funzionare e ora va(mi ripeteva sempre lo stesso numero)
        l=incoda(l,a);
    }
    stampa(l);

    /*printf("\nquale occorrenza vuoi contare?   ");
    scanf("%d",&a);
    printf("\nle occorrenze di %d sono: %d",a,occorrenza(l,a));
    printf("\nelimino le occorrenze di %d ",a);
    elocc(l,a);
    stampa(l);*/

    printf("\ncreo una lista con solo i multipli di 3:  ");
    l2=multiplo(l,l2);                                       ///non funziona molto bene... prende i multipli a cazzo
    stampa(l2);



}

nodo*nelem(int a)
{
    nodo*q=(struct LISTA*)malloc(sizeof(struct LISTA));
    q->primo=a;
    q->next=NULL;
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
int occorrenza(nodo*p,int a)
{
    int flag=0;
    if(p!=NULL)
    {
        if(p->primo==a)
        {
            flag=1+occorrenza(p->next,a);
        }
        else
        {
            flag=occorrenza(p->next,a);
        }
    }
    return flag;
}

nodo*elocc(nodo*p,int a)
{
    nodo*tmp=p;
    if(p!=NULL)
    {
        if(p->primo==a)
        {
            p=elocc(p->next,a);
            free(tmp);
        }
        else
        {
            p->next=elocc(p->next,a);
        }
    }
    return p;
}



void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d ",p->primo);
        p=p->next;
    }
}

nodo*multiplo(nodo*l1,nodo*l2)
 {
     int i=0;
     nodo*tmp=NULL;
     nodo*l3=l1;
     if(l3!=NULL)
     {
         if(l3->primo%3==0)
         {
             tmp=incoda(tmp,l3->primo);
             l1=elocc(l1,l3->primo);
         }
         l3=l3->next;
     }
     return tmp;
 }


/*
non serve ad un cazzo,ho fatto tutto nel main
grazie al cazzo!!!! ti ritorna un intero! bufu!!!
int casuale(int a)
{
    srand((unsigned) time(NULL));
    a=rand()%100+1;
    return a;
}*/
///ecco come dovrebbe essere fatta una funzione casuale
nodo*casualee(nodo*p,int dim) //gli passo la dimensione della lista e la lista
{
    int i=0;
    int a=0;
    srand((unsigned)time(NULL));
    for(i=0;i<dim;i++)
    {
        a=rand()%100+1;
        p=incoda(p,a);
    }
    return p;
}
