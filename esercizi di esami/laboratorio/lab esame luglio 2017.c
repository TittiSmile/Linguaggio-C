/*scrivere un programma in c che svolgi i seguenti compiti:
1)generare 100 casuali da 10 a 50 e salvarli in un array
2)chiedere all'utente di inserirei un intero n da tastiera e salvi in un file 'numbers.txt' tutti i numeri multipli di n nell'array
3)leggere il file 'numbers.txt' in una lista l1,mostrando a video il numero totale degli elementi nel file ed il relativo contenuto
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

///
int *casuale(int*a,int dim);
///
int*modifica(FILE*pf,int*a,int dim,int n);
///
nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
nodo*leggi(FILE*pf);
void stampa(nodo*p);
int lenfile(FILE*pf);


int main ()
{
    nodo*l=NULL;
    FILE*pf;
    int i=0,dim,n;
    int a[20];

                                                   ///PUNTO 1
    printf("grandezza?  ");
    scanf("%d",&dim);

    casuale(a,dim);
                                                    ///PUNTO 2
    printf("\ninserisci un numero n:  ");
    scanf("%d",&n);
    printf("\nscrivo nel file 'numbers.txt' solo i multipli di %d",n);
    modifica(pf,a,dim,n);
                                                    ///PUNTO 3
    l=leggi(pf);
    printf("\nleggo da file:");
    stampa(l);
    printf("\n\ngli elementi nella file sono: %d \n",lenfile(pf));



    return 0;
}

int *casuale(int*a,int dim)
{
    int i=0;
    srand((unsigned)time(NULL));
    for(i=0;i<dim;i++)
    {
        a[i]=rand()%40+10;
        printf("%d\n",a[i]);
    }
    return a;
}

///
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
        printf("errore di apertura");
    }

    fclose(pf);
    return p;
}

int*modifica(FILE*pf,int*a,int dim,int n)
{
    int i=0;
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    pf=fopen("numbers.txt","w");
    if(pf)
    {
        for(i=0;i<dim;i++)
            {
               if(a[i]%n==0)
                    {
                       fprintf(pf," %d ",a[i]);
                    }
            }
    }
    else
    {
        printf("errore di apertura");
    }
    fclose(pf);
    return a;
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d->",p->primo);
        p=p->next;
    }
}

int lenfile(FILE*pf)
{
    int cont=0;
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
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
        printf("errore di apertura");
    }

    fclose(pf);
    return cont;
}
