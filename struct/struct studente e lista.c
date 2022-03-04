#include <stdio.h>
#include <stdlib.h>
#define MAX 20
typedef struct STUDENTE
{
    char cognome[MAX];
    char nome[MAX];
    int matricola;
    int nesami;
    //int voto;
    float *med;
}stud;

typedef struct LISTA
{
    struct STUDENTE *dato;  ///invece di avere il campo 'primo' abbiamo il puntatore alla struct studente
    struct LISTA *next;
}nodo;
/// s è la variabile per la struct studente. p è la variabile per la lista

nodo*crea(nodo*p,stud*s);
nodo*ordine(nodo*p);
nodo*insordine(nodo*p,nodo*tmp);
void stampal(nodo*p);
stud*inizia();
nodo*maggiorik(stud*s,int n,float k); //
float media(stud*s);
void stampas(stud*s,int dim); //



int main ()
{
    nodo*l=NULL;
    stud**s;
    int i,media,dim,n;

    printf("quanti studenti vuoi nell'array? ");
    scanf("%d",&dim);
    s=(struct STUDENTE**)malloc(sizeof(struct STUDENTE)*n);

    for(i=0;i<dim;i++)
    {
        s=inizia();
    }
    printf("ecco l'array:  ");
    stampas(s,dim);



    return 0;
}



nodo*crea(nodo*p,stud*s)
{
    nodo*l=(struct LISTA*)malloc(sizeof(struct LISTA));
    l->dato=s;
    l->next=p;
    return l;
}

nodo*ordine(nodo*p)
{
    nodo*tmp;
    nodo*l=NULL;
    while(p!=NULL)
    {
        tmp=p;
        p=p->next;
        l=insordine(l,tmp);
    }
    return l;
}

nodo*insordine(nodo*p,nodo*tmp)
{
    if(tmp==NULL)
    {
        p->next=tmp;
        tmp=p;
    }
    else
    {
        float mediap=media(p->dato);
        float mediatmp=media(tmp->dato);
        if(mediatmp>mediap)
        {
            p->next=tmp;
            tmp=p;
        }
            else
            {
                tmp->next=insordine(p,tmp->next);
            }
    }

    return tmp;
}

void stampal(nodo*p)
{
    float m;
     if(p!=NULL)
     {
         m=media(p->dato);
         printf("\n%s %s %d %d %d %f \n",p->dato->nome,p->dato->cognome,p->dato->matricola,p->dato->nesami,media);
         p=p->next;
     }
}

stud*inizia()
{
    int i=0;
    struct STUDENTE*tmp=(struct STUDENTE*)malloc(sizeof(struct STUDENTE));

    printf("nome: ");
    scanf("%s",tmp->nome);
    printf("cognome: ");
    scanf("%s",tmp->cognome);
    printf("numero di matricola: ");
    scanf("%d",&tmp->matricola);
    printf("esami sostenuti: ");
    scanf("%d",&tmp->nesami);
    tmp->med=(float*)malloc(sizeof(float)*(tmp->nesami));
    for(i=0;i<(tmp->nesami);i++)
    {
        printf("inserisci il voto per l'esame %d :",i+1);
        scanf("%d",&(tmp->med[i]));
    }
    return tmp;
}

nodo*maggiorik(stud*s,int n,float k)
{
    nodo*p=NULL;
    int i=0;
    float m;
    for(i=0;i<n;i++)
    {
        m=media(s[i]);
        if (m>k)
        {
            p=crea(p,s[i]);
        }
    }
    p=ordine(p);
    return p

}

float media(stud*s)
{
    float m=0;
    int i=0;
    for(i=0;i<(s->nesami);i++)
    {
        m+=(s->med[i]);
        m=m/(s->nesami);
    }
    return m;
}

void stampas(stud*s,int dim)
{
    int i=0;
    float m;
    for(i=0;i<dim;i++)
    {
        m=media(s[i]);
        printf("%s %s %d %d %f",s[i]->nome,s[i]->cognome,s[i]->matricola,s[i]->nesami,media);
    }

}

