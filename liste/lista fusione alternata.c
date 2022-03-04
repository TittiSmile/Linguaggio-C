#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*intesta(nodo*p,int a);
nodo*incoda(nodo*p,int a);
nodo*alterna(nodo*l1,nodo*l2);
void stampa(nodo*p);


int main ()
{
    nodo*l1=NULL;
    nodo*l2=NULL;
    nodo*l3=NULL;
    int i=0,n,dim,m,dom;

    printf("quanto vuoi grande la lista 1?  ");
    scanf("%d",&dim);
    printf("quanto vuoi grande la lista 2?  ");
    scanf("%d",&dom);

    for(i=0;i<dim;i++)
    {
        printf("inserisci %d elemento lista 1:   ",i+1);
        scanf("%d",&n);
        l1=incoda(l1,n);
    }

    for(i=0;i<dom;i++)
    {
        printf("inserisci %d elemento lista 2:   ",i+1);
        scanf("%d",&m);
        l2=incoda(l2,m);
    }

    printf("la lista 1 e':  ");
    stampa(l1);
    printf("la lista 2 e':  ");
    stampa(l2);

    printf("\nalterno gli elementi delle liste:  ");
    l3=alterna(l1,l2);
    stampa(l3);




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

    ///iterativa


    /*nodo*l3=NULL;
    nodo*tmp1;
    nodo*tmp2;
    while(l1!=NULL)
    {
        tmp1=l1->next;
        tmp2=l2->next;
        l3=incoda(l3,l1->primo);
        l3=incoda(l3,l2->primo);
        l1=tmp1;
        l2=tmp2;
    }
    return l3;*/
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d\n",p->primo);
        p=p->next;
    }
}

