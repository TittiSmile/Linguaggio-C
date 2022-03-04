///non propriamente corretta
#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
nodo*insordine(nodo*p,int a);
nodo*elk(nodo*p,int k);
nodo*funzocc(nodo*p,int k); ///elimina tutte le occorrenze ripetute k volte
void stampa(nodo*p);


int main ()
{
    nodo*l1=NULL;
    int k=0;

    l1=incoda(l1,10);l1=incoda(l1,20);l1=incoda(l1,5);l1=incoda(l1,20);l1=incoda(l1,20);l1=incoda(l1,10);
    stampa(l1);
    printf("\ninserisci un numero k: ");
    scanf("%d",&k);

    printf("\nritorno la lista senza quelli che si ripetono %d volte\n",k);
    l1=funzocc(l1,k);
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

nodo*elk(nodo*p,int k)
{
    nodo*tmp;
    if(p==NULL)
    {
        return p;
    }
    tmp=elk(p->next,k);
    if(tmp->primo==k)
    {
        tmp=p;
        p=p->next;
        free(tmp);
    }
    return p;
}

nodo*insordine(nodo*p,int a)
{
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    if(p==NULL || p->primo > a)
    {
        tmp=nelem(a);
        tmp->next=p;
        p=tmp;
    }
    else
    {
        p->next=insordine(p->next,a);
    }
    return p;
}

nodo*funzocc(nodo*p,int k)
{
   nodo*tmp;
   nodo*l=NULL;
   int cont=0;
   while(p!=NULL)
   {
       tmp=p->next;
       while(tmp!=NULL)
       {
           if(tmp->primo== p->primo)
           {
               cont++;
           }
           tmp=tmp->next;
       }
       if(cont==k)
       {
           l=insordine(l,p->primo);
       }
       cont=1;
       p=p->next;
   }
   return l;

}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("%d->",p->primo);
        p=p->next;
    }
}
