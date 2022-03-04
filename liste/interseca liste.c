#include <stdio.h>
#include <malloc.h>
typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;

nodo*nelem(int a);
nodo*intesta(nodo*p,int a); ///mi serve solo per la funzione 'interseca'
nodo*incoda(nodo*p,int a);
nodo*ricerca(nodo*p,int a);
nodo*elimina(nodo*p,int a); ///non credo di usarla ma mi va di scriverla.
nodo*interseca(nodo*l1,nodo*l2);
void stampa(nodo*p);

int main ()
{
    ///visto che il programma si incentra solo sulla funzione 'interseca',non ho intenzione di usare lo switch case
    nodo*l1=NULL;
    nodo*l2=NULL;
    nodo*l3=NULL;
    int i=0,dim1,num1;
    int j=0,dim2,num2;

    printf("|quanti numeri vuoi nella lista 1? ");
    scanf("%d",&dim1);
    for(i=0;i<dim1;i++)
    {
        printf("\n\tinserisci %d elemento lista 1:  ",i+1);
        scanf("%d",&num1);
         l1=incoda(l1,num1);
    }

    printf("\n\t\tlista 1: ");
    stampa(l1);

    printf("|nquanti numeri vuoi nella lista 2? ");
    scanf("%d",&dim2);
    for(j=0;j<dim2;j++)
    {
        printf("\n\tinserisci %d elemento lista 2:  ",j+1);
        scanf("%d",&num2);
         l2=incoda(l2,num2);
    }

    printf("\n\t\tlista 2: ");
    stampa(l2);
printf("\ninterseco le due liste(vedo se ci sono numeri uguali e li stampo in una lista)\n");
l3=interseca(l1,l2);
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

nodo*ricerca(nodo*p,int a)
{
    nodo*trovato=NULL;
    for(;p!=NULL && trovato==NULL;p=p->next)
    {
        if(p->primo==a)
        {
            trovato=p;
        }
    }
    return trovato;
}

nodo*elimina(nodo*p,int a)
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

nodo*interseca(nodo*l1,nodo*l2)
{
    nodo*l3=NULL;
    if(l1)
    {
        l3=interseca(l1->next,l2);
        if(ricerca(l2,l1->primo))
        {
            l3=intesta(l3,l1->primo);
        }
    }
    return l3;
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n %d\n",p->primo);
        p=p->next;
    }
}


