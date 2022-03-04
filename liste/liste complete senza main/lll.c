///FUNZIONA TUTTO! ho commentato le funzioni perchè farle tutte e 3 insieme porta degli errori (com'è giusto che sia)
#include <stdio.h>
#include <malloc.h>
typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;

nodo*nelem(int a);
nodo*intesta (nodo*p,int a);
nodo*incoda(nodo*p,int a);
nodo*ricerca(nodo*p,int a);
nodo*elimina(nodo*p,int a);
void stampa(nodo*p);
nodo*alternalista(nodo*l1,nodo*l2);
nodo*fondilista(nodo*l1,nodo*l2);
nodo*intersecalista(nodo*l1,nodo*l2);

int main ()
{
    nodo*l1=NULL;
    nodo*l2=NULL;
    nodo*l3=NULL;
    int dim,n,i;
    int dom,m,j;

    printf("quanti elementi nella lista 1? ");
    scanf("%d",&dim);
    for(i=0;i<dim;i++)
    {
        printf("\ninserisci %d numero  ",i+1);
        scanf("%d",&n);
        l1=incoda(l1,n);
    }
    printf("\n la lista 1 e':");
    stampa(l1);

    printf("quanti elementi nella lista 2? ");
    scanf("%d",&dom);
    for(j=0;j<dom;j++)
    {
        printf("\ninserisci %d numero  ",j+1);
        scanf("%d",&m);
        l2=incoda(l2,m);
    }
    printf("\n la lista 2 e':");
    stampa(l2);

    /* printf("\nalterno lista 1 e lista 2:\n");
     l3=alternalista(l1,l2);
     stampa(l3);*/

    /* printf("\nfondo le due liste:\n");
     l3=fondilista(l1,l2);
     stampa(l3);*/

     /*printf("\ninterseco le due liste (ovvero,vedo se ci sono elem. in comune)\n");
     l3=intersecalista(l1,l2);
     stampa(l3);*/





    return 0;
}


nodo*nelem(int a)
{
   nodo*q=(struct LISTA*)malloc(sizeof(struct LISTA));
   q->primo=a;
   q->next=NULL;
   return q;
}

nodo*intesta (nodo*p,int a)
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
   nodo*trovato=NULL;
   for(;p!=NULL && trovato==NULL;p=p->next)
   {
       if (p->primo==a)
       {
           trovato=p;
       }
   }
   return trovato;
}

nodo*elimina(nodo*p,int a)
{
    nodo*tmp;
    for(;p!=NULL;p=tmp)
    {
        tmp=p->next;
        p->next=NULL;
        free(p);
    }

}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d\n",p->primo);
        p=p->next;
    }
}

nodo*alternalista(nodo*l1,nodo*l2)
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
        l2->next=alternalista(l1->next,l2->next);
        l3->next=l2;
    }
    return l3;
}

nodo*fondilista(nodo*l1,nodo*l2)
{
    nodo*l3;
    if(l1==NULL)
    {
        return l2;
    }
    else if (l2==NULL)
    {
        return l1;
    }
    else if(l1->primo < l2->primo)
    {
        l3=l1;
        l3->next=fondilista(l1->next,l2);
    }
    else
    {
        l3=l2;
        l3->next=fondilista(l1,l2->next);
    }
    return l3;


}

nodo*intersecalista(nodo*l1,nodo*l2)
{
    nodo*l3=NULL;
    if(l1)
    {
        l3=intersecalista(l1->next,l2);
        if(ricerca(l2,l1->primo))
        {
           l3=intesta(l3,l1->primo);
        }
    }

    return l3;
}



