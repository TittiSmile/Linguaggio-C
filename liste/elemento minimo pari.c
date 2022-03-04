/// anche qui,la funzione funziona ma con qualche problemino ):
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*intesta(nodo*p,int a);
nodo*incoda(nodo*p,int a);
nodo*minpari(nodo*p);
void stampa(nodo*p);


int main ()
{
    int i=0,dim,n;
    nodo*l=NULL;

    printf("quanti elementi vuoi? ");
    scanf("%d",&dim);
    for(i=0;i<dim;i++)
    {
        printf("inserisci %d valore: ",i+1);
        scanf("%d",&n);
        l=incoda(l,n);
    }
    stampa(l);
    printf("\nritorno l'elemento pari più piccolo\n");
    l=minpari(l);
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

nodo*minpari(nodo*p)
{
    int min=INT_MAX;
    nodo*tmp;
    if(p==NULL)
    {
        return p;
    }
    while(p!=NULL)
    {
        if(p->primo%2 == 0 && p->primo < min)
        {
            tmp=p;
            min=p->primo;
        }
        p=p->next;
    }
    return tmp;

}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("%d -> \n",p->primo);
        p=p->next;
    }
}
