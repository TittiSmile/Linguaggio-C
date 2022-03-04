#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 20
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

typedef struct DOPPIA
{
    int primo;
    struct DOPPIA*prev;
    struct DOPPIA*next;
}dop;

typedef struct STUDENTE
{
    char nome[MAX];
    char cognome[MAX];
    int matricola;
    int esame;
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
nodo*elmaxk(nodo*p,int k);
nodo*minmaxk(nodo*p,int k); //i minori prima dei maggiori. la quitto perchè non mi va di fare l'inserimento in coda.
nodo*klista(nodo*p,int k);   //i numeri diversi da k in un'altra lista.
///
nodo*maxdispari(nodo*p);
nodo*elpari(nodo*p);
int sumpre(nodo*p);
void sum(nodo*p);
///
stud**leggi(FILE*pf,stud**s,int n);
void stampafile(stud**s,int n,int k);
///
dop*nelem2(nodo*p,dop*tmp2);
dop*ritorna(nodo*p);
void stampa2(dop*p2);


int main ()
{
    nodo*l1=NULL;
    nodo*l2=NULL;
    nodo*l3=NULL;
    int i=0,k,dim,n,a,dom,m;

    FILE*pf=NULL;

    dop*l4=NULL;

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

   /* printf("elimino tutta la lista");
    l1=elimina(l1);
    stampa(l1);
    if(l1==NULL)
    {
        printf("\nlista vuota");
    }*/

   /* printf("quale occorrenza vuoi contare?  ");
    scanf("%d",&n);
    printf("\nle occorrenze di %d sono: %d ",n,occorrenza(l1,n));*/

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

    /*printf("interseco gli elementi comuni:");
    l3=interseca(l1,l2);
    stampa(l3);*/

    /*printf("differenza simmetrica delle due liste(prendo tutti gli elementi non in comune)");
    l3=diffsimm(l1,l2,l3);
    stampa(l3);*/
                                                           ///
    /*printf("inserisci un numero k:   ");
    scanf("%d",&k);*/

    /*printf("elimino tutti i numeri maggiodi di %d",k);
    l1=elmaxk(l1,k);
    stampa(l1);*/

    /*printf("metto i maggiori di %d prima dei minori di %d",k,k);
    l1=minmaxk(l1,k);                                                  //problema con la funzione,serve un else
    stampa(l1);*/

    /*printf("metto tutti i numeri diversi da %d in un'altra lista: ",k);
    l1=klista(l1,k);
    stampa(l1);*/
                                                       ///
    /*printf("ecco il massimo puntatore dispari della lista: ");  //in realtà, se il tuo max puntatore non è l'ultimo inserito,ti stampa anche gli altri valori nella lista
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
    l4=ritorna(l1);
    stampa2(l4);*/

   /* pf=fopen("a.txt","r");
    if(pf==NULL)
    {
        printf("file danneggiato o impossibile da aprire");
    }
    else
    {
        fscanf(pf,"%d",&n);
        struct STUDENTE **s=(struct STUDENTE**)malloc(sizeof(struct STUDENTE)*n);
        s=leggi(pf,s,n);
        printf("digita un numero k:  ");
        scanf("%d",&k);
        stampafile(s,n,k);

        fclose(pf);
    }*/

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
       printf("\n%d -> ",p->primo);
       p=p->next;
    }
}

nodo*reverse(nodo*p)
{
    if(p==NULL)
        return 0;
    reverse(p->next);
    printf("\n%d -> ",p->primo);
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
nodo*elmaxk(nodo*p,int k)
{
    nodo*tmp=p;
    if(p!=NULL)
    {
        if(p->primo > k)
        {
            p=elmaxk(p->next,k);
            free(tmp);
        }
        else
        {
            p->next=elmaxk(p->next,k);
        }
        return p;
    }
}

nodo*minmaxk(nodo*p,int k)
{
    nodo*tmp;
   if(p==NULL || p->next==NULL )
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
       ///
   }
}

nodo*klista(nodo*p,int k)
{
    nodo*tmp;
    if(p==NULL)
    {
        return p;
    }
    tmp=klista(p->next,k);
    if(p->primo !=k)
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
        if (!(p->primo%2!=0))
        {
            tmp=p;
            p=p->next;
            free(tmp);
        }
    }
    return p;
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

void sum(nodo*p)
{
    while(p!=NULL)
    {
        p->primo=sumpre(p);
        p=p->next;
    }
}

///
stud**leggi(FILE*pf,stud**s,int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        s[i]=(struct STUDENTE*)malloc(sizeof(struct STUDENTE));
        fscanf(pf,"%s %s %d %d",s[i]->nome,s[i]->cognome,&(s[i]->matricola),&(s[i]->esame));
    }
    return s;
}

void stampafile(stud**s,int n,int k)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        if(s[i]->esame > k)
        {
            printf("%s %d\n",s[i]->nome,s[i]->matricola);
        }
    }
    return;
}

///
dop*nelem2(nodo*p,dop*tmp2)
{
    dop*flag=(struct DOPPIA*)malloc(sizeof(struct DOPPIA));
    flag->prev=NULL;
    flag->primo=p->primo;
    flag->next=tmp2;
    return flag;
}

dop*ritorna(nodo*p)
{
    dop*tmp2=NULL;
    if(p!=NULL)
    {
        tmp2=ritorna(p->next);
        tmp2=nelem2(p,tmp2);
        if(p->next!=NULL)
        {
            tmp2->next->prev=tmp2;
        }
    }
    return tmp2;
}

void stampa2(dop*p2)
{
    while(p2!=NULL)
    {
        printf("\n<-> %d <-> ",p2->primo);
        p2=p2->next;
    }
}
