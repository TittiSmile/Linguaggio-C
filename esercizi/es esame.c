///N.B. la funzione 'multiplo' non funziona bene... non mi stampa la nuova lista. EDIT: risolto
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;

nodo*nelem(int a);
nodo*intesta(nodo*p,int a);
nodo*incoda(nodo*p,int a);
nodo*casuale(nodo*p,int dim);
int occorrenza(nodo*p,int a);
nodo*elimina_occorrenza(nodo*p,int a);
nodo*multiplo(nodo*p,int a);
void stampa(nodo*p);
int lunghezza(nodo*p);

int main ()
{
    nodo*l=NULL;
    nodo*l2=NULL;
    int dim,num,i;
    int volte;

    /*while(volte<20)
    {
        num=rand()%99+1;
        volte++;
        l=incoda(l,num);
    }*/
    l=casuale(l,5);
    stampa(l);
    printf("\nquale occorrenza vuoi contare? ");
    scanf("%d",&num);
    printf("\nle occorrenze di %d erano %d ",num,occorrenza(l,num));

    printf("\nquale occorrenza vuoi rimuovere? ");
    scanf("%d",&num);
    l=elimina_occorrenza(l,num);
    printf("\nho eliminato le occorrenze di %d ",num);
    stampa(l);

    printf("\ntutti i multipli di 3 andranno su una nuova lista ");
    l2=multiplo(l,num);
    stampa(l2);


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

nodo*casuale(nodo*p,int dim)
{
    int i=0;
    int a;
    srand((unsigned)time(NULL));
    for(i=0;i<dim;i++)
    {
        a=rand()%10+1;
        p=incoda(p,a);
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

nodo*elimina_occorrenza(nodo*p,int a)
{
    nodo*tmp=p;
    if(p!=NULL)
    {
        if(p->primo==a)
        {
            p=elimina_occorrenza(p->next,a);
            free(tmp);
        }
        else
        {
            p->next=elimina_occorrenza(p->next,a);
        }
    }
    return p;
}

nodo*multiplo(nodo*p,int a)
{
    nodo*l1=NULL;
    while(p!=NULL)
    {
        if(p->primo%3==0)
        {
            l1=intesta(l1,p->primo);
        }
        p=p->next;
    }
return l1;
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d\n",p->primo);
        p=p->next;
    }
}

int lunghezza(nodo*p)
{
    int len=0;
    while(p!=NULL)
    {
        p=p->next;
        len++;
    }
    return len;
}
