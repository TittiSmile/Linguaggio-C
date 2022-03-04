#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

typedef struct COPPIE
{
    int a;
    int b;
    struct COPPIE*next;
}coppie;

nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
nodo*casuale(nodo*p,int dim);
void stampa(nodo*p);
///
coppie*crea(coppie*c,int n1,int n2);
coppie*ins_coda(coppie*c,int n1,int n2);
coppie*ritorna_coppie(nodo*p,coppie*c,int k);
void stampacop(coppie*c);

int main ()
{
    nodo*l1=NULL;
    coppie*cop=NULL;
    int num1,num2,k,dim,i=0;

    printf("quanti numeri vuoi inserire? ");
    scanf("%d",&dim);
    l1=casuale(l1,dim);
    stampa(l1);

    printf("\ninserisci un numero k:  ");
    scanf("%d",&k);
    cop=ritorna_coppie(l1,cop,k);
    stampacop(cop);






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

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d->",p->primo);
        p=p->next;
    }
}

///
coppie*crea(coppie*c,int n1,int n2)
{
    c=(coppie*)malloc(sizeof(coppie));
    c->a=n1;
    c->b=n2;
    c->next=NULL;
    return c;
}

coppie*ins_coda(coppie*c,int n1,int n2)
{
    if(c==NULL)
    {
        c=crea(c,n1,n2);
    }
    else
    {
        c->next=ins_coda(c->next,n1,n2);
    }
    return c;
}

coppie*ritorna_coppie(nodo*p,coppie*c,int k)
{
    nodo*tmp=p;
    int var=0;
    if(p!=NULL)
    {
        c=ritorna_coppie(tmp->next,c,k);
        var=tmp->primo;
        while(tmp!=NULL)
        {
            if(var!=tmp->primo && (var+tmp->primo)>k)
            {
                c=ins_coda(c,var,tmp->primo);
            }
            tmp=tmp->next;
        }
    }
    return c;
}



void stampacop(coppie*c)
{
    while(c!=NULL)
    {
        printf("(%d , %d )->",c->a,c->b);
        c=c->next;
    }
}
