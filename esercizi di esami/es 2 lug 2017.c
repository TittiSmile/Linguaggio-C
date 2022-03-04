#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
nodo*casuale(nodo*p,int dim);
nodo*elimina_minorik(nodo*p,int k);
void stampa(nodo*p);

int main ()
{
    nodo*l1=NULL;
    int k,dim;

    printf("quanto vuoi grande la tua lista?  ");
    scanf("%d",&dim);
    l1=casuale(l1,dim);
    stampa(l1);

    printf("\ninserisci un numero k:   ");
    scanf("%d",&k);
    printf("\nelimino tutti i record minori di %d: ",k);
    l1=elimina_minorik(l1,k);
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

nodo*casuale(nodo*p,int dim)
{
    int i=0,n;
    srand((unsigned)time(NULL));
    for(i=0;i<dim;i++)
    {
        n=rand()%20+1;
        p=incoda(p,n);
    }
    return p;
}

nodo*elimina_minorik(nodo*p,int k)
{
    nodo*tmp=p;
    if(p!=NULL)
    {
        if(p->primo < k)
        {
            p=elimina_minorik(p->next,k);
            free(tmp);
        }
        else
        {
            p->next=elimina_minorik(p->next,k);
        }
    }
    return p;
    ///versione ITERATIVA
    /*nodo*cur=p;
     nodo*tmp;
     while(cur->next!=NULL)
     {
         if(cur->next->primo < k)
         {
             tmp=cur->next;
             cur->next=cur->next->next;
             free(tmp);
         }
         else
            cur=cur->next;
     }
     if(p->primo < k)
     {
         tmp=p;
         p=p->next;
         free(tmp);
     }
return p;*/
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d-> ",p->primo);
        p=p->next;
    }
}








/* tmp->primo=k;
         while( ++cont < n )
            {
                cur = cur->next;
            }
        tmp->next = cur->next;
        cur->next=tmp;*/
