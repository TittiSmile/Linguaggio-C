///N.B. se si fanno tutte e 3 le funzioni in un'unica volta,probabilmente non dà il risultato sperato
#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;

void menu();
nodo*nelem(int a);
nodo*intesta(nodo*p,int a);
nodo*incoda(nodo*p,int a);
nodo*incoda2(nodo*p,nodo*tmp);///N.B. questo 'incoda' serve per la funzione 'mk'. questo 'incoda' è utile quando non abbiamo l'elemento già creato(cioè non abbiamo la funzione 'nelem')
nodo*ricerca(nodo*p,int a);
nodo*elimina(nodo*p);
nodo*elk(nodo*p,int k);
nodo*mk(nodo*p,int k);
nodo*diversik(nodo*p,int k);
void stampa(nodo*p);

int main ()
{
    nodo*l=NULL;
    int i,k,num,dim,scelta;
    printf("quanti numeri vuoi nella lista?  ");
    scanf("%d",&dim);
    for(i=0;i<dim;i++)
    {
        printf("inserisci numero:  ");
        scanf("%d",&num);
        l=incoda(l,num);
    }
    printf("\nla tua lista e':\n");
    stampa(l);

    printf("\ndigita un numero k\n");
    scanf("%d",&k);


    menu();

    do
    {
      printf("\ndigitare la scelta");
      scanf("%d",&scelta);

        switch(scelta)
        {
        case 1:
            printf("elimino i maggiori di %d \n",k);
            l=elk(l,k);
            stampa(l);
            break;
        case 2:
            printf("inserisco i minori di %d prima dei maggiori di %d",k,k);
            l=mk(l,k);
            stampa(l);
            break;
        case 3:
            printf("sposto i numeri diversi da %d in un'altra lista\n",k);
            l=diversik(l,k);
            stampa(l);
            break;
        default:
            printf("\nscelta errata");
            break;
        }

    }while(scelta!=3);


    return 0;
}


void menu()
{
    printf("1)elimina i maggiori di k\n2)minori di k prima dei maggiori di k\n3)numeri diversi da k in un'altra lista\n");
}

nodo*nelem(int a)
{
    nodo*q=(nodo*)malloc(sizeof(nodo*));
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

nodo*incoda2(nodo*p,nodo*tmp)
{
    if(p==NULL)
    {
        tmp->next=p;
        return tmp;
    }
    else
    {
        p->next=incoda2(p->next,tmp);
        return p;
    }

}

nodo*ricerca(nodo*p,int a)
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

nodo*elimina(nodo*p)
{
    nodo*tmp=NULL;
    for(;p!=NULL;p=tmp)
    {
        tmp=p->next;
        p->next=NULL;
        free(p);
    }
    return p;
}

nodo*elk(nodo*p,int k)
{
    nodo*tmp;
    if(p==NULL)
    {
        return p;
    }
    else
    {
        p->next=elk(p->next,k);
        if(p->primo >k)
        {
            tmp=p;
            p=p->next;
            free(tmp);
        }
    }
    return p;
}

nodo*mk(nodo*p,int k)
{
    nodo*tmp;
    if(p==NULL  || p->next==NULL)
    {
        return p;
    }
    tmp=mk(p->next,k);
    if(p->primo <k)
    {
        p->next=tmp;
        return p;
    }
    else
    {
        tmp=incoda2(tmp,p);
        return tmp;
    }
}


nodo*diversik(nodo*p,int k)
{
    nodo*tmp=NULL;
    if(p==NULL)
        return p;
    tmp=diversik(p->next,k);
    if(p->primo !=k)
    {
        tmp=intesta(tmp,p->primo);
    }
    return tmp;
}


void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n\n %d",p->primo);
        p=p->next;
    }
}





