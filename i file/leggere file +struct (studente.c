#include <stdio.h>
#include <stdlib.h>
#define max 20
typedef struct STUDENTE
{
    char nome[max];
    char cognome[max];
    int matricola;
    int esame;
}nodo;

nodo**leggi(FILE*pf,nodo**p,int n);
void stampa(nodo**p,int n,int k);


int main ()
{
    FILE*pf=NULL;
    char nome[max];
    int n,k;
    printf("inserire il nome del file da aprire:  ");
    scanf("%s",nome);


    pf=fopen(nome,"r");                                    /// RICORDA DI APRIRE IL FILE CON A.TXT ovvero,aggiungi l'estensione
    if(pf==NULL)
    {
        printf("FILE VUOTO o inesistente ");
    }
    else
    {
        fscanf(pf,"%d",&n);
        struct STUDENTE **l=(struct STUDENTE**)malloc(sizeof(struct STUDENTE)*n);
        l=leggi(pf,l,n);
        printf("digita un numero k equivalente al numero di esami:  ");
        scanf("%d",&k);
        stampa(l,n,k);

        fclose(pf);
    }


    return 0;
}

nodo **leggi(FILE *pf,nodo **p,int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        p[i]=(struct STUDENTE *)malloc(sizeof(struct STUDENTE));
        fscanf(pf,"%s %s %d %d ",p[i]->nome,p[i]->cognome,&(p[i]->matricola),&(p[i]->esame));
    }
    return p;
}

void stampa(nodo**p,int n,int k)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        if(p[i]->esame > k)
        {
            printf("%s %d\n ",p[i]->nome,(p[i]->matricola));
        }
    }
return;
}
