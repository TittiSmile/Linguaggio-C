/*Scrivere una funzione ricorsiva in linguaggio ANSI C che data una lista concatenata di interi L,
senza ripetizioni, restituisca una lista contenente tutte le coppie, non ordinate, di numeri
appartenenti ad L la cui somma è maggiore k. Dimostrae la correttezza della funzione tramite il
principio di induzione.
Ad esempio:

k=10 L-> 5 -> 1 -> 4 -> 2 ->  3 -> 8 -> NIL
top -> (3,8) -> (4,8) -> (5,8) -> NIL

k=8 L -> 5 -> 1 -> 4 -> 2 -> 3 -> 6
top -> (3,6) -> (4,6) -> (5,4) -> (5,6) */
#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

typedef struct COPPIE
{
    int primoc;
    int secondoc;
    struct COPPIE*nextc;
}cop;

nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
void stampa(nodo*p);
///
cop*nelemc(int a,int b);
cop*incodac(cop*c,int a,int b);
cop*kcoppie(nodo*p,cop*c,int k);
void stampac(cop*c);



int main ()
{
   nodo*l1=NULL;
   cop*c1=NULL;
   int k;
   l1=incoda(l1,4);l1=incoda(l1,5);l1=incoda(l1,1);l1=incoda(l1,2);l1=incoda(l1,3);l1=incoda(l1,6);
   stampa(l1);

   printf("\ninserisci un numero k:   ");
   scanf("%d",&k);

   printf("\nle coppie la cui somma e' maggiore di %d sono: ",k);
   c1=kcoppie(l1,c1,k);
   stampac(c1);

    return 0;
}

nodo*nelem(int a)
{
    nodo*q=(nodo*)malloc(sizeof(nodo));
    q->primo=a;
    q->next=NULL;
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

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d->",p->primo);
        p=p->next;
    }
}

///
cop*nelemc(int a,int b)
{
    cop*q=(cop*)malloc(sizeof(cop));
    q->primoc=a;
    q->secondoc=b;
    q->nextc=NULL;
    return q;
}

cop*incodac(cop*c,int a,int b)
{
    if(c==NULL)
    {
        c=nelemc(a,b);
    }
    else
    {
        c->nextc=incodac(c->nextc,a,b);
    }
    return c;
}

cop*kcoppie(nodo*p,cop*c,int k)
{
    nodo*tmp;
    if(p!=NULL)
    {
        tmp=p->next;
        while(tmp!=NULL)
        {
           if(p->primo+tmp->primo > k)
            {
                c=incodac(c,p->primo,tmp->primo);
            }
            tmp=tmp->next;
        }
        c=kcoppie(p->next,c,k);
    }
    return c;
}

void stampac(cop*c)
{
    while(c!=NULL)
    {
        printf("\n( %d, %d )->",c->primoc,c->secondoc);
        c=c->nextc;
    }
}
