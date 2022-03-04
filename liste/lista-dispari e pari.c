#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;

nodo*nelem(int a);/// scrivo 'nodo*nelem (int a)' per fare prima. è identico all'uso di 'struct LISTA *nelem (int a)'
nodo*intesta(nodo*p,int a);
nodo*incoda(nodo*p,int a);
nodo*dispari_prima(nodo*p); /// tutti i numeri dispari andranno prima dei pari
nodo*newpari(nodo*p); /// questa funzione mette i numeri pari in un'altra lista
void stampa(nodo*p);

int main ()
{
    nodo*p=NULL;
    nodo*p2=NULL;
    int i=0,num=0,dim=0;

    /*printf("quanti numeri nella lista?\n");
    scanf("%d",&dim);

    for(i=0;i<dim;i++)
    {
        printf("inserisci %d numero ",i+1);
        scanf("%d",&num);
        p=incoda(p,num);
    }
    printf("La lista e' \n");
    stampa(p);*/

    p=incoda(p,2);p=incoda(p,5);p=incoda(p,6);p=incoda(p,7);
    stampa(p);

    printf("mettiamo i numeri dispari prima dei pari");
    p=dispari_prima(p);
    stampa (p);

    /*printf("\ni pari in un'altra lista\n");
    p=newpari(p);
    stampa(p);*/

    return 0;
}






nodo*nelem(int a)
{
   struct LISTA *q=(struct LISTA*)malloc(sizeof(struct LISTA));
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


///N.B.!!!!!
/// ho fatto due procedimenti perchè:
/// il primo,quello commentato, è stato fatto dalla mia testolina però gli elementi pari (quelli che secondo la traccia devono
/// andare alla fine) appaiono come indirizzo di memoria. mentre nella seconda funzione va tutto liscio. entrambe sono corrette
///tranne per l'errore nel primo procedimento.
nodo*dispari_prima(nodo*p)
{
                        ///non riesco a farla ricorsiva D:
    /*nodo*tmp;
    if(p==NULL)
    {
        return p;
    }
    p->next=dispari_prima(p->next);
    if(p->primo%2==0)
    {

    }
    return p;*/

  /* nodo*tmp=p;
   if(p==NULL || p->next==NULL)
   {
       return p;
   }
   tmp=dispari_prima(p->next);
   if(p->primo%2!=0)
   {
       p->next=tmp;
       return p;
   }
   else
   {
       tmp=incoda(tmp,p);
       return tmp;
   }*/
 nodo*tmp=p;
 int flag=0;
 if(p!=NULL)
 {
     while(tmp!=NULL)
     {
             if(tmp->primo%2!=0)
         {
             flag=p->primo;
             p->primo=tmp->primo;
             tmp->primo=flag;
         }
          tmp=tmp->next;
     }
     //p->next=p->next; //serve per rendere la funzione totalmente ITERATIVA
        //p->next=dispari_prima(p->next);  questo è il passaggio ricorsivo.
 }

 return p;
}

///N.B. questa è un'altra funzione fatta da me ma,come quella di sopra,non va bene in quanto non dà i numeri ma il loro indirizzo
/// probabilmente c'è qualcosa che non va ma dovrebbe essere ugualmente corretta.
//aggiornamento: corretta (anche se questa funzione non ha senso ma vbb)

nodo*newpari(nodo*p)
{
    nodo*tmp;
    if(p==NULL)
    {
        return p;
    }
    tmp=newpari(p->next);
    if(p->primo%2==0)
    {
        tmp=intesta(tmp,p->primo);
    }
    return tmp;
}




void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d\n",p->primo);
        p=p->next;
    }
}

