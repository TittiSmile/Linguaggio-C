#include <stdio.h>
#include <stdlib.h>
typedef struct STUDENTE
{
    char nome[20];
    char cognome[20];
    int matricola;
    int esami;
    struct STUDENTE*next;
}stud;

stud*inizlista(FILE*pf);  ///sto inizializzando la lista,gli passo le cose nel file
stud*incoda(stud*p,FILE*pf); ///funziona come la incoda normale solo che passa le cose nel file;
stud*leggi(FILE*pf);
void stampa(stud*p,int k);
void stampa2(stud*p);

int main ()
{
    stud*l=NULL;
    FILE*pf;
    int dim,i=0,k;

    l=leggi(pf);
    stampa2(l);
    printf("\ninserisci un numero k:  ");
    scanf("%d",&k);
    stampa(l,k);



    return 0;
}

stud*inizlista(FILE*pf)
{
    stud*p=(stud*)malloc(sizeof(stud));
    fscanf(pf,"%s %s %d %d",p->nome,p->cognome,&p->matricola,&p->esami);
    p->next=NULL;
    return p;
}

stud*incoda(stud*p,FILE*pf)
{
    if(p==NULL)
    {
        p=inizlista(pf);
    }
    else
    {
        p->next=incoda(p->next,pf);
    }
    return p;
}


stud*leggi(FILE*pf)
{
    stud*p=NULL;
    int i=0;
    int nums;
    pf=fopen("a.txt","r");
    if(pf)
    {
        fscanf(pf," %d ",&nums);
        for(i=0;i<nums;i++)
        {
            p=incoda(p,pf);
        }
    }
    else
    {
        printf("errore di apertura");
    }

    fclose(pf);
    return p;
}

void stampa2(stud*p)
{
    while(p!=NULL)
    {
        printf("\n%s %s %d %d",p->nome,p->cognome,p->matricola,p->esami);
        p=p->next;
    }
}


void stampa(stud*p,int k)
{
    while(p!=NULL)
    {
        if(p->esami>k)
        {
            printf("%s %d",p->cognome,p->matricola);
        }
        p=p->next;
    }
}
