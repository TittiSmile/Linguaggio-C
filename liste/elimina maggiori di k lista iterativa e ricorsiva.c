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
nodo*eliminamaggiorik(nodo*p,int k);
void stampa(nodo*p);

int main ()
{
    nodo*l=NULL;
    int k,i=0,dim,n;

    printf("quanto vuoi grande la tua lista?   ");
    scanf("%d",&dim);

    for(i=0;i<dim;i++)
    {
        printf("inserisci %d elemento:   ",i+1);
        scanf("%d",&n);
        l=incoda(l,n);
    }

    printf("\nla lista e':   ");
    stampa(l);

    printf("\ninserisci un numero k:   ");
    scanf("%d",&k);

    printf("elimino i maggiori di k: \n");
    l=eliminamaggiorik(l,k);
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

nodo*eliminamaggiorik(nodo*p,int k)
{
  nodo*tmp=NULL;
  if(p==NULL)
  {
      return p;
  }
  else
  {
      p->next=eliminamaggiorik(p->next,k);
      if(p->primo > k)
      {
          tmp=p;
          p=p->next;
          free(tmp);
      }
  }
  return p;

  //ITERATVA
 /* nodo*tmp;
  nodo*var=p;
  while(var->next!=NULL)
  {
       if(var->next->primo > k)
          {
           tmp=var->next;
           var->next=var->next->next;
           free(tmp);
          }
           else
           {
            var=var->next;
            }
    }
    if(p->primo > k)
    {
        tmp=p;
        p=p->next;
        free(tmp);
    }
    return p;*/
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d",p->primo);
        p=p->next;
    }
}


