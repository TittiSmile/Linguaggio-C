#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;


nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
int somma(nodo*p);        ///questa è la semplice somma di TUTTI gli elementi della lista: 3->1->5->   out: 9
int sommapre(nodo*p);    ///va richiamata nella funzione sotto
void sum(nodo*p);
void stampa(nodo*p);
nodo*reverse(nodo*p);

int main ()
{
    int i=0,dim,n;
    nodo*l=NULL;
    printf("quanto vuoi grande la tua lista?  ");
    scanf("%d",&dim);
    for(i=0;i<dim;i++)
    {
        printf("inserisci %d elemento:   ",i+1);
        scanf("%d",&n);
        l=incoda(l,n);
    }
    stampa(l);

    printf("\nsommo man mano tutti gli elementi: \n ");
    sum(l);
    stampa(l);



    return 0;
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

int somma(nodo*p)
{
    int s=0;
    if(p==0)
    {
        return 0;
    }
    else
    {
        s=somma(p->next);
        s+=p->primo;
        return s;
    }
}

int sommapre(nodo*p)
{
    int s=0;
    while(p!=NULL)
    {
        s+=p->primo;
        p=p->next;
    }
    return s;
}

void sum(nodo*p)
{
    while(p!=NULL)
    {
        p->primo=sommapre(p);
        p=p->next;
    }
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("%d->",p->primo);
        p=p->next;

    }printf("NIL");
}
nodo*reverse(nodo*p)
{
    if(p==NULL)
        return 0;
    reverse(p->next);
    printf("%d-> ",p->primo);
}

