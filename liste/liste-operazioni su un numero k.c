#include <stdio.h>
#include <stdlib.h>
/*
N.B.!!!!!!!!!
questo esercizio FUNZIONA però ci sono alcuni errorucci nella funzione 'mk';probabilmente c'è qualche problema nell'assegnamento
di un indirizzo di memoria; (infatti l'ultimo elemento da mettere in ordine appare come indirizzo di memoria e non come numero):
le funzioni sono CORRETTE prese singolarmente ma,probabilmente,mettendole in un solo esercizio, alcune funzioni vanno in
"conflitto" e sballano degli output. Ho provato singolarmente ogni funzione e dà risultati GIUSTI!!


*/

typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;


struct LISTA *nelem(int a);
struct LISTA *intesta(struct LISTA *p,int a);
struct LISTA *incoda(struct LISTA *p,int a);
//struct LISTA *incoda(struct LISTA *p,struct LISTA *tmp);
struct LISTA *elk(struct LISTA *p,int k); //questa funzione elimina tutti i numeri maggiori di k
struct LISTA *mk(struct LISTA *p,int k);//questa funzione mette i numeri <k prima di k e i numeri >k dopo k
struct LISTA *diversik(struct LISTA *p,int k);//questa funzione,dato ad esempio k=3, mette su un'altra funzione i numeri rimanenti. ESEMPIO! lista: 1-2-3-3. k=3. nuova lista: 1-2
void stampa(struct LISTA *p);


int main ()
{
    struct LISTA *l=NULL;
    int k=0,num=0,i=0,dim=0;

    printf("Quanti numeri vuoi nella lista?\n");
    scanf("%d",&dim);

    for(i=0;i<dim;i++)
    {
        printf("inserisci %d numero nella lista:  ",i+1);
        scanf("%d",&num);
        l=incoda (l,num);
    }
    printf("La lista e':\n");
    stampa(l);

   printf("\nInserisci un  numero k:\n");
   scanf("%d",&k);

   printf("Verranno eliminati tutti i numeri maggiori di %d",k );
   l=elk(l,k);
   stampa(l);
   if(l==NULL)
   {
       printf("\nLista vuota!!\n");
   }

   printf("\nTutti i numeri minori di %d appariranno prima dei maggiori di %d!\n",k,k);
   l=mk(l,k);
   stampa(l);

  printf("\ntutti i numeri diversi  da %d andranno in un'altra lista! \n",k);
  l=diversik(l,k);
  stampa(l);


    return 0;
}

struct LISTA *nelem(int a)
{
 struct LISTA *q=(struct LISTA *)malloc(sizeof(struct LISTA));
 q->primo=a;
 q->next=NULL;
 return q;
}

struct LISTA *intesta(struct LISTA *p,int a)
{
 struct LISTA *q=nelem(a);
 q->next=p;
 return q;
}

struct LISTA *incoda(struct LISTA *p,int a)
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

/*struct LISTA *incoda(struct LISTA *p,struct LISTA *tmp)
{
   if(p==NULL)
   {
       tmp->next=p;
       return tmp;
   }
   else
   {
     tmp->next=incoda(p->next,tmp);
     return p;
   }

}*/



struct LISTA *elk(struct LISTA *p,int k)
{
    ///versione RICORSIVA
   /* struct LISTA *tmp;
 if(p==NULL)
 {
     return p;
 }
 else
 {
   p->next=elk(p->next,k);
   if(p->primo>k)      //elimina tutti i numeri maggiori di k!!
   {
       tmp=p;
       p=p->next;
       free(tmp);
   }
   return p;
 }*/

 ///versione ITERATIVA
 nodo*tmp;
 nodo*cur=p;
 while(cur->next!=NULL)
 {
     if(cur->next->primo>k)
     {
         tmp=cur->next;
         cur->next=cur->next->next;
         free(tmp);
     }
     cur=cur->next;
 }
 if(p->primo>k)
 {
     tmp=p;
     p=p->next;
     free(tmp);
 }
 return p;
}


struct LISTA *mk(struct LISTA *p,int k)
{                             ///N.B. questa versione,inserisce il tutto in una nuova lista e NON modifica quella che già abbiamo
 struct LISTA *tmp;
 if(p==NULL || p->next==NULL)
 {
     return p;
 }
 tmp=mk(p->next,k);
 if(p->primo <k)
 {
     p->next=tmp;
     return p;
 }
 else
 {
     tmp=incoda(tmp,p->primo);
     return tmp;
 }

 ///QUESTA MODIFICA LA LISTA DI PARTENZA SENZA SPOSTARE IN UNA NUOVA LISTA
  /*nodo*tmp;
     if(p!=NULL)
     {
         p->next=minoriprima(p->next,k);
         if(p->primo>k)
         {
             tmp=p;
             p=incoda(p->next,tmp->primo);
         }

     }
     return p;*/
}


struct LISTA *diversik(struct LISTA *p,int k)
{
    struct LISTA *l1=NULL;
    if(p==NULL)
    {
        return p;
    }
    l1=diversik(p->next,k);
    if(p->primo != k)
    {
        l1=intesta(l1,p->primo);
    }
    return l1;
}

void stampa(struct LISTA *p)
{
    while(p!=NULL)
    {
        printf("\n %d\n",p->primo);
        p=p->next;
    }
}
