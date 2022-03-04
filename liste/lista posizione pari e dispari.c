/*data una lista L1 si fornisca una funzione iterativa che restituisca una lista L2 con i numeri della lista L1 in posizione
pari. esempio:
input: L1-> 1-43-2-6-44-5
output: L1-> 1-2-44      L2-> 43-6-5
TRACCIA DEL 21/01/16
c'è comunque qualcosa che non va.... rip
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;


nodo*nelem(int a);
nodo*intesta(nodo*p,int a);   ///non è necessaria ma la faccio lo stesso
nodo*incoda(nodo*p,int a);
int occorrenza(nodo*p,int a);   ///Non necessaria
nodo*elimina_occorrenza(nodo*p,int a);
nodo*paridispari(nodo*l1);
void stampa(nodo*p);

int main ()
{
    nodo*l1=NULL;
    nodo*l2=NULL;
    int i,dim,n,a;

    /*printf("quanto vuoi grande la tua lista?  ");
    scanf("%d",&dim);
    for(i=0;i<dim;i++)
    {
        printf("inserisci l'elemento %d :  ",i+1);
        scanf("%d",&n);
        l1=incoda(l1,n);
    }*/

    l1=incoda(l1,22);l1=incoda(l1,1);l1=incoda(l1,5);l1=incoda(l1,3);l1=incoda(l1,28);l1=incoda(l1,15);
    printf("\nla lista e': ");
    stampa(l1);

    l2=paridispari(l1);
    printf("\ndivido i numeri in posizione pari e dispari in due liste separate:\n ");
    printf("\nlista 1: ");
    stampa(l1);
    printf("\nlista 2: ");
    stampa(l2);


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

int occorrenza(nodo*p,int a)
{
    int flag;
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
   ///versione iterativa
    /*nodo*tmp;
    nodo*cur=p;
    while(cur->next!=NULL)
    {
        if(cur->next->primo==a)
        {
            tmp=cur->next;
            cur->next=cur->next->next;
            free(tmp);
        }
        cur=cur->next;
    }
    if(p->primo==a)
    {
        tmp=p;
        p=p->next;
        free(tmp);
    }
    return p;*/
}

nodo*paridispari(nodo*l1)
{
  int flag=1;
  nodo*tmp=NULL;
  nodo*var=l1;
  while(var!=NULL)
  {
      if(flag%2==0)
      {
          tmp=incoda(tmp,var->primo);
          l1=elimina_occorrenza(l1,var->primo);
      }
      var=var->next;
      flag++;
  }
  return tmp;
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n %d  ",p->primo);
        p=p->next;
    }
}

