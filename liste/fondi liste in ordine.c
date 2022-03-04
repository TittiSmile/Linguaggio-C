/* programma che fonde due liste e le restituisce in ordine crescente*/
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
nodo*fondi(nodo*l1,nodo*l2);
nodo*inserisci_ordine(nodo*p,int a); ///in realtà questa funzione (che ricordo mette in ordine
                                    ///gli elementi direttamente dall'acquisizione) non serve perchè non mette in ordine i
                                    ///numeri durante l'unione. va usata la funzione ordine crecente apposta.
nodo*crescente(nodo*p);
nodo*ordine(nodo*tmp,nodo*p);
void stampa(nodo*p);

int main ()
{
    nodo*l1=NULL;
    nodo*l2=NULL;
    nodo*l3=NULL;
    int dim,dom,i=0,j=0,n,m;

    printf("quanto vuoi grande la lista 1 ?  ");
    scanf("%d",&dim);
    printf("quanto vuoi grande la lista 2 ?  ");
    scanf("%d",&dom);

    for(i=0;i<dim;i++)
    {
        printf("inserisci %d elemento della lista 1 : ",i+1);
        scanf("%d",&n);
        l1=incoda(l1,n);
    }
    for(j=0;j<dom;j++)
    {
        printf("inserisci %d elemento della lista 2: ",j+1);
        scanf("%d",&m);
        l2=incoda(l2,m);
    }



    printf("\nla lista 1 e':   ");
    stampa(l1);
    printf("\nla lista 2 e':   ");
    stampa(l2);

    l1=crescente(l1);
    l2=crescente(l2);


    printf("\nfondo le due liste e le metto in ordine crescente\n");
    l3=fondi(l1,l2);
    l3=crescente(l3);
    stampa(l3);



    return 0;
}


nodo*nelem(int a)
{
    nodo*q=(struct LISTA*)malloc(sizeof(struct LISTA));
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

nodo*fondi(nodo*l1,nodo*l2)
{
    nodo*l3=NULL;
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
nodo*inserisci_ordine(nodo*p,int a)
{
    nodo*tmp;
    if(p==NULL || tmp->primo > a)    ///ordine CRESCENTE
    {
        tmp=(struct LISTA*)malloc(sizeof(struct LISTA));
        tmp->primo=a;
        tmp->next=p;
        p=tmp;
    }
    else
    {
        p->next=inserisci_ordine(p->next,a);
    }
    return p;
}

struct LISTA *ordine(struct LISTA *p,struct LISTA *tmp)
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

struct LISTA *crescente(struct LISTA *p)
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

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d ",p->primo);
        p=p->next;
    }
}
