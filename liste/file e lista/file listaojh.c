#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*intesta(nodo*p,int a);
nodo*incoda(nodo*p,int a);
nodo*ricerca(nodo*p,int a);
nodo*elimina(nodo*p);
int occorrenza(nodo*p,int a);
nodo*elocc(nodo*p,int a);
void stampa(nodo*p);
nodo*reverse(nodo*p);
int somma(nodo*p);
///
nodo*ordina(nodo*p,nodo*tmp);
nodo*crescente(nodo*p);
nodo*insordine(nodo*p,int a);
///
nodo*elmaggiorik(nodo*p,int k);
nodo*listak(nodo*p,int k);
///
int max(nodo*p);   ///non ritorna un puntatore ma un numero,il massimo della lista
int min(nodo*p);   ///non ritorna un puntatore ma un numero,il minimo della lista
nodo*elpari(nodo*p);   ///elimina i pari in posizione dispari
nodo*duplica(nodo*p,int a);
nodo*casuale(nodo*p,int dim);
nodo*multiplo(nodo*p); ///ritorna tutti i multipli (in questo caso 3 ma basta cambiare il numero della condizione)
float media(nodo*p,int dim);
///
nodo*leggi(FILE*pf);
nodo*scrivi(FILE*pf,int dim);
nodo*modifica(FILE*pf,nodo*p);
int lenfile(FILE*pf);        ///conta quanti elementi ci sono nel file



int main ()
{
    nodo*l=NULL;
    nodo*l2=NULL;
    int dim,i=0,n,k;
    FILE*pf;

    printf("numero elementi? ");
    scanf("%d",&dim);

    /*for(i=0;i<dim;i++)
    {
        printf("inserisci numeri:  ");
        scanf("%d",&n);
        l=incoda(l,n);
    }
    stampa(l);

    printf("\n*****\n\nquale elemento ricercare?  ");
    scanf("%d",&n);
    if(ricerca(l,n))
       {
           printf("elemento trovato");
       }
    else
    {
        printf("elemento NON trovato");
    }
    printf("\nquale occorrenza vuoi contare? ");
    scanf("%d",&n);
    printf("\nle occorrenze di %d sono:%d ",n,occorrenza(l,n));
    printf("\nquale elemento eliminare?  ");
    scanf("%d",&n);
    l=elocc(l,n);
    stampa(l);
    printf("\nla somma degli elementi e': %d",somma(l));
    printf("\nelimino la lista");
    l=elimina(l);*/

    /*for(i=0;i<dim;i++)
    {
        printf("inserisci numeri:  ");
        scanf("%d",&n);
        l=incoda(l,n);
    }
    stampa(l);

    printf("\nrdine crescente:  ");
    l=crescente(l);
    stampa(l);*/
    l=casuale(l,dim);
    stampa(l);
    /*printf("\nil più grande e': %d ",max(l));
    printf("\nil più piccolo e': %d ",min(l));
    printf("\nla media e': %f ",media(l,dim));*/

   /* printf("\ninserisci un numero k: ");
    scanf("%d",&k);
    printf("\nelimino i maggiori di %d ",k);
    l=elmaggiorik(l,k);
    stampa(l);

    printf("\nmetto i numeri diversi da %d in un'altra lista: ",k);
    l2=listak(l,k);
    printf("\nlista due(senza il numero %d )... non lo abbiamo eliminato",k);
    stampa(l2);
    printf("\nlista uno");
    stampa(l);*/

    /*printf("\nelimino i pari in posizione dispari: ");
    l=elpari(l);
    stampa(l);*/

    /*printf("\ninserisic un numero da duplicare:  ");
    scanf("%d",&n);
    l=duplica(l,n);
    stampa(l);
    l=modifica(pf,l);*/

    printf("\nritorno tutti i multipli:  ");   ///in questo caso,multipli di 3
    l=multiplo(l);
    stampa(l);
    l=modifica(pf,l);

    printf("\nquanti numeri scritti nel file:%d ",lenfile(pf));

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

nodo*ricerca(nodo*p,int a)
{
    nodo*trovato=NULL;
    for(;p!=NULL && trovato==NULL;p=p->next)
    {
        if (p->primo==a)
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

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d->",p->primo);
        p=p->next;
    }
}

nodo*reverse(nodo*p)
{
    if(p==NULL)
        return 0;
    reverse(p->next);
    printf("\n%d->",p->primo);
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

///
nodo*ordina(nodo*p,nodo*tmp)
{
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

nodo*crescente(nodo*p)
{
    nodo*tmp;
    nodo*l1=NULL;
    while(p!=NULL)
    {
        tmp=p;
        p=p->next;
        l1=ordina(l1,tmp);
    }
    return l1;
}

nodo*insordine(nodo*p,int a)
{
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    if(p==NULL || p->primo>a)
    {
        tmp=nelem(a);
        tmp->next=p;
        p=tmp;
    }
    else
    {
        p->next=insordine(p->next,a);
    }
    return p;
}

///
nodo*elmaggiorik(nodo*p,int k)
{
    nodo*tmp=p;
    if(p!=NULL)
    {
        if(p->primo > k)
        {
            p=elmaggiorik(p->next,k);
            free(tmp);
        }
        else
        {
            p->next=elmaggiorik(p->next,k);
        }
    }
    return p;
}

nodo*listak(nodo*p,int k)
 {
     nodo*tmp;
     if(p==NULL)
     {
         return p;
     }
     tmp=listak(p->next,k);
     if(p->primo!=k)
     {
         tmp=intesta(tmp,p->primo);  ///andava bene anche in coda
     }
     return tmp;
 }

///
int max(nodo*p)
{
    int max=INT_MIN;
    nodo*tmp;
    if(p==NULL)
    {
        return 0;
    }
    while(p!=NULL)
    {
        if(p->primo > max)
        {
            tmp=p;
            max=p->primo;
        }
        p=p->next;
    }
    return max;
}

int min(nodo*p)
{
    int min=INT_MAX;
    nodo*tmp;
    if(p==NULL)
    {
        return 0;
    }
    while(p!=NULL)
    {
        if(p->primo < min)
        {
            tmp=p;
            min=p->primo;
        }
        p=p->next;
    }
    return min;
}

nodo*elpari(nodo*p)
{
    nodo*tmp;
    if(p)
    {
        if(p->next)
        {
            p->next->next=elpari(p->next->next);
        }
        if(!(p->primo%2!=0))
        {
            tmp=p;
            p=p->next;
            free(tmp);
        }
    }
    return p;
}

nodo*duplica(nodo*p,int a)
{
    if(occorrenza(p,a)==1)
    {
        p=intesta(p,a);  ///va bene anche in coda
    }
    return p;
}

nodo*casuale(nodo*p,int dim)
{
    int a;
    int i=0;
    srand((unsigned)time(NULL));
    for(i=0;i<dim;i++)
    {
        a=rand()%100+1;
        p=incoda(p,a);
    }
    return p;
}

nodo*multiplo(nodo*p)
{
    /*nodo*tmp;
    nodo*l3=l1;
    while(l3!=NULL)
    {
  stampa(l2);
    printf("\nlista uno");
    stampa(l);*/
    nodo*tmp=p;     ///sarebbe un elimina occorrenza con l'if diverso... elimina tutti i NON multipli di 3
    if(p!=NULL)
    {
        if(p->primo%3!=0)
        {
            p=multiplo(p->next);
            free(tmp);
        }
        else
        {
            p->next=multiplo(p->next);
        }
    }
    return p;
}

float media(nodo*p,int dim)
{
    float m;
    int i=0;
    if(p!=NULL)
    {
        for(i=0;i<dim;i++)
        {
            m=(float)somma(p)/(float)dim;
        }
    }
    return m;
}

///
nodo*leggi(FILE*pf)
{
    nodo*p=NULL;
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    int i=0;
    pf=fopen("file listaojh.txt","r");
    if(pf)
    {
        while(!(feof))
        {
            fscanf(pf," %d ",&tmp->primo);
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
    nodo*p=NULL;
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    int i=0;
    pf=fopen("file listaojh.txt","w");
    if(pf)
    {
        for(i=0;i<dim;i++)
        {
            printf("inserisci numero:  ");
            scanf("%d",&tmp->primo);
            fprintf(pf," %d ",tmp->primo);
            p=incoda(p,tmp->primo);     ///se vuoi scriverli casuali,basta che ti invochi 'casuale'invece di 'incoda'
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
    pf=fopen("file listaojh.txt","w");
    if(pf)
    {
        while(p!=NULL)
        {
            fprintf(pf," %d ",p->primo);
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
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    int cont=0;
    pf=fopen("file listaojh.txt","r");
    if(pf)
    {
        while(fscanf(pf," %d ",&tmp->primo)==1)
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
