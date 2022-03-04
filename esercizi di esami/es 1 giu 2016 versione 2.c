#include <stdio.h>
#include <stdlib.h>
typedef struct STUDENTE
{
    char nome[20];
    char cognome[20];
    int esame;
    int matricola;
}stud;

stud**leggi(FILE*pf,stud**s,int n);
void stampa(stud**s,int n,int k);

int main ()
{
    FILE*pf;
    int k,i=0,n;
    stud**s;


    pf=fopen("a.txt","r");
    if(pf)
    {
        fscanf(pf," %d ",&n);
        stud**s=(stud**)malloc(sizeof(stud)*n);
        leggi(pf,s,n);
        printf("\ninserisci un numero k:  ");
        scanf("%d",&k);
        stampa(s,n,k);
    }
    else
    {
        printf("errore di apertura");
    }

    fclose(pf);




    return 0;
}

stud**leggi(FILE*pf,stud**s,int n)
{
    int i=0;
    pf=fopen("a.txt","r");
    if(pf)
    {
        fscanf(pf," %d ",&n);
        for(i=0;i<n;i++)
        {
            s[i]=(stud*)malloc(sizeof(stud)*n);
            fscanf(pf," %s %s %d %d ",s[i]->nome,s[i]->cognome,&s[i]->matricola,&s[i]->esame);
        }
    }
    else
    {
        printf("errore di apertura");
    }

    fclose(pf);
    return s;
}

void stampa(stud**s,int n,int k)
{
    int i=0;
        for(i=0;i<n;i++)
        {
            if(s[i]->esame>k)
            {
                printf("\n%s %s %d %d",s[i]->nome,s[i]->cognome,s[i]->matricola,s[i]->esame);
            }
        }
}

