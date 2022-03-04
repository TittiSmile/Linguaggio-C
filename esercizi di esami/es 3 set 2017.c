/*data una lista di interi e due numeri k ed n (con n >=1),scrivere una funzione ricorsiva che inserisca k nella n-esima posizione
della lista l. tale funzione deve avere come argomenti la lista l,il numero k e la posizione n. NOTA: se n è 1, l'inserimento va
effettuato in testa; se n è maggiore della lunghezza della lista,l'inserimento va effettuato in coda.  */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*intesta(nodo*p,int a);
nodo*incoda(nodo*p,int a);
nodo*casuale(nodo*p,int dim);
int lenList(nodo*p);
nodo*InsInPosizione(nodo*p,int k,int n); //dove n è la posizione del k elemento nella lista
void stampa(nodo*p);

int main ()
{
    nodo*l1=NULL;
    int dim,k,posizione,a;

    /*printf("quanto vuoi grande la tua lista?  ");
    scanf("%d",&dim);
    l1=casuale(l1,dim);*/
    l1=incoda(l1,12);l1=incoda(l1,1);l1=incoda(l1,30);
    stampa(l1);

    printf("\ninserisci un numero k: ");
    scanf("%d",&k);
    printf("\ninserisci la posizione dove vuoi inserire k=%d:  ",k);
    scanf("%d",&posizione);
    l1=InsInPosizione(l1,k,posizione);
    stampa(l1);


    return 0;
}

nodo*nelem(int a)
{
    nodo*q=(nodo*)malloc(sizeof(nodo));
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

nodo*casuale(nodo*p,int dim)
{
    int i=0,n;
    srand((unsigned)time(NULL));
    for(i=0;i<dim;i++)
    {
        n=rand()%20+1;
        p=incoda(p,n);
    }
    return p;
}

int lenList(nodo*p)
{
    int cont=0;
    while(p!=NULL)
    {
        cont++;
        p=p->next;
    }
    return cont;
}

nodo*InsInPosizione(nodo*p,int k,int n)
{
    int cont=0;
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    nodo*cur=p;

    if(p==NULL)
    {
        return p;
    }
    else
    {
        if(n==1)
        {
            p=intesta(p,k);
        }

        else if (n>=1 && n<lenList(p)) ///else if (n!=1 && n<lenlist(p))
        {
            tmp->primo=k; ///assegno k al nodo della lista temporanea
           while(++cont<n) ///finchè il contatore è minore della posizione corrente faccio ++ perchè parte da 1 questo while pare NON necessario
            {
                cur=cur->next;
            }
            tmp->next=cur->next;
            cur->next=tmp;        ///la lista temporanea e cur assumono lo stesso valore
        }

        else if(n>lenList(p))
        {
            p=incoda(p,k);
        }
    }
    return p;
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d->",p->primo);
        p=p->next;
    }
}


