///ci sono alcuni problemini che non so risolvere... non ho neanche continuato lo switch(edit: che cazzo volevi metterci nello switch?)
/// EDIT: ho cercato di migliorare qualcosina

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAX 50
typedef struct LISTA
{
    char *primo;
    struct LISTA *next;
}nodo;

void menu();
nodo*nelem(char *a);
nodo*intesta(nodo*p,char *a);
nodo*incoda(nodo*p,char *a);
nodo*ricerca(nodo*p,char *a);
nodo*elimina(nodo*p);
void dealloca(nodo*p);
void stampa(nodo*p);


int main()
{
    nodo*l=NULL;
    char parola[MAX];
    char scelta;
    int i=0,dim;

    printf("quanto vuoi grande la lista?  ");
    scanf("%d",&dim);

    for(i=0;i<dim;i++)
    {
        printf("inserisci %d parola: ",i+1);
        scanf("%s",parola);
        l=intesta(l,parola);
    }
    stampa(l);

    printf("\nquale stringa vuoi ricercare? ");
    scanf("%s",parola);

    l=ricerca(l,parola);
    if(ricerca(l,parola)==1)
    {
        printf(" trovato ");
    }
    else
    {
        printf(" NON trovato ");
    }

    printf("\nelimino tutta la lista: ");
    l=elimina(l);
    stampa(l);
    if((l)==NULL)
    {
        printf("\nlista vuota!!");
    }

    /*menu();
    do
    {
        do
            {
                 printf("\n\tcosa vuoi fare?\n");
                 scelta=getchar();
            }while(isspace(scelta));
            getchar();

        switch(scelta)
        {
        case 'a':
            printf("\ninserici nome in testa\n");
            scanf("%c",&parola);
            for(i=0;i<strlen(parola);i++)
            {
                l=intesta(l,parola[i]);
            }
           // dealloca(l);
            break;
        case 'b':
            printf("\ninserici nome in coda\n");
            scanf("%c",&parola);
            for(i=0;i<strlen(parola);i++)
            {
                l=incoda(l,parola[i]);
            }
          //  dealloca(l);
            break;
        case 'c':
            break;
        case 'd':
            break;
        case 'e':
            printf("\nstampo le parole\n");
            stampa(l);
            break;
        case 'f':
            printf("\narrivederci\n");
            break;
        default:
            printf("\nscelta non valida\n");
            break;
        }

    }while(scelta!='f');*/



 return 0;
}


void menu()
{
    printf("\na)aggiungi in testa\nb)aggiungi in coda\nc)ricerca parola\nd)elimina\ne)stampa\nf)esci\n");
}

nodo*nelem(char *a)
{
    nodo*q=(struct LISTA*)malloc(sizeof(struct LISTA));
    a=(char*)malloc(sizeof(char));                   ///lo inizializzo dinamicamente perchè non so quanto è grande la stringa
    q->primo=a;
    q->next=NULL;
    return q;
}

nodo*intesta(nodo*p,char *a)
{
    nodo*q=nelem(a);
    q->next=p;
    strcpy(q->primo,a);///IMPORTANTE!!!! così copio il contenuto di a nella in q->primo
    return q;
}

nodo*incoda(nodo*p,char *a)
{
    if(p==NULL)
    {
        p=nelem(a);
        strcpy(p->primo,a);   ///importante!!
    }
    else
    {
        p->next=incoda(p->next,a);
    }
    return p;
}

nodo*ricerca(nodo*p,char *a)
{
  nodo*trovato=NULL;
  for(;p!=NULL && trovato==NULL;p=p->next)
  {
      if(p->primo==a)
      {
          trovato=p;
      }
  }
  return trovato;
}

nodo*elimina(nodo*p)
{
    nodo*tmp=NULL;
    for(;p!=NULL;p=tmp)
    {
        tmp=p->next;
        p->next=NULL;
        free(p);
    }
    return p;
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\nlista: %s \n",p->primo);
        p=p->next;
    }
}


void dealloca(nodo*p)
{
  if(p!=NULL)
  {
      dealloca(p->next);
      p->next=NULL;
      free(p);
  }
}
