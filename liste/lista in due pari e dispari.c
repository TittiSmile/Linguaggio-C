#include <stdio.h>
#include <malloc.h>
typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;

nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
nodo*elimina_elemento(nodo*p,int a); ///simile alla funzione'elimina occorrenze'. l'unica differenza è che non viene chiesto di inserire da tastiera l'elemento da eliminare
nodo*pari_dispari(nodo*l1,nodo*l2);
void stampa(nodo*p);

int main ()
{
    nodo*l1=NULL;
    nodo*l2=NULL;
    int dim,num,i;
    /*printf("quanto vuoi grande la tua lista? ");
    scanf("%d",&dim);
    for(i=0;i<dim;i++)
    {
        printf("inserisci numero  ");
        scanf("%d",&num);
        l1=incoda(l1,num);
    }*/
    l1=incoda(l1,3);l1=incoda(l1,5);l1=incoda(l1,4);l1=incoda(l1,2);
    stampa(l1);
    printf("sposto gli elementi di posizione pari in un'altra lista\n");
    l2=pari_dispari(l1,l2);
    printf("\nla lista 1 (con elementi dispari) e': ");
    stampa(l1);
    printf("\nla lista 2 (con elementi pari)  e': ");
    stampa(l2);



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

nodo*elimina_elemento(nodo*p,int a)
{
     nodo*tmp=p;
    if(p!=NULL)
    {
        if(p->primo==a)
        {
           /* tmp=p->next;
            free(tmp);
            p=tmp;*/        ///dal primo elemento in poi mi stampa gli indirizzi di memoria D: meglio quella sotto

           p=elimina_elemento(p->next,a);
           free(tmp);                              ///versione ricorsiva
        }
        else
        {
            p->next=elimina_elemento(p->next,a);
        }
    }
    return p;



}

nodo*pari_dispari(nodo*l1,nodo*l2)
{
    int cont=1;
    nodo*tmp=NULL;
    nodo*l3=l1;
    while(l3!=NULL)
    {
        if(cont%2==0)
        {
            tmp=incoda(tmp,l3->primo);
            l1=elimina_elemento(l1,l3->primo);
        }
        l3=l3->next;
        cont++;
    }
    return tmp;
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d\n",p->primo);
        p=p->next;
    }
}


