#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
void stampa(nodo*p);
nodo*casuale(nodo*p,int dim);
///
nodo*leggi(FILE*pf);
nodo*scrivi(FILE*pf,int dim);
nodo*modifica(FILE*pf,nodo*p);
int lenfile(FILE*pf);


int main ()
{
    nodo*l=NULL;
    nodo*tmp=NULL;
    FILE*pf;
    int i=0,dim,n;

    printf("quanto vuoi grande la lista?  ");
    scanf("%d",&dim);

    l=casuale(l,dim);
    stampa(l);

    printf("\n\n");
    l=modifica(pf,l);
    l=leggi(pf);
    stampa(l);




    return 0;
}

nodo*nelem(int a)
{
    nodo*q=(nodo*)malloc(sizeof(nodo));
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

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d->",p->primo);
        p=p->next;
    }
}

nodo*casuale(nodo*p,int dim)
{
    int i=0;
    int a=0;
    srand((unsigned)time(NULL));
    for(i=0;i<dim;i++)
    {
        a=rand()%100+1;
        p=incoda(p,a);
    }
    return p;
}

///
nodo*leggi(FILE*pf)
{
    nodo*p=NULL;
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    pf=fopen("lista file modifica solo file.txt","r");
    if(pf)
    {
        while(!feof(pf))
        {
            fscanf(pf," %d ",&tmp->primo);  ///leggo tutta la lista
            if(tmp->primo%3==0)///di quelli che leggo,se è multiplo di 3,lo inserisco nella coda della lista
            {
                p=incoda(p,tmp->primo);
            }
        }
    }
    else
    {
        printf("errore di apertura");
    }

    fclose(pf);
    return p;
}

nodo*scrivi(FILE*pf,int dim)
{
    nodo*p=NULL;
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    int i=0;
    pf=fopen("lista file modifica solo file.txt","w");
    if(pf)
    {
        ///questa qui non la usiamo perchè c'è la funzione casuale! questa serve per mettere i numeri manualmente
           /*for(i=0;i<dim;i++)
           {
               printf("inserisci numero:   ");
               scanf("%d",&tmp->primo);
               fprintf(pf," %d ",tmp->primo);
               p=incoda(p,tmp->primo);
           }*/
           ///versione casuale
           srand((unsigned)time(NULL));
           for(i=0;i<dim;i++)
           {
               tmp->primo=rand()%100+1;
               fprintf(pf," %d ",tmp->primo);
               p=casuale(p,tmp->primo);
           }
    }
    else
    {
        printf("errore di apertura");
    }

    fclose(pf);
    return p;
}

nodo*modifica(FILE*pf,nodo*p)
{
    pf=fopen("lista file modifica solo file.txt","w");
    if(pf)
    {
        while(p!=NULL)
        {
            fprintf(pf," %d ",p->primo);
            p=p->next;
        }
    }
    else
    {
        printf("errore di apertura");
    }

    fclose(pf);
    return p;
}

int lenfile(FILE*pf)
{
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    int cont=0;
    pf=fopen("lista file modifica solo file.txt","r");
    if(pf)
    {
        while(fscanf(pf," %d ",&tmp->primo)==1)
        {
            cont ++;
        }
    }
    else
    {
        printf("errore di apertura");
    }

    fclose(pf);
    return cont;
}
