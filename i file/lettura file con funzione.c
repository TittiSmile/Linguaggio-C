#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
nodo*leggi(FILE*pf);
void stampa(nodo*p);


int main ()
{
    FILE*pf;
    nodo*l=NULL;

    pf=fopen("a.txt","r");
    if(pf)
    {
        printf("leggo il file:  \n");
        l=leggi(pf);
        stampa(l);
    }
    else
    {
        printf("errore di apertura");
    }

    fclose(pf);


    return 0;
}



nodo*nelem(int a)
{
    nodo*q=(nodo*)malloc(sizeof(nodo));
    q->primo=a;
    q->next=NULL;
    return q;
}

nodo*incoda(nodo*p,int a)
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

nodo*leggi(FILE*pf)
{
    nodo*p=NULL, *tmp;
    while (!feof(pf))
       {
       tmp=(nodo *)malloc(sizeof(nodo));
       fscanf(pf,"%d", &tmp->primo);
       p=incoda(p,tmp->primo);
       }
     return p;
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d ->",p->primo);
        p=p->next;
    }
}


