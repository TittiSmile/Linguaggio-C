///fondo le due liste mettendo i numeri in ordine l1: 1 4 2 l2: 66 3 22  stampo: 1-2-3-4-22-66
#include <stdio.h>
#include <malloc.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*intesta(nodo*p,int a);
nodo*incoda(nodo*p,int a);
nodo*ricerca(nodo*p,int a);
//nodo*inordine(nodo*l1,nodo*l2);
nodo*inordine(nodo*p,int a);
nodo*fusione(nodo*l1,nodo*l2);
void stampa(nodo*p);

int main ()
{
    nodo*l1=NULL;
    nodo*l2=NULL;
    nodo*l3=NULL;
    int i,dim1,n;
    int j,dim2,m;
    printf("\nquanto vuoi grande la lista 1? ");
    scanf("%d",&dim1);
    for(i=0;i<dim1;i++)
    {
        printf("inserisci elemento  ");
        scanf("%d",&n);
        //l1=incoda(l1,n);
        l1=inordine(l1,n);
    }


   stampa(l1);

    printf("\nquanto vuoi grande la lista 2? ");
    scanf("%d",&dim2);
    for(j=0;j<dim2;j++)
    {
        printf("inserisci elemento  ");
        scanf("%d",&m);
        //l2=incoda(l2,m);
        l2=inordine(l2,m);
    }


   stampa(l2);


    printf("\nunisco le due liste ");
    l3=fusione(l1,l2);
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
    return p;
}

nodo*inordine(nodo*p,int a)
{
    /*if(l1==NULL || l1->primo > l2->primo)
    {
        l2->next=l1;
        l1=l2;
    }
    else
    {
        l1->next=inordine(l1->next,l2);
    }
    return l1;*/

    nodo*tmp;
    if(p==NULL || a< p->primo)
    {
        tmp=(struct LISTA*)malloc(sizeof(struct LISTA));
        tmp->primo=a;
        tmp->next=p;
        p=tmp;
    }
    else
    {
        p->next=inordine(p->next,a);
    }
  return p;
}

nodo*fusione(nodo*l1,nodo*l2)
{
   nodo*l3=NULL;
   if(l1==NULL)
   {
       return l2;
   }
   else if (l2==NULL)
   {
       return l1;
   }
   else if(l1->primo < l2->primo)
   {
       l3=l1;
       l3->next=fusione(l1->next,l2);
   }
   else
   {
       l3=l2;
       l3->next=fusione(l1,l2->next);
   }
   return l3;
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d\n",p->primo);
        p=p->next;
    }
}

