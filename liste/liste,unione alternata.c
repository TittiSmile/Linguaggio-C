#include <stdio.h>

typedef struct LISTA
{
   int primo;
   struct LISTA *next;
}nodo;

struct LISTA *nelem(int a);
struct LISTA *incoda(struct LISTA *p,int a);
struct LISTA *unisci (struct LISTA *l1,struct LISTA *l2);
void stampa (struct LISTA *p);


int main()
{
    struct LISTA *p1=NULL;
    struct LISTA *p2=NULL;
    struct LISTA *p3=NULL;
    int n=0,m=0;
    int i=0,num=0;

    printf("Quanti numeri vuoi nella lista 1?\n");
    scanf("%d",&n);
    printf("Quanti numeri vuoi nella lista 2?\n");
    scanf("%d",&m);

    for(i=0;i<n;i++)
    {
        printf("Inserisci %d  numero nella lista 1!\n",i+1);
        scanf("%d",&num);
        p1=incoda(p1,num);
    }

    for(i=0;i<m;i++)
    {
        printf("Inserisci %d  numero nella lista 2!\n",i+1);
        scanf("%d",&num);
        p2=incoda(p2,num);
    }

    printf("\nLa prima lista e':\n");
    stampa(p1);

    printf("\nLa seconda lista e':\n");
    stampa(p2);



    printf("\nLe due liste insieme sono:\n");
    p3=unisci(p1,p2);
    stampa(p3);

    return 0;
}


struct LISTA *nelem(int a)
{
 struct LISTA *q=(struct LISTA *)malloc(sizeof(struct LISTA));
 q->primo=a;
 q->next=NULL;
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

////////////////////////N.B.!!!!!!!!
//questa funzione unisce le due liste in modo alternato ovvero: prima un elemento di l1 e poi un elemento di l2!!!
struct LISTA *unisci (struct LISTA *l1,struct LISTA *l2)
{
 struct LISTA *l3=l1;
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
     l2->next=unisci(l1->next,l2->next);
     l3->next=l2;
 }
    return l3;
}


void stampa (struct LISTA *p)
{
    while(p!=NULL)
    {
        printf("\n %d",p->primo);
        p=p->next;
    }
}


