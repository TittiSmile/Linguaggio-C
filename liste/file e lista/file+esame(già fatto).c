/*dato un intero l fare in c:
1)una funzione che inizializza l con 50 interi casuali tra 1 e 100
2)una funzione che,letto un intero n da tastiera,rimuova le occorrenze di n da l n e stampi le occorrenze rimosse
3)una funzione che crei una lista M,contenente solo gli elementi di l che sono multipli di 3  e stampisu schermo la lunghezza di m
   questo è l'esame del 24 giu 2016. già l'ho fatto ma ho deciso di rifarlo e aggiungere i file*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;                                ///leggere soltanto i numeri pari da file

nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
int occorrenza(nodo*p,int a);
nodo*elocc(nodo*p,int a);
nodo*multiplo(nodo*p);
int lunghezza(nodo*p,int dim);
void stampa(nodo*p);
nodo*casuale(nodo*p,int dim);
///
nodo*leggi(FILE*pf);
nodo*scrivi(FILE*pf,int dim);
nodo*modifica(FILE*pf,nodo*p);
int lenfile(FILE*pf);

int main ()
{
    nodo*l=NULL;
    nodo*l2=NULL;
    FILE*pf;
    int dim,i=0,n;

    printf("grandezza lista?  ");
    scanf("%d",&dim);
    l=casuale(l,dim);
    stampa(l);

    /*printf("\nquale occorrenza eliminare? ");
    scanf("%d",&n);
    printf("\nle occorrenze di %d sono: %d",n,occorrenza(l,n));
    l=elocc(l,n);
    printf("\noccorrenze di %d eliminate ",n);
    stampa(l);*/

    printf("\nlista che contiene solo i multipli di 3: ");
    l2=multiplo(l);   ///l resta invariata,ovviamente
    stampa(l2);

    printf("\nscrivo sul file i multipli: ");
    l2=modifica(pf,l2);


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

nodo*multiplo(nodo*p)
{
     nodo*tmp;             ///svolgimento uguale a 'klista' solo che cambia la condizione dell'if
    if(p==NULL)
    {
        return p;
    }
    tmp=multiplo(p->next);
    if(p->primo%3==0)
    {
        tmp=incoda(tmp,p->primo);
    }
    return tmp;
    ///            N.B.!!!!!!!
    ///questa due funzioni,alla fine,restituiscono la stessa cosa (i multipli di 3). solo che,la prima ti INSERISCE IN CODA
    ///i non multipli(quindi,nel caso tu voglia continuare a lavorare con i non multipli,puoi farlo) mentre la seoncda ti ELIMINA
    ///tutti i numeri che non sono multipli di 3 (quindi li hai persi per sempre e non puoi lavorarci più).
    /*nodo*tmp=p;
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
    return p;*/


}

int lunghezza(nodo*p,int dim)
{
    int i=0;
    int len=0;
    for(i=0;i<dim;i++)
    {
        len++;
    }
    return len;
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d->",p->primo);
        p=p->next;
    }
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

///
nodo*leggi(FILE*pf)
{
    nodo*p=NULL;
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    pf=fopen("file+esame(gia' fatto).txt","r");
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
    int i=0;
    nodo*p=NULL;
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    pf=fopen("file+esame(gia' fatto).txt","w");
    if(pf)
    {
        /*for(i=0;i<dim;i++)
        {
            printf("inserisci numero:  ");
            scanf("%d",&tmp->primo);
            fprintf(pf," %d ",tmp->primo);
            p=incoda(p,tmp->primo);
        }*/

        ///STO USANDO UNA FUNZIONE CHE GENERA NUMERI CASUALI,HO BISOGNO DI QUESTO SE VOGLIO SCRIVERE DIRETTAMENTE LA LISTA
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
    pf=fopen("file+esame(gia' fatto).txt","w");
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
    pf=fopen("file+esame(gia' fatto).txt","");
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
