#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;

void menu();
nodo*new_elem(int a);
nodo*inserisci_intesta(nodo*p,int a);
nodo*inserisci_incoda(nodo*p,int a);
nodo*elimina_lista(nodo*p);
nodo*ricerca_elemento(nodo*p,int a);
void stampa_lista(nodo*p);
nodo*rewerse(nodo*p);

int main ()
{
    nodo*lista=NULL;
    int scelta;
    int num;

    do
    {
        menu();
        printf("\ncosa vuoi fare? ");
        scanf("%d",&scelta);

        switch(scelta)
        {
        case 1:
            printf("inserimento in testa: ");
            scanf("%d",&num);
            lista=inserisci_intesta(lista,num);
            break;
        case 2:
            printf("inserimento in coda: ");
            scanf("%d",&num);
            lista=inserisci_incoda(lista,num);
            break;
        case 3:
            printf("elimino tutta la lista\n");
            lista=elimina_lista(lista);
            break;
        case 4:
            printf("quale elemento vuoi cercare nella lista?  ");
            scanf("%d",&num);
            if(ricerca_elemento(lista,num))
            {
                printf("\nelemento trovato");
            }
            else
            {
                printf("\nelemento NON trovato");
            }
            break;
        case 5:
            printf("stampo la lista");
            stampa_lista(lista);
            break;
        case 6:
            printf("stampo al contrario");
            lista=rewerse(lista);
        case 7:
              printf("\narrivederci");
            break;
        default:
            printf("\nscelta non valida");
            break;
        }

    }while(scelta!=7);


    return 0;
}

void menu()
{
    printf("1)aggiungi elemento in testa\n2)aggiungi elemento in coda\n3)elimina la lista\n4)ricerca elemento\n5)stampa\n6)stampa al contrario\n7)esci\n");
}

nodo*new_elem(int a)
{
    nodo*q=(struct LISTA*)malloc(sizeof(struct LISTA));
    q->primo=a;
    q->next=NULL;
    return q;
}

nodo*inserisci_intesta(nodo*p,int a)
{
    nodo*q=new_elem(a);
    q->next=p;
    return q;
}

nodo*inserisci_incoda(nodo*p,int a)
{
    if(p==NULL)
    {
        p=new_elem(a);
    }
    else
    {
        p->next=inserisci_incoda(p->next,a);
    }
    return p;
}

nodo*elimina_lista(nodo*p)
{
   nodo*tmp;
   for(;p!=NULL;p=tmp)
   {
       tmp=p->next;
       p->next=NULL;
       free(p);
   }
}

nodo*ricerca_elemento(nodo*p,int a)
{
    nodo*trovato;
    for(;p!=NULL && trovato==NULL;p=p->next)
    {
        if(p->primo==a)
        {
            trovato=p;
        }
    }
    return trovato;
}

void stampa_lista(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n %d ",p->primo);
        p=p->next;
    }
}
nodo*rewerse(nodo*p)
{
    if(p==NULL)
        return 0;
     rewerse(p->next);
        printf("\n%d",p->primo);
}
