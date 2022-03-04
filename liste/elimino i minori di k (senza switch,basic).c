#include <stdio.h>
#include <malloc.h>
typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;

nodo*crea_elemento(int a);
nodo*inserisci_intesta(nodo*p,int a);
nodo*inserisci_incoda(nodo*p,int a);
nodo*elimina_minori(nodo*p,int k);
void stampa_lista(nodo*p);

int main ()
{
    int k,i,dim,num;
    nodo*l=NULL;

    printf("quanti numeri vuoi inserire nella lista? ");
    scanf("%d",&dim);
    for(i=0;i<dim;i++)
    {
        printf("inserisci numero ");
        scanf("%d",&num);
        l=inserisci_incoda(l,num);
    }
    printf("\nla lista e': \n");
    stampa_lista(l);

    printf("\ninserisci un numero k: ");
    scanf("%d",&k);
    printf("\nelimino tutti i numeri minori di %d",k);
    l=elimina_minori(l,k);
    printf("\nstampo la lista");
    stampa_lista(l);


    return 0;
}


nodo*crea_elemento(int a)
{
  nodo*q=(struct LISTA*)malloc(sizeof(struct LISTA));
  q->primo=a;
  q->next=NULL;
  return q;
}

nodo*inserisci_intesta(nodo*p,int a)
{
    nodo*q=crea_elemento(a);
    q->next=p;
    return q;
}

nodo*inserisci_incoda(nodo*p,int a)
{
    if(p==NULL)
    {
        p=crea_elemento(a);
    }
    else
    {
        p->next=inserisci_incoda(p->next,a);
    }
    return p;

}

nodo*elimina_minori(nodo*p,int k)
{
    nodo*tmp;
    if(p==NULL)
    {
        return p;
    }
    else
    {
        p->next=elimina_minori(p->next,k);
        if(p->primo<k)
        {
            tmp=p;
            p=p->next;
            free(tmp);
        }
    }
    return p;
}

void stampa_lista(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d\n",p->primo);
        p=p->next;
    }
}
