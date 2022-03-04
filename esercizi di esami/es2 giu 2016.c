#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;
///non tutte le funzioni sono necessarie
nodo*nelem(int a);
nodo*intesta (nodo*p,int a );
nodo*incoda(nodo*p,int a);
nodo*eliminamaggiorik(nodo*p,int k);
void stampa(nodo*p);
nodo*ordina(nodo*p,nodo*tmp);
nodo*crescente(nodo*p);

int main ()
{
    nodo*l=NULL;
    int i=0,n,dim,k;

    printf("quanti elementi vuoi?  ");
    scanf("%d",&dim);

    for(i=0;i<dim;i++)
    {
        printf("inserisci %d elemento: ",i+1);
        scanf("%d",&n);
        l=incoda(l,n);
    }
    l=crescente(l);
    stampa(l);

    printf("\ninserisci un numero k:  ");
    scanf("%d",&k);
    l=eliminamaggiorik(l,k);
    stampa(l);


    return 0;
}


nodo*nelem(int a)
{
    nodo*q=(struct LISTA*)malloc(sizeof(struct LISTA));
    q->primo=a;
    q->next=NULL;
    return q;
}

nodo*intesta (nodo*p,int a )
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

nodo*eliminamaggiorik(nodo*p,int k)
{
     ///provo a farla ITERATIVAMENTE
    nodo*tmp=p;
    nodo*l;
    while(tmp->next!=NULL)
    {
        if(tmp->next->primo>k)
        {
            l=tmp->next;
            tmp->next=tmp->next->next;
            free(l);
        }
        else
        {
            tmp=tmp->next;
        }
    }
    if(p->primo > k)
    {
        tmp=p;
        p=p->next;
        free(tmp);
    }

     return p;

    ///maniera RICORSIVA

    /*nodo*tmp=p;
    if(p!=NULL)
    {
       if(p->primo>k)
       {
         p=eliminamaggiorik(p->next,k);
         free(tmp);
       }
       else
       {
         p->next=eliminamaggiorik(p->next,k);
       }
    }
    return p;*/

}


void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("%d-> \n",p->primo);
        p=p->next;
    }

}

nodo*ordina(nodo*p,nodo*tmp)
{
    if(p==NULL || p->primo > tmp->primo)
    {
        tmp->next=p;
        p=tmp;
    }
    else
    {
        p->next=ordina(p->next,tmp);
    }
    return p;
}

nodo*crescente(nodo*p)
{
    nodo*tmp;
    nodo*l=NULL;
    while(p!=NULL)
    {
        tmp=p;
        p=p->next;
        l=ordina(l,tmp);
    }
    return l;
}

