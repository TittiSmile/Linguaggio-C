#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define MAX 20
#include "basic.h"
#include "SuDueListe.h"
#include "listaSuK.h"
#include "ordinamento.h"
#include "other.h"
#include "structStudente.h"
#include "linkedToDoubly.h"
#include "listaFile.h"

int main()
{

    nodo*l1=NULL;
    nodo*l2=NULL;
    nodo*l3=NULL;
    nodo*l5=NULL;

    int i=0,k,dim,n,a,dom,m,cas,dupl;

    FILE*pf=NULL;

    stud**s=NULL;

    doppia*l4=NULL;
    printf("quanto vuoi grande la tua lista? ");
    scanf("%d",&dim);

    /*for(i=0;i<dim;i++)
    {
        printf("inserisci %d elemento lista 1:   ",i+1);     ///QUANDO non mi scoccio di digitare
        scanf("%d",&n);
        l1=incoda(l1,n);
    }
    stampa(l1);*/

                                                        //l1=CasualiLista(l1,dim);
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
   /* printf("\nquanto vuoi grande la tua lista? ");
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
