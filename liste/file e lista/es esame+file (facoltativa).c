/*
data una lista di interi:
1)una funzione che letto un intero n da tastiera popoli l con 50 interi casuali tra 3 ed n,
2)una funzione che letto un intero p da tastiera stampi il numero di occorrenze di p in l
3)una funzione che letto un intero m da tastiera crei due nuove liste l1 e l2 dove l1 contiene tutti i multipli di m
   ed l2 i non multipli di m
*/
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
nodo*casuale(nodo*p,int dim);
nodo*mul(nodo*p,int m);
nodo*nonmul(nodo*p,int m);
void stampa(nodo*p);
///
nodo*leggi(FILE*pf);
nodo*scrivi(FILE*pf,int dim);
nodo*modifica(FILE*pf,nodo*p);
int lenfile(FILE*pf);

int main ()
{
    nodo*l1=NULL;
    nodo*l2=NULL;
    nodo*l3=NULL;
    FILE*pf;
    int i=0,dim,p=0,a,m;

    printf("numero elementi? ");
    scanf("%d",&dim);

    l1=casuale(l1,dim);
    stampa(l1);

    printf("\nquali occorrenze vuoi contare?  ");
    scanf("%d",&p);
    printf("\nle occorrenze di %d sono: %d ",p,occorrenza(l1,p));

    printf("\ninserisci un numero m:  ");
    scanf("%d",&m);

    printf("\nlista con solo multipli di %d",m);
    l2=mul(l1,m);
    stampa(l2);
    printf("\nlista con i NON multipli di %d",m);
    l3=nonmul(l1,m);
    stampa(l3);

    l2=modifica(pf,l2);
    l3=modifica(pf,l3);



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

nodo*casuale(nodo*p,int dim)
{
    int i=0;
    int a=0;
    int n=0;
    printf("inserisci un numero:   ");
    scanf("%d",&n);
    srand((unsigned)time(NULL));
    for(i=0;i<dim;i++)
    {
        a=rand()%(n-2)+3;    ///ho messo n-2 perchè se,ad esempio,mettevo n=5 mi andava da 3 a 7
        p=incoda(p,a);
    }
    return p;
}

nodo*mul(nodo*p,int m)
{
    nodo*tmp;
    if(p==NULL)
    {
        return p;
    }
    tmp=mul(p->next,m);
    if(p->primo%m==0)
    {
        tmp=incoda(tmp,p->primo);
    }
    return tmp;
}

nodo*nonmul(nodo*p,int m)
{
   nodo*tmp;
   if(p==NULL)
   {
       return p;
   }
   tmp=nonmul(p->next,m);
   if(p->primo%m!=0)
   {
       tmp=incoda(tmp,p->primo);
   }
   return tmp;
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d->",p->primo);
        p=p->next;
    }
    if(p==NULL)
    {
        printf("\nNULL");
    }

}

///
nodo*leggi(FILE*pf)
{
    nodo*p=NULL;
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    pf=fopen("es esame+file(facoltativa).txt","r");
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
        printf("\nerrore di apertura");
    }

    fclose(pf);
    return p;
}

nodo*scrivi(FILE*pf,int dim)
{
    int i=0;
    nodo*p=NULL;
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    pf=fopen("es esame+file(facoltativa).txt","w");
    if(pf)
    {
        for(i=0;i<dim;i++)
        {
            printf("inserisci numero:  ");
            scanf("%d",&tmp->primo);
            fprintf(pf," %d ",tmp->primo);
            p=incoda(p,tmp->primo);
        }
    }
    else
    {
        printf("\nerrore di apertura");
    }

    fclose(pf);
    return p;
}

nodo*modifica(FILE*pf,nodo*p)
{
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    pf=fopen("es esame+file(facoltativa).txt","a"); ///a sta per append ovvero agguinge e non sovrascrive(w)
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
        printf("\nerrore di apertura");
    }
    fclose(pf);
    return p;
}

int lenfile(FILE*pf)
{
    int cont=0;
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    pf=fopen("es esame+file(facoltativa).txt","r");
    if(pf)
    {
        while(fscanf(pf," %d ",&tmp->primo)==1)
        {
            cont++;
        }
    }
    else
    {
        printf("\nerrore di apertura");
    }
    fclose(pf);
    return cont;
}

