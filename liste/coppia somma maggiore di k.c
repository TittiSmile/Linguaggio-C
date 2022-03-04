/*data una lista concatenata di interi L,senza ripetizioni,restituisca una lista non ordinata di numeri appartenenti ad L
la cui somma è maggiore di k   */
#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
 {
     int primo;
     struct LISTA*next;
 }nodo;

typedef struct LISTA2
{
    int primo;
    int secondo;
    struct LISTA2*next;
}nodi;


nodi*aggiungi(nodi*p,int a,int b);
nodi*creacoppia(nodo*p,nodi*coppia,int a);
nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
void stampa(nodo*p);
void stampa2(nodi*p);


int main ()
{
    nodo*l=NULL;
    nodi*c=NULL;
    int i=0,dim,n,k;
    printf("quanti elementi vuoi nella lista? ");
    scanf("%d",&dim);
    for(i=0;i<dim;i++)
    {
        printf("inserisci %d elemento: ",i+1);
        scanf("%d",&n);
        l=incoda(l,n);
    }
    stampa(l);

    printf("\ninserisci un numero k: ");
    scanf("%d",&k);
    c=creacoppia(l,c,k);

    printf("\necco la lista:\n");
    stampa2(c);


    return 0;
}

nodi*aggiungi(nodi*p,int a,int b)
{
    if(p==NULL)
    {
        nodi*tmp=(struct LISTA2*)malloc(sizeof(struct LISTA2));
        tmp->primo=a;
        tmp->secondo=b;
        tmp->next=NULL;
        p=tmp;
    }
    else
    {
        p->next=aggiungi(p->next,a,b);
    }
    return p;
}

nodi*creacoppia(nodo*p,nodi*coppia,int a)
{
    if(p!=NULL)
    {
        nodo*tmp=p->next;
        while(tmp!=NULL)
        {
            if(p->primo + tmp->primo > a)
            {
                coppia=aggiungi(coppia,p->primo,tmp->primo);
            }
            tmp=tmp->next;
        }
        coppia=creacoppia(p->next,coppia,a);
    }
    return coppia;
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

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d ",p->primo);
        p=p->next;
    }
}

void stampa2(nodi*p)
{
       while(p!=NULL)
    {
        printf("\n%d %d ",p->primo,p->secondo);
        p=p->next;
    }
}

