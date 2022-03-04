//funziona TUTTO tranne le funzioni con i commenti
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 20
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

typedef struct LISTA_DOPPIA
{
    int primo;
    struct LISTA_DOPPIA*prev;
    struct LISTA_DOPPIA*next;
}doppia;

typedef struct STUDENTE
{
    char nome[MAX];
    char cognome [MAX];
    int matricola;
    int esami;
}stud;


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
///
nodo*alterna(nodo*l1,nodo*l2);
nodo*fondi(nodo*l1,nodo*l2);
nodo*interseca(nodo*l1,nodo*l2);
nodo*diffsimm(nodo*l1,nodo*l2,nodo*l3);
///
nodo*elmaggiorik(nodo*p,int k);
nodo*minmaxk(nodo*p,int k);   ///i maggiori di k prima dei minori di k
nodo*klista(nodo*p,int k);   ///mette su un'altra lista i numeri diversi da k
///
nodo*maxdispari(nodo*p);
nodo*elpari(nodo*p);
void sum(nodo*p);
int sumpre(nodo*p);
///
stud**leggi(FILE*pf,stud**p,int n);
void stampafile(stud**p,int n,int k);     //mi serve solo per verificare che funzioni la funzione lol
///
doppia*nelem2(doppia*tmp2,nodo*p);
doppia*ritdop(nodo*p);
void stampa2(doppia*p2);         //mi serve solo per verificare che funzioni la funzione lol

int main()
{
    nodo*l1=NULL;
    nodo*l2=NULL;
    nodo*l3=NULL;
    int i=0,k,dim,n,a,dom,m;

    FILE*pf=NULL;

    doppia*l4=NULL;

                                                           ///
    /*printf("quanto vuoi grande la tua lista? ");
    scanf("%d",&dim);
    for(i=0;i<dim;i++)
    {
        printf("inserisci %d elemento lista 1:   ",i+1);
        scanf("%d",&n);
        l1=incoda(l1,n);
    }
    printf("stampo la lista:");
    stampa(l1);*/
                                                             ///
    /*printf("quale elemento vuoi ricercare? ");
    scanf("%d",&n);
    l1=ricerca(l1,n);
    if(ricerca(l1,n))
    {
        printf(" trovato ");
    }
    else
    {
        printf(" NON trovato ");
    }*/

    /*printf("elimino tutta la lista");
    l1=elimina(l1);
    stampa(l1);
    if(l1==NULL)
    {
        printf("\nlista vuta");
    }*/

    /*printf("quale occorrenza vuoi contare?  ");
    scanf("%d",&n);
    printf("le occorrenze di %d sono: %d ",n,occorrenza(l1,n));*/

    /*printf("quale occorrenza vuoi eliminare?  ");
    scanf("%d",&n);
    l1=elocc(l1,n);
    stampa(l1);*/

    /*printf("stampo al contrario: ");
    reverse(l1);*/

    /*printf("faccio la somma di tutti gli elementi presenti nella lista:\n");
    printf("la somma e': %d ",somma(l1));*/

    /*printf("ordino la lista in ordine crescente: ");
    l1=crescente(l1);
    stampa(l1);*/
                                                        ///
    /*printf("quanto vuoi grande la tua lista? ");
    scanf("%d",&dom);
    for(i=0;i<dom;i++)
    {
        printf("inserisci %d elemento lista 2:   ",i+1);
        scanf("%d",&m);
        l2=incoda(l2,m);
    }
    printf("stampo la lista:");
    stampa(l2);*/

    /*printf("alterno gli elementi delle due liste:");
    l3=alterna(l1,l2);
    stampa(l3);*/

    /*printf("fondo le due liste:");
    l3=fondi(l1,l2);
    stampa(l3);*/

    /*printf("intersecon gli elementi comuni:");
    l3=interseca(l1,l2);
    stampa(l3);*/

    /*printf("differenza simmetrica delle due liste(prendo tutti gli elementi non in comune)");
    l3=diffsimm(l1,l2,l3);
    stampa(l3);*/
                                                           ///
    /*printf("inserisci un numero k:   ");
    scanf("%d",&k);*/

    /*printf("elimino tutti i numeri maggiodi di %d",k);
    l1=elmaggiorik(l1,k);
    stampa(l1);*/

    /*printf("metto i maggiori di %d prima dei minori di %d",k,k);
    l1=minmaxk(l1,k);                                                  //problema con la funzione,serve un else
    stampa(l1);*/

    /*printf("metto tutti i numeri diversi da %d in un'altra lista: ",k);
    l1=klista(l1,k);
    stampa(l1);*/
                                                       ///
    /*printf("ecco il massimo puntatore dispari della lista: ");
    l1=maxdispari(l1);
    stampa(l1);*/

    /*printf("elimino i numeri pari in posizione dispari: ");
    l1=elpari(l1);
    stampa(l1);*/

    /*printf("il numero è sostituito dalla somma col valore precedente");
    sum(l1);
    stampa(l1);*/
                                                        ///
    /*printf("ritorno la lista doppiamente concat. ");
    l4=ritdop(l1);
    stampa2(l4);*/

    pf=fopen("a.txt","r");
    if(pf==NULL)
    {
        printf("file danneggiato o impossibile da aprire");
    }
    else                                                        // il numero della matricola non è quello del file e non so perchè
    {
        fscanf(pf,"%d",&n);
        struct STUDENTE **s=(struct STUDENTE**)malloc(sizeof(struct STUDENTE)*n);
        s=leggi(pf,s,n);
        printf("digita un numero k:  ");
        scanf("%d",&k);
        stampafile(s,n,k);

        fclose(pf);
    }



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

nodo*ricerca(nodo*p,int a)
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
        printf("\n%d\n\t ",p->primo);
        p=p->next;
    }
}

nodo*reverse(nodo*p)
{
    if(p==NULL)
        return 0;
    reverse(p->next);
    printf("\n%d ",p->primo);
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
    nodo*l=NULL;
    while(p!=NULL)
    {
        tmp=p;
        p=p->next;
        l=ordina(l,tmp);
    }
    return l;
}

///
nodo*alterna(nodo*l1,nodo*l2)
{
    nodo*l3=l1;
    if(l1==NULL)
    {
        return l2;
    }
    else if(l2==NULL)
    {
        return l1;
    }
    else
    {
        l2->next=alterna(l1->next,l2->next);
        l3->next=l2;
    }
    return l3;
}

nodo*fondi(nodo*l1,nodo*l2)
{
    nodo*l3;
    if(l1==NULL)
    {
        return l2;
    }
    else if(l2==NULL)
    {
        return l1;
    }
    else if(l1->primo < l2->primo)
    {
        l3=l1;
        l3->next=fondi(l1->next,l2);
    }
    else
    {
        l3=l2;
        l3->next=fondi(l1,l2->next);
    }
    return l3;
}

nodo*interseca(nodo*l1,nodo*l2)
{
    nodo*l3=NULL;
    if(l1)
    {
        l3=interseca(l1->next,l2);
        if(ricerca(l2,l1->primo))
        {
           l3=intesta(l3,l1->primo);
        }
    }
    return l3;
}

nodo*diffsimm(nodo*l1,nodo*l2,nodo*l3)
{
    if(l1==NULL && l2==NULL)
    {
        return l3;
    }
    else if(l1==NULL)
    {
        l3=incoda(l3,l2->primo);
        return diffsimm(l1,l2->next,l3);
    }
    else if(l2==NULL)
    {
        l3=incoda(l3,l1->primo);
        return diffsimm(l1->next,l2,l3);
    }
    else if(l1->primo < l2->primo)
    {
        l3=incoda(l3,l1->primo);
        return diffsimm(l1->next,l2,l3);
    }
    else if(l1->primo > l2->primo)
    {
        l3=incoda(l3,l2->primo);
        return diffsimm(l1,l2->next,l3);
    }
    return diffsimm(l1->next,l2->next,l3);
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

nodo*minmaxk(nodo*p,int k)
{
    nodo*tmp;
    if(p==NULL || p->next==NULL)
    {
     return p;
    }
    tmp=minmaxk(p->next,k);
    if(p->primo < k)
    {
        p->next=tmp;
    }
    else
    {
        //
    }
    return p;
}

nodo*klista(nodo*p,int k)
{
    nodo*tmp;
    if(p==NULL)
    {
        return p;
    }
    tmp=klista(p->next,k);
    if(p->primo!=k)
    {
        tmp=intesta(tmp,p->primo);
    }
    return tmp;
}

///
nodo*maxdispari(nodo*p)
{
    nodo*tmp;
    int max=INT_MIN;
    if(p==NULL)
    {
        return p;
    }
    while(p!=NULL)
    {
        if(p->primo%2!=0 && p->primo > max)
        {
            tmp=p;
            max=p->primo;
        }
        p=p->next;
    }
    return tmp;
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

void sum(nodo*p)
{
    while(p!=NULL)
    {
        p->primo=sumpre(p);
        p=p->next;
    }
}

int sumpre(nodo*p)
{
    int s=0;
    while(p!=NULL)
    {
        s+=p->primo;
        p=p->next;
    }
    return s;
}

///
stud**leggi(FILE*pf,stud**p,int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        p[i]=(struct STUDENTE*)malloc(sizeof(struct STUDENTE));
        fscanf(pf,"%s %s %d %d",p[i]->nome,p[i]->cognome,&(p[i]->matricola),&(p[i]->esami));
    }
    return p;
}

void stampafile(stud**p,int n,int k)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        if(p[i]->esami > k)
        {
           printf("nome:%s     matricola:%d\n ",p[i]->nome,(p[i]->matricola));
        }
    }
    return;
}

///
doppia*nelem2(doppia*tmp2,nodo*p)
{
    doppia*flag=(struct LISTA_DOPPIA*)malloc(sizeof(struct LISTA_DOPPIA));
    flag->prev=NULL;
    flag->primo=p->primo;
    flag->next=tmp2;
    return flag;
}

doppia*ritdop(nodo*p)
{
    doppia*tmp2=NULL;
    if(p!=NULL)
    {
      tmp2=ritdop(p->next);
      tmp2=nelem2(tmp2,p);
      if(p->next!=NULL)
      {
          tmp2->next->prev=tmp2;
      }
    }
    return tmp2;
}

void stampa2(doppia*p2)
{
    while(p2!=NULL)
    {
        printf("\n<->%d<-> ",p2->primo);
        p2=p2->next;
    }
}




