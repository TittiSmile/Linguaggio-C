#include <stdio.h>
#include <stdlib.h>

void inserisci (struct studente *s);
int caricascheda(struct studente *stu);
int cerca(struct studente *stu,int n,char *cognome);
int visualizzamedia(struct studente *stu,int n);


struct studente
{
    char cognome[30];
    short votomax;
    short votomin;
    float media;
    
};

int main()
{
   struct studente stu; 
    inserisci(&stu);
    
    return 0;
}

void inserisci (struct studente *s)
{
    printf("cognome:    ");
    scanf("%s",s->cognome);
    printf("\nvoto piu' alto:    ");
    scanf("%d",&s->votomax);
    printf("\nvoto piu' basso:    ");
    scanf("%d",&s->votomin);
    printf("\nmedia voti:    ");
    scanf("%f",&s->media);
}







