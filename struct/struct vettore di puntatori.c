#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define maxlen 100
#define maxstr 20
typedef struct scheda
{
    char nome[maxstr];
    char cognome[maxstr];
    int anni;
}schedario;


void menu();
struct scheda*riempi();
int carica (struct scheda **s);
int cerca(struct scheda **s,int n,char *cognome);
int elimina(struct scheda **s,int n,int i);
int aggiungi (struct scheda **s,int n);
void stampa(struct scheda**s,int n);


int main ()
{
    struct scheda *modulo[maxlen];
    int n=0;
    int i=0;
    int scelta;
    char cognome[maxstr];
    n=carica(modulo);

    do
    {
        menu();
        printf("\ncosa scegli?  ");
        scanf("%d",&scelta);
        switch(scelta)
        {
        case 1:
            printf("\naggiungi scheda:\n");
            aggiungi(modulo,n);
            break;
        case 2:
            printf("\nelimina cognome:\n");
            scanf("%s",cognome);
            i=cerca(modulo,n,cognome);
            if(i>=0)
            {
                n=elimina(modulo,n,i);
            }
            break;
        case 3:
            printf("\nstampa\n");
            stampa(modulo,n);
            break;
        case 4:
            printf("\nche cognome vuoi cercare?\n");
            scanf("%s",cognome);
            if(cerca(modulo,n,cognome))
            {
                printf("\nelemento trovato\n");
            }
            else
            {
                printf("\nelemento non trovato\n");
            }
            break;
        case 5:
            printf("\narrivederci\n");
            break;
        default:
            printf("\nscelta errata\n");
            break;
        }
    }while(scelta!=5);
    return 0;
}



void menu()
{
    printf("1)aggiungi elemento\n2)elimina elemento\n3)stampa\n4)cerca\n5)esci\n");
}

struct scheda*riempi()
{
 struct scheda*s=(struct scheda*)malloc(sizeof(struct scheda*));
 printf("Nome: ");
 scanf("%s",s->nome);
 printf("Cognome: ");
 scanf("%s",s->cognome);
 printf("Anni: ");
 scanf("%d",&(s->anni));
}

int carica (struct scheda **s)
{
    int i;
    int n=0;

    for(i=0;i<maxlen;i++)
    {
        s[i]=NULL;
    }
    do
    {
        printf("\nQuante schede vuoi inserire?  ");
        scanf("%d",&n);
    }while(n>maxlen);
    for(i=0;i<n;i++)
    {
        s[i]=riempi();
    }
    return n;
}

int cerca(struct scheda **s,int n,char *cognome)
{
    int i=0;
    int trovato=-1;
    while(i<n && trovato==0)      ///andrebbe bene anche un ciclo for: for(i=0;i<n && trovato==0;i++)
    {
        if(strcmp(s[i]->cognome,cognome)==0)
        {
            trovato=i;
        }
        i++;
    }
    return trovato;
}

int elimina(struct scheda **s,int n,int i)
{
    int j=0;
    free(s[i]);
    for(j=i;(j+1)<n;j++)
    {
        s[j]=s[j+1];
    }
    s[n]=NULL;
    return n-1;
}

int aggiungi (struct scheda **s,int n)
{
    if(n<maxlen)
    {
        s[n]=riempi();
         n++;
    }
    return n;
}

void stampa(struct scheda **s,int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("\nscheda %d:\nnome: %s\ncognome: %s\nanni: %d\n",i+1,s[i]->nome,s[i]->cognome,s[i]->anni);
    }
}

