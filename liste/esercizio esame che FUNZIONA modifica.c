#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
nodo*ordina(nodo*p,nodo*tmp);
nodo*crescente(nodo*p);
int occorrenza(nodo*p,int a);
void stampa(nodo*p);

int main ()
{
    nodo*l=NULL;
    nodo*l2=NULL;
    int n,i=0,k,dim,var,cont,j=0,m;

    printf("quanto vuoi grande la tua lista? ");
    scanf("%d",&dim);

    printf("inserisci un range massimo di numero(cioe' i numeri vanno stampati,per esempio, massimo fino a 5) ");
    scanf("%d",&m);

    for(i=0;i<dim;i++)
    {
        do
        {
            printf("elemento %d :   ",i+1);
            scanf("%d",&n);
            if(n>m)
            {
                printf("\nerrore,il range massimo e':%d \n",m);
            }
        }while(n > m);

        l=incoda(l,n);
    }

    printf("quante occorrenze vuoi contare?");
    scanf("%d",&cont);

   printf("inserisci un numero k:   ");
   scanf("%d",&k);
   while(j<cont)
  {
        printf("di quale numero vuoi contare le occorrenza?  ");
        scanf("%d",&n);
        var=occorrenza(l,n);
        if(var > k)
        {
            l2=incoda(l2,n);
        }
        j++;
  }
    l2=crescente(l2);
    stampa(l2);

    return 0;
}


nodo*nelem(int a)
{
    nodo*q=(struct LISTA*)malloc(sizeof(struct LISTA));
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

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d ",p->primo);
        p=p->next;
    }
}
