/* data una lista L di interi:
1) una funzione che popoli la lista con 50 caratteri ASCII casuali
2) Una funzione che calcoli quanti caratteri sono compresi tra a e z
3) una funzione che,letto un intero c da tastiera, conti il numero di occorrenze di c in L e crei una nuova lista l1 che contiene
   tutti i caratteri tranne c*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct LISTA
{
    char primo;
    struct LISTA*next;
}nodo;

nodo*nelem(char a);
nodo*incoda(nodo*p,char a);
int occorrenza(nodo*p,char a);
nodo*elocc(nodo*p,char a);
int lunghezza(nodo*p);   ///conta quanti char tra a e z ci sono
void stampa(nodo*p);
nodo*casuale(nodo*p,int dim);  ///popola la lista casualmente



int main()
{
    nodo*l=NULL;
    nodo*l2=NULL;
    int dim,i=0,n;
    char c;

    printf("quanti elementi vuoi?  ");
    scanf("%d",&dim);                    ///dovrebbero essere 50 ma fanculo

    l=casuale(l,dim);
    stampa(l);

    printf("\nconto le occorrenze dei caratteri tra a e z: ");
    printf("\noccorrenze: %d ",lunghezza(l));

    fflush(stdin);
    printf("\nquale occorrenza vuoi contare? ");
    scanf("%c",&c);
    printf("\nle occorrenze di %c sono: %d ",c,lunghezza(l));


    printf("\nnuova lista senza %c ",c);
    l2=elocc(l,c);
    stampa(l2);

    return 0;
}

nodo*nelem(char a)
{
    nodo*q=(nodo*)malloc(sizeof(nodo));
    q->primo=a;
    q->next=NULL;
    return q;
}

nodo*incoda(nodo*p,char a)
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

int occorrenza(nodo*p,char a)
{
    int flag=0;
    if(p!=NULL)
    {
        if(p->primo==a)
        {
            flag=1+occorrenza(p->next,a);
        }
        else
        {
            flag=occorrenza(p->next,a);
        }
    }
    return flag;
}

nodo*elocc(nodo*p,char a)
{
    nodo*tmp=p;
    if(p!=NULL)
    {
        if(p->primo==a)
        {
            p=elocc(p->next,a);
            free(tmp);
        }
        else
        {
            p->next=elocc(p->next,a);
        }
    }
    return p;
}

int lunghezza(nodo*p)
{
    int len=0;
    while(p!=NULL)
    {
         if(p->primo> 'a' && p->primo < 'z')
         {
              len++;
         }

        p=p->next;
    }
    return len;
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%c->",p->primo);
        p=p->next;
    }
}

nodo*casuale(nodo*p,int dim)
{
    char c;
    int i=0;
    srand((unsigned)time(NULL));
    for(i=0;i<dim;i++)
    {
        c=rand()%50+'a';   ///ho messo 50 così non escono solo caratteri da a - z metto comunque 'a' per fargli capire che sono caratteri. posso mettere qualunque carattere tra i due apici,usciranno caratteri diversi
        p=incoda(p,c);
    }
    return p;
}
