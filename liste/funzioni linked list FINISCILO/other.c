#include <time.h>
#include <limits.h>
#define MAX 20
#include "basic.h"
#include "SuDueListe.h"
#include "listaSuK.h"
#include "ordinamento.h"
#include "other.h"
#include "structStudente.h"
#include "linkedToDoubly.h"



///QUINTO  BLOCCO
nodo*MassimoDispariLista(nodo*p)
{
    int max=INT_MIN;
    nodo*tmp;
    if(p==NULL)
    {
        return p;
    }
    while(p!=NULL)
    {
        if(p->primo%2!=0 && p->primo > max)
        {
            tmp=p;
            max=p->primo;
        }
        p=p->next;
    }
    return tmp;
}

nodo*EliminaPariPosizDispari(nodo*p)
{
    nodo*tmp;
    if(p)
    {
        if(p->next)
        {
            p->next->next=EliminaPariPosizDispari(p->next->next);
        }
    }
    if(!(p->primo%2))
    {
        tmp=p;
        p=p->next;
        free(tmp);
    }
    return p;
}

void somma(nodo*p)
{
    while(p!=NULL)
    {
        p->primo=sommaPrecedenti(p->next);
        p=p->next;
    }
}

int sommaPrecedenti(nodo*p)
{
    int s=0;
    while(p!=NULL)
    {
        s+=p->primo;
        p=p->next;
    }
}

///OTTAVO BLOCCO
int LunghezzaLista(nodo*p)
{
    int i=0;
    while(p!=NULL)
    {
        i++;
        p=p->next;
    }
    return i;
}
nodo*AggiungiDuplicati(nodo*p,int a)
{
    if(p!=NULL)
    {
        if(occorrenza(p,a)==1)
        {
            p=intesta(p,a);
        }
    }
    return p;
}

nodo*CasualiLista(nodo*p,int a) //a sarebbe la dimensione della lista!!!
{
 int n=0;
 int i=0;
 srand((unsigned)time(NULL));
 for(i=0;i<a;i++)
 {
     n=rand()%50+1;  //ho scelto da 1 a 50
     p=incoda(p,n);
 }
 return p;
}

nodo*InvertiLista(nodo*p)
{
    ///non so perchè ma crasha alla fine lol  N.B. devi mettere prev=NULL
    /*nodo*curr=p;
    nodo*prev=NULL;
    nodo*succ;
    while(curr!=NULL)
    {
        succ=curr->next;
        curr->next=prev;
        prev=curr;
        curr=succ;
    }
    p=prev;
    return p;*/

    nodo*cur=p;
    p=NULL;
    while(cur!=NULL)
    {
        nodo*var=cur;
        cur=cur->next;
        var->next=p;
        p=var;
    }
    return p;
}

nodo*duplica(nodo*p) ///elimina tutti i duplicati dalla lista
{
  ///VERSIONE RICORSIVA
  nodo*tmp=p;
  nodo*cur=p;
  if(p==NULL)
  {
   return p;
  }
  p->next=duplica(p->next);
  while(cur!=NULL && cur->next!=NULL)
  {
    cur=cur->next;
    if(p->primo==cur->primo)
    {
      tmp=p->next;
      free(p);
    }
  }
  return tmp;

  ///VERSIONE ITERATIVA
  /*nodo*cur=p;
  nodo*tmp;
  nodo*var=p;
  while(var!=NULL)
  {
      while(cur->next!=NULL)
      {
          if(var->primo==cur->next->primo)
          {
              tmp=cur->next;
              cur->next=cur->next->next;
              free(tmp);
          }
          else
            cur=cur->next;
      }
      var=var->next;
      cur=var;
  }
  return p;*/

}


