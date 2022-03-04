#include <stdio.h>
#include <malloc.h>
typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;

nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
nodo*prima(nodo*p);
void stampa(nodo*p);

int main ()
{
    nodo*l1=NULL;
    nodo*l2=NULL;

    l1=incoda(l1,3);l1=incoda(l1,5);l1=incoda(l1,4);l1=incoda(l1,2);l1=incoda(l1,6);
    stampa(l1);
    printf("\n\n");
    l1=prima(l1);  ///non so perchè ma l'ultimo elemento non viene visualizzato
    stampa(l1);




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

nodo*prima(nodo*p)
{
   nodo*tmp=p;
   int cont=0;
   if(p!=NULL)
   {
      while(tmp!=NULL)
       {
           if(tmp->primo%2==0)
           {
             cont=tmp->primo;
             tmp->primo=p->primo;
             p->primo=cont;
           }
           tmp=tmp->next;
       }
       //p->next=prima(p->next); //passo ricorsivo
       p=p->next;
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


