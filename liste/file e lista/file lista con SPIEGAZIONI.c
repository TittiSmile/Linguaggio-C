#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
nodo*elocc(nodo*p,int a);
nodo*casuale(nodo*p,int dim);
void stampa(nodo*p);
///
nodo*leggi(FILE*pf);
nodo*scrivi(FILE*pf,int dim);
nodo*modifica(FILE*pf,nodo*p);
int lenfile(FILE*pf);

int main ()
{
    nodo*l=NULL;
    FILE*pf;
    int i=0,dim,n;

    printf("grandezza lista?  ");
    scanf("%d",&dim);

   // l=casuale(l,dim);
    printf("\nscrivo nella lista:");
    l=scrivi(pf,dim);
    stampa(l);

    printf("\nleggo dalla lista:");
    l=leggi(pf);
    stampa(l);

    ///FACOLTATIVI!!!! servono,rispettivamente,a mettere in "pausa il terminale" e a pulire il terminale da ciò che c'era prima
    system("PAUSE");
    system("CLS");

    printf("\nquale occorrenza vuoi eliminare?  ");
    scanf("%d",&n);
    l=elocc(l,n);
    stampa(l);

    printf("\nmodifico la lista!!");
    l=modifica(pf,l);
    stampa(l);

    printf("\ngli elementi nel file sono: %d",lenfile(pf));



    return 0;
}

nodo*nelem(int a)
{
    nodo*q=(nodo*)malloc(sizeof(nodo));
    q->primo=a;
    q->next=NULL;
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

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d->",p->primo);
        p=p->next;
    }
}

///
nodo*leggi(FILE*pf)   ///legge il contenuto del file e lo inserisce nella coda di una lista vuota (ci serve se vogliamo stamparla
{
    nodo*p=NULL;
   nodo*tmp=(nodo*)malloc(sizeof(nodo));
   pf=fopen("file lista con spiegazioni.txt","r");
   if(pf)
   {
       while(!feof(pf))
       {
           fscanf(pf," %d ",&tmp->primo);   ///è importante mettere %d tra due spazi(uno dietro e uno avanti)
           p=incoda(p,tmp->primo);
       }
   }
   else
   {
       printf("\nerrore di apertura");
   }

   fclose(pf);
   return p;
}

nodo*scrivi(FILE*pf,int dim)/*questa funzione scrive direttamente sul file. cioè, nel momento in cui si acquisisce la lista,
                            la si mette nel file. la lista viene scritta in contemporanea col file*/
{
   nodo*p=NULL;
   nodo*tmp=(nodo*)malloc(sizeof(nodo));
   int i=0;
   pf=fopen("file lista con spiegazioni.txt","w");
   if(pf)
   {                               ///VERSIONE non CASUALE!!!! INSERISCI TU 'MANUALMENTE' I NUMERI
      /*for(i=0;i<dim;i++)
      {
           printf("inserisci numero:  ");   ///come dicevo,inserisce direttamente l'elemento nella lista e,contemporaneamente,lo crea nel file
          scanf("%d",&tmp->primo);         ///metto tmp->primo perchè si tratta di acquisire un elemento della lista che va messo nel file
          fprintf(pf," %d ",tmp->primo);   ///lo scrivo nel file! senza & perchè non stiamo leggendo da file ma stiamo scriendo(o stampando) sul file
          p=incoda(p,tmp->primo);
      }*/
                                            ///VERSIONE CON RAND(CASUALE)
      srand((unsigned)time(NULL));
      for(i=0;i<dim;i++)
      {
        tmp->primo=rand()%100+1;      ///tmp->primo (che sarà il numero casuale,dovrà essere casuale! (you don't say)
        fprintf(pf," %d ",tmp->primo);
        p=incoda(p,tmp->primo);
      }
   }
   else
   {
       printf("\nerrore di apertura");
   }

   fclose(pf);
   return p;
}

nodo*modifica(FILE*pf,nodo*p)    ///questa funzione scrive sul file ma senza farlo in contemporanea sulla lista.
                                ///si può,ad esempio,creare una lista e svolgere farie funzioni su di essa e,infine,tramite questa funzione,si scrve tutto su un file
{
   nodo*tmp=(nodo*)malloc(sizeof(nodo));
   pf=fopen("file lista con spiegazioni.txt","w");
   if(pf)
   {
       while(p!=NULL)      ///dimostrazione del fatto che la lista deve prima essere creata ed inizializzata (non come 'scrivi' che viene creata simultaneamente)
       {
           fprintf(pf," %d ",p->primo);   ///scrivo man mano il contenuto della lista (già creata,inizializzata ecc)su un file
           p=p->next;
       }
   }
   else
   {
       printf("\nerrore di apertura");
   }

   fclose(pf);
   return ;
}

int lenfile(FILE*pf)    ///Serve a contare quanti elementi ci sono nel file... fa sempre comodo saperla
{
   nodo*tmp=(nodo*)malloc(sizeof(nodo));
   int cont=0;
   pf=fopen("file lista con spiegazioni.txt","r");
   if(pf)
   {
       while(fscanf(pf," %d ",&tmp->primo)==1)
       {
           cont ++;
       }
   }
   else
   {
       printf("\nerrore di apertura");
   }

   fclose(pf);
   return cont ;
}
