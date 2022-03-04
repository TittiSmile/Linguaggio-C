/* ESAME DEL 13 LUGLIO 2016
si supponga di avere un vettore V con le informazioni di n studenti. per ogni studente si hanno dati su nome,cognome,matricola
e votI ottenuti.scrivere una funzione 'maggioridik' che prenda come argomenti il vettore V e il numero n di studenti
 ed un intero k. la funzione 'maggioridik' deve fornire in uscita una lista L di puntatori agli studenti di V con media
 maggiore di k. il campo 'dato' (nel mio caso 'primo') deve essere un puntatore ad un elemento del vettore v. la lista
 deve essere in ordine crescente rispetto alla media. */
///c'è un problema con la funzione maggioridik

#include <stdio.h>
#include <stdlib.h>
#define max 20
typedef struct STUDENTE
{
    char nome[max];
    char cognome[max];
    int matricola;
    int voto;
    float *m;
}stud;

typedef struct LISTA
{
    /*  non so che ho scritto. bho!
    ///struct STUDENTE*primo    si potrebbe usare direttamente il puntatore a struct
    char nome[max];
    char cognome[max];
    int matricola;
    int voto;
    struct LISTA*next;*/
    stud*primo;              //è il puntatore alla struct
    struct LISTA*next;
}nodo;

nodo*nelem(nodo*p,stud*v);
stud*inizia();
nodo*ordina(nodo*p,nodo*tmp);
nodo*crescente(nodo*p);
nodo*maggioridik(stud**v,int n,float k);
float calmedia(stud*v);
void*stampa(nodo*p);
void*stampas(stud*v,int n);



int main ()
{



    return 0;
}



nodo*nelem(nodo*p,stud*v)
{
    nodo*tmp=(struct LISTA*)malloc(sizeof(struct LISTA));
    tmp->primo=v;
    tmp->next=p;
    return tmp;

}

stud*inizia()
{
    int i=0;
    stud*tmp=(struct STUDENTE*)malloc(sizeof(struct STUDENTE));
    printf("digitare il cognome: ");
    scanf("%s",tmp->cognome);
    printf("digitare il nome: ");
    scanf("%s",tmp->nome);
    printf("digitare la matricola: ");
    printf("%d",&(tmp->matricola));
    printf("digitare il numero di esami sostenuti: ");
    scanf("%d",&(tmp->voto));
    tmp->m=(float*)malloc(sizeof(float)*(tmp->voto));
    for(i=0;i<tmp->voto;i++)
    {
        printf("digitare il voto per l'esame %d: ",i+1);
        scanf("%d",&(tmp->m));
    }
    return tmp;
}

nodo*ordina(nodo*p,nodo*tmp)
{                                                   ///
    if(p==NULL || p->primo > tmp->primo)
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

nodo*crescente(nodo*p)             ///richiama la funzione ordina
{
    nodo*tmp;
    nodo*l=NULL;
    while(p!=NULL)
    {
        tmp=p;
        p=p->next;
        l=ordina(l,tmp);
    }
    return l;
}
nodo*maggioridik(stud**v,int n,float k)
{
    nodo *l=NULL;
    int i;
    float media;
    for(i=0;i<n;i++){
        media=calmedia(v);
        if(media>k)
            l=nelem(l,v);
        }
    l=crescente(l);

    return l;

}

float calmedia(stud*v)
{
    /*int i=0;
    float ris=0;
    for(i=0;i<v->voto;i++)
    {
        ris=ris+(v->m);
    }
    return ris;*/
    float res=0;
    int i;
    for(i=0;i<(v->voto);i++)
        res=res+(v->m);
    res=res/(v->voto);
    return res;
}

void*stampa(nodo*p)
{
    float med;
    while(p!=NULL)
    {
        med=calmedia(p->primo);
        printf("\n %s %s %d %d  %f \n ",p->primo->nome,p->primo->cognome,p->primo->matricola,p->primo->voto,med);
        p=p->next;
    }
}

void*stampas(stud*v,int n)
{
    int i=0;
    float med;
    for(i=0;i<n;i++)
    {
        med=calmedia(v);
        printf("%s %s %d %d %.2f\n", v->nome,v->cognome,v->matricola,v->voto,med);
    }
}
