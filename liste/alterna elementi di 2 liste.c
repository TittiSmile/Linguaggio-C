#include <stdio.h>
#include <malloc.h>
typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;

nodo*crea_elemento(int a); ///sarebbe la funzione 'nelem' metto nomi più lunghi per capire meglio e perchè all'esame sarà così ^-^
nodo*inserimento_in_testa(nodo*p,int a);
nodo*inserimento_in_coda(nodo*p,int a);
nodo*alterna_elementi_liste(nodo*l1,nodo*l2);
void stampa(nodo*p);
nodo*stampa_reverse(nodo*p);


int main ()
{
 ///non userò lo switch case perchè mi sembra piuttosto inutile ma,nel caso in cui volessi farlo,basta semplicemente fare
 ///come con tutti gli altri esercizi... non cambia un cazzo (case 1 in testa, case 2,in coda,case 3,alerna lista,case 4 stampa
 /// case 5 stampa al contrario,case 5 arrivederci,default scelta non valida. ricordarsi il menu!)

nodo*l1=NULL;
nodo*l2=NULL;
nodo*l3=NULL;
int dim1,i=0,num1;
int dim2,j=0,num2;

printf("|quanti elementi vuoi nella lista 1? ");
scanf("%d",&dim1);
for(i=0;i<dim1;i++)
{
    printf("\tinserisci %d elemento nella lista 1:",i+1);
    scanf("%d",&num1);
    l1=inserimento_in_coda(l1,num1);
}
printf("\t\tlista 1:\n");
stampa(l1);

printf("\n|quanti elementi vuoi nella lista 2? ");
scanf("%d",&dim2);
for(j=0;j<dim2;j++)
{
    printf("\tinserisci %d elemento nella lista 1:",j+1);
    scanf("%d",&num2);
    l2=inserimento_in_coda(l2,num2);
}
printf("\t\tlista 2:\n");
stampa(l2);

printf("\n|alterno elementi lista 1 e lista 2: ");
l3=alterna_elementi_liste(l1,l2);
stampa(l3);


    return 0;
}




nodo*crea_elemento(int a)
{
    nodo*q=(struct LISTA*)malloc(sizeof(struct LISTA));
    q->primo=a;
    q->next=NULL;
    return q;
}

nodo*inserimento_in_testa(nodo*p,int a)
{
   nodo*q=crea_elemento(a);
   q->next=p;
   return q;
}

nodo*inserimento_in_coda(nodo*p,int a)
{
   if(p==NULL)
   {
       p=crea_elemento(a);
   }
   else
   {
       p->next=inserimento_in_coda(p->next,a);
   }
   return p;
}


nodo*alterna_elementi_liste(nodo*l1,nodo*l2)
{
    nodo*l3=l1;
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
        l2->next=alterna_elementi_liste(l1->next,l2->next);
        l3->next=l2;
    }
    return l3;
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n %d \n",p->primo);
        p=p->next;
    }
}

nodo*stampa_reverse(nodo*p)
{
    if (p==NULL)
        return 0;
    stampa_reverse(p->next);
    printf("\n%d\n",p->primo);
}
