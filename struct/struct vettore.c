#include <stdio.h>
#include <string.h>
#define maxlen 100
#define maxstr 20
typedef struct scheda
{
    char nome[maxstr];
    char cognome[maxstr];
    int anni;
}schedario;


void menu();
void riempi(struct scheda *s);
int carica (struct scheda *s);
int cerca (struct scheda *s,int n,char *cognome);
int elimina (struct scheda *s,int n,int i);
int aggiungi(struct scheda *s,int n);
void stampa(struct scheda *s,int n);

int main ()
{
char cognome[maxstr];
struct scheda modulo[maxlen];
int scelta;
int n=0;
int i=0;
n=carica(modulo);

menu();
do
{
    printf("cosa scegli?\n");
    scanf("%d",&scelta);
    switch(scelta)
    {
    case 1:
        printf("\naggiungi elemento: ");
        aggiungi(modulo,n);
        break;
    case 2:
        printf("\nquale cognome vuoi eliminare? ");
        scanf("%s",cognome);
        i=cerca(modulo,n,cognome);
        if(i>=0)
        {
            n=elimina(modulo,n,i);
        }
        break;
    case 3:
        printf("\nstampo: \n");
        stampa(modulo,n);
        break;
    case 4:
        printf("\nquale elemento vuoi ricercare? ");
        scanf("%s",cognome);
        if(cerca(modulo,n,cognome))
        {
            printf("\nelemento trovato\n");
        }
        else
        {
            printf("\nelemento NON trovato\n");
        }
        break;
    case 5:
        printf("\narrivederci");
        break;
    default:
        printf("\nscelta non valida");
        break;
    }
}while(scelta!=5);

    return 0;
}


void menu()
{
    printf("1)aggiungi elemento\n2)elimina elemento\n3)stampa\n4)cerca\n5)esci\n");
}

void riempi(struct scheda *s)
{
    printf("Nome: ");
    scanf("%s",s->nome);
    printf("Cognome: ");
    scanf("%s",s->cognome);
    printf("Anni: ");
    scanf("%d",&s->anni);
}

int carica (struct scheda *s)
{
    int n=0;
    int i=0;
    do
    {
      printf("\nquante schede vuoi inserire?  ");
      scanf("%d",&n);
    }while(n>maxlen);
    for(i=0;i<n;i++)
        {
            riempi(&s[i]);
        }
        return n;
}

int cerca (struct scheda *s,int n,char *cognome)
{
    int i=0;
    int trovato=-1;
    while(i<n && trovato==-1)
    {
        if(strcmp(s[i].cognome,cognome)==0)
        {
            trovato=i;
        }
    }
    return trovato;
}

int elimina (struct scheda *s,int n,int i)
{
    int j=0;
    for(j=i;(j+1)<n;j++)
            s[j]=s[j+1];

    return n-1;
}


int aggiungi(struct scheda *s,int n)
{
    if(n<maxlen)
    {
        riempi(&s[n]);
        n++;
    }
    return n;
}

void stampa(struct scheda *s,int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("\nscheda[%d]:\nnome:%s\ncognome:%s\nanni:%d\n",i+1,s[i].nome,s[i].cognome,s[i].anni);
    }

}
