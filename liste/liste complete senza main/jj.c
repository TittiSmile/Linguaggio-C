#include <stdio.h>
#include <malloc.h>
typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;

nodo*nelem(int a);
nodo*intesta(nodo*p,int a);
nodo*incoda(nodo*p,int a);
nodo*ricerca(nodo*p,int a);
nodo*elimina(nodo*p);
int occorrenza(nodo*p,int a);
nodo*elimina_occorrenza(nodo*p,int a);
void stampa(nodo*p);
nodo*reverse(nodo*p);
int somma(nodo*p);
nodo*alterna(nodo*l1,nodo*l2);
nodo*unisci(nodo*l1,nodo*l2);
nodo*interseca(nodo*l1,nodo*l2);
nodo*maggiorik(nodo*p,int k);
nodo*inordine(nodo*p,nodo*tmp);
nodo*crescente(nodo*p);
nodo*inSordine(nodo*p,int a);


int main ()
{
   nodo*l1=NULL;
   nodo*l2=NULL;
   nodo*l3=NULL;

  l1=inSordine(l1,22);
  l1=inSordine(l1,29);
  l1=inSordine(l1,20);
  stampa(l1);
  printf("\n___\n");
  l2=inSordine(l2,32);
  l2=inSordine(l2,39);
  l2=inSordine(l2,30);
  stampa(l2);
   printf("\n___-\n");
   l3=unisci(l1,l2);
    stampa(l3);


/*
   ///inserisco la mia lista
   l1=incoda(l1,20);
   l1=incoda(l1,3);
   l1=incoda(l1,10);
   stampa(l1);
//normalmente,avremmo chiesto di inserire la grandezza della lista e poi avremmo fatto un for che prendeva tutti gli elementi
//stavolta,al posto di 'n' ho messo un numero per velocizzare il tutto.
printf("\n\t___\n");
l2=incoda(l2,15);
l2=incoda(l2,9);
l2=incoda(l2,5);
stampa(l2);

printf("\n___\n\nunisco le due liste in un'unica lista\n");
l3=unisci(l1,l2);
stampa(l3);
printf("\nordino le liste in modo crescente");
l3=crescente(l3);
stampa(l3);
 */










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
    nodo*trovato;
    for(;p!=NULL && trovato==NULL;p=p->next)
    {
        if (p->primo==a)
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

nodo*maggiorik(nodo*p,int k)
{
    nodo*tmp;
    if(p!=NULL)
    {
        p->next=maggiorik(p->next,k);
        if(p->primo > k)
        {
            tmp=p->next;
            p=p->next;
            free(tmp);
        }
    }
    return p;
}

nodo*inordine(nodo*p,nodo*tmp)
{
    if(p==NULL || p->primo > tmp->primo)
    {
        tmp->next=p;
        p=tmp;
    }
    else
    {
        p->next=inordine(p->next,tmp);
    }
}

nodo*crescente(nodo*p)
{
    nodo*tmp;
    nodo*l=NULL;
    while(p!=NULL)
    {
        tmp=p;
        p=p->next;
        l=inordine(l,tmp);
    }
    return l;
}

nodo*inSordine(nodo*p,int a)
{
    nodo*tmp;
    if(p==NULL || p->primo > a)
    {
        tmp=nelem(a);
        tmp->next=p;
        p=tmp;
    }
    else
    {
        p->next=inSordine(p->next,a);
    }
    return p;
}




