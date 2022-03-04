/*data una lista di interi l creare:
1)una funzione che letto un intero n da tastiera popoli la lista con 50 interi casuali da 1 a n
2) una funzione che letto un intero p da tastiera conti le sue occorrenze
3)una funzione che letto un numero m da tastiera crei due nuove liste l1 e l2 dove l1 contiene i MULTIPLI di m e l'altra no  */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
int occorrenza(nodo*p,int a);
nodo*multiplo(nodo*p,int a);
void mul(nodo**l1,nodo**l2,nodo*p,int a);
void stampa(nodo*p);


int main ()
{
    nodo*l=NULL;
    nodo*l2=NULL;
    nodo*l3=NULL;
    int i,n,m,num,p;

    printf("inserisci un numero n: ");
    scanf("%d",&n);
    srand((unsigned)time(NULL));
    for(i=0;i<50;i++)
    {
        num=rand()%n+1;
        l=incoda(l,num);
    }
    stampa(l);

    printf("\n quale occorrenza vuoi contare?  ");
    scanf("%d",&p);
    printf("\nle occorrenze di %d sono: %d",p,occorrenza(l,num));

    printf("\ninserisci un numero m: ");
    scanf("%d",&m);
    printf("\ncreo una lista coi multipli di %d ",m);
  //  l2=multiplo(l,num);
   // stampa(l2);
   mul(&l2,&l3,l,m);
   printf("\nmultipli di %d: \n",m);
   stampa(l2);
   printf("\nNON multipli di %d: \n",m);
   stampa(l3);


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
             flag=+occorrenza(p->next,a);
        }
    }
    return flag;
}

nodo*multiplo(nodo*p,int a)
{
   /*nodo*tmp;
   if(p==NULL)
   {
       return p;
   }
   tmp=multiplo(p->next,a);
   if(p->primo%a==0)
   {
       tmp=incoda(tmp,p->primo);
   }
   return tmp;*/

}

void mul(nodo**l1,nodo**l2,nodo*p,int a)
{
    while(p!=NULL)
    {
        if(p->primo%a==0)
        {
            *l1=incoda(*l1,p->primo);
        }
        else
        {
           * l2=incoda(*l2,p->primo);
        }
            p=p->next;
    }

}


void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("%d->  ",p->primo);
        p=p->next;
    }
}

