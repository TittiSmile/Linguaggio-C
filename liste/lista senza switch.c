#include <stdio.h>
#include <malloc.h>
typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;

nodo*creo_elemento(int a); ///la chiamo così per capire meglio. sarebbe la funzione 'nelem'
nodo*inserimento_in_testa(nodo*p,int a); ///sarebbe 'intesta'
nodo*inserimento_in_coda(nodo*p,int a); ///sarebbe 'incoda'
nodo*ricerca_elemento(nodo*p,int a);
nodo*elimina_lista(nodo*p);
int conta_occorrenze(nodo*p,int a);
nodo*elimina_occorrenze(nodo*p,int a);
void stampa_lista(nodo*p);
nodo*stampa_reverse(nodo*p);
int lunghezza_lista(nodo*p);
int somma(nodo*p);


int main ()
{

///stavolta non uso lo switch case, saranno funzioni una dopo l'altra (sperando che non si bugga)
nodo*l=NULL;
int num;

printf("|inserisci elemento in testa\n");
scanf("%d",&num);
l=inserimento_in_testa(l,num);

printf("|inserisci elemento in coda\n");
scanf("%d",&num);
l=inserimento_in_coda(l,num);

printf("|ricerca elemento\n");
scanf("%d",&num);
if(ricerca_elemento(l,num))
{
   printf("\n elemento trovato\n");
}
else
{
     printf("\n elemento NON trovato\n");
}

/*printf("\nelimino la lista\n");
elimina_lista(l);
stampa_lista(l);*/                /// se stampo dopo l'eliminazione,si va in loop. la funzione è corretta ma probabilmente
                                   ///non avendo lo switch il programma impazzisce


printf("\n|quale occorrenza vuoi contare?\n");
scanf("%d",&num);
printf("\nle occorrenze di %d sono %d ",num,conta_occorrenze(l,num));

/*printf("\n|di quale numero vuoi eliminare le occorrenze?\n");
scanf("%d",&num);
printf("\nelimino le occorrenze");
elimina_occorrenze(l,num);*/                                            ///stesso discorso della funzione 'elimina_lista'

stampa_lista(l);
printf("|reverse\n");
stampa_reverse(l);

printf("\n|la lunghezza della lista e': %d",lunghezza_lista(l));

printf("\n|la somma degli elementi della lista e': %d",somma(l));



    return 0;
}


nodo*creo_elemento(int a)
{
   nodo*q=(struct LISTA*)malloc(sizeof(struct LISTA));
   q->primo=a;
   q->next=NULL;
   return q;
}

nodo*inserimento_in_testa(nodo*p,int a)
{
    nodo*q=creo_elemento(a);
    q->next=p;
    return q;
}

nodo*inserimento_in_coda(nodo*p,int a)
{
    if(p==NULL)
    {
        p=creo_elemento(a);
    }
    else
    {
        p->next=inserimento_in_coda(p->next,a);
    }
    return p;
}


nodo*ricerca_elemento(nodo*p,int a)
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


nodo*elimina_lista(nodo*p)
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


int conta_occorrenze(nodo*p,int a)
{
    int flag=0;
   if(p!=NULL)
    {
        if(p->primo==a)
        {
            flag=1+conta_occorrenze(p->next,a);
        }
        else
        {
            flag=conta_occorrenze(p->next,a);
        }
    }
    return flag;
}

nodo*elimina_occorrenze(nodo*p,int a)
{
    nodo*tmp=p;
    if(p!=NULL)
    {
        if(p->primo==a)
        {
            p=elimina_occorrenze(p->next,a);
            free(tmp);
        }
        else
        {
         p->next=elimina_occorrenze(p->next,a);
        }
    }
    return p;
}

void stampa_lista(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n %d \n",p->primo);
        p=p->next;
    }
}

nodo*stampa_reverse(nodo*p)
{
    if(p==NULL)
        return 0;
    stampa_reverse(p->next);
    printf("\n %d \n",p->primo);
}

int lunghezza_lista(nodo*p)
{
    int len=0;
    while(p!=NULL)
    {
        p=p->next;
        len++;
    }
    return len;
}


int somma(nodo*p)
{
    int sum;
    if(p==NULL)
    {
        return 0;
    }
    else
    {
        sum=somma(p->next);
        sum+=p->primo;
        return sum;
    }

}
