#include <stdio.h>
#include <stdlib.h>
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

///SECONDO BLOCCO
nodo*InsInOrdine(nodo*p,int a)
{
  nodo*tmp=(nodo*)malloc(sizeof(nodo));
  if(p==NULL || tmp->primo > a)
  {
    tmp=nelem(a);
    tmp->next=p;
    p=tmp;
  }
  else
  {
  p->next=InsInOrdine(p->next,a);
  }
  return p;
}

nodo*ordinamento(nodo*p,nodo*tmp)
{
    if(p==NULL || p->primo > tmp->primo)
    {
       tmp->next=p;
       p=tmp;
    }
    else
    {
        p->next=ordinamento(p->next,tmp);
    }
return p;
}

nodo*crescente(nodo*p)
{
nodo*tmp;
nodo*l=NULL;
while(p!=NULL)
{
  tmp=p;
  p=p->next;
  l=ordinamento(l,tmp);
}
return l;
}
