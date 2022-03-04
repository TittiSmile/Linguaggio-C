/*data una lista di interi si realizzi:
1) una funzoine che letti due interi n ed m da tastiera crei l di lunghezza n inizializzata con una sequenza di interi
   decrescenti a partire da m
2)una funzione che,letto un intero p da tastiera duplichi tutte le occorrenze di p in l
3)una funzione che calcoli la media dei valori contenuti in l*/

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
int occorrenza(nodo*p,int a);
void stampa(nodo*p);
int somma(nodo*p);
float media(nodo*p,int dim);
nodo*duplica(nodo*p,int a);
nodo*casuale(nodo*p,int dim);
///
nodo*ordina(nodo*p,nodo*tmp);
nodo*crescente(nodo*p);
nodo*insordine(nodo*p,int a);
///
nodo*leggi(FILE*pf);
nodo*scrivi(FILE*pf,int dim);
nodo*modifica(FILE*pf,nodo*p);
int lenfile(FILE*pf);

int main ()
{
    nodo*l=NULL;
    nodo*l2=NULL;
    FILE*pf;
    int dim=0,i=0,m,num,cont=0;

    /*printf("numero elementi? ");
    scanf("%d",&dim);
      l=casuale(l,dim);
    stampa(l);
    l=modifica(pf,l);

    printf("\nquanti numeri scritti nel file:%d ",lenfile(pf));*/

    printf("numero elementi? ");
    scanf("%d",&dim);

   /*for(i=0;i<dim;i++)
   {
       printf("inserisci numero ");
       scanf("%d",&num);
       l=incoda(l,num);
   }*/
   l=casuale(l,dim);
   stampa(l);
   /* nodo*l=NULL;
    nodo*l2=NULL;
    FILE*pf;
    int dim=0,i=0,m,num,cont=0;   ///dim è il mio n

    printf("numero elementi? ");
    scanf("%d",&dim);
    l=casuale(l,dim); ///mi rompo di digitarli.
    stampa(l);

     printf("\nscrivo nel file");
    l=modifica(pf,l);
    printf("\nelementi nel file: %d \n",lenfile(pf));



    system("\nPAUSE");
    system("CLS");
    printf("\ninserisci un numero m: ");
    scanf("%d",&m);
    for(i=0;i<dim;i++)
    {
        do
        {
            printf("inserisci un numero minore di %d:  ",m);
            scanf("%d",&num);
            if(num>m)
                printf("errore,riprova.\n");
        }while(num>m);
        l2=insordine(l2,num);
    }
   stampa(l2);
   system("\nPAUSE");
   system("CLS");



   printf("\ninserisci un numero da duplicare:  ");
   scanf("%d",&num);
   l2=duplica(l2,num);
   stampa(l2);
   printf("\nla media dei numeri nella lista e': %f",media(l2,dim));


    printf("\nscrivo nel file");
    l2=modifica(pf,l2);
    printf("\nelementi nel file: %d ",lenfile(pf));

 system("\nPAUSE");*/
  l=modifica(pf,l);
   printf("\nquanti numeri scritti nel file:%d ",lenfile(pf));


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


void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d->",p->primo);
        p=p->next;
    }
}

int somma(nodo*p)
{
    int s=0;
    if(p==NULL)
    {
        return 0;
    }
    else
    {
        s=somma(p->next);
        s+=p->primo;
        return s;
    }
}

float media(nodo*p,int dim)
{
    int i=0;
    float m;
    if(p!=NULL)
    {
        for(i=0;i<dim;i++)
        {
            m=(float)somma(p)/(float)dim;
        }
    }
    return m;
}

nodo*duplica(nodo*p,int a)
{
    if(occorrenza(p,a)==1)
    {
        p=incoda(p,a);
    }
    return p;
}

nodo*casuale(nodo*p,int dim)
{
    int i=0;
    int a;
    srand((unsigned)time(NULL));
    for(i=0;i<dim;i++)
    {
        a=rand()%100+1;
        p=incoda(p,a);
    }
    return p;
}

///
nodo*ordina(nodo*p,nodo*tmp)
{
    if(p==NULL || p->primo<tmp->primo)
    {
        tmp->next=p;
        p=tmp;
    }
    else
    {
        p=ordina(p->next,tmp);
    }
    return p;
}

nodo*crescente(nodo*p)
{
    nodo*tmp;
    nodo*l1=NULL;
    while(p!=NULL)
    {
        tmp=p;
        p=p->next;
        l1=ordina(l1,tmp);
    }
    return l1;
}

nodo*insordine(nodo*p,int a)
{
    if(p==NULL || p->primo < a)
    {
        nodo*tmp=(nodo*)malloc(sizeof(nodo));
        tmp=nelem(a);
        tmp->next=p;
        p=tmp;
    }
    else
    {
        p->next=insordine(p->next,a);
    }
    return p;
}

///
nodo*leggi(FILE*pf);
nodo*scrivi(FILE*pf,int dim);
nodo*modifica(FILE*pf,nodo*p)
{
    /*pf=fopen("file e listass.txt","w");
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
    return p;*/
    pf=fopen("file e listass.txt","w");
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
    pf=fopen("file e listass.txt","r");
    if(pf)
    {
        while(fscanf(pf," %d ",&tmp->primo)==1)
        {
            cont++;
        }
    }
    else
    {
        printf("errore di apertura");
    }
    fclose(pf);
    return cont;
}



