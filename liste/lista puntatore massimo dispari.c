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
nodo*massimodisp(nodo*p);   ///la funzione sarà ITERATIVA
void stampa(nodo*p);


int main ()
{
    nodo*l=NULL;
    nodo*tmp=NULL;
    int i=0,dim,n;
    int max=INT_MIN;

    /*printf("quanto vuoi grande la tua lista?  ");
    scanf("%d",&dim);

    for(i=0;i<dim;i++)
    {
        printf("inserisci %d elemento:   ",i+1);
        scanf("%d",&n);
        l=incoda(l,n);
    }*/
    l=incoda(l,3);l=incoda(l,34);l=incoda(l,22);l=incoda(l,35);l=incoda(l,21);
    printf("\nla lista e':  ");
    stampa(l);


    tmp=massimodisp(l);
    printf("\nmassimo elemento:\n");
    stampa(tmp);



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

nodo*massimodisp(nodo*p)   ///ITERATIVO
{
   nodo*tmp=NULL;
   int max=INT_MIN;
   if(p==NULL)
   {
       return NULL;
   }
   while(p!=NULL)
   {
       if(p->primo%2!=0  && p->primo > max)
       {
           tmp=p;
           max=p->primo;
       }
       p=p->next;
   }
   return tmp;
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d ",p->primo);
        p=p->next;
    }
}



