///N.B. contiene solo le funzioni e la struct

#include <stdio.h>
#include <malloc.h>
typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;

///prototipi
nodo*nelem(int a);
nodo*intesta(nodo*p,int a);
nodo*incoda (nodo*p,int a);
nodo*ricerca(nodo*p,int a);
nodo*elimina(nodo*p);
int occorrenza(nodo*p,int a);
nodo*elimina_occorrenza(nodo*p,int a);
void stampa(nodo*p);
nodo*reverse(nodo*p);
int somma(nodo*p);
nodo*alterna_lista(nodo*l1,nodo*l2);
nodo*unisci_lista(nodo*l1,nodo*l2);
nodo*interseca(nodo*l1,nodo*l2);

int main ()
{
    ///roba
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

nodo*incoda (nodo*p,int a)
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
    nodo*trovato;
    for(;p!=NULL && trovato==NULL;p=p->next)
    {
        if(p->primo==a)
        {
            trovato=p;
        }
    }
    return trovato;
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

void stampa(nodo*p)
{
   while(p!=NULL)
   {
       printf("\n%d\n",p->primo);
       p=p->next;
   }
}

nodo*reverse(nodo*p)
{
   if(p==NULL)
        return 0;
   reverse(p->next);
   printf("\n%d\n",p->primo);
}

int somma(nodo*p)
{
  int s=0;
  if(p==0)
  {
      return 0;
  }
  else
  {
      s=somma(p->next);
      s+=p->primo;
      return s;
  }
}

nodo*alterna_lista(nodo*l1,nodo*l2)
{
    nodo*l3=l1;
    if(l1==NULL)
    {
        return l2;
    }
    else if(l2==NULL)
    {
        return l1;
    }
    else
    {
       l2->next=alterna_lista(l1->next,l2->next);
       l3->next=l2;
    }
    return l3;
}

nodo*unisci_lista(nodo*l1,nodo*l2)
{
   nodo*l3;
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
        l3->next=unisci_lista(l1->next,l2);
    }
    else
    {
        l3=l2;
        l3->next=unisci_lista(l1,l2->next);
    }
       return l3;
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
