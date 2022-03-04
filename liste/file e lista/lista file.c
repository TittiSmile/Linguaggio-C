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
int occorrenza(nodo*p,int a);
nodo*elocc(nodo*p,int a);
nodo*multipli(nodo*p);
void stampa(nodo*p);
///
nodo*leggi(FILE*pf);
nodo*scrivi(FILE*pf,int dim);
nodo*modifica(FILE*pf,nodo*p);
int elemfile(FILE*pf);

int main()
{
    FILE*pf;
    nodo*l=NULL;
    int i=0,dim,n;

    printf("quanti numeri vuoi?  ");
    scanf("%d",&dim);

    printf("scrivo:\n");
    l=scrivi(pf,dim);
    printf("leggo:\n");
    l=leggi(pf);
    stampa(l);
    printf("\nelikmino i multipli di 3: ");
    l=multipli(l);
    stampa(l);

    l=modifica(pf,l);

    printf("\nquanti numeri scritti nel file:%d ",elemfile(pf));  ///calcolo quanti elementi ci sono nel file



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

int occorrenza(nodo*p,int a)
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

nodo*elocc(nodo*p,int a)
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

nodo*multipli(nodo*p)
{
    nodo*tmp=p;
    if(p!=NULL)
    {
        if(p->primo%3!=0)
        {
            p=multipli(p->next);
            free(tmp);
        }
        else
        {
            p->next=multipli(p->next);
        }
    }
    return p;
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d-> ",p->primo);
        p=p->next;
    }
}

///                                            ________________________________________
nodo*leggi(FILE*pf)
{
    nodo*p=NULL;
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    pf=fopen("aas.txt","r");
    if(pf)
    {
        while(!feof(pf))
        {
            fscanf(pf," %d ",&tmp->primo);
            p=incoda(p,tmp->primo);
        }
    }
    else
    {
        printf("problema di apertura");
    }

    fclose(pf);
    return p;
}

nodo*scrivi(FILE*pf,int dim)
{
    nodo*p=NULL;
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    int i=0;
    pf=fopen("aas.txt","w");
    if(pf)
    {
        srand((unsigned)time(NULL));
        for(i=0;i<dim;i++)
        {
           // printf("\ninserisci numero:   ");
            //scanf("%d",&tmp->primo);
            tmp->primo=rand()%100+1;
            fprintf(pf," %d ",tmp->primo);
            p=incoda(p,tmp->primo);
        }
    }
    else
    {
        printf("problema di apertura");
    }

    fclose(pf);
    return p;
}

nodo*modifica(FILE*pf,nodo*p)
{
    pf=fopen("aas.txt","w");
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
        printf("problema di apertura");
    }

    fclose(pf);
    return p;
}

int elemfile(FILE*pf)
{
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    int cont=0;
    pf=fopen("aas.txt","r");
    if(pf)
    {
        while(fscanf(pf," %d ",&tmp->primo)==1)
        {
           cont++;
        }
    }
    else
    {
        printf("problema di apertura");
    }

    fclose(pf);
    return cont;
}
