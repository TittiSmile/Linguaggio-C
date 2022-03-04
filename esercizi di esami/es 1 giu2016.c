#include <stdio.h>
#include <stdlib.h>
#define max 15
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

typedef struct STUDENTE
{
    char nome[max];
    char cognome[max];
    int matricola;
    int esami;
}stud;


stud**leggifile(FILE*pf,stud**s,int n);
void stampa(stud**s,int n,int k);

int main()
{
    FILE*pf;
    int i=0,k,n;

    pf=fopen("lista.txt","r");
    if(pf==NULL)
    {
        printf("errore di apertura.");
    }
    else
    {
        fscanf(pf,"%d",&n);
        stud**s=(struct STUDENTE**)malloc(sizeof(struct STUDENTE)*n);
        s=leggifile(pf,s,n);
        printf("\ninserisci un numero k: ");
        scanf("%d",&k);
        stampa(s,n,k);
    }

    fclose(pf);




    return 0;
}

stud**leggifile(FILE*pf,stud**s,int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        s[i]=(struct STUDENTE*)malloc(sizeof(struct STUDENTE));
        fscanf(pf,"%s %s %d %d",s[i]->nome,s[i]->cognome,&s[i]->matricola,&s[i]->esami);
    }
    return s;

}

void stampa(stud**s,int n,int k)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        if(s[i]->esami > k)
        {
            printf("%s %d\n",s[i]->cognome,(s[i]->matricola));
        }
    }
}


