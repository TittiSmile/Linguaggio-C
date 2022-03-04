/*questa funzione,che prende numeri da 1 ad m da inserire nella lista L, mette in una nuova lista tutti gli elementi di
L che si ripetono più di k volte.
k=2
L= 1 4 5 6 4 8 4 9           L2= 4*/
#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
nodo*insordine(nodo*p,int a);
nodo*funzocc(nodo*p,int k); ///elimina tutte le occorrenze ripetute k volte
void stampa(nodo*p);

int main ()
{
    nodo*l1=NULL;
    int k=0;
    int n=0,m=0,dim=0,i=0;

    l1=incoda(l1,5);l1=incoda(l1,3);l1=incoda(l1,4);l1=incoda(l1,1);l1=incoda(l1,5);l1=incoda(l1,1);l1=incoda(l1,2);
    l1=incoda(l1,4);l1=incoda(l1,4);l1=incoda(l1,3);l1=incoda(l1,1);
    stampa(l1);

   /* printf("inserisci grandezza lista: ");
    scanf("%d",&dim);

    printf("inserisci un numero m: ");
    scanf("%d",&m);

    printf("\n\tiserisci numeri da 1 ad %d",m);
    do
    {
        for(i=0;i<dim;i++)
        {
            printf("\ninserisci %d numero in lista:  ",i+1);
            scanf("%d",&n);
            l1=incoda(l1,n);
        }
        if (n<1 && n>=m)
        {
            printf("\t\terrore,riprova");
        }
    }while(n>1 && n>m);*/

    printf("\ninserisci un numero k: ");
    scanf("%d",&k);
    l1=funzocc(l1,k);
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

nodo*insordine(nodo*p,int a)
{
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    if(p==NULL || p->primo > a)
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

nodo*funzocc(nodo*p,int k)
{
    nodo*l=NULL;
    nodo*succ;
    int cont=0;//oppure =1
    int var;
    while(p!=NULL)
    {
        var=p->primo;
        succ=p->next;
        while(succ)
        {
            if(succ->primo==var)
            {
                cont++;
            }
            succ=succ->next;
        }
        if(cont > k)
        {
            l=insordine(l,var);
        }
        cont=1;
        p=p->next;
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
}

