#include <stdio.h>
/*
N.B.!!!!
alcune funzioni non funzionano bene anche se il tutto sembra essere scritto in modo  corretto.
per la funzione 'unisci', puoi vedere l'esercizio che già ho fatto ('liste unite + ordine').
non so perchè,pur essendo uguale la funzione,in questo esercizio va in loop.
l'altra funzion ( 'interseca') funziona seppur con degli errori di output.
                                  ***AGGIORNAMENTO***
per rendere il programma migliore e senza "problemi" ho tentato di fare uno switch case. le funzioni,prese singolarmente,funzionano
o almeno così pare. l'unico problema è che facendo tutto di seguito,il programma va in loop. ci sono anche problemi nella stampa
della funzione 'elimina doppi'.
*/

typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;

void menu();
struct LISTA *nelem(int a);
struct LISTA *intesta(struct LISTA *p,int a);
struct LISTA *incoda(struct LISTA *p,int a);
struct LISTA *ricerca(struct LISTA *p,int a);
struct LISTA *alterna(struct LISTA *l1,struct LISTA *l2);
struct LISTA *unisci(struct LISTA *l1,struct LISTA *l2);
struct LISTA *interseca(struct LISTA *l1,struct LISTA *l2);
struct LISTA *eliminadoppi(struct LISTA *p);
void stampa(struct LISTA *p);


int main ()
{
    struct LISTA *l1=NULL;
    struct LISTA *l2=NULL;
    struct LISTA *l3=NULL;
    int dim=0,dom=0,num=0, mun=0,i=0,scelta;


printf("Quanti elementi vuoi nella lista 1? \n");
scanf("%d",&dim);
printf("Quanti elementi vuoi nella lista 2? \n");
scanf("%d",&dom);

for(i=0;i<dim;i++)
{
    printf("Inserisci %d elemento nella lista 1!!! ",i+1);
    scanf("%d",&num);
    l1=incoda(l1,num);
}

for(i=0;i<dom;i++)
{
    printf("inserisci %d elemento nella lista 2!!! ",i+1);
    scanf("%d",&mun);
    l2=incoda(l2,mun);
}

menu();
do
{
    printf("\n\n\t\tcosa vuoi fare ora?\n");
    scanf("%d",&scelta);
    switch(scelta)
    {
        case 1:
            printf("\nGli elementi nella lista 1 sono:\n");
            stampa(l1);
            printf("\nGli elementi nella lista 2 sono:\n");
            stampa(l2);
            break;
        case 2:
            printf("\nGli elementi (alternati) delle due liste  sono:\n");
            l3=alterna(l1,l2);
            stampa(l3);
            break;
        case 3:
            printf("\nGli elementi (uniti) delle due liste sono:\n ");
            l3=unisci(l1,l2);
            stampa(l3);
            break;
        case 4:
            printf("\nGli elementi (intersecati) delle due liste  sono:\n");
            l3=interseca(l1,l2);
            stampa(l3);
            if(l3==NULL)
            {
                printf("\nLista vuota!! NON ci sono elementi da intersecare\n");
            }
            break;
        case 5:
            printf("\nElimina elementi doppi\n");
            l3=eliminadoppi(l3);
            stampa(l3);
            break;
        case 6:
            printf("\narrivederci\n");
            break;
        default:
            printf("\nerrore\n");
            break;
    }

}while(scelta!=6);




/*printf("\nGli elementi nella lista 1 sono:\n");
stampa(l1);
printf("\nGli elementi nella lista 2 sono:\n");
stampa(l2);

printf("\nGli elementi (alternati) delle due liste  sono:\n");
l3=alterna(l1,l2);
stampa(l3);

//printf("\nGli elementi (uniti) delle due liste  sono:\n");
//l3=unisci(l1,l2);
//stampa(l3);


printf("\nGli elementi (intersecati) delle due liste  sono:\n");
l3=interseca(l1,l2);
stampa(l3);*/



    return 0;
}



void menu()
{
    printf("1)stampa le liste\n2)stampa le liste in modo alternato\n3)unisci gli elementi delle liste\n");
    printf("4)interseca gli elementi delle liste\n5)elimina i duplicati\n6)esci\n");
}


struct LISTA *nelem(int a)
{
 struct LISTA *q=(struct LISTA *)malloc(sizeof(struct LISTA));
 q->primo=a;
 q->next=NULL;
 return q;
}

struct LISTA *intesta(struct LISTA *p,int a)
{
 struct LISTA *q=nelem(a);
 q->next=p;
 return q;
}


struct LISTA *incoda(struct LISTA *p,int a)
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

struct LISTA *ricerca(struct LISTA *p,int a)
{
 struct LISTA *trovato=NULL;
 for(;p!=NULL && trovato==NULL;p=p->next)
 {
     if(p->primo==a)
     {
         trovato=p;
     }
 }
 return trovato;

}

struct LISTA *alterna(struct LISTA *l1,struct LISTA *l2)
{
    struct LISTA *l3=l1;
    if(l1==NULL)
    {
        return l2;
    }
    else if(l2==NULL)
    {
        return l1;
    }
    else
    {
        l2->next=alterna(l1->next,l2->next);
        l3->next=l2;
    }
    return l3;
};

/////////////////////////////
///N.B.!!!! non so perchè ma va in loop!!!
struct LISTA *unisci(struct LISTA *l1,struct LISTA *l2)
{
    struct LISTA *l3=NULL;
    if(l1==NULL)
    {
        return l2;
    }
    else if(l2==NULL)
    {
        return l1;
    }
    else if( l1->primo < l2->primo)
    {
        l3=l1;
        l3->next=unisci(l1->next,l2);
    }
    else
    {
        l3=l2;
        l3->next=unisci(l1,l2->next);
    }
    return l3;

};


///N.B.!!! non so perchè ma l'intersezione non è del tutto corretta
struct LISTA *interseca(struct LISTA *l1,struct LISTA *l2)
{

 struct LISTA *l3=NULL;
 if(l1)
 {
     l3=interseca(l1->next,l2);
     if(ricerca(l2,l1->primo))
     {
         l3=intesta(l3,l1->primo);
     }
 }
 return l3;

}
///questa funzione lascia l'ultima occorrenza!!!!
struct LISTA *eliminadoppi(struct LISTA *p)
{
 struct LISTA *tmp=p;
 struct LISTA *flag=p;
 if(p==NULL)
 {
     return p;
 }
 p->next=eliminadoppi(p->next);

 while(tmp!=NULL && tmp->next!=NULL)
 {
     tmp=tmp->next;
  if(p->primo == tmp->primo)
  {
      flag=p->next;
      free(p);
  }
   return flag;
 }

}


void stampa(struct LISTA *p)
{
    while(p!=NULL)
    {
        printf("\n %d",p->primo);
        p=p->next;
    }
}


