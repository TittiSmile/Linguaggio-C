#include <stdio.h>
#include <malloc.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
int somma(nodo*p);        ///sommo tutti gli elementi della lista
nodo*sommaprec(nodo*p);    ///sostituisco ogni elemento con la somma dei precedenti
void stampa(nodo*p);

int main ()
{
   nodo*l=NULL;
   int dim,i,n;
   /*printf("quanti elementi vuoi nella lista?  ");
   scanf("%d",&dim);
   for(i=0;i<dim;i++)
   {
       printf("\ninserisci numero  ");
       scanf("%d",&n);
       l=incoda(l,n);
   }
   stampa (l);*/
   l=incoda(l,4);l=incoda(l,5);l=incoda(l,1);l=incoda(l,2);

   printf("la somma di tutti gli elementi e': %d",somma(l));

    printf("\nsostituisco ogni elemento con la somma del precedente\n");
    l=sommaprec(l);
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

int somma(nodo*p)
{
    int s=0;
    if(p==NULL)
    {
        return 0;
    }
    else
    {
        s=somma(p->next);
        s+=p->primo;
        return s;
    }
}

nodo*sommaprec(nodo*p)
{

    ///è buggata,non funziona
    nodo*tmp=p;
    int s=0;
    if(p==NULL)
    {
        return p;
    }
    else
        {
          s+=p->primo;
          tmp->primo=s;
          return tmp;
        }
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d\n",p->primo);
        p=p->next;
    }
}
