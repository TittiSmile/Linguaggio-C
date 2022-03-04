/* TRACCIA PROG II LAB
data una lista di caratteri si realizzino in C:
1)una funzione che popoli L con 50 caratteri ASCII casuali
2)una funzione che calcoli quanti caratteri sono compresi tra a e z (codice a=97,z=122)
3)una funzione che,letto un carattere c da tastiera,conti il numero di occorrenze di c in L e crei una nuova lista L1
  contenente tutti i caratteri di L tranne c
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct LISTA
{
    char primo;
    struct LISTA*next;
}nodo;

nodo*nelem(char a);
nodo*incoda(nodo*p,char a);
char casuale(char a);
int contachar(nodo*p);
int occorrenza(nodo*p,char a);
nodo*elocc(nodo*p,char a);
void stampa(nodo*p);

int main ()
{
    nodo*l=NULL;
    nodo*l1=NULL;
    char a=0,c=0;
    int i=0,n,dim,var,temp,flag=0;

    ///1

    printf("\t***CREO LA LISTA CON NUMERO DI CARATTERI DEFINITI DALL'UTENTE***");
    printf("\nquanto vuoi grande la lista?");
    scanf("%d",&dim);

    for(i=0;i<dim;i++)
    {
          a=rand()%25+'a';
         //a=casuale(a);             ///N.B. la funzione è corretta!! solo che mi dà sempre lo stesso carattere
          l=incoda(l,a);
    }
    stampa(l);

    ///2

    printf("\n\t***CALCOLO QUANTI CARATTERI SONO COMPRESI TRA A E Z***");
    printf("\nconto quanti caratteri sono compresi tra 'a' e 'z':   ");
    var=contachar(l);
    printf("%d",var);

    ///3

    printf("\n\t***CONTO ED ELIMINO LE OCCORRENZE***");
    printf("\ndi quale carattere vuoi contare l'occorrenza ed eliminare? ");
    scanf("%c",&c);                                                         ///non so per quale motivo non legge la scanf.
    scanf("%c",&c);                                                         ///l'ho messo 2 volte perchè la 1 non lo legge ._.
    ///N.B. SE USI 'fflush(stdin)' VIENE PULITO IL BUFFER DI INPUT

    flag=occorrenza(l,a);
    printf("\nle occorrenze di %c sono: %d ",c,flag);
    printf("\nelimino le sue occorrenze: ");
    l1=elocc(l,a);                              ///mi elimina l'ultimo elemento anche se la funzione è corretta
    stampa(l1);

    printf("\n\n\t\t***___TITTI BOMBER___***");

    return 0;
}



nodo*nelem(char a)
{
    nodo*q=(struct LISTA*)malloc(sizeof(struct LISTA));
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

char casuale(char a)
{
    srand( (unsigned)time( NULL ) );
   ///in questo caso,sto dicendo che devi prendere casualmente i caratteri dell'alfabeto(25)
    a=rand()%25+'a';
    return a;
}

int contachar(nodo*p)
{
    int flag=0;
    if(p!=NULL)
    {
        if(p->primo>='a' && p->primo <= 'z')
        {
            flag=1+contachar(p->next);
        }
        else
        {
            flag=contachar(p->next);
        }
    }
    /*while(p!=NULL)              metodo iterativo
    {
       if(p->primo>='a' && p->primo <= 'z')
       {
           flag++;
       }
       p=p->next;
    }*/
    return flag;
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

nodo*elocc(nodo*p,char a)
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
        printf("\n%c ",p->primo);
        p=p->next;
    }
}

