#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct LISTA
{
    char *stringa;
    struct LISTA*next;
}nodo;

nodo*nelem(char *a);
nodo*incoda(nodo*p,char *a);
void stampa(nodo*p);
void copia(char *a,char*s);

int main ()
{
    nodo*l=NULL;
    char s[25];
    int dim,n,i=0;

    printf("quante parole?:  ");
    scanf("%d",&dim);

    for(i=0;i<dim;i++)
    {
        printf("inserisci %d parola:  ",i+1);
        scanf("%s",s);
        l=incoda(l,s);
    }

    stampa(l);

    return 0;
}

nodo*nelem(char *a)
{
    nodo*q=(struct LISTA*)malloc(sizeof(struct LISTA));
    a=(char*)malloc(sizeof(char));
    q->stringa=a;
   // copia(q->stringa,a);
    //strcpy(q->stringa,a);    posso fare a meno di queste due funzioni
    q->next=NULL;
    return q;
}

nodo*incoda(nodo*p,char *a)
{
    if(p==NULL)
    {
        p=nelem(a);
        copia(p->stringa,a);
        ///posso usare anche la funzione strcpy(p->stringa,a);
    }
    else
    {
        p->next=incoda(p->next,a);
    }
    return p;
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("%s-> \n",p->stringa);
        p=p->next;
    }
}

void copia(char *a,char*s)
{
   int i=0;
    while(s[i]!= '\0')
    {
        a[i]=s[i];
        i++;
    }
    a[i]='\0';
}
