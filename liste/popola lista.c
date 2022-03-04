#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*intesta(nodo*p,int a);
nodo*incoda(nodo*p,int a);
void stampa(nodo*p);
int len(nodo*p);
void dealloca(nodo*p);
nodo*primop(nodo*p);


int main ()
{
    int dim,n,lun;
    int i=0;
    nodo*l=NULL;

    printf("quanti elementi vuoi nella lista? ");
    scanf("%d",&dim);
    for(i=0;i<dim;i++)
    {
        printf("inserisci %d elemento: ",i+1);
        scanf("%d",&n);
        l=incoda(l,n);
    }
    stampa(l);
    printf("\nla lista e' lungha: %d ",len(l));

   // dealloca(l);                           N.B. deallocare NON vuol dire eliminare la lista!!!
    //printf("\nlista deallocata.");

    printf("\nil puntatore pari ritorna: "); /// funziona ma! non elimina il numero dispari dopo il pari
    l=primop(l);
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
        printf("\n %d \n",p->primo);
        p=p->next;
    }
}
int len(nodo*p)
{
    int i=0;
    while(p!=NULL)
    {
        i++;
        p=p->next;
    }
    return i;
}

void dealloca(nodo*p)
{
    ///serve a deallocare!! non ad eliminare la lista!!!!
    if (p!=NULL) {
		dealloca(p->next);
		p->next=NULL;
		free(p);
		}
}
nodo*primop(nodo*p)
{
    nodo*var=NULL;
    int a;
   if(p==NULL)
   {
       return p;
   }
    while(p!=NULL)
   {
       if(p->primo %2==0)
       {
           var=p;
           a=p->primo;
       }
       p=p->next;
   }
   return var;
}
