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
nodo*elminorik(nodo*p,int k);
void stampa(nodo*p);

int main ()
{
    nodo*l=NULL;
    int i=0,dim,n,k;

    printf("\nche grandezza?  ");
    scanf("%d",&dim);

    for(i=0;i<dim;i++)
    {
        printf("inserisci numero:   ");
        scanf("%d",&n);
        l=incoda(l,n);
    }
    stampa(l);


    printf("\ninserisci un  numero k:  ");
    scanf("%d",&k);
    printf("\nelimino i minori di %d:  ",k);
    l=elminorik(l,k);
    stampa(l);



    return 0;
}

nodo*nelem(int a)
{
    nodo*q=(nodo*)malloc(sizeof(nodo));
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

nodo*elminorik(nodo*p,int k)
{
  nodo*tmp;
  if(p==NULL)
  {
      return p;
  }
  else
  {
      p->next=elminorik(p->next,k);
      if(p->primo < k)
      {
          tmp=p;
          p=p->next;
          free(tmp);
      }
  }
  return p;
                      ///metodo ricorsivo
 /* nodo*tmp;
  if(p==NULL)
  {
      return p;
  }
  tmp=elminorik(p->next,k);
  if(p->primo > k)
  {
      tmp=incoda(tmp,p->primo);
  }
  return tmp;*/
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d->",p->primo);
        p=p->next;
    }
}
