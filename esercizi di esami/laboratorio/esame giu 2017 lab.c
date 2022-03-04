/*Scrivere un programma in C che effettui i seguenti compiti:
1)legga 20 interi dalla tastiera e li stalva in una lista l1, calcolando e mostrando a video Minimo Massimo e Media
2)Chieda all'utente di inserire un intero n da tastiera e salvi in un file "numbers.txt" tutti i numeri minori di n
3) Legga il file "numbers.txt" in una lista l2,calcolando su di essa e mostrando a video Minimo Massimo e Media
Le tre funzioni devono essere invocate in sequenza dal main e deve essere stampato a schermo il contenuito delle strutture
dati al termine di ogni funzione*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
void stampa(nodo*p);
int somma(nodo*p);
float media(nodo*p,int dim);
///
int max(nodo*p);
int min(nodo*p);
nodo*elimaxk(nodo*p,int k);
///
nodo*scrivi(FILE*pf,int dim);
nodo*leggi(FILE*pf);
nodo*modifica(FILE*pf,nodo*p);
int numelfile(FILE*pf);

int main ()
{
    FILE*pf;
    nodo*l=NULL;
    nodo*l2=NULL;
    int i=0,dim,n,num,cont;


    printf("quanti elementi?  "); ///dovrebbero essere 20 ma sono troppi. decido di chiedere all'utente la grandezza della lista
    scanf("%d",&dim);

    l=scrivi(pf,dim);
    stampa(l);

    printf("\nla media e': %f ",media(l,dim));
    printf("\nil numero piu' grande e':%d  ",max(l));
    printf("\nil numero piu' piccolo e':%d  \n",min(l));
    ///
    system("pause");                                            ///metto prima in pausa sennò non si legge un caspio
    system("cls");                                             ///pulisco lo schermo
    printf("\n\t\n***________***\n\ninserisci un numero n: ");
    scanf("%d",&num);
    printf("\nelimino i maggiori di %d ",num);
    l=elimaxk(l,num);
    printf("\nscrivo nel file");
    l=modifica(pf,l);
    printf("\nFATTO\n");
    ///
    system("pause");                                            ///metto prima in pausa sennò non si legge un caspio
    system("cls");                                             ///pulisco lo schermo
    printf("\n\t\n***___________***\n\nfaccio operazioni su L2!");
    l2=leggi(pf);
    stampa(l2);
    cont=numelfile(pf);
    printf("\ni numeri presenti nel file sono: %d ",cont);
    printf("\nla media e': %f ",media(l2,cont));
    printf("\nil numero piu' grande e':%d  ",max(l2));
    printf("\nil numero piu' piccolo e':%d  \n",min(l2));


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
    float m=0;
    int i=0;
    if(p!=NULL)
    {
        for(i=0;i<dim;i++)
        {
            m=(float)somma(p)/(float)dim;   ///ho usato il cast
        }
    }
    return m;
}
///
int max(nodo*p)
{
    int max=INT_MIN;
    int i=0;
    nodo*tmp;
    if(p==NULL)
    {
        return 0;
    }
    while(p!=NULL)
    {
        if(p->primo>max)
        {
            tmp=p;
            max=p->primo;
        }
        p=p->next;
    }
    return max;
}

int min(nodo*p)
{
    int min=INT_MAX;
    int i=0;
    nodo*tmp;
    if(p==NULL)
    {
        return 0;
    }
    while(p!=NULL)
    {
        if(p->primo<min)
        {
            tmp=p;
            min=p->primo;
        }
        p=p->next;
    }
    return min;

}

nodo*elimaxk(nodo*p,int k)
{
    nodo*tmp=p;
    if(p!=NULL)
    {
        if(p->primo>k)
        {
            p=elimaxk(p->next,k);
            free(tmp);
        }
        else
        {
            p->next=elimaxk(p->next,k);
        }
    }
    return p;
}

///
nodo*scrivi(FILE*pf,int dim)
{
    nodo*p=NULL;
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    int i=0;
    pf=fopen("numbers.txt","w");
    if(pf)
    {
        for(i=0;i<dim;i++)
        {
            printf("inserisci numero: ");
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

nodo*leggi(FILE*pf)
{
    nodo*p=NULL;
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    pf=fopen("numbers.txt","r");
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

nodo*modifica(FILE*pf,nodo*p)
{
    pf=fopen("numbers.txt","w");
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

int numelfile(FILE*pf)
{
    nodo*p=NULL;
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    int cont=0;
    pf=fopen("numbers.txt","r");
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
