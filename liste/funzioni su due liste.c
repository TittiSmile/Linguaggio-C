#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;

void menu();
nodo*nelem(int a);
nodo*intesta(nodo*p,int a);
nodo*incoda(nodo*p,int a);
nodo*ricerca(nodo*p,int a);
nodo*elimina(nodo*p);
nodo*alterna(nodo*l1,nodo*l2);
nodo*unisci(nodo*l1,nodo*l2);
nodo*interseca(nodo*l1,nodo*l2);
void stampa(nodo*p);



int main ()
{
nodo*l1=NULL;
nodo*l2=NULL;
nodo*l3=NULL;
int i,scelta,n,dim,m,dom;

printf("quanti numeri nella lista 1? ");
scanf("%d",&dim);
printf("quanti numeri nella lista 2? ");
scanf("%d",&dom);
for(i=0;i<dim;i++)
{
    printf("inserire elemento nella lista 1\n");
    scanf("%d",&n);
    l1=incoda(l1,n);
}
for(i=0;i<dom;i++)
{
    printf("inserire elemento nella lista 2\n");
    scanf("%d",&m);
    l2=incoda(l2,m);
}

printf("la lista 1 e': \n");
stampa(l1);
printf("\nla lista 2 e': \n");
stampa(l2);


menu();
do
{
    printf("\ndigita la tua scelta ");
    scanf("%d",&scelta);
    switch(scelta)
    {
    case 1:
        printf("alterno elementi delle due liste \n");
        l3=alterna(l1,l2);
        stampa(l3);
        break;
    case 2:
        printf("unisco elementi delle due liste \n");
        l3=unisci(l1,l2);
        stampa(l3);
        break;
    case 3:
        printf("interseco elementi delle due liste \n");
        l3=interseca(l1,l2);
        stampa(l3);
        break;
    default:
        printf("\nscelta errata");
        break;
    }

}while(scelta!=3);

   return 0;
}


void menu()
{
    printf("\n1) alterna elementi lista\n2)unisci elementi\n3)interseca elementi");
}

nodo *nelem(int a)
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
    /*
    ITERATIVA
    nodo*tmp;
    nodo*q;
    q=nelem(a);
    if(p!=NULL)
    {
      for(tmp=p;tmp->next!=NULL;tmp=tmp->next)
        {
         tmp->next=q;
        }
       tmp->next=q;
    }
    else
    {
      p=q
    }
return p;
    */
}

nodo*ricerca(nodo*p,int a)
{
 /*  nodo*trovato;
   for(;p!=NULL && trovato==NULL;p=p->next)
   {
       trovato=p;
   }
   return trovato;     /// non sono sicura della correttezza di questa funzione... infatti non funziona lol
   */

   //versione corretta
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
        free (p);
    }
    return p;
}



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
    nodo*l3=NULL;
    if(l1==NULL)
    {
        return l2;
    }
    else if (l2==NULL)
    {
        return l1;
    }
    else if(l1->primo < l2->primo)
    {
        l3=l1;
        l3->next=alterna(l1->next,l2);
    }
    else
    {
        l3=l2;
        l3->next=alterna(l1,l2->next);
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
            l3=intesta (l3,l1->primo);
        }
    }
    return l3;
}


void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n\n %d",p->primo);
        p=p->next;
    }
}


