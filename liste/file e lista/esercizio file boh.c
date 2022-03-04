///Molte di queste funzioni non mi servono effettivamente. le scrivo giusto per ricordarmele
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
///SECONDO BLOCCO
nodo*ordina(nodo*p,nodo*tmp);
nodo*crescente(nodo*p);
nodo*insordine(nodo*p,int a);
///TERZO BLOCCO
nodo*alterna(nodo*l1,nodo*l2);
nodo*fondi(nodo*l1,nodo*l2);
nodo*interseca(nodo*l1,nodo*l2);
nodo*diffsimm(nodo*l1,nodo*l2,nodo*l3);
///QUARTO BLOCCO
nodo*elmaggiorik(nodo*p,int k);
nodo*minmaxk(nodo*p,int k);   ///i maggiori di k prima dei minori di k
nodo*klista(nodo*p,int k);   ///mette su un'altra lista i numeri diversi da k
///QUINTO BLOCCO
nodo*maxdispari(nodo*p);
nodo*elpari(nodo*p);
void sum(nodo*p);
int sumpre(nodo*p);
///roba coi file
nodo*leggi(FILE*pf);
nodo*scrivi(FILE*pf,int dim);
nodo*modifica(FILE*pf,nodo*p);
int elfile(FILE*pf);
///OTTAVO BLOCCO
int lunghezza(nodo*p);
void casuale();
nodo*duplicati(nodo*p,int a);

int main ()
{//printf("\n    O\n   *|*\n  * | *\n *  |  *\n  *3=D*\n  *   *\n *     *\n");
    ///___________***SERVE PER VEDERE SE LE FUNZIONI FUNZIONANO,LOL. NON è IL VERO PROGRAMMA***_____________
    nodo*l1=NULL;
    nodo*l2=NULL;
    nodo*l3=NULL;
    int i=0,k,dim,n,a,dom,m,cas,dupl;

    FILE*pf;

                                                          ///***PRIMO BLOCCO***
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
        printf("\nlista vuota");
    }*/

    /*printf("quale occorrenza vuoi contare?  ");
    scanf("%d",&n);
    printf("\nle occorrenze di %d sono: %d ",n,occorrenza(l1,n));*/

    /*printf("\nquale occorrenza vuoi eliminare?  ");
    scanf("%d",&n);
    l1=elocc(l1,n);
    stampa(l1);*/

    /*printf("\nstampo al contrario: ");
    reverse(l1);*/

    /*printf("faccio la somma di tutti gli elementi presenti nella lista:\n");
    printf("la somma e': %d ",somma(l1));*/

                                                         ///***SECONDO BLOCCO***
   /*printf("\nordino la lista in ordine crescente:\n ");
    l1=crescente(l1);
    stampa(l1);*/

    /*printf("inserisco in ordine crescente: ");     ///l'inserimento in coda più su non deve esserci se c'è questo
    for(i=0;i<dim;i++)
    {
        printf("inserisci %d elemento lista 1:   ",i+1);
        scanf("%d",&n);
        l1=insordine(l1,n);
    }
    printf("stampo la lista:");
    stampa(l1);*/
                                                    ///***TERZO BLOCCO***
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
                                                           ///***QUARTO BLOCCO***
    /*printf("inserisci un numero k:   ");
    scanf("%d",&k);*/

    /*printf("elimino tutti i numeri maggiodi di %d",k);
    l1=elmaggiorik(l1,k);
    stampa(l1);*/

    /*printf("metto tutti i numeri diversi da %d in un'altra lista: ",k);
    l1=klista(l1,k);
    stampa(l1);*/
                                                       ///***QUINTO BLOCCO***
    /*printf("ecco il massimo puntatore dispari della lista: ");                 ///mi stampa per primo il max dispari ma anche altri numeri della lista
    l1=maxdispari(l1);
    stampa(l1);*/

    /*printf("elimino i numeri pari in posizione dispari: ");
    l1=elpari(l1);
    stampa(l1);*/

    /*printf("il numero è sostituito dalla somma col valore precedente");
    sum(l1);
    stampa(l1);*/                                                           ///vengono stampati dal basso verso l'alto

                                                ///***OTTAVO BLOCCO***

    /*printf("\nla lista e' lunga: %d",lunghezza(l1));

    printf("\nesco numeri casuali: ");
    srand((unsigned)time(NULL));
    for(i=0;i<dim;i++)
    {
        cas=rand()%100+1;
        l1=incoda(l1,cas);
    }
    stampa(l1);

    printf("\nquale numero vuoi duplicare? ");
    scanf("%d",&dupl);
    l1=duplicati(l1,dupl);
    stampa(l1);*/


      ///_______***INIZIA QUIII***_______

      printf("quanto vuoi grande la tua lista? ");
      scanf("%d",&dim);

      printf("scrivo la lista sul file:  ");
      l1=scrivi(pf,dim);

      printf("inserisci numero da duplicare:  ");
      scanf("%d",&dupl);
      l1=duplicati(l1,dupl);
      stampa(l1);
      l1=modifica(pf,l1);

      printf("\ngli elementi nel file sono: %d ",elfile(pf));


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
        printf("\n%d-> ",p->primo);
        p=p->next;
    }
}

nodo*reverse(nodo*p)
{
    if(p==NULL)
        return 0;
    reverse(p->next);
    printf("\n%d-> ",p->primo);
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

///SECONDO BLOCCO
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

nodo*insordine(nodo*p,int a)
{
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    if(p==NULL || p->primo > a)
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

///TERZO BLOCCO
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
    else if(l1->primo > l2->primo)
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
    if(l1==NULL)
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

///QUARTO BLOCCO
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

nodo*klista(nodo*p,int k)   ///mette su un'altra lista i numeri diversi da k
{
    /*nodo*tmp=p;    //questa versione elimina i diversi da k
    if(p!=NULL)
    {
        if(p->primo != k)
        {
            p=elmaggiorik(p->next,k);
            free(tmp);
        }
        else
        {
            p->next=elmaggiorik(p->next,k);
        }
    }
    return p;*/
    ///
    nodo*tmp;          //questa versione mette in testa i numeri diversi da k,non elimina nulla.
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

///QUINTO BLOCCO
nodo*maxdispari(nodo*p)
{
    int max=INT_MIN;
    int i=0;
    nodo*tmp;
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

///OTTAVO BLOCCO
int lunghezza(nodo*p)
{
    int len;
    while(p!=NULL)
    {
        len++;
        p=p->next;
    }
    return len;
}

void casuale()
{
    int a=0;
    srand((unsigned)time(NULL));
    a=rand()%100+1;
}

nodo*duplicati(nodo*p,int a)
{
    int i=0;
    if(occorrenza(p,a)==1)
    {
        p=intesta(p,a);   //anche incoda va bene
    }
    return p;
}

///
nodo*leggi(FILE*pf)
{
    nodo*p=NULL;
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    pf=fopen("aa.txt","r");
    if(pf)
    {
        while(!feof(pf))
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
    pf=fopen("aa.txt","w");
    if(pf)
    {
        for(i=0;i<dim;i++)
        {
            printf("\ninserisci numero:  ");
            scanf(" %d",&tmp->primo);
            fprintf(pf,"%d",tmp->primo);
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
     pf=fopen("aa.txt","w");
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
}

int elfile(FILE*pf)
{
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    int cont=0;
    pf=fopen("aa.txt","r");
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
