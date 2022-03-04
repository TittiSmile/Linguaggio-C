#include <stdio.h>
typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;

struct LISTA *nelem(int a);
struct LISTA *intesta(struct LISTA *p,int a);
struct LISTA *incoda(struct LISTA *p,int a);
struct LISTA *ricerca(struct LISTA *p,int a);
struct LISTA *intersezione(struct LISTA *l1,struct LISTA *l2);
void stampa(struct LISTA *p);


int main ()
{
    struct LISTA *l1=NULL;
    struct LISTA *l2=NULL;
    struct LISTA *l3=NULL;
    int i=0,num=0,dim=0;
    int mun=0,dom=0;

    printf("Quanti elementi nella lista 1?\n");
    scanf("%d",&dim);
    printf("Quanti elementi nella lista 2?\n");
    scanf("%d",&dom);

    for(i=0;i<dim;i++)
    {
        printf("Inserisci %d elemento  ",i+1);
        scanf("%d",&num);
        l1=incoda(l1,num);
    }

    for(i=0;i<dom;i++)
    {
        printf("Inserisci %d elemento  ",i+1);
        scanf("%d",&mun);
        l2=incoda(l2,mun);
    }

    printf("\nLa lista 1 e': \n");
    stampa(l1);
    printf("\nLa lista 2 e': \n");
    stampa(l2);

    printf("\nLe due liste intersecate sono:\n ");
    l3=intersezione(l1,l2);
    stampa(l3);
    if(l3==NULL)
    {
        printf("Lista vuota!! NON ci sono intersezioni");
    }




    return 0;
}



struct LISTA *nelem(int a)
{
 struct LISTA *q=(struct LISTA *)malloc(sizeof(struct LISTA));
 q->primo=a;
 q->next=NULL;
 return q;
}

struct LISTA *intesta(struct LISTA *p,int a)
{
 struct LISTA *q=nelem(a);
 q->next=p;
 return q;

}

struct LISTA *incoda(struct LISTA *p,int a)
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

struct LISTA *ricerca(struct LISTA *p,int a)
{
 struct LISTA *trovato;
 for(;p!=NULL && trovato==NULL;p=p->next)
 {
     if(p->primo==a)
     {
         trovato=p;
     }
 }
    return trovato;
}


struct LISTA *intersezione(struct LISTA *l1,struct LISTA *l2)
{
 struct LISTA *l3=NULL;
 if(l1)
{
     l3=intersezione(l1->next,l2);
     if(ricerca(l2,l1->primo))
     {
         l3=intesta(l3,l1->primo);
     }
}
    return l3;
}


void stampa(struct LISTA *p)
{
    while(p!=NULL)
    {
        printf("\n %d \n",p->primo);
        p=p->next;
    }
}




