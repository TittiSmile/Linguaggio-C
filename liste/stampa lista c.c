#include <stdio.h>

typedef struct LISTA
{
    int primo;
    struct LISTA *next;
} nodo;

struct LISTA *nelem(int a);
struct LISTA *incoda (struct LISTA *p,int a);
void stampa (struct LISTA *p);


int main ()
{
    struct LISTA *l=NULL;
    int num;
    int volte;
    int i=0;

    printf("quanti numeri vuoi inserire?\n");
    scanf("%d",&volte);

    for(i=0;i<volte;i++)
    {
          printf("inserisci un numero in coda:\n ");
            scanf("%d",&num);
            l=incoda(l,num);

    }

    printf("stampo lista:\n");
    stampa(l);

    return 0;
}

struct LISTA *nelem(int a)
{
   nodo*q=(struct LISTA *)malloc (sizeof(struct LISTA));
   q->primo=a;
   q->next=NULL;
   return q;
}

struct LISTA *incoda (struct LISTA *p,int a)
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
};


void stampa (struct LISTA *p)
{
    while(p!=NULL)
    {
        printf("lista:-> %d \n",p->primo);
        p=p->next;
    }
}




