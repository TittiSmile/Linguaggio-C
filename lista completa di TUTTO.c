/*devo mettere nel BLOCCO OTTO le funzioni: inverti e media e anche la funzione maxmink. una cosa da migliorare sono alcuni nomi
delle funzioni per una maggiore leggibilità. per il resto è tutto OK*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
nodo*elimina_occorrenza(nodo*p,int a);
void stampa(nodo*p);
nodo*reverse(nodo*p);
int sommaLista(nodo*p);
///SECONDO BLOCCO
nodo*InsInOrdine(nodo*p,int a);
nodo*ordinamento(nodo*p,nodo*tmp);
nodo*crescente(nodo*p);
///TERZO BLOCCO
nodo*AlternaListe(nodo*l1,nodo*l2);
nodo*UnisciListe(nodo*l1,nodo*l2);
nodo*IntersecaListe(nodo*l1,nodo*l2);
nodo*DifferenzaSimmetricaListe(nodo*l1,nodo*l2,nodo*l3);
nodo*concatena(nodo*l1,nodo*l2);
///QUARTO BLOCCO
nodo*EliminaMaggioriK(nodo*p,int k);
nodo*ListaConK(nodo*p,int k);
///QUINTO BLOCCO
nodo*MassimoDispariLista(nodo*p);
nodo*EliminaPariPosizDispari(nodo*p);
void somma(nodo*p);
int sommaPrecedenti(nodo*p);
///SESTO BLOCCO
stud**leggis(FILE*pf,stud**p);
void stampafile(stud**p,int k,FILE*pf);     ///mi serve solo per verificare che funzioni la funzione lol
///SETTIMO BLOCCO
doppia*nelem2(doppia*tmp2,nodo*p);
doppia*ritdop(nodo*p);
void stampa2(doppia*p2);
///OTTAVO BLOCCO
int LunghezzaLista(nodo*p);
nodo*AggiungiDuplicati(nodo*p,int a);
nodo*CasualiLista(nodo*p,int a);
nodo*InvertiLista(nodo*p);
nodo*duplica(nodo*p);
///NONO BLOCCO
nodo*leggiFile(FILE*pf);
nodo*scriviFile(FILE*pf,int dim);
nodo*modificaFile(nodo*p,FILE*pf);
int LunghezzaFile(FILE*pf);






int main ()
{

    nodo*l1=NULL;
    nodo*l2=NULL;
    nodo*l3=NULL;
    nodo*l5=NULL;

    int i=0,k,dim,n,a,dom,m,cas,dupl;

    FILE*pf=NULL;

    stud**s=NULL;

    doppia*l4=NULL;

                                                           ///***PRIMO BLOCCO***
    printf("quanto vuoi grande la tua lista? ");
    scanf("%d",&dim);

    /*for(i=0;i<dim;i++)
    {
        printf("inserisci %d elemento lista 1:   ",i+1);     ///QUANDO non mi scoccio di digitare
        scanf("%d",&n);
        l1=incoda(l1,n);
    }
    stampa(l1);*/

                                                        l1=CasualiLista(l1,dim);
                                                        printf("\tstampo la lista 1:");
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
    l1=elimina_occorrenza(l1,n);
    stampa(l1);*/

    /*printf("\nstampo al contrario: ");
    reverse(l1);*/

    /*printf("\nfaccio la somma di tutti gli elementi presenti nella lista:\n");
    printf("\nla somma e': %d ",sommaLista(l1));*/

                                                         ///***SECONDO BLOCCO*** (ordinamenti)
    /*printf("\nordino la lista in ordine crescente:\n ");
    l1=crescente(l1);
    stampa(l1);*/

    /*printf("\ninserisco in ordine crescente: ");
    for(i=0;i<dim;i++)
    {
        printf("\ninserisci %d elemento lista 1:   ",i+1);
        scanf("%d",&n);
        l1=InsInOrdine(l1,n);
    }
    printf("stampo la lista:");
    stampa(l1);*/
                                                    ///***TERZO BLOCCO*** (funzioni su due liste)
    /*printf("\nquanto vuoi grande la tua lista? ");
    scanf("%d",&dom);
                                                    l2=CasualiLista(l2,dom);
                                                    printf("\tstampo la lista 2:");
                                                    stampa(l2);*/
    /*for(i=0;i<dom;i++)
    {
        printf("\ninserisci %d elemento lista 2:   ",i+1);
        scanf("%d",&m);
        l2=incoda(l2,m);
    }
    printf("stampo la lista:");
    stampa(l2);*/

    /*printf("\nalterno gli elementi delle due liste:");
    l3=AlternaListe(l1,l2);
    stampa(l3);*/

    /*printf("\nfondo le due liste:");
    l3=UnisciListe(l1,l2);
    stampa(l3);*/

    /*printf("\ninterseco gli elementi comuni:");
    l3=IntersecaListe(l1,l2);
    stampa(l3);*/


    /*printf("\ndifferenza simmetrica delle due liste(prendo tutti gli elementi non in comune)");
    l3=DifferenzaSimmetricaListe(l1,l2,l3);
    stampa(l3);*/

    /*printf("\nconcatenazione delle due liste:\n");
    l3=concatena(l1,l2);
    stampa(l3);*/
                                                           ///***QUARTO BLOCCO***(funzioni su k)
    /*printf("\ninserisci un numero k:   ");
    scanf("%d",&k);*/

    /*printf("elimino tutti i numeri maggiodi di %d",k);
    l1=EliminaMaggioriK(l1,k);
    stampa(l1);*/

    /*printf("metto i maggiori di %d prima dei minori di %d",k,k);
    l1=minmaxk(l1,k);                                                  //problema con la funzione,serve un else
    stampa(l1);*/

    /*printf("\nmetto tutti i numeri diversi da %d in un'altra lista: ",k);
    l1=ListaConK(l1,k);
    stampa(l1);*/
                                                       ///***QUINTO BLOCCO***(dispari e somme)
    /*printf("\necco il massimo puntatore dispari della lista: ");                 ///mi stampa per primo il max dispari ma anche altri numeri della lista
    l1=MassimoDispariLista(l1);
    stampa(l1);*/

    /*printf("\nelimino i numeri pari in posizione dispari: ");
    l1=EliminaPariPosizDispari(l1);
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
    /*printf("\nleggo cosa c'è nel file:");
    stud**s=(nodo**)malloc(sizeof(nodo)); //ATTENZIONE!!! in realtà andrebbe moltiplicato per n(numero di studenti nel file. il problema è che n l'ho messo direttamente nella funzione e quindi non ci troviamo.
                                          // ho provato a fare in questo modo ma NON sono molto convinta.  volevo evitare di mettere l'acquisizione del file nel main. procedi come in "tutto.c"
    s=leggis(pf,s);
    printf("\ninserisci un numero k: ");
    scanf("%d",&k);
    stampafile(s,k,pf);*/
                                                     ///***SETTIMO BLOCCO***(lista doppiamente concatenata)
    /*printf("\nritorno la lista doppiamente concat. ");
    l4=ritdop(l1);
    stampa2(l4);*/
                                                ///***OTTAVO BLOCCO***(random,duplica,lunghezza)

    /*rintf("\nla lista e' lunga: %d",LunghezzaLista(l1));*/

    /*printf("\nesco numeri casuali: ");
    for(i=0;i<dim;i++)
    {
        cas=rand()%100+1;
        l1=incoda(l1,cas);
    }
    stampa(l1);*/

    /*printf("\nquale numero vuoi duplicare? ");
    scanf("%d",&dupl);
    l1=AggiungiDuplicati(l1,dupl);
    stampa(l1);*/

    /*printf("\ninverto la lista: ");
    l1=InvertiLista(l1);
    stampa(l1);*/

    /*l5=incoda(l5,4);l5=incoda(l5,4);l5=incoda(l5,4);l5=incoda(l5,5);
    printf("\nelimino tutti i duplicati dalla lista: ");
    l5=duplica(l5);
    stampa(l5);*/

                                       ///***NONO BLOCCO***(leggere,scrivere,modifica,file e lista


   /* printf("\nscrivi dei NUMERI sul file: \n");
    l2=scriviFile(pf,dim);
    stampa(l2);

    printf("\nleggo cosa c'e' nel file:  ");
    l2=leggiFile(pf);
    stampa(l2);

    printf("\nmodifica il file:  ");
    l2=modificaFile(l2,pf);
    stampa(l2);

    printf("\nnel file ci sono %d numeri.",LunghezzaFile(pf));*/

      printf("\n\n\t\t***CREDITS BY TITTI***");


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
{p=nelem(a);}
else
{p->next=incoda(p->next,a);}
return p;

///VERSIONE ITERATIVA NON ANCORA SPERIMENTATA!!!!!!!!!
/*struct elem* tmp=top;
	if (top==NULL){
		top=newnodo;
	}
	else {
		while (tmp->next!=NULL){
				tmp=tmp->next;
		}
		tmp->next=newnodo;
	}
	return top;*/
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
  return flag;
}
}

nodo*elimina_occorrenza(nodo*p,int a)
{
 nodo*tmp=p;
    if(p!=NULL)
    {
      if(p->primo==a)
      {
        p=elimina_occorrenza(p->next,a);
        free(tmp);
      }
      else
      {
        p->next=elimina_occorrenza(p->next,a);
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
   {return 0;}
  reverse(p->next);
  printf("\n%d->",p->primo);
}

int sommaLista(nodo*p)
{
   int s=0;
   if(p==NULL)
   {return 0;}
   else
   {
     s=sommaLista(p->next);
     s+=p->primo;
     return s;
   }
}

///SECONDO BLOCCO
nodo*InsInOrdine(nodo*p,int a)
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
  p->next=InsInOrdine(p->next,a);
  }
  return p;
}

nodo*ordinamento(nodo*p,nodo*tmp)
{
    if(p==NULL || p->primo > tmp->primo)
    {
       tmp->next=p;
       p=tmp;
    }
    else
    {
        p->next=ordinamento(p->next,tmp);
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
  l=ordinamento(l,tmp);
}
return l;
}

///TERZO BLOCCO
nodo*AlternaListe(nodo*l1,nodo*l2)
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
        l2->next=AlternaListe(l1->next,l2->next);
        l3->next=l2;
    }
    return l3;
}

nodo*UnisciListe(nodo*l1,nodo*l2)
{
    nodo*l3=NULL;
    if(l1==NULL)
    {
        return l2;
    }
    else if(l2==NULL)
    {
        return l1;
    }
    else if(l1-> primo < l2->primo)
    {
        l3=l1;
        l3->next=UnisciListe(l1->next,l2);

    }
    else
    {
        l3=l2;
        l3->next=UnisciListe(l1,l2->next);
    }
    return l3;

}

nodo*IntersecaListe(nodo*l1,nodo*l2)
{
    nodo*l3=NULL;
    if(l1)
    {
        l3=IntersecaListe(l1->next,l2);
        if(ricerca(l2,l1->primo))
        {
            l3=intesta(l3,l1->primo);
        }
    }
    return l3;
}

nodo*DifferenzaSimmetricaListe(nodo*l1,nodo*l2,nodo*l3)
{
    if(l1==NULL && l2==NULL)
    {
        return l3;
    }
    else if(l1==NULL)
    {
        l3=incoda(l3,l2->primo);
        return DifferenzaSimmetricaListe(l1,l2->next,l3);
    }
    else if(l2==NULL)
    {
        l3=incoda(l3,l1->primo);
        return DifferenzaSimmetricaListe(l1->next,l2,l3);
    }
    else if(l1->primo < l2->primo)
    {
        l3=incoda(l3,l1->primo);
        return DifferenzaSimmetricaListe(l1->next,l2,l3);
    }
     else if(l1->primo > l2->primo)
    {
        l3=incoda(l3,l2->primo);
        return DifferenzaSimmetricaListe(l1,l2->next,l3);
    }
    return DifferenzaSimmetricaListe(l1->next,l2->next,l3);
}

nodo*concatena(nodo*l1,nodo*l2)
{
    nodo*l3=l1;
    if(l1==NULL)
        return l2;
    if(l2==NULL)
        return l1;
    while(l3->next!=NULL)
        {
            l3=l3->next;
        }
        l3->next=l2;
    return l1;

}


///QUARTO BLOCCO
nodo*EliminaMaggioriK(nodo*p,int k)
{
    nodo*tmp=p;
    if(p!=NULL)
    {
        if(p->primo > k)
        {
            p=EliminaMaggioriK(p->next,k);
            free(tmp);
        }
        else
        {
            p->next=EliminaMaggioriK(p->next,k);
        }
    }
    return p;

    /*nodo*tmp;
    if(p==NULL)
    {
        return p;
    }
    p->next=EliminaMaggioriK(p->next,k);    ///scorro p->next perchè devo modificare la lista di partenza
    if(p->primo>k)
    {
       tmp=p;
       p=p->next;
       free(tmp);
    }
    return p;*/
}

nodo*ListaConK(nodo*p,int k) ///toglie tutti i numeri diversi da k e li mette in un'altra lista
{
    nodo*tmp;
    if(p==NULL)
    {
        return p;
    }
    tmp=ListaConK(p->next,k); ///metto tmp=... perchè mi servirà  una lista nuova!
    if(p->primo==k)
    {
        tmp=incoda(tmp,p->primo);
    }
    return tmp;
}

///QUINTO  BLOCCO
nodo*MassimoDispariLista(nodo*p)
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

nodo*EliminaPariPosizDispari(nodo*p)
{
    nodo*tmp;
    if(p)
    {
        if(p->next)
        {
            p->next->next=EliminaPariPosizDispari(p->next->next);
        }
    }
    if(!(p->primo%2))
    {
        tmp=p;
        p=p->next;
        free(tmp);
    }
    return p;
}

void somma(nodo*p)
{
    while(p!=NULL)
    {
        p->primo=sommaPrecedenti(p->next);
        p=p->next;
    }
}

int sommaPrecedenti(nodo*p)
{
    int s=0;
    while(p!=NULL)
    {
        s+=p->primo;
        p=p->next;
    }
}

///SESTO BLOCCO
stud**leggis(FILE*pf,stud**p)
{
    int i=0;
    int dim=0;
    pf=fopen("qw.txt","r");
    if(pf)                       ///ho scritto così per evitare di farlo nel MAIN
    {
      fscanf(pf," %d ",&dim);
        for(i=0;i<dim;i++)
        {
        p[i]=(stud*)malloc(sizeof(stud));
        fscanf(pf,"%s %s %d %d ",p[i]->cognome,p[i]->nome,&p[i]->matricola,&p[i]->esame);
        }
    }
    else
    {
        printf("errore");
    }
    fclose(pf);

    return p;
}

void stampafile(stud**p,int k,FILE*pf)
{
    int i=0;
    int dim=0;
    pf=fopen("qw.txt","r");
    if(pf)
    {
        fscanf(pf," %d ",&dim);
        for(i=0;i<dim;i++)
        {
            if(p[i]->esame>k)
            {
                printf("%s %d",p[i]->cognome,p[i]->matricola);
            }
        }
    }
    else
    {
        printf("errore");
    }

    fclose(pf);

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
    {//♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦♦WTF IS THIS OMG
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
int LunghezzaLista(nodo*p)
{
    int i=0;
    while(p!=NULL)
    {
        i++;
        p=p->next;
    }
    return i;
}
nodo*AggiungiDuplicati(nodo*p,int a)
{
    if(p!=NULL)
    {
        if(occorrenza(p,a)==1)
        {
            p=intesta(p,a);
        }
    }
    return p;
}

nodo*CasualiLista(nodo*p,int a) //a sarebbe la dimensione della lista!!!
{
 int n=0;
 int i=0;
 srand((unsigned)time(NULL));
 for(i=0;i<a;i++)
 {
     n=rand()%50+1;  //ho scelto da 1 a 50
     p=incoda(p,n);
 }
 return p;
}

nodo*InvertiLista(nodo*p)
{
    ///non so perchè ma crasha alla fine lol  N.B. devi mettere prev=NULL
    /*nodo*curr=p;
    nodo*prev=NULL;
    nodo*succ;
    while(curr!=NULL)
    {
        succ=curr->next;
        curr->next=prev;
        prev=curr;
        curr=succ;
    }
    p=prev;
    return p;*/

    nodo*cur=p;
    p=NULL;
    while(cur!=NULL)
    {
        nodo*var=cur;
        cur=cur->next;
        var->next=p;
        p=var;
    }
    return p;
}

nodo*duplica(nodo*p) ///elimina tutti i duplicati dalla lista
{
  ///VERSIONE RICORSIVA
  nodo*tmp=p;
  nodo*cur=p;
  if(p==NULL)
  {
   return p;
  }
  p->next=duplica(p->next);
  while(cur!=NULL && cur->next!=NULL)
  {
    cur=cur->next;
    if(p->primo==cur->primo)
    {
      tmp=p->next;
      free(p);
    }
  }
  return tmp;

  ///VERSIONE ITERATIVA
  /*nodo*cur=p;
  nodo*tmp;
  nodo*var=p;
  while(var!=NULL)
  {
      while(cur->next!=NULL)
      {
          if(var->primo==cur->next->primo)
          {
              tmp=cur->next;
              cur->next=cur->next->next;
              free(tmp);
          }
          else
            cur=cur->next;
      }
      var=var->next;
      cur=var;
  }
  return p;*/

}



///NONO BLOCCO
nodo*leggiFile(FILE*pf)
{
    nodo*p=NULL;
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    pf=fopen("qw.txt","r");
    if(pf)
    {
        while(!(feof(pf)))
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

nodo*scriviFile(FILE*pf,int dim)
{
    int i=0;
    nodo*p=NULL;
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    pf=fopen("qw.txt","w");
    if(pf)
    {
        srand((unsigned)time(NULL));
        for(i=0;i<dim;i++)
        {
           /* printf("inserisci un numero: ");
            scanf("%d",&tmp->primo);
            fprintf(pf," %d ",tmp->primo);
            p=incoda(p,tmp->primo);*/

            tmp->primo=rand()%100+1;        //SE VOGLIO NUMERI CASUALI NEL FILE!!!
            fprintf(pf," %d ",tmp->primo);
            p=incoda(p,tmp->primo);
        }
    }
    else
    {
        printf("errore");
    }

    fclose(pf);

    return p;
}

nodo*modificaFile(nodo*p,FILE*pf)
{
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    pf=fopen("qw.txt","a");             ///ho messo "a" in append,cioè aggiunge a quello che già c'è e NON sovrascrive.
    if(pf)
    {
        printf("digita per scrivere sul file:   ");
        scanf("%d",&tmp->primo);
        fprintf(pf," %d ",tmp->primo);
        p=incoda(p,tmp->primo);
    }
    else
    {
        printf("errore");
    }

    fclose(pf);
    return p;
}

int LunghezzaFile(FILE*pf)
{
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    int cont=0;
    pf=fopen("qw.txt","r");
    if(pf)
    {
        while(fscanf(pf," %d ",&tmp->primo)==1)
        {
            cont++;
        }
    }
    else
    {
        printf("errore");
    }
    fclose(pf);
    return cont;
}



