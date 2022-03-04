/*Data L una lista di caratteri si realizzino in C:
1)Una funzione che popoli L con 60 caratteri casuali tra a e z (codice ascii a = 97 , z=122)[.
2)Una funzione che calcoli il carattere che appare con maggiore frequenza in L.
3)Una funzione che letto un carattere c da tastiera crei due nuove liste L1 ed L2 dove L1 contiene tutti i caratteri alfabeticamente
  minori o uguali a c ed L2 tutti quelli maggiori. Le tre funzioni devono essere invocate in sequenza dal main e deve essere
stampato a schermo il contenuto delle liste al termine di ogni funzione.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
typedef struct LISTA
{
    char primo;
    struct LISTA*next;
}nodo;

nodo*nelem(char a);
nodo*incoda(nodo*p,char a);
int occorrenza(nodo*p,char a);
nodo*alfabmin(nodo*p,nodo*l1,char a);
nodo*alfabmin2(nodo*p,char a);
nodo*alfabmax(nodo*p,char a);
void stampa(nodo*p);
char casuale(char a);
nodo*cas(nodo*p,char a);


int main ()
{
    nodo*l1=NULL;
    nodo*l2=NULL;
    nodo*l3=NULL;
    int i=0,dim,n;
    char c;

    srand((unsigned)time(NULL));


    for(i=0;i<60;i++)
    {
        n=rand()%25+'a';
        l1=incoda(l1,n);
    }
    stampa(l1);

    printf("\nquale occorrenza vuoi cercare? ");
    scanf("%c",&n);
    printf("le occorrenze di %c sono: %d",n,occorrenza(l1,n));

    fflush(stdin);
    printf("\ninserisci un carattere: ");
    scanf("%c",&c);

    printf("\nnuova lista con caratteri minori di %c:\n ",c);
    l1=alfabmin2(l1,c);
    stampa(l1);

     for(i=0;i<60;i++)
    {
        n=rand()%25+'a';
        l1=incoda(l1,n);
    }
     printf("\nnuova lista con caratteri maggiori di %c:\n ",c);
    l1=alfabmax(l1,c);
    stampa(l1);




    return 0;
}

nodo*nelem(char a)
{
    nodo*q=(nodo*)malloc(sizeof(nodo));
    q->primo=a;
    q->next=NULL;
    return q;
}

nodo*incoda(nodo*p,char a)
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

int occorrenza(nodo*p,char a)
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

nodo*alfabmin(nodo*p,nodo*l1,char a) ///ho provato a farlo diversamente da alfabmin2 ma non è andata lol
{
    /*nodo*l3=NULL;
    while(l1!=NULL)
    {
        if(l1->primo <= a)
        {
            l3=incoda(l3,l1->primo);
        }
        l1=l1->next;
    }
    return l3;*/
    while(p!=NULL)
    {
        if(p->primo <=a)
        {
            l1=incoda(l1,p->primo);
        }
        p=p->next;
    }
    return l1;
}

nodo*alfabmin2(nodo*p,char a)
{
    nodo*tmp;
    if(p==NULL)
    {
        return p;
    }
    tmp=alfabmin2(p->next,a);
    if(p->primo <= a)
    {
        tmp=incoda(tmp,p->primo);
    }
    return tmp;

}

nodo*alfabmax(nodo*p,char a)
{
    nodo*tmp;
    if(p==NULL)
    {
        return p;
    }
    tmp=alfabmax(p->next,a);
    if(p->primo >= a)
    {
        tmp=incoda(tmp,p->primo);
    }
    return tmp;
}


void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf(" %c->",p->primo);
        p=p->next;
    }
    printf(" NULL.");
}

char casuale(char a)
{
    char c;
    srand((unsigned)time(NULL));
    c=rand()%25+'a';
    return c;
}

