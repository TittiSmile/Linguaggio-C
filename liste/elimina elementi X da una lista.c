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
void stampa(nodo*p);
nodo*eliminax(nodo*p,int a);

int main ()
{
    int i=0,dim,n;
    int num;
    nodo*l=NULL;

    printf("quanti elementi vuoi? ");
    scanf("%d",&dim);
    for(i=0;i<dim;i++)
    {
        printf("inserisci %d valore: ",i+1);
        scanf("%d",&n);
        l=incoda(l,n);
    }
    stampa(l);
    printf("\nquanti numeri vuoi eliminare?  \n");
    scanf("%d",&num);
    l=eliminax(l,num);
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

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("%d->\n",p->primo);
        p=p->next;
    }
}

nodo*eliminax(nodo*p,int a)
{
    nodo*tmp=p;
    /*nodo*tmp;
    for(;p!=NULL;p=tmp)
    {
        tmp=p->next;
        p->next=NULL;
        free(p);
    }*/

   /* if(p!=NULL)
    {
        if(p->primo==a)
        {
            p=elocc(p->next,a);
            free(tmp);  //per tmp=p;
        }
        else
        {
            p->next=elocc(p->next,a);
        }
    }
    return p;*/
    /*if(p!=NULL)                         ///serve ad eliminare tutti quelli più piccoli di a!!!!!
    {
        if(p->primo < a)
        {
            p=eliminax(p->next,a);
            free(tmp);
        }
        else
        {
            p->next=eliminax(p->next,a);
        }
    }
    return p;*/
    if(p!=NULL)
    {
        while(p->primo < a)
        {
            p=eliminax(p->next,a);
            free(tmp);
          //  p->next=eliminax(p->next,a);
          p=p->next;
        }
    }
    return p;

}
