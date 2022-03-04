/*data una lista di interi si realizzi:
1) una funzoine che letti due interi n ed m da tastiera crei l di lunghezza n inizializzata con una sequenza di interi deresenti a partire da m
2)una funzione che,letto un intero p da tastieramduplichi tutte le occorrenze di p in l
3)una funzione che calcoli la media dei valori contenuti in l*/
#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

///non tutte le funzioni sono necessarie al fine dell'esercizio
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
//
nodo*insordine(nodo*p,int a);
nodo*ordina(nodo*p,nodo*tmp);
nodo*crescente(nodo*p);
float media(nodo*p);
int lunghezza(nodo*p);
nodo*duplica(nodo*p,int a);

int main()
{
    nodo*l=NULL;
    int i,n,m,num,p;
    float med;

    printf("quanto grande la lista?  ");
    scanf("%d",&n);
    printf("\ninserisci un numero m (da m in poi i numeri saranno decrescenti):  ");
    scanf("%d",&m);
    for(i=0;i<n;i++)
    {
        do
        {
            printf("elemento %d:  (scegli numeri da %d in giù) ",i+1,m);
            scanf("%d",&num);
                if(num>m)
                {
                    printf("\terrore! riprova\n");
                }
        }while(num>m);

        l=insordine(l,num);
        //l=incoda(l,num);
        //l=crescente(l);
    }
    stampa(l);

    printf("\ndigita un numero da duplicare nella lista:  ");
    scanf("%d",&p);
    l=duplica(l,p);
    l=crescente(l);
    stampa(l);

    printf("\nla media di tutti gli elementi e': %f ",media(l));

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
    nodo*trovato;
    for(;p!=NULL && trovato==NULL;p=p->next)
    {
        if(p->primo==a)
        {
            trovato=p;
        }
    }
    return p;
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
        printf("%d->\n",p->primo);
        p=p->next;
    }
}

nodo*reverse(nodo*p)
{
    if(p==NULL)
            return 0;
    reverse(p->next);
    printf("%d->\n",p->primo);
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
nodo*insordine(nodo*p,int a)
{
    nodo*tmp=(struct LISTA*)malloc(sizeof(struct LISTA));
  // nodo*tmp;
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

nodo*ordina(nodo*p,nodo*tmp)
{
    if(p==NULL || p->primo < tmp->primo)
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
    nodo*tmp=NULL;
    nodo*l=NULL;
    while(p!=NULL)
    {
        tmp=p;
        p=p->next;
        l=ordina(l,tmp);
    }
    return l;
}

float media(nodo*p)
{
    float m;
    int i=0;
    m=somma(p)/lunghezza(p);
    return m;
}

int lunghezza(nodo*p)
{
    int i=0;
    while(p!=NULL)
    {
        i++;
        p=p->next;
    }
    return i;
}

nodo*duplica(nodo*p,int a)
{
    int i=0;
    if(occorrenza(p,a)==1)
    {
        p=incoda(p,a);
    }
    else
        return p;
}
