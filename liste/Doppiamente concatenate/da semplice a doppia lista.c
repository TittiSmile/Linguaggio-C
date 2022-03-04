/*Creare, ricorsivamente, una lista doppiamente concatenata a partire da una semplicemente concatenata.
Dimostrare con il principio di induzione la correttezza della funzione e blablabla...*/
#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

typedef struct LISTA_DOPPIA
{
    int primo;
    struct LISTA_DOPPIA *prev;
    struct LISTA_DOPPIA *next;
}doppia;

///per la semplicemente concatenata
nodo*nelem(int a);
nodo*intesta(nodo*p,int a);
nodo*incoda(nodo*p,int a);
void stampa(nodo*p);
///per la doppiamente concatenata
doppia*nelem2(doppia*a,nodo*p);      ///questa funzione è diversa da come si fa normalmente(prende due parametri)perchè deve passare due valori
///la funzione incoda2 non ci serve. abbiamo una lista a cazzo da far ritornare doppia (ed è anche ricorsiva)
doppia*ritorna(nodo*p);
void stampa2(doppia*d2);



int main ()
{
    int dim,num,i=0;
    nodo*l=NULL;
    doppia*d=NULL;

    printf("quanto vuoi grande la tua lista? ");
    scanf("%d",&dim);

    printf("inserisci elementi nella lista:\n");
    for(i=0;i<dim;i++)
    {
        printf("elemento %d:   ",i+1);
        scanf("%d",&num);
        l=incoda(l,num);
    }
    printf("\nla lista e':   ");
    stampa(l);

    printf("\nritorno la lista doppiamente concatenata: ");
    d=ritorna(l);
    stampa2(d);



    return 0;
}


nodo*nelem(int a)
{
    nodo*q=(struct LISTA*)malloc(sizeof(struct LISTA));
    q->primo=a;
    q->next=NULL;
    return q;
}

nodo*intesta(nodo*p,int a)
{
    nodo*q=nelem(a);
    q->next=p;
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

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d ",p->primo);
        p=p->next;
    }
}


doppia*nelem2(doppia*a,nodo*p)
{
    doppia*flag=(struct LISTA_DOPPIA*)malloc(sizeof(struct LISTA_DOPPIA));
    flag->next=a;
    flag->prev=NULL;
    flag->primo=p->primo;
    return flag;
}

doppia*ritorna(nodo*p)
{
    doppia*var=NULL;
    if(p!=NULL)
    {
        var=ritorna(p->next);
        var= nelem2(var,p);
        if(p->next!=NULL)
        {
            var->next->prev=var;
        }
    }
    return var;
}

void stampa2(doppia*d2)
{
    while(d2!=NULL)
    {
        printf("\n%d ",d2->primo);
        d2=d2->next;
    }
}


