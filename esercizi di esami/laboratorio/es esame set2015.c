///la funzione 'eloccprimi' va rivista,non  stampa tutti i numeri primi
#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

///non tutte queste funzioni sono necessarie
void menu();
nodo*nelem(int a);
nodo*intesta(nodo*p,int a);
nodo*incoda(nodo*p,int a);
nodo*ricerca(nodo*p,int a);
nodo*elimina(nodo*p);
int occorrenza(nodo*p,int a);
nodo*elocc(nodo*p,int a);
nodo*eloccprimi(nodo*p);
void stampa(nodo*p);
nodo*reverse(nodo*p);
int somma(nodo*p);


int main ()
{
    nodo*l=NULL;
    int i=0,n,dim,scelta,s;

    menu();
    do
    {
        printf("\n\t\tcosa vuoi fare? ");
        scanf("%d",&scelta);
        switch(scelta)
        {

        case 1:
            printf("\ninserisci un numero in testa: ");
            scanf("%d",&n);
            l=intesta(l,n);
            break;
        case 2:
            printf("\ninserisci un numero in coda:  ");
            scanf("%d",&n);
            l=incoda(l,n);
            break;
        case 3:
            printf("\nquale elemento vuoi ricercare?");
            scanf("%d",&n);
            if(ricerca(l,n))
            {
                printf("\nelemento trovato!");
            }
            else
            {
                printf("\nelemento NON trovato!");
            }
            break;
        case 4:
            printf("\nritono 'vero' se la somma degli elementi e' pari:");
            s=somma(l);
            if(s%2==0)
            {
                printf("\nla somma e' PARI!");
            }
            else
            {
                printf("\nla somma NON e' pari");
            }
            break;
        case 5:
            printf("\ncancello TUTTA la lista");
            l=elimina(l);
            printf("\nlista eliminata");
            break;
        case 6:
            printf("\nstampo la lista: ");
            stampa(l);
            if(l==NULL)
            {
                printf("\nlista VUOTA!");
            }
            break;
        case 7:
            printf("\nriduco la lista a numeri PRIMI: ");
            l=eloccprimi(l);
            break;
        case 8:
            printf("\nstampo la lista al contrario: ");
            l=reverse(l);
            break;
        case 9:
            printf("\narrivederci");
            break;
        default:
            printf("\nscelta errata");
            break;
        }


    }while(scelta!=9);



    return 0;
}

void menu()
{
    printf("1)inserisci in testa\n2)inserisci in coda\n3)ricerca valore\n4)ritorna vero se la somma e' pari\n5)cancella lista");
    printf("\n6)stampa\n7)riduzione a numeri primi\n8)reverse\n9)esci");
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

nodo*ricerca(nodo*p,int a)
{
    nodo*trovato;
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
    nodo*tmp;
    for(;p!=NULL;p=tmp)
    {
        tmp=p->next;
        p->next=NULL;
        free(p);
    }
    return p;
}

int occorrenza(nodo*p,int a)
{
    int flag=0;
    if(p!=NULL)
    {
        if(p->primo==a)
        {
            flag=1+occorrenza(p->next,a);
        }
        else
        {
            flag=occorrenza(p->next,a);
        }
    }
    return flag;
}

nodo*elocc(nodo*p,int a)
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


nodo*eloccprimi(nodo*p)
{
    ///questa mi serve ad eliminare i numeri NON primi ma c'è qualcosa che non va
    nodo*tmp=p;
    if(p!=NULL)
    {
        if(p->primo%2==0 || p->primo%3==0 || p->primo%4==0 || p->primo%5==0 || p->primo%7==0 || p->primo%11==0)
        {
            p=eloccprimi(p->next);
            free(tmp);
        }
        else
        {
            p->next=eloccprimi(p->next);
        }
    }
    return p;

}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("%d->\n",p->primo);
        p=p->next;
    }
}

nodo*reverse(nodo*p)
{
    if(p==NULL)
        return 0;
    reverse(p->next);
    printf("%d->\n",p->primo);
}

int somma(nodo*p)
{
    int s=0;
    if(p==NULL)
    {
        return 0;
    }
    else
    {
        s=somma(p->next);
        s+=p->primo;
        return s;
    }
}
