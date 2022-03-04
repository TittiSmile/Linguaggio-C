/*scrivere un programma che faccia le seguenti cose:
1) generare 100 caratteri tra a e z (codice a=97 z=122) e salvarli in un file chars.txt
2) leggere il file chars.txt in una lista l1
3)stampare a video il carattere che compare più frequentemente e quello meno frequentemente ed il relativo numero di occorrenze */
///RIVEDI TERZO PUNTO!!!!
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
nodo*casuale(nodo*p,int dim);
int occorrenza(nodo*p,char a);
int contatore(nodo*p,char a);
void stampa(nodo*p);
///
nodo*scrivi(FILE*pf,int dim);
nodo*leggi(FILE*pf);



int main ()
{
    nodo*l1=NULL;
    int dim,i=0;
    char a;
    FILE*pf;

    printf("quanto vuoi grande la lista? ");
    scanf("%d",&dim);
    //l1=casuale(l1,dim);
    //stampa(l1);

    l1=scrivi(pf,dim);
    l1=leggi(pf);
    stampa(l1);

    printf("\nquale carattere vuoi contare le occorrenze?  ");
    fflush(stdin);
    scanf("%c",&a);
    printf("le occorrenze di %c sono: %d",a,occorrenza(l1,a));



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

nodo*casuale(nodo*p,int dim)
{///potevo fare questa funzione anche direttamente in 'scrivi' però ho preferito smezzarla.
    int i=0;
    char a;
    srand((unsigned)time(NULL));
    for(i=0;i<dim;i++)
    {
        a=rand()%25+'a';
        p=incoda(p,a);
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

int contatore(nodo*p,char a)
{

}


void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%c",p->primo);
        p=p->next;
    }

}

///
nodo*scrivi(FILE*pf,int dim)
{
    nodo*p=NULL;
    int i=0;
    pf=fopen("a.txt","w");
    if(pf)
    {
        for(i=0;i<dim;i++)
        {
             p=casuale(p,dim);
             fprintf(pf," %c ",p->primo);
             p=p->next;
        }
    }
    else
    {
        printf("errore");
    }

    fclose(pf);

    return p;
}

nodo*leggi(FILE*pf)
{
    nodo*p=NULL;
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    pf=fopen("a.txt","r");
    if(pf)
    {
        while(!(feof(pf)))
        {
            fscanf(pf," %c ",&tmp->primo);
            p=incoda(p,tmp->primo);
        }
    }
    else
    {
        printf("errore");
    }

    fclose(pf);
    return p;
}
