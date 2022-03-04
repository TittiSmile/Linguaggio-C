#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*casuale(nodo*p,int dim);
nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
nodo*fondi(nodo*l1,nodo*l2);
void stampa(nodo*p);


int main ()
{
    nodo*l1=NULL;
    nodo*l2=NULL;
    nodo*l3=NULL;
    int dim,a,i=0,dom;

    printf("\ngrandezza lista UNO?  ");
    scanf("%d",&dim);
    printf("\ngrandezza lista DUE?  ");
    scanf("%d",&dom);

    l1=casuale(l1,dim);
    l2=casuale(l2,dom);
    printf("\nlista uno:  ");
    stampa(l1);
    printf("\nlista due:  ");
    stampa(l2);
    printf("\nfondo le due liste:  ");
    l3=fondi(l1,l2);
    stampa(l3);

    return 0;
}

nodo*casuale(nodo*p,int dim)
{
    int i=0;
    int a;
    srand((unsigned)time(NULL));
    for(i=0;i<dim;i++)
    {
        a=rand()%100+1;
        p=incoda(p,a);
    }
    return p;
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

nodo*fondi(nodo*l1,nodo*l2)
{
   /* nodo*l3;
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
        l3=incoda(l3,l1->primo);
        l3->next=fondi(l1->next,l2);
    }
    else //if(l1->primo > l2->primo)
    {
        l3=incoda(l3,l2->primo);
        l3->next=fondi(l1,l2->next);
    }
    return l3;*/
      struct elem *l3 = NULL;

  if ( l1 == NULL ) return l2;
  if ( l2 == NULL ) return l1;

    if ( l1->primo < l2->primo ) {
      l3 = incoda( l3, l1->primo );
      l3->next = fondi( l1->next, l2 );
    }
    else {
      l3 = incoda( l3, l2->primo );
      l3->next = fondi( l1, l2->next );
    }

  return l3;
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d->",p->primo);
        p=p->next;
    }
}
