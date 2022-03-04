#include <stdio.h>
#include <malloc.h>
typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;


nodo*nelem(int a);
nodo*intesta(nodo*p,int a);
nodo*incoda(nodo*p,int a);
nodo*ricerca(nodo*p,int a);
nodo*elimina(nodo*p);
nodo*unisci(nodo*l1,nodo*l2);
nodo*inordine(nodo*p,nodo*tmp);
nodo*crescente(nodo*p);
void stampa(nodo*p);


int main ()
{
   nodo*l1=NULL;
   nodo*l2=NULL;
   nodo*l3=NULL;
   int i=0,j=0,len1,len2,numl1,numl2;

  printf("quanto vuoi grande la 1 lista?  ");
  scanf("%d",&len1);
  printf("\nquanto vuoi grande la 2 lista?  ");
  scanf("%d",&len2);

  for(i=0;i<len1;i++)
  {
      printf("\ninserisci %d elemento della lista 1:  ",i+1);
      scanf("%d",&numl1);
      l1=incoda(l1,numl1);
  }

  for(j=0;j<len2;j++)
  {
      printf("\ninserisci %d elemento della lista 1:  ",j+1);
      scanf("%d",&numl2);
      l2=incoda(l2,numl2);
  }

    printf("\nla lista 1 è:\n");
    stampa(l1);

    printf("\nla lista 2 è:\n");
    stampa(l2);

    printf("\nle due liste unite sono:\n");
    l3=unisci(l1,l2);
    stampa(l3);

    printf("\nora le metto in ordine crescente:\n");
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

nodo*elimina(nodo*p)
{
   nodo*tmp=NULL;
   for(;p!=NULL;p=tmp)
   {
       tmp=p->next;
       p->next=NULL;
       free(p);
   }
   return p;
}

nodo*inordine(nodo*p,nodo*tmp)
{
  if(p==NULL || p->primo > tmp->primo)
  {
      tmp->next=p;
      p=tmp;
  }
  else
  {
      p->next=inordine(p->next,tmp);
  }
  return p;

}

nodo*crescente(nodo*p)
{
    nodo*tmp;
    nodo*lista=NULL;
    while(p!=NULL)
    {
        tmp=p;
        p=p->next;
        lista=inordine(lista,tmp);
    }
    return lista;
}

nodo*unisci(nodo*l1,nodo*l2)
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
        l3->next=unisci(l1->next,l2);
    }
    else
    {
        l3=l2;
        l3->next=unisci(l1,l2->next);
    }
    return l3;


}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\nlista: %d\n",p->primo);
        p=p->next;
    }
}
