#include <stdio.h>
#include <stdlib.h>
#define max 20
typedef struct LISTA
{
    int *primo;
    struct LISTA*next;
}nodo;

typedef struct STUDENTE
{
    nome[max];
    cognome[max];
    int voto;
    int esame;
    float *media;
}stud;

nodo*crea(nodo*p,stud *s);
float media(stud*media);
struct maggiorik(stud**v,int k,int n);
void stampa(nodo*p);
stud*inizia();


int main ()
{





    return 0;
}

nodo*crea(nodo*p,stud *s);
float media(stud*media);
struct maggiorik(stud**v,int k,int n);
void stampa(nodo*p);
stud*inizia()
{
    stud*tmp(struct STUDENTE*)malloc(sizeof(struct STUDENTE));
    tmp->media=(float*)malloc(sizeof(float)*(tmp->esame));
    printf("inserisci nome: ");
    scanf("%s",tmp->nome);
    printf("inserisci cognome: ");
    scanf("%s",tmp->cognome);
    printf("inserisci matricola: ");
    scanf("%d",&tmp->matricola);
    printf("inserisci esami: ");
    scanf("%d",&tmp->esame);



}

