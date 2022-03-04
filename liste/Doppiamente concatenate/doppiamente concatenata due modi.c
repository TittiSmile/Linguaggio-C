///funzione che ritorna la doppiamente concatenata da una semplice
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
    struct LISTA_DOPPIA*next;
    struct LISTA_DOPPIA*prev;
}doppia;

nodo*nelem(int a);
nodo*intesta(nodo*p,int a);
nodo*incoda(nodo*p,int a);
void stampa(nodo*p);
///QUESTO è IL METODO CHE USO SEMPRE
doppia*nelem2(nodo*p,doppia*d);
doppia*ritornad(nodo*p);
void stampa_doppia(doppia*d);
///QUESTO è IL METODO ALTERNATIVO CHE VOGLIO PROVARE
doppia*crea_doppia_list(int a);
doppia*InTestaDoppia(doppia*d,int a);
doppia*ritDoppia(nodo*p,doppia*d);

int main ()
{
    nodo*l1=NULL;
    doppia*d1=NULL;

    l1=incoda(l1,4);l1=incoda(l1,2);l1=incoda(l1,7);l1=incoda(l1,12);
    stampa(l1);

    printf("\nritorno doppiamente concatenata:  ");
    d1=ritDoppia(l1,d1);
    stampa_doppia(d1);

    return 0;
}


nodo*nelem(int a)
{
    nodo*q=(nodo*)malloc(sizeof(nodo));
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
        printf("\n%d->",p->primo);
        p=p->next;
    }
    printf("  NULL");
}



///QUESTO è IL METODO CHE USO SEMPRE (ricorsivo)
doppia*nelem2(nodo*p,doppia*d)
{
    doppia*flag=(doppia*)malloc(sizeof(doppia));
    flag->prev=NULL;
    flag->primo=p->primo;
    flag->next=d;
    return flag;
}

doppia*ritornad(nodo*p)
{
    doppia*tmp2=NULL;
    if(p!=NULL)
    {
        tmp2=ritornad(p->next);
        tmp2=nelem2(p,tmp2);
        if(p->next!=NULL)
        {
            tmp2->next->prev=tmp2;
        }
    }
    return tmp2;
}

void stampa_doppia(doppia*d)
{
    printf("\nNULL");
    while(d!=NULL)
    {
        printf("\n<->%d<->",d->primo);
        d=d->next;
    }
    printf("\nNULL");
}

///QUESTO è IL METODO ALTERNATIVO CHE VOGLIO PROVARE(iterativo)
doppia*crea_doppia_list(int a)
{
    doppia*dob=(doppia*)malloc(sizeof(doppia));
    dob->prev=NULL;
    dob->primo=a;
    dob->next=NULL;
    return dob;
}

doppia*InTestaDoppia(doppia*d,int a)
{
    doppia*tmp2=crea_doppia_list(a);
    if(d!=NULL)
    {
        tmp2->next=d;
        d->prev=tmp2;
    }
    d=tmp2;
    return d;
}

doppia*ritDoppia(nodo*p,doppia*d)
{
    nodo*tmp=p;
    if(p!=NULL)
    {
        d=ritDoppia(tmp->next,d);
        d=InTestaDoppia(d,tmp->primo);
    }
    return d;
}

