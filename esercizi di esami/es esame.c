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
nodo*elimina(nodo*p);
nodo*elocc(nodo*p,int a);
nodo*elposdisp(nodo*p);
void stampa(nodo*p);
nodo*reverse(nodo*p);

int main ()
{
    nodo*l=NULL;
    int n,dim,i=0;

    printf("quanti elementi?  ");
    scanf("%d",&dim);

    for(i=0;i<dim;i++)
    {
        printf("elemento %d: ",i+1);
        scanf("%d",&n);
        l=incoda(l,n);
    }
    stampa(l);

    printf("\nelimino elementi in posizione dispari e stampo al contrario: \n");
    l=elposdisp(l);
    reverse(l);



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

nodo*elimina(nodo*p)
{
    nodo*tmp;
    for(;p!=NULL;p=tmp)
    {
        tmp=p->next;
        p->next=NULL;
        free(p);
    }
    return p;
}

nodo*elocc(nodo*p,int a)
{
    nodo*tmp=p;
    if(p!=NULL)
    {
        if(p->primo==a)
        {
            p=elocc(p->next,a);
        }
        else
        {
            p->next=elocc(p->next,a);
        }
    }
    return p;
}

nodo*elposdisp(nodo*p)
{
    int i=1;
    nodo*tmp=NULL;
    nodo*tmp2=p;
    while(tmp2!=NULL)
    {
        if(i%2==0)
        {
          tmp=incoda(tmp,tmp2->primo);
          p=elocc(p,tmp2->primo);
        }
        tmp2=tmp2->next;
        i++;
    }
    return tmp;
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("%d->\n",p->primo);
        p=p->next;
    }
}

nodo*reverse(nodo*p)
{
    if(p==NULL)
        return 0;
    reverse(p->next);
    printf("%d->\n",p->primo);

}

