#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;


nodo*nelem(int a);
nodo*intesta(struct LISTA *p,int a);
nodo*incoda(struct LISTA *p,int a);
nodo*diversik(struct LISTA *p,int k);//questa funzione,dato ad esempio k=3, mette su un'altra funzione i numeri rimanenti. ESEMPIO! lista: 1-2-3-3. k=3. nuova lista: 1-2
void stampa(struct LISTA *p);


int main ()
{
    nodo*l=NULL;
    nodo*l2=NULL;
    int k=0,num=0,i=0,dim=0;

    l=incoda(l,3);l=incoda(l,5);l=incoda(l,1);l=incoda(l,22);l=incoda(l,12);
    printf("La lista e':\n");
    stampa(l);

   printf("\nInserisci un  numero k:\n");
   scanf("%d",&k);

  printf("\ntutti i numeri diversi  da %d andranno in un'altra lista! \n",k);
  l2=diversik(l,k);
  stampa(l2);


    return 0;
}

nodo*nelem(int a)
{
 nodo *q=(nodo*)malloc(sizeof(nodo));
 q->primo=a;
 q->next=NULL;
 return q;
}

nodo *intesta(struct LISTA *p,int a)
{
 nodo *q=nelem(a);
 q->next=p;
 return q;
}

nodo *incoda(struct LISTA *p,int a)
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

nodo*diversik(struct LISTA *p,int k)
{
    /*nodo*l1=NULL;
    if(p==NULL)
    {
        return p;
    }
    l1=diversik(p->next,k);
    if(p->primo != k)
    {
        l1=intesta(l1,p->primo);
    }
    return l1;*/

    ///ricorsiva ALTERNATIVA
    nodo*l1=NULL;
    if(p!=NULL)
    {
        l1=diversik(p->next,k);
            if(p->primo != k)
            {
                l1=intesta(l1,p->primo);
            }
    }

    return l1;

    ///iterativa
    /*nodo*tmp=NULL;
    nodo*cur=p;
    while(cur->next!=NULL)
    {
        if(cur->next->primo!=k)
        {
            tmp=incoda(tmp,cur->next->primo);
        }
        cur=cur->next;
    }
    if(p->primo!=k)
    {
        tmp=incoda(tmp,p->primo);
    }
    return tmp;*/
}

void stampa(struct LISTA *p)
{
    while(p!=NULL)
    {
        printf("\n %d\n",p->primo);
        p=p->next;
    }
}
