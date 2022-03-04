#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*intesta(nodo*p,int a);
nodo*incoda(nodo*p,int a);
nodo*ricerca(nodo*p,int a);
nodo*elimina(nodo*p);
int occorrenza(nodo*p,int a);
nodo*elocc(nodo*p,int a);
void stampa(nodo*p);
nodo*leggi(FILE*pf);
nodo*scrivi(FILE*pf,int dim);
nodo*modifica(FILE*pf,nodo*p);



int main()
{
    FILE*pf;
    nodo*l=NULL;
    int i=0,n,dim;

         ///****VERSIONE CHE CHIEDE ALL'UTENTE DI INSERIE NUMERI NEL FILE***

    printf("quanti numeri vuoi?   ");
    scanf("%d",&dim);

    printf("scrivo nel file:\n");
    l=scrivi(pf,dim);

    printf("leggo il file:\n");
    l=leggi(pf);
    stampa(l);

    /*printf("\nquale elemento vuoi ricercare nel file?  ");
    scanf("%d",&n);
    l=leggi(pf);
    if(ricerca(l,n))
    {
        printf("\nelemento trovato!");
    }
    else
    {
        printf("\nelemento NON trovato!");
    }*/
                                                        ///conta le occorrenze nel file
    /*printf("\nquale occorrenza vuoi cercare?  ");
    scanf("%d",&n);
    l=leggi(pf);
    printf("le occorrenza di %d sono: %d ",n,occorrenza(l,n));*/

                                               ///elimina le occorrenze modificando la lista
    /*printf("\nquale occorrenza eliminare?   ");  ///ovviamente,il file a.txt,deve avere dei numeri
    scanf("%d",&n);
    l=leggi(pf);
    l=elocc(l,n);
    stampa(l);*/
                                 ///elimina le occorrenze modificando il file
    /*printf("\nmodifico il file eliminando le occorrenze di %d:  ",n);
    l=modifica(pf,l);
    printf("FATTO!");*/




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

nodo*ricerca(nodo*p,int a)
{
    nodo*trovato=NULL;
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
    nodo*tmp;
    for(;p!=NULL;p=tmp)
    {
        tmp=p->next;
        p->next=NULL;
        free(p);
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

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d->",p->primo);
        p=p->next;
    }
}

nodo*leggi(FILE*pf)
{
    nodo*p=NULL;
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    pf=fopen("a.txt","r");
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

     pf=fopen("a.txt","w");
    if(pf)
    {
        for(i=0;i<dim;i++)
        {
            printf("inserisci numero:   ");
            scanf("%d",&tmp->primo);
            fprintf(pf," %d ",tmp->primo);
            p=incoda(p,tmp->primo);
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
    pf=fopen("a.txt","w");
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
    ///manca return p?
}
