#include <stdio.h>
typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;

nodo*nelem(int a);
nodo*intesta(nodo*p,int a);
nodo*incoda(nodo*p,int a);
void stampa(nodo*p);
void dealloca(nodo*p);

int main ()
{
    int valore,i,num;
    nodo*l=NULL;

    printf("quanti elementi vuoi inserire?\n");
    scanf("%d",&valore);

    for(i=0;i<valore;i++)
    {
        printf("inserisci %d elemento ",i+1);
        scanf("%d",&num);
        l=incoda(l,num);
    }

    stampa(l);
    printf("\ndealloco la lista\n");
    dealloca(l);

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


void stampa(nodo*p)
{
   while(p!=NULL)
   {
       printf("\nlista:\n %d",p->primo);
       p=p->next;
   }
}

void dealloca(nodo*p)
{
    if(p!=NULL)
    {
     dealloca(p->next);
     p->next=NULL;
     free(p);

    }

}
