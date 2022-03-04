///N.B. funziona TUTTO tranne la funzione primopari che è una merda =D
#include <stdio.h>
#define INT_MAX 1000
#define INT_MIN -1000
typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;

void menu();
nodo*nelem(int a);
nodo*intesta(nodo*p,int a);
nodo*incoda(nodo*p,int a);
nodo*ricerca (nodo*p,int a);
nodo*elimina (nodo*p);
void stampa (nodo*p);
nodo*rewerse (nodo*p);
nodo*primopari(nodo*p);

int main ()
{
    nodo*l=NULL;
    int i,scelta,num;

    menu();
do
{

    printf("\n\n\t\t inserire scelta:\n");
    scanf("%d",&scelta);

    switch(scelta)
    {
    case 1:
        printf("\ninserire in testa: ");
        scanf("%d",&num);
        l=intesta(l,num);
        break;
    case 2:
        printf("\ninserire in coda: ");
        scanf("%d",&num);
        l=incoda(l,num);
        break;
    case 3:
        printf("\ndigitare elemento da ricercare:");
        scanf("%d",&num);
        if(ricerca(l,num))
        {
            printf("\nelemento trovato");
        }
        else
        {
            printf("\nelemento NON trovato");
        }
        break;
    case 4:
        printf("\nelimino la lista");
        l=elimina(l);
        break;
    case 5:
        printf("\nstampo la lista");
        stampa(l);
        break;
    case 6:
        printf("\nstampo la lista al contrario");
        l=rewerse(l);
        break;
    case 7:
        printf("\nrestituisco il puntatore al numero pari più piccolo");
        printf("pari:%d\n ",primopari(l));
        break;
    default:
        printf("\nscelta non valida\n");
        break;
    }

}while(scelta!=7);




    return 0;
}


void menu()
{
    printf("1)inserisci in testa\n2)inserisci in coda\n3)ricerca elemento\n4)elimina lista\n5)stampa\n6)stampa al contrario\n");
    printf("7)ritorna puntatore minimo pari");
}

nodo*nelem(int a)
{
  nodo*q=(struct LISTA*)malloc(sizeof(struct LISTA)); //in c++ sarebbe: nodo*q=new nodo;
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

nodo*ricerca (nodo*p,int a)
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

nodo*elimina (nodo*p)
{
    nodo*temp=NULL;
    for(;p!=NULL;p=temp)
    {
        temp=p->next;
        p->next=NULL;
        free(p);
    }
    return p;
}

void stampa (nodo*p)
{
    while(p!=NULL)
    {
        printf("\nLista: %d \n",p->primo);
        p=p->next;
    }
}

nodo*rewerse (nodo*p)
{
    if(p==NULL)
    {
        return 0;
    }
    else
    {
        rewerse(p->next);
        printf("\nlista: %d \n",p->primo);
    }

}

nodo*primopari(nodo*p)
{
    nodo* pmin=NULL;
    int min=INT_MAX;
    if(p==NULL)
    {
        return p;
    }
    while(p!=NULL)
    {
        if((p->primo) % 2==0 && p->primo<min)
        {
            pmin=p;
            min=p->primo;
        }
         p=p->next;
    }
       return pmin;


}

/*
struct lista *massimoDispari (struct lista *top)
{
    struct lista *pmax=NULL;
    int max=INT_MIN;
     if (top==NULL)
            return NULL;
     while (top!=NULL)
     {
               if (top->dato%2!=0 && top->dato>max)
                {
                pmax=top;
                max=top->dato;
                }
          top=top->next;
        }
 return pmax;}
*/
