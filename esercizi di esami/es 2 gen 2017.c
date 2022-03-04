#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

typedef struct COPPIE
{
    int x;
    int y;
    struct COPPIE*next;
}cop;

nodo*nelem(int a);
cop*nelemcop(int x,int y);
nodo*incoda(nodo*p,int a);
cop*incodacop(cop*c,int x,int y);
cop*coppie(nodo*p,cop*c,int k);
void stampa(nodo*p);
void stampacop(cop*c);

int main ()
{
    nodo*l=NULL;
    cop*t=NULL;
    int dim,i=0,n,k;

    printf("quanti elmenti nella lista?  ");
    scanf("%d",&dim);
    for(i=0;i<dim;i++)
    {
        printf("inseirsci:  ");
        scanf("%d",&n);
        l=incoda(l,n);
    }
    stampa(l);

    printf("\ninserisci un numero k:  ");
    scanf("%d",&k);
    t=coppie(l,t,k);
    stampacop(t);

    return 0;
}

nodo*nelem(int a)
{
    nodo*q=(nodo*)malloc(sizeof(nodo));
    q->primo=a;
    q->next=NULL;
    return q;
}

cop*nelemcop(int x,int y)
{
  cop*q=(cop*)malloc(sizeof(cop));
  q->x=x;
  q->y=y;
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

cop*incodacop(cop*c,int x,int y)
{
    if (c==NULL)
    {
        c=nelemcop(x,y);
    }
    else
    {
        c->next=incodacop(c->next,x,y);
    }
    return c;
}

cop*coppie(nodo*p,cop*c,int k)
{
   if(p!=NULL){
		nodo*tmp=p->next;
		while(tmp!=NULL){
			if(p->primo + tmp->primo>k){
				c=incodacop(c,p->primo,tmp->primo);
			}tmp=tmp->next;
		}
		c=coppie(p->next,c,k);
	}
return c;
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d->",p->primo);
        p=p->next;
    }
}

void stampacop(cop*c)
{
    while(c!=NULL)
    {
        printf("\n(%d,%d)->",c->x,c->y);
        c=c->next;
    }
}

