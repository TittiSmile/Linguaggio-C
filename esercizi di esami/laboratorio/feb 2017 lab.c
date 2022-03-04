/*
scrivere un programma in c che:
1)legga 20 caratteri dalla tastiera e li salvi in un array a
2)i caratteri numerici di a vengono salvati in una lista l1 di interi ed i caratteri tra a e z in una lista l2 di caratteri
3)stampi a video il più piccolo numero di l1 ed il carattere maggiore di l2 in ordine alfabetico
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

typedef struct LISTAC
{
    char primoc;
    struct LISTAC*nextc;
}nodoc;


nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
nodo*min(nodo*p,int a);
void stampa(nodo*p);
///
nodoc*nelemc(char c);
nodoc*incodac(nodoc*pc,char c);
nodoc*minc(nodoc*pc,char c);
void stampac(nodoc*pc);


int main()
{
    nodo*l1=NULL;
    int dim,i,n;
    char c;
    char a[20];

    for(i=0;i<5;i++)
    {
       printf("inserisci %d elemento: ",i+1);
       fflush(stdin);
       scanf("%c",&c);
       if(c>=48 && c<=57 )
       {
           incoda(l1,a[i]);
       }
    }
    stampa(l1);


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

nodo*min(nodo*p,int a);
void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("%d-> ",p->primo);
        p=p->next;
    }
}

///
nodoc*nelemc(char c)
{
    nodoc*qc=(nodoc*)malloc(sizeof(nodoc));
    qc->primoc=c;
    qc->nextc=NULL;
    return qc;
}
nodoc*incodac(nodoc*pc,char c)
{
    if(pc!=NULL)
    {
        pc=nelemc(c);
    }
    else
    {
        pc->nextc=incodac(pc->nextc,c);
    }
    return pc;
}

nodoc*minc(nodoc*pc,char c);
void stampac(nodoc*pc)
{
     while(pc!=NULL)
    {
        printf("%c-> ",pc->primoc);
        pc=pc->nextc;
    }

}
