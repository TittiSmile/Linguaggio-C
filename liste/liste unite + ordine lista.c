#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;

struct LISTA *nelem(int a);
struct LISTA *incoda(struct LISTA *p,int a);
struct LISTA *unione(struct LISTA *l1,struct LISTA *l2);
struct LISTA *inordine(struct LISTA *p,struct LISTA *tmp); //questa funzione serve per quella crescente
struct LISTA *crescente(struct LISTA *p);
struct LISTA *insor(struct LISTA *p,int a);//N.B.| questa lista ti fa inserire dei numeri direttamente in ordine senza passare per le funzioni in coda o in testa!
void stampa(struct LISTA *p);


int main ()
{
    struct LISTA *l1=NULL;
    struct LISTA *l2=NULL;
    struct LISTA *l3=NULL;
    int n=0,m=0,dim,dom;
    int i=0;

    printf("Quanti elementi vuoi inserire nella lista 1?\n");
    scanf("%d",&n);
    printf("Quanti elementi vuoi inserire nella lista 2?\n");
    scanf("%d",&m);

    for(i=0;i<n;i++)
    {
        printf("\nInserisci %d numero nella lista 1! ",i+1);
        scanf("%d",&dim);
        l1=incoda(l1,dim);
       //l1=insor(l1,dim);
    }

        for(i=0;i<m;i++)
    {
        printf("\nInserisci %d numero nella lista 1! ",i+1);
        scanf("%d",&dom);
        l2=incoda(l2,dom);
       //l2=insor(l2,dom);
    }
    printf("Gli elementi della lista 1 sono:\n");
    stampa(l1);
    printf("\nGli elementi della lista 2 sono:\n");
    stampa(l2);

    printf("\nGli elementi delle due liste unite sono:\n");
    l3=unione(l1,l2);
    stampa(l3);

    printf("\nMetto la lista in ordine crescente\n");
    l3=crescente(l3);
    stampa(l3);






    return 0;
}



struct LISTA *nelem(int a)
{
 struct LISTA *q=(struct LISTA *)malloc(sizeof(struct LISTA));
 q->primo=a;
 q->next=NULL;
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


struct LISTA *unione(struct LISTA *l1,struct LISTA *l2)
//unisco le due liste:prima tutti gli elementi di uno poi tutti gli elementi dell'altro
{
    struct LISTA *l3=NULL;
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
        l3->next=unione(l1->next,l2);
    }
    else
    {
        l3=l2;
        l3->next=unione(l1,l2->next);
    }
    return l3;
}




struct LISTA *inordine(struct LISTA *p,struct LISTA *tmp)
{
   if(p==NULL || p->primo > tmp->primo) // se cambio in '<' la lista viene in ordine DECRESCENTE
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



struct LISTA *crescente(struct LISTA *p)
{
 struct LISTA *tmp;
 struct LISTA *nlista=NULL;
 while(p!=NULL)
 {
     tmp=p;
     p=p->next;
     nlista=inordine(nlista,tmp);
 }
 return nlista;
}


struct LISTA *insor(struct LISTA *p,int a) //modo RICORSIVO
{
    ///questa commentata mooooolto probabilmente è sbagliata
    /*struct LISTA *tmp;
    if(p==NULL || p->primo > a)
    {
        tmp=nelem(a);
        tmp->next=p;
        p=tmp;
    }
    else
    {
        p->next=insor(p->next,a);
    }
    return p;*/

    nodo*tmp=(struct LISTA*)malloc(sizeof (struct LISTA));
    if(p==NULL || tmp->primo > a)
    {
        ///tmp->primo=a; non è corretto
        tmp=nelem(a);
        tmp->next=p;
        p=tmp;
    }
    else
    {
        p->next=insor(p->next,a);
    }
    return p;
}



void stampa(struct LISTA *p)
{
    while(p!=NULL)
    {
        printf("\n %d",p->primo);
        p=p->next;
    }
}


