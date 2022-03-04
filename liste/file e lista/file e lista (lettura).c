#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

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


int main ()
 {
     nodo*l=NULL;
     int dim,n,i=0;
     FILE*pf;
     int res,a;

     /*printf("quanti elementi nella lista? ");
     scanf("%d",&dim);

     for(i=0;i<dim;i++)
     {
         printf("inserisci %d elemento ",i+1);
         scanf("%d",&n);
         l=incoda(l,n);
     }*/

    /* printf("\nquale elemento vuoi cercare? ");
     scanf("%d",&n);
     l=ricerca(l,n);
     if(ricerca(l,n))
     {
         printf("elemento trovato!\n");
     }
     else
     {
         printf("elemento NON trovato!\n");
     }

     printf("\nquale occorrenza vuoi contare? ");
     scanf("%d",&n);
     printf("\nle occorrenze di %d sono: %d ",n,occorrenza(l,n));

    printf("\nquale occorrenza vuoi eliminare?  ");                  ///con la funzione ricerca non funziona ò.ò non so perchè
    scanf("%d",&n);
    l=elocc(l,n);
    stampa(l);*/

    /*reverse(l);

    printf("la somma di tutti gli elementi e': %d",somma(l));

    printf("\nelimino tutta la lista");
    l=elimina(l);

    stampa(l);
    if(l==NULL)
    {
        printf("\nlista vuota!");
    }*/
                                       ///****LEGGO DA FILE****///

  /* l=(struct LISTA*)malloc(sizeof(struct LISTA));
    pf=fopen("lista.txt","r");
    while(!(feof(pf)))
    {
        res=fscanf(pf,"%d",&l->primo);
        printf("%d->",l->primo);
        l=l->next;
        i++;
    }
    fclose(pf);*/                     ///questo è il mio metodo! ma,dopo aver letto i numeri,va in crash quindi non funziona

    nodo*tmp;

    pf=fopen("lista.txt","r");
    while(1)
    {
        res=fscanf(pf,"%d",&a);
        if(res!=1)
        {
            break;
        }
            if(l==NULL)
            {
                l=(struct LISTA*)malloc(sizeof(struct LISTA));
                tmp=l;
            }
            else
            {
                tmp->next=(struct LISTA*)malloc(sizeof(struct LISTA));
                tmp=tmp->next;
            }
            tmp->primo=a;
            tmp->next=NULL;

    }


    fclose(pf);
    stampa(l);


    ///legge ma va in crash subito dopo. probabilmente ci vuole qualche condizione di uscita

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
    }
    return flag;
}

nodo*elocc(nodo*p,int a)
{
  /*  nodo*tmp=p;
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
    return p;*/
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
