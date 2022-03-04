///13/7/16    RIVEDERE E COMPLETARE
#include <stdio.h>
#include <stdlib.h>
#define max 20
typedef struct STUDENTE
{
    char nome[max];
    char cognome[max];
    int matricola;
    int esami;
    float *voto;
}stud;

typedef struct LISTA
{
    int *primo;
    struct LISTA*next;
}nodo;

stud*inizia();
nodo*crea(nodo*p,stud*s); ///visto che è sia una lista che una struct,la funzione crea è leggermente diversa
nodo*ordina(nodo*p,nodo*tmp);
nodo*crescente(nodo*p);
float media(stud*s);
nodo*maggiorik(stud**s,int k,int n);
void stampa(nodo*p);
void stampa_stud(stud**s,int n);



int main ()
{



    return 0;
}


stud*inizia()
{
    int i=0;
    stud*s=(struct STUDENTE*)malloc(sizeof(struct STUDENTE));
    s->voto=(float*)malloc(sizeof(float)*(s->esami));
    printf("digitare il cognome:  ");
    scanf("%s",s->cognome);
    printf("digitare il nome:  ");
    scanf("%s",s->nome);
    printf("digitare la matricola:  ");
    scanf("%d",&s->matricola);
    printf("digitare il numero di esami sostenuti:  ");
    scanf("%d",&s->esami);
    for(i=0;i<(s->esami);i++)
    {
        printf("inserire il voto dell'esame %d:  ",i+1);
        scanf("%f",&(s->voto[i]));
    }
    return s;
}

nodo*crea(nodo*p,stud*s)
{
     nodo*tmp=(struct LISTA*)malloc(sizeof(struct LISTA));
     tmp->primo=s;                                                 ///
     tmp->next=p;
     return tmp;
}

nodo*ordina(nodo*p,nodo*tmp)
{
    if(p==NULL || tmp->primo > tmp->next)
    {
        tmp->next=p;
        p=tmp;
    }
    else
    {
        p->next=ordina(p->next,tmp);
    }
    return p;
}

nodo*crescente(nodo*p)
{
    nodo*tmp;
    nodo*l=NULL;
    while(p!=tmp)
    {
        tmp=p;
        p=p->next;
        l=ordina(l,tmp);
    }
    return l;
}

float media(stud*s);
nodo*maggiorik(stud**s,int k,int n);
void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d  ",p->primo);
        p=p->next;
    }
}

void stampa_stud(stud**s,int n);
