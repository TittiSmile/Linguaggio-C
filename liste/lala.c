#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
nodo*casuale(nodo*p,int dim);
void stampa(nodo*p);
nodo*elmagk(nodo*p,int k);
nodo*elmagkric(nodo*p,int k);
nodo*elmagk2(nodo*p,int k);

int main ()
{///DA FARE: FUNZIONI DI ELIMINA DUPLICATI (RIC E ITER).
    int dim,k;
    nodo*l=NULL;

    printf("inserisci dimensione lista:  ");
    scanf("%d",&dim);
    l=casuale(l,dim);
    stampa(l);
    printf("inserisci un numero k: ");
    scanf("%d",&k);
    l=elmagk2(l,k);
    printf("\nelimino i maggiori di %d \n",k);
    stampa(l);



    return 0;
}

nodo*nelem(int a)
{
    nodo*q=(nodo*)malloc(sizeof(nodo));
    q->primo=a;
    q->next=NULL;
    return q;
    /*intesta!!!!!
    nodo*q=nelem(a);
    q->next=p;
    return q;
    */
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

nodo*casuale(nodo*p,int dim)
{
    int i=0;
    int a=0;
    srand((unsigned)time(NULL));
    for(i=0;i<dim;i++)
    {
        a=rand()%100+1;
        p=incoda(p,a);
    }
    return p;
}

void stampa(nodo*p)
{
 while(p!=NULL)
 {
     printf("%d\n",p->primo);
     p=p->next;
 }
}

nodo*elmagk(nodo*p,int k)     ///versione iterativa
{
    nodo*cur=p;
    nodo*tmp;
    while(cur->next!=NULL)
    {
        if(cur->next->primo >k)
        {
            tmp=cur->next;
            cur->next=cur->next->next;
            free(tmp);
        }
        else
        cur=cur->next;
    }
    if(p->primo > k)
    {
        tmp=p;
        p=p->next;
        free(tmp);
    }
    return p;
}

nodo*elmagkric(nodo*p,int k)
{
    nodo*tmp;
    if(p==NULL)
    {
        return p;
    }
    else
    {
        p->next=elmagkric(p->next,k);
        if(p->primo > k)
        {
            tmp=p;
            p=p->next;
            free(tmp);
        }
    }
    return p;
}

nodo*elmagk2(nodo*p,int k)     ///versione ricorsiva 2
{
    nodo*tmp=p;
    if(p!=NULL)
    {
        if(p->primo >k)
        {
            p=elmagk2(p->next,k);
            free(tmp);
        }
        else
        {
            p->next=elmagk2(p->next,k);
        }
    }
    return p;
}
