///da COMPLETARE alcune funzioni.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
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
    char cognome[MAX];
    int matricola;
    int esame;
}stud;

///PRIMO BLOCCO
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
///SESTO BLOCCO
stud**leggis(FILE*pf,stud**p,int n);
void stampafile(stud**p,int n,int k);     ///mi serve solo per verificare che funzioni la funzione lol
///SETTIMO BLOCCO
doppia*nelem2(doppia*tmp2,nodo*p);
doppia*ritdop(nodo*p);
void stampa2(doppia*p2);
///OTTAVO BLOCCO
int lunghezza(nodo*p);
nodo*casuale(nodo*p,int dim);
nodo*duplicati(nodo*p,int a);     ///aggiunge i duplicati di un numero in una lista
float media(nodo*p,int dim);
nodo*inverti(nodo*p);              ///inverti la lista (esce reverse ma lo diventa stabilmente)
///NONO BLOCCO
nodo*leggi(FILE*pf);
nodo*scrivi(FILE*pf,int dim);
nodo*modifica(FILE*pf,nodo*p);
int lenfile(FILE*pf);

int main()
 {
    nodo*l1=NULL;
    nodo*l2=NULL;
    nodo*l3=NULL;
    int i=0,k,dim,n,a,dom,m,cas,dupl;

    FILE*pf=NULL;

    doppia*l4=NULL;

                                                           ///***PRIMO BLOCCO***
    printf("quanto vuoi grande la tua lista? ");
    scanf("%d",&dim);
   /* for(i=0;i<dim;i++)
    {
        printf("inserisci %d elemento lista 1:   ",i+1);     ///QUANDO mi scoccio di digitare
        scanf("%d",&n);
        l1=incoda(l1,n);
    }*/

    l1=casuale(l1,dim);
    printf("stampo la lista:");
    stampa(l1);

    /*printf("\nquale elemento vuoi ricercare? ");
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

    /*printf("\nelimino tutta la lista");
    l1=elimina(l1);
    stampa(l1);
    if(l1==NULL)
    {
        printf("\nlista vuota");
    }*/

    /*printf("\nquale occorrenza vuoi contare?  ");
    scanf("%d",&n);
    printf("\nle occorrenze di %d sono: %d ",n,occorrenza(l1,n));*/

    /*printf("\nquale occorrenza vuoi eliminare?  ");
    scanf("%d",&n);
    l1=elocc(l1,n);
    stampa(l1);*/

    /*printf("\nstampo al contrario: ");
    reverse(l1);*/

    /*printf("\nfaccio la somma di tutti gli elementi presenti nella lista:\n");
    printf("\nla somma e': %d ",somma(l1));*/

                                                         ///***SECONDO BLOCCO*** (ordinamenti)
    /*printf("\nordino la lista in ordine crescente:\n ");
    l1=crescente(l1);
    stampa(l1);*/

    /*printf("\ninserisco in ordine crescente: ");
    for(i=0;i<dim;i++)
    {
        printf("inserisci %d elemento lista 1:   ",i+1);
        scanf("%d",&n);
        l1=insordine(l1,n);
    }
    printf("stampo la lista:");
    stampa(l1);*/
                                                    ///***TERZO BLOCCO*** (funzioni su due liste)
    /*printf("\nquanto vuoi grande la tua lista? ");
    scanf("%d",&dom);
    for(i=0;i<dom;i++)
    {
        printf("\ninserisci %d elemento lista 2:   ",i+1);
        scanf("%d",&m);
        l2=incoda(l2,m);
    }
    printf("stampo la lista:");
    stampa(l2);*/

    /*printf("\nalterno gli elementi delle due liste:");
    l3=alterna(l1,l2);
    stampa(l3);*/

    /*printf("\nfondo le due liste:");
    l3=fondi(l1,l2);
    stampa(l3);*/

    /*printf("\ninterseco gli elementi comuni:");
    l3=interseca(l1,l2);
    stampa(l3);*/


    /*printf("differenza simmetrica delle due liste(prendo tutti gli elementi non in comune)");
    l3=diffsimm(l1,l2,l3);
    stampa(l3);*/
                                                           ///***QUARTO BLOCCO***(funzioni su k)
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
                                                       ///***QUINTO BLOCCO***(dispari e somme)
    /*printf("ecco il massimo puntatore dispari della lista: ");                 ///mi stampa per primo il max dispari ma anche altri numeri della lista
    l1=maxdispari(l1);
    stampa(l1);*/

    /*printf("elimino i numeri pari in posizione dispari: ");
    l1=elpari(l1);
    stampa(l1);*/

    /*printf("il numero è sostituito dalla somma col valore precedente");
    sum(l1);
    stampa(l1);*/                                                           ///vengono stampati dal basso verso l'alto
                                                  ///***SESTO BLOCCO***(scrittura file)
    /*pf=fopen("a.txt","r");
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
                                                     ///***SETTIMO BLOCCO***(lista doppiamente concatenata)
    /*printf("ritorno la lista doppiamente concat. ");
    l4=ritdop(l1);
    stampa2(l4);*/
                                                ///***OTTAVO BLOCCO***(random,duplica,lunghezza)

    /*printf("\nla lista e' lunga: %d",lunghezza(l1));

    printf("\nesco numeri casuali: ");
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

    /*printf("\ninverto la lista: ");
    l1=inverti(l1);
    stampa(l1);*/
                                       ///***NONO BLOCCO***(leggere,scrivere,modifica,file e lista


     return 0;
 }

///PRIMO BLOCCO
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
        if(p->primo ==a)
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
    if(p==NULL || tmp->primo > a)
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

///QUARTO BLOCCO
nodo*elmaggiorik(nodo*p,int k)
{
    nodo*tmp=p;
    if(p!=NULL)
    {
        if(p->primo>k)
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
                           ///versione alternativa(in realtà non elimina ma mette solo in coda quelli diversi da k)
   /* nodo*tmp;
    if(p==NULL)
    {
        return p;
    }
    tmp=elmaggiorik(p->next,k);
    if(p->primo!=k)
    {
        tmp=incoda(tmp,p->primo);
    }
    return tmp;*/
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
        return p;
    }
    else
    {
        tmp=incoda(tmp,p->primo);
    }
    return tmp;
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

///QUINTO BLOCCO
nodo*maxdispari(nodo*p)
{
     int max=INT_MIN;
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
    }
    if(!(p->primo%2!=0))
    {
        tmp=p;
        p=p->next;
        free(tmp);
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

///SESTO BLOCCO
stud**leggis(FILE*pf,stud**p,int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        p[i]=(stud*)malloc(sizeof(stud*)*n);
        fscanf(pf," %s %s %d %d ",p[i]->nome,p[i]->cognome,&p[i]->matricola,&p[i]->esame);
    }
    return p;
                          ///versione alternativa,senza fare fopen nel main

    /*int i=0;
    pf=fopen("a.txt","r");
    if(pf)
    {
        fscanf(pf," %d ",&n); ///ovviamente,se lo acquisiamo da qua,non devo passargli n nella funzione
        for(i=0;i<n;i++)
        {
             p[i]=(stud*)malloc(sizeof(stud*)*n);
            fscanf(pf," %s %s %d %d ",p[i]->nome,p[i]->cognome,&p[i]->matricola,&p[i]->esame);
        }
    }
    else
    {
      printf("errore di apertura");
    }


    fclose(pf);
    return p;

    */
}

void stampafile(stud**p,int n,int k)
{
    int i=0;
      for(i=0;i<n;i++)
    {
        if(p[i]->esame > k)
        {
            printf("\n%s %d ",p[i]->nome,p[i]->matricola);
        }
    }

}

///SETTIMO BLOCCO
doppia*nelem2(doppia*tmp2,nodo*p)
{
    doppia*flag=(doppia*)malloc(sizeof(doppia));
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
        printf("\n<->%d<->",p2->primo);
        p2=p2->next;
    }
}

///OTTAVO BLOCCO
int lunghezza(nodo*p)
{
    int len=0;
    while(p!=NULL)
    {
        len++;
    }
    return len;
}

nodo*casuale(nodo*p,int dim)
{
    int i=0;
    int a=0;
    srand((unsigned)time(NULL));
    for(i=0;i<dim;i++)
    {
        a=rand()%100+1;
        p=incoda(p,a);
    }
    return p;
}

nodo*duplicati(nodo*p,int a)
{
    if(occorrenza(p,a)==1)
    {
        p=intesta(p,a);
    }
    return p;
}

float media(nodo*p,int dim)
{
    float m=0;
    int i=0;
    for(i=0;i<dim;i++)
    {
        m=(float)somma(p)/(float)dim;  ///ho fatto il casting
    }
    return m;
}

nodo*inverti(nodo*p)
{
    nodo*curr=p;
    nodo*prev;
    nodo*succ;
    while(curr!=NULL)
    {
        succ=curr->next;
        curr->next=prev;
        prev=curr;
        curr=succ;
    }
    p=prev;
    return p;
}


///NONO BLOCCO
nodo*leggi(FILE*pf)
{
    nodo*p=NULL;
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    pf=fopen("tutto.txt","r");
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
    pf=fopen("tutto.txt","w");
    if(pf)
    {                ///VERSIONE CHE CHIEDE DI INSERIRE NUMERI MANUALMENTE
        /*for(i=0;i<dim;i++)
        {
            printf("inserisci numero:  ");
            scanf("%d",&tmp->primo);
            fprintf(pf," %d ",tmp->primo);
            p=incoda(p,tmp->primo);
        }*/
        ///VERSIONE QUANDO SI HA LA FUNZIONE CASUALE (GENERA NUMERI CASUALI)
         srand((unsigned)time(NULL));
         for(i=0;i<dim;i++)
        {
            tmp->primo=rand()%100+1;
            fprintf(pf," %d ",tmp->primo);
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
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    pf=fopen("tutto.txt","w");
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
    int cont=0;
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    pf=fopen("tutto.txt","r");
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
