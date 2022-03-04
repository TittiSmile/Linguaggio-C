///N.B.!!!! la funzione funziona (srry per il gioco di parole) MA c'è un problema nella stampa:
///il minimo numero pari lo trova ma se c'è un altro numero dopo,non stampa solo il minimo ma anche il numero dopo
/// esempio: 6-4-2    stampa____> MIN Pari  2
///          2-4-6   stampa____> MIN Pari 2 4 6    4 e 6 in questo caso sono errore ma il 2 (min pari) lo trova. è come
/// se non eliminasse tutti i numeri dopo il min pari.
#include <stdio.h>
#include <malloc.h>
#define INT_MAX  1000
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*intesta(nodo*p,int a);
nodo*incoda(nodo*p,int a);
nodo*elimina(nodo*p);             ///non credo la userò ma la metto
nodo*minimo_pari(nodo*p);
void stampa(nodo*p);

int main ()
{
    nodo*l=NULL;
    int dim,num,i;
    printf("quanti elementi vuoi nella lista? ");
    scanf("%d",&dim);
    for(i=0;i<dim;i++)
    {
        printf("\ninserisci numero ");
        scanf("%d",&num);
        l=incoda(l,num);
    }
    stampa(l);


printf("\necco il puntatore minimo pari: ");
    l=minimo_pari(l);
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

nodo*elimina(nodo*p)
{
    nodo*tmp;
    for(;p!=NULL;p=tmp)
    {
        tmp=p->next;
        p->next=NULL;
        free(p);
    }
    return p;
}

nodo*minimo_pari(nodo*p)
{
    int min=INT_MAX;
    nodo*pmin=NULL;
    if(p==NULL)
    {
        return NULL;
    }
    while(p!=NULL)
    {
        if(p->primo%2==0 && p->primo<min)
        {
            pmin=p;
            min=p->primo;
        }
        p=p->next;

    }
return pmin;
}



void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d\n",p->primo);
        p=p->next;
    }
}

