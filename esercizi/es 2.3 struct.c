#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define maxlen 100
#define maxstr 20
struct studente
{
    char cognome[maxstr];
    int votomin;
    int votomax;
    float media;
};

void menu();
struct studente *riempi();
int carica (struct studente **s);
int cerca (struct studente **s,int n,char *cognome);
void stampa(struct studente **s,int n);
//void stampa(struct studente *s);
int cercamedia(struct studente **s,int n);
void media(struct studente **s,int n);


int main ()
{

    struct studente *dati[maxlen];
    char cognome[maxstr];
    int n=0;
    int i=0;
    int scelta;
    n=carica(dati);

    do
    {
        menu();
        printf("\ncosa scegli? ");
        scanf("%d",&scelta);
        switch(scelta)
        {
        case 1:
            printf("\nvisualizza i dati inseriti:\n");
             stampa(dati,n);
            //stampa(dati);
            break;
        case 2:
            printf("\ndigitare il cognome dello studente da cercare:   ");
            scanf("%s",cognome);
            i=cerca(dati,n,cognome);
            if(i==-1)
            {
                printf("\n non trovato\n");
            }
            else
            {
                printf("\n trovato\n");
            }
            break;
        case 3:
            printf("\nvisualizzo lo studente con la media maggiore\n");
            media(dati,n);
            break;
        case 4:
            printf("\narrivederci");
            break;
        default:
            printf("\nscelta errata");
            break;
        }


    }while(scelta!=4);





    return 0;
}


void menu()
{
    printf("1)visualizza dati(stampa)\n2)cerca uno studente per il cognome e visualizzalo\n3)visualizza lo studente con la media più alta\n4)esci");

}

struct studente *riempi()
{
 struct studente*s=(struct studente*)malloc(sizeof(struct studente*));
 printf("cognome:  ");
 scanf("%s",s->cognome);
 printf("voto minimo: ");
 scanf("%d",&s->votomin);
 printf("voto massimo: ");
 scanf("%d",&s->votomax);
 printf("media voti:  ");
 scanf("%f",&s->media);
return s;
}

int carica (struct studente **s)
{
    int n=0;
    int i=0;
    for(i=0;i<maxlen;i++)
    {
        s[i]=NULL;
    }
    do
    {
        printf("\nquante schede vuoi inserire?");
        scanf("%d",&n);
    }while(n>maxlen);
    for(i=0;i<n;i++)
    {
        s[i]=riempi();
    }
    return n;
}

int cerca (struct studente **s,int n,char *cognome)
{
    int i=0;
    int trovato=-1;
    while(i<n && trovato==-1)
    {
        if(strcmp(s[i]->cognome,cognome)==0)
        {
            trovato=i;
        }
        i++;
    }
    return trovato;
}

void stampa(struct studente **s,int n)
{
     int i=0;
    for(i=0;i<n;i++)
    {
    printf("scheda %d:\ncognome: %s\nvoto più alto: %d\nvoto più basso:%d \nmedia:%f \n",i+1,s[i]->cognome,s[i]->votomax,s[i]->votomin,s[i]->media);

    }
}
/*void stampaStudente(struct studente * s){
    printf("< COGNOME        : %s\n",s->cognome);
    printf("< VOTO PIU' BASSO: %2d\n",s->votomin);
    printf("< VOTO PIU' ALTO : %2d\n",s->votomax);
    printf("< MEDIA          : %2d\n",s->media);
    return;
}*/

int cercamedia(struct studente **s,int n)
{
    int i;
    int temp;
    int mediamax=-1;
    for(i=0;i<n;i++)
    {
        if(s[i]->media>mediamax)
        {
          mediamax=s[i]->media;
          temp=i;
        }
    }
    return temp;
}
void media(struct studente **s,int n)
{
    int i;
    i=cercamedia(s,n);
    printf("\nstampo la media più alta:  ");
    stampa(s[i],n);
}
