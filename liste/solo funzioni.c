#include <stdio.h>
#include <malloc.h>
#define INT_MIN -1000
typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;

nodo*crea_elemento(int a);
nodo*inserisci_intesta(nodo*p,int a);
nodo*inserisci_incoda(nodo*p,int a);
nodo*ricerca_elemento(nodo*p,int a);
nodo*elimina_lista(nodo*p);
int occorrenza(nodo*p,int a);
nodo*elimina_occorrenza(nodo*p,int a);
void stampa_lista(nodo*p);
nodo*reverse(nodo*p);
nodo*alterna_elementi_lista(nodo*l1,nodo*l2);
nodo*fusione_liste(nodo*l1,nodo*l2);
nodo*interseca_liste(nodo*l1,nodo*l2);
nodo*elimina_maggiorik(nodo*p,int k);
nodo*massimo_dispari(nodo*p);
int somma_elementi_lista(nodo*p);
int lunghezza_lista(nodo*p);




int main ()
{
    ///non credo che lo riempirò perchè ci saranno solo funzioni varie

    return 0;
}


nodo*crea_elemento(int a)
{
    nodo*q=(struct LISTA*)malloc(sizeof(struct LISTA));
    q->primo=a;
    q->next=NULL;
    return q;
}

nodo*inserisci_intesta(nodo*p,int a)
{
    nodo*q=crea_elemento(a);
    q->next=p;
    return q;
}

nodo*inserisci_incoda(nodo*p,int a)
{
  if(p==NULL)
  {
      p=crea_elemento(a);
  }
  else
  {
      p->next=inserisci_incoda(p->next,a);
  }
  return p;
}

nodo*ricerca_elemento(nodo*p,int a)
{
   nodo*trovato=NULL;
   for(;p!=NULL && trovato==NULL;p=p->next);
   {
       if(p->primo==a)
       {
           trovato=p
       }
   }
   return trovato;
}

nodo*elimina_lista(nodo*p)
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

void stampa_lista(nodo*p)
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

nodo*alterna_elementi_lista(nodo*l1,nodo*l2)
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
        l2->next=alterna_elementi_lista(l1->next,l2->next);
        l3->next=l2;
    }
    return l3;
}

nodo*fusione_liste(nodo*l1,nodo*l2)
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
        l3->next=fusione_liste(l1->next,l2);
    }
    else
    {
        l3=l2;
        l3->next=fusione_liste(l1,l2->next);
    }
    return l3;
}

nodo*interseca_liste(nodo*l1,nodo*l2)
{
    nodo*l3=NULL;
    if(l1)
    {
        l3=interseca_liste(l1->next,l2);
        if(ricerca(l2,l1->primo))
        {
            l3=inserisci_intesta(l3,l1->primo);
        }
    }
    return l3;
}

nodo*elimina_maggiorik(nodo*p,int k)
{
    nodo*tmp;
  if(p==NULL)
  {
      return p;
  }
  else
  {
      p->next=elimina_maggiorik(p->next,a);
      if(p->primo > k)
      {
          tmp=p;
          p=p->next;
          free(tmp);
      }
  }
  return p;
}

nodo*massimo_dispari(nodo*p)
{
    nodo*pmax=NULL;
    int max=INT_MIN;

    if(p==NULL)
    {
        return NULL;
    }
    while(p!=NULL)
    {
        if(p->primo%2!=0 && p->primo<max)
        {
            pmax=p;
            max=p->primo;
        }
        p=p->next;
    }
    return pmax;
}

int somma_elementi_lista(nodo*p)
{
    int sum=0;
    if(p==NULL)
    {
        return 0;
    }
    else
    {
        sum=somma_elementi_lista(p->next);
        sum+=p->primo;
        return sum;
    }
}

int lunghezza_lista(nodo*p)
{
    int len=0;
    while(p!=NULL)
    {
        p=p->next;
        len++;
    }
    return len;
}


