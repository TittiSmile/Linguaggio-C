/* data una lista L di interi:
1) una funzione che popoli la lista con 50 caratteri ASCII casuali (prenderò solo lettere) N.B. se volessi anche caratteri 'speciali' mi basterebbe mettere %50+'a' (comprende 50 caratteri ascii a partire da 'a')
2) Una funzione che calcoli quanti caratteri sono compresi tra a e z
3) una funzione che,letto un intero c da tastiera, conti il numero di occorrenze di c in L e crei una nuova lista l1 che contiene
   tutti i caratteri tranne c
   N.B. questo esame già l'ho fatto!!! l'unica cosa che aggiungo sono i file...*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct LISTA
{
    char primo;  ///non metto char*primo perchè NON è una stringa. ma semplici caratteri
    struct LISTA*next;
}nodo;

nodo*nelem(char a);
nodo*intesta(nodo*p,char a);
nodo*incoda(nodo*p,char a);
nodo*elocc(nodo*p,char a);
nodo*casuale(nodo*p,int dim);
void stampa(nodo*p);
///
nodo*leggi(FILE*pf);
nodo*scrivi(FILE*pf,int dim);
nodo*modifica(FILE*pf,nodo*p);
int lenfile(FILE*pf);


int main ()
{
    nodo*l=NULL;
    FILE*pf;
    int dim,i=0;
    char a;

    printf("grandezza lista?   ");
    scanf("%d",&dim);

    //l=casuale(l,dim);    ///avrei anche potuto usare questa funzione e,più avanti,fare l=modifica(pf,l);
    l=scrivi(pf,dim);   ///così facendo,scrivo direttamente sul file e popolo anche la lista
    stampa(l);

    fflush(stdin);///serve a svuotare la cache di scanf
    printf("\nquale carattere vuoi eliminare?  ");
    scanf("%c",&a);
    l=elocc(l,a);

    printf("\nmodifico la lista e leggo cio' che c'e' dentro!");
    l=modifica(pf,l);
    l=leggi(pf);
    stampa(l);

    printf("\ngli elementi nel file sono:  %d",lenfile(pf));


    return 0;
}

nodo*nelem(char a)
{
    nodo*q=(nodo*)malloc(sizeof(nodo));
    q->primo=a;
    q->next=NULL;
    return q;
}

nodo*intesta(nodo*p,char a)
{
    nodo*q=nelem(a);
    q->next=p;
    return q;
}

nodo*incoda(nodo*p,char a)
{
    if(p==NULL)
    {
        p=nelem(a);
    }
    else
    {
        p->next=incoda(p->next,a);
    }
    return p;
}

nodo*elocc(nodo*p,char a)
{
    nodo*tmp=p;
    if(p!=NULL)
    {
        if(p->primo==a)
        {
            p=elocc(p->next,a);
            free(tmp);
        }
        else
        {
            p->next=elocc(p->next,a);
        }
    }
    return p;
}

nodo*casuale(nodo*p,int dim)
{
  int i=0;
  char a=0;
  srand((unsigned)time(NULL));
  for(i=0;i<dim;i++)
  {
      a=rand()%25+'a'; ///serve per i caratteri dell'alfabeto da a-z (minuscoli)
      p=incoda(p,a);
  }
  return p;
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%c->",p->primo);
        p=p->next;
    }
}

///
nodo*leggi(FILE*pf)
{
    nodo*p=NULL;
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    pf=fopen("file lista caratteri.txt","r");
    if(pf)
    {
        while(!feof(pf))
        {
            fscanf(pf," %c ",&tmp->primo);
            p=incoda(p,tmp->primo);
        }
    }
    else
    {
        printf("errore di apertura");
    }

    fclose(pf);
    return p;
}

nodo*scrivi(FILE*pf,int dim)
{
    int i=0;
    nodo*p=NULL;
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    pf=fopen("file lista caratteri.txt","w");
    if(pf)
    {
        ///per inserimento manuale
        /*for(i=0;i<dim;i++)
        {
            printf("inserisci elemento: ");
            scanf("%c",&tmp->primo);
            fprintf(pf," %c ",tmp->primo);
            p=incoda(p,tmp->primo);
        }*/
        ///HO LA FUNZIONE CASUALE!!!
        srand((unsigned)time(NULL));
         for(i=0;i<dim;i++)
        {
            tmp->primo=rand()%25+'a';
            fprintf(pf," %c ",tmp->primo);
            p=incoda(p,tmp->primo);
        }

    }
    else
    {
        printf("errore di apertura");
    }

    fclose(pf);
    return p;
}
nodo*modifica(FILE*pf,nodo*p)
{
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    pf=fopen("file lista caratteri.txt","w");
    if(pf)
    {
        while(p!=NULL)
        {
            fprintf(pf," %c ",p->primo);
            p=p->next;
        }
    }
    else
    {
        printf("errore di apertura");
    }

    fclose(pf);
    return p;
}

int lenfile(FILE*pf)
{
    int cont=0;
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    pf=fopen("file lista caratteri.txt","r");
    if(pf)
    {
        while(fscanf(pf," %c ",&tmp->primo)==1)
        {
            cont++;
        }
    }
    else
    {
        printf("errore di apertura");
    }

    fclose(pf);
    return cont;
}


