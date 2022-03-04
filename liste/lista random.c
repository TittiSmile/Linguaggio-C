#include <stdio.h>
#include <time.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;


int casuale();
nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
void stampa(nodo*p);

int main ()
{
    nodo*l=NULL;
   int a=0;
   int i;
   int num;

 //  a=casuale();
   //printf("\n%d\n",a);

/*printf("\ninserisci numero in coda: ");
scanf("%d",&num);
l=incoda(l,num);

printf("\nlista:\n");
stampa(l);*/

     for(i=0;i<5;i++)
     {
         a=rand()%100+1;
         l=incoda(l,a);
     }                           ///genera 5 numeri casuali


 //   l=incoda(l,a);

printf("\nlista:\n");
stampa(l);



    return 0;
}


int casuale()
{
    int contatore;
    srand(time(NULL));
    contatore=rand()%100+1;
    return contatore;
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

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d\n",p->primo);
        p=p->next;
    }
}

