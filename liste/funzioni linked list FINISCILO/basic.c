#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define MAX 20
#include "basic.h"
///PRIMO BLOCCO
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
{p=nelem(a);}
else
{p->next=incoda(p->next,a);}
return p;

///VERSIONE ITERATIVA NON ANCORA SPERIMENTATA!!!!!!!!!
/*struct elem* tmp=top;
	if (top==NULL){
		top=newnodo;
	}
	else {
		while (tmp->next!=NULL){
				tmp=tmp->next;
		}
		tmp->next=newnodo;
	}
	return top;*/
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
  return flag;
}
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
    printf("\n%d->",p->primo);
    p=p->next;
    }
}

nodo*reverse(nodo*p)
{
   if(p==NULL)
   {return 0;}
  reverse(p->next);
  printf("\n%d->",p->primo);
}

int sommaLista(nodo*p)
{
   int s=0;
   if(p==NULL)
   {return 0;}
   else
   {
     s=sommaLista(p->next);
     s+=p->primo;
     return s;
   }
}
