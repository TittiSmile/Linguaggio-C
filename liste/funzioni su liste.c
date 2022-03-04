///ci sono tante funzioni e le proverò singolarmente commentando man mano le cose che vanno bene
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*intesta(nodo*p,int a);
nodo*incoda(nodo*p,int a);
nodo*ricerca(nodo*p,int a);
int occorrenza(nodo*p,int a);
nodo*elimina_occorrenza(nodo*p,int a);
nodo*elimina(nodo*p);
void stampa(nodo*p);
nodo*reverse(nodo*p);
int somma(nodo*p);
///su k
nodo*elimina_maggiorik(nodo*p,int k);
nodo*maggioriprimak (nodo*p,int k);
///ordinamento
nodo*ordina(nodo*p,nodo*tmp);
nodo*crescente(nodo*p);
///unione, intersez,alterna
nodo*alterna(nodo*l1,nodo*l2);
nodo*unisci(nodo*l1,nodo*l2);
nodo*interseca(nodo*l1,nodo*l2);
nodo*diffsimm(nodo*l1,nodo*l2,nodo*l3);
///pari e dispari
nodo*puntdispmax(nodo*p);
nodo*elpari(nodo*p);



int main ()
{
    nodo*l1=NULL;
    nodo*l2=NULL;
    nodo*l3=NULL;
    nodo*tmp=NULL;
    int i=0,n,k,a;
    l1=incoda(l1,1);l1=incoda(l1,2);l1=incoda(l1,3);l1=incoda(l1,4);
    l2=incoda(l2,5);l2=incoda(l2,6);l2=incoda(l2,7);l2=incoda(l2,8);
    stampa(l1);
   /* printf("inserire elemento da ricercare: ");
    scanf("%d",&n);
    if(ricerca(l1,n))                                          FUNZIONA
        printf("elemento trovato");
    else
    {
        printf("elemento NON trovato");
    }*/

    /*printf("quale occorrenza vuoi cercare?   ");
    scanf("%d",&n);
    a=occorrenza(l1,n);                                        FUNZIONA
    printf("\nil numero di occorrenze di %d e': %d",n,a);*/

    /*printf("quale occorrenza vuoi eliminare?   ");
    scanf("%d",&n);
    l1=elimina_occorrenza(l1,n);                                FUNZIONA
    stampa(l1);*/

    /*printf("elimino la lista:  ");
    l1=elimina(l1);
    stampa(l1);                                               FUNZIONA
    printf("LISTA ELIMINATA");*/

    /*printf("stampo al contrario");                           FUNZIONA
    reverse(l1);*/

    //printf("la somma di tutti gli elementi della lista e': %d",somma(l1));   FUNZIONA

    /*printf("inserisic un numero k:  ");
    scanf("%d",&k);
    l1=elimina_maggiorik(l1,k);                                        FUNZIONA
    stampa(l1);*/

   /* printf("inserisic un numero k:  ");
    scanf("%d",&k);
    printf("minori prima dei maggiori di k");              NON FUNZIONA
    l1=maggioriprimak(l1,k);
    stampa(l1);*/

   /* printf("ordino in modo crescente la lista:");
    l1=crescente(l1);                                     FUNZIONA
    stampa(l1);*/

    /*printf("alterno gli elementi delle due liste:  ");
    l3=alterna(l1,l2);                                           FUNZIONA
    stampa(l3);*/

   /*printf("unisco gli elementi delle due liste: ");
    l3=unisci(l1,l2);                                            FUNZIONA
    stampa(l3);*/

    /*printf("interseco gli elementi delle due liste:  ");
    l3=interseca(l1,l2);
    stampa(l3);                                                      FUNZIONA
    if(l3==NULL)
    {
        printf("\n\tNON ci sono elementi in comune");
    }*/

    /*printf("faccio la differenza simmetrica delle due liste: ");        FUNZIONA
    l3=diffsimm(l1,l2,l3);
    stampa(l3);*/

    /*printf("ritorno il massimo puntatore dispari della lista 1: ");
    tmp=puntdispmax(l1);                                             FUNZIONA in parte
    stampa(tmp);*/

    /*printf("elimino i numeri pari in posizione dispari della lista 1: ");   FUNZIONA
    l1=elpari(l1);
    stampa(l1);*/


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
    return trovato;
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
    if(p==NULL)
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

///su k
nodo*elimina_maggiorik(nodo*p,int k)
{
    ///questo metodo funziona!! (è simile all'elimina occorrenza) solo che ho scritto anche un'altra versione di svolgimento
    nodo*tmp=p;
    if(p!=NULL)
    {
        if(p->primo > k)
        {
            p=elimina_maggiorik(p->next,k);
            free(tmp);
        }
        else
        {
            p->next=elimina_maggiorik(p->next,k);
        }
    }
    return p;
    /*
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
    */
}

nodo*maggioriprimak (nodo*p,int k)
{
    nodo*tmp;
    if(p==NULL || p->next==NULL)
    {
        return p;
    }
    tmp=maggioriprimak(p->next,k);
    if(p->primo < k)
    {
        p->next=tmp;
    }
    else
    {
        //tmp=incoda(tmp,p);      ///il problema è qui
    }
    return tmp;
}

///ordinamento
nodo*ordina(nodo*p,nodo*tmp)
{
    if(p==NULL || p->primo > tmp->primo)
    {
        tmp->next=p;
        p=tmp;
    }
    else
        {
            p->next=ordina(p->next,tmp);
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
     l=ordina(l,tmp);
 }
return l;
}

///unione, intersez,alterna
nodo*alterna(nodo*l1,nodo*l2)
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
        l2->next=alterna(l1->next,l2->next);
        l3->next=l2;
    }
    return l3;
}

nodo*unisci(nodo*l1,nodo*l2)
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
        l3->next=unisci(l1->next,l2);
    }
    else
    {
        l3=l2;
        l3->next=unisci(l1,l2->next);
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

nodo*diffsimm(nodo*l1,nodo*l2,nodo*l3)
{
    if(l1==NULL && l2==NULL)
    {
        return l3;
    }
    else if(l1==NULL)
    {
        l3=incoda(l3,l2->primo);
        return diffsimm(l1,l2->next,l3);
    }
    else if(l2==NULL)
    {
        l3=incoda(l3,l1->primo);
        return diffsimm(l1->next,l2,l3);
    }
    else if(l1->primo < l2->primo)
    {
        l3=incoda(l3,l1->primo);
        return diffsimm(l1->next,l2,l3);
    }
    else if(l1->primo > l2->primo)
    {
        l3=incoda(l3,l2->primo);
        return diffsimm(l1,l2->next,l3);
    }
    return diffsimm(l1->next,l2->next,l3);
}

///pari e dispari
nodo*puntdispmax(nodo*p)
{
   nodo*tmp=NULL;
   int max=INT_MIN;
   if(p==NULL)
   {
       return NULL;
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

nodo*elpari(nodo*p)
{
    nodo*tmp;
    if(p)
    {
        if(p->next)
            {
                p->next->next=elpari(p->next->next);
            }

        if (!(p->primo%2))
        {
            tmp=p;
            p=p->next;
            free(tmp);
        }
    }
    return p;

}

