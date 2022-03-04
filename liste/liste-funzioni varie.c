#include <stdio.h>

typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;

void menu();
struct LISTA *nelem(int a);
struct LISTA *intesta(struct LISTA *p,int a);
struct LISTA *incoda(struct LISTA *p,int a);
struct LISTA *ricerca(struct LISTA *p,int a);
struct LISTA *inordine(struct LISTA *p,int a);//invece di inserire incoda o intesta,inserisce dei numeri direttamente in modo crescente/decrescente
struct LISTA *ordine(struct LISTA *p,struct LISTA *tmp);//serve per mettere(dopo l'inserimento) in ordine la lista in modo crescente/decrescente
struct LISTA *crescente(struct LISTA *p);//è la funzione che usiamo nel main: ha bisogno della funzione ordine
struct LISTA *alterna(struct LISTA *l1,struct LISTA *l2);
struct LISTA *unisci(struct LISTA *l1,struct LISTA *l2);
struct LISTA *interseca(struct LISTA *l1,struct LISTA *l2);
void stampa(struct LISTA *p);


int main()
{
   struct LISTA *l1=NULL;
   struct LISTA *l2=NULL;
   struct LISTA *l3=NULL;
    int dim=0,n=0,i=0,num;
    int dom=0,m=0,scelta;

    printf("Quanti numeri nella lista 1?\n");
    scanf("%d",&dim);
    printf("Quanti numeri nella lista 2?\n");
    scanf("%d",&dom);

    for(i=0;i<dim;i++)
    {
        printf("Inserisci %d numero ",i+1);
        scanf("%d",&n);
        l1=incoda(l1,n);
    }

    for(i=0;i<dom;i++)
    {
        printf("Inserisci %d numero ",i+1);
        scanf("%d",&m);
        l2=incoda(l2,m);
    }

    printf("La lista 1 e':");
    stampa(l1);
    printf("La lista 2 e':");
    stampa(l2);


    printf("Le liste alternate sono:\n");
    l3=alterna(l1,l2);
    stampa(l3);

 /*  pintf("Le liste unite sono:\n");
    l3=unisci(l1,l2);
    stampa(l3);*/                    ///N.B. la funzione è giusta ma se la metti in un programma con altre funzioni, va in LOOP!
    printf("Le due liste unite ed in ordine crescente sono: \n");
    l3=crescente(l3);
    stampa(l3);





    return 0;
}


void menu()
{
    printf("\n\t1)Ordina una lista in modo crescente\n\t2)alterna gli elementi delle liste\n\t3)unisci gli elementi delle liste\n");
    printf("\t4)interseca gli elementi delle liste\n\t5)esci");
}

struct LISTA *nelem(int a)
{
 nodo*q=(nodo*)malloc(sizeof(nodo)); // posso usare ANCHE struct LISTA *q=(struct LISTA*) malloc(sizeof(struct LISTA));
 q->primo=a;
 q->next=NULL;
 return q;
}


struct LISTA *intesta(struct LISTA *p,int a)
{
 nodo*q=nelem(a); //anche qui,come sopra posso usare ANCHE struct LISTA *q=nelem(a);
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

struct LISTA *ricerca(struct LISTA *p,int a)
{
 struct LISTA *trovato;
 for(;p!=NULL && trovato==NULL;p=p->next)
 {
     if(p->primo==trovato)
     {
         trovato=p;
     }
 }
    return trovato;
}

struct LISTA *inordine(struct LISTA *p,int a)
{
 struct LISTA *tmp;
 if(p==NULL || p->primo > a)
 {
     tmp=nelem(a);
     tmp->next=p;
     p=tmp;
 }
 else
 {
     p->next=inordine(p->next,a);
 }
 return p;
}

struct LISTA *ordine(struct LISTA *p,struct LISTA *tmp)
{
 if(p==NULL || p->primo > tmp->primo)
 {
     tmp->next=p;
     p=tmp;
 }
 else
 {
     p->next=ordine(p->next,tmp);
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
     nlista=ordine(nlista,tmp);
 }
    return nlista;
}

struct LISTA *alterna(struct LISTA *l1,struct LISTA *l2)
{
 struct LISTA  *l3=l1;
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


struct LISTA *unisci(struct LISTA *l1,struct LISTA *l2)
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
         l3->next=unisci(l1->next,l2);

     }
 else
 {
  l3=l2;
  l3->next=unisci(l1,l2->next);
 }
 return l3;
}

struct LISTA *interseca(struct LISTA *l1,struct LISTA *l2)
{
 struct LISTA *l3;
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

void stampa(struct LISTA *p)
{
    while(p!=NULL)
    {
        printf("\n %d \n",p->primo);
        p=p->next;
    }
}



/*
struct lista inordine(struct lista *p,int k)
{
struct lista *tmp;
if(p==NULL || p->primo>a)
tmp=nelem(a);
p=tmp

else
p->next=inordine(p->next,a)
return p;

}

alterna
{
struct lista *l3=l1;
if (l1==NULL) return l2;
if (l2==NULL) return l1;
   else
l2->next=alterna (l1->next,l2->next);
l3->next=l2;
return l3;
}

unisci
struct lista *l3;
if (l1==NULL) return l2;
    if (l2==NULL) return l1;
    else if (l1->primo < l2->primo)
    l3=l1
    l3->next=unisci (l1->next,l2);
    else
    l3=l2
    l3->next=unisci (l1,l2-next);
    return l3


interseca
struct lista *l3;
if(l1)
l3=interseca(l1->next,l2;
if(ricerca(l2,l1->primo))
l3=intesta(l1-primo,l2);
return l3









*/
