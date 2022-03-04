#include <stdio.h>

typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;

void menu();
struct LISTA *nelem (int a);
struct LISTA *intesta (struct LISTA *p,int a);
struct LISTA *incoda (struct LISTA *p,int a);
struct LISTA *ricerca (struct LISTA *p,int a);
struct LISTA *elimina (struct LISTA *p);
void stampa(struct LISTA *p);
struct LISTA *rewerse (struct LISTA *p);

int main ()
{
    struct LISTA *lol=NULL;
    int scelta;
    int num;

    menu();

    do
    {
        printf("\n\tInserire la scelta\n");
        scanf("%d",&scelta);

        switch(scelta)
       {
        case 1:
            printf("\nInserisci numero\n");
            scanf("%d",&num);
            lol=intesta(lol,num);
            break;
        case 2:
            printf("\nInserisci numero\n");
            scanf("%d",&num);
            lol=incoda(lol,num);
            break;
        case 3:
            printf("\nInserisci numero da ricercare nella lista\n");
            scanf("%d",&num);
            lol=ricerca(lol,num);
            if(ricerca(lol,num))
            {
                printf("\nelemento trovato");
            }
            else
            {
                printf("\nelemento NON trovato");
            }
            break;
        case 4:
            printf("\nElimia lista\n");
            lol=elimina(lol);
            break;
        case 5:
            printf("\nStampa lista\n");
            stampa(lol);
            if(lol==NULL)
            {
                printf("Lista VUOTA!");
            }
            break;
        case 6:
            printf("\nStampa lista al contrario\n");
            lol=rewerse(lol);
            if(lol==NULL)
            {
                printf("Lista VUOTA!");
            }
            break;
        case 7:
            printf("Arrivederci");
            break;
        default:
            printf("Scelta non valida");
        }

    }while(scelta!=7);




    return 0;
}

void menu()
{
    printf("1)in testa\n2)in coda\n3)ricerca\n4)elimina lista\n5)stampa\n6)stampa al contrario\n7)esci");
}
struct LISTA *nelem (int a)
{
 struct LISTA *q=(struct LISTA*)malloc(sizeof(struct LISTA));
 q->primo=a;
 q->next=NULL;
 return q;
}


struct LISTA *intesta (struct LISTA *p,int a)
{
 struct LISTA *q=nelem(a);
 q->next=p;
 return q;
}

struct LISTA *incoda (struct LISTA *p,int a)
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



struct LISTA *ricerca (struct LISTA *p,int a)
{
   struct LISTA *trovato=NULL;
   for(;p!=NULL && trovato==NULL; p=p->next)
   {
       if(p->primo==a)
       {
           trovato=p;
       }
   }
       return trovato;
}



struct LISTA *elimina (struct LISTA *p)
{
    struct LISTA *temp;
    for(;p!=NULL;p=temp)
    {
        temp=p->next;
        p->next=NULL;
        free (p);
    }
    return p;
}


void stampa(struct LISTA *p)
{
    while(p!=NULL)
    {
       printf("Lista: %d \n",p->primo);
       p=p->next;
    }

}

struct LISTA *rewerse (struct LISTA *p)
{
 if(p==NULL)
        return 0;
 rewerse(p->next);
 printf("Lista rewerse: %d\n",p->primo);
}

