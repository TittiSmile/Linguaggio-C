///le funzioni singole sono corrette ma messe insieme in un programma, danno problemi.
#include <stdio.h>
#include <malloc.h>
typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;


void menu();
nodo*nelem(int a);
nodo*intesta(nodo*p,int a);
nodo*incoda(nodo*p,int a);
nodo*ricerca(nodo*p,int a);
nodo*elimina(nodo*p);
nodo*alterna(nodo*l1,nodo*l2);
nodo*unisci(nodo*l1,nodo*l2);
nodo*interseca(nodo*l1,nodo*l2);
nodo*elimina_doppi(nodo*p);
void dealloca(nodo*p);
void stampa(nodo*p);

int main ()
{
    nodo*l1=NULL;
    nodo*l2=NULL;
    nodo*l3=NULL;
    int scelta,i=0,j=0;
    int len1,len2;
    int numl1,numl2;

    printf("\nquanto vuoi grande la lista 1?\n");
    scanf("%d",&len1);
    printf("\nquanto vuoi grande la lista 2?\n");
    scanf("%d",&len2);

    for(i=0;i<len1;i++)
    {
        printf("\ninserisci %d elemento della lista 1:  ",i+1);
        scanf("%d",&numl1);
         l1=incoda(l1,numl1);
    }

      for(j=0;j<len2;j++)
    {
        printf("\ninserisci %d elemento della lista 2:  ",j+1);
        scanf("%d",&numl2);
        l2=incoda(l2,numl2);
    }

    menu();

    do
    {
        printf("\n\t\tcosa vuoi fare?   ");
        scanf("%d",&scelta);

        switch(scelta)
        {
        case 1:
            printf("\nalterno elementi delle due liste:\n");
            l3=alterna(l1,l2);
            stampa(l3);
            dealloca(l3);
            break;
        case 2:
            printf("\nunisco elementi delle due liste:\n");
            l3=unisci(l1,l2);
            stampa(l3);
            dealloca(l3);
        case 3:
            printf("\nfaccio l'intersezione degli elementi in comune:\n");
            l3=interseca(l1,l2);
            stampa(l3);
            dealloca(l3);
            break;
        case 4:
            printf("\nelimino i numeri doppi\n");
            l3=elimina_doppi(l3);
            stampa(l3);
            dealloca(l3);
            break;
        case 5:
            printf("\nelimino tutto\n");
            l1=elimina(l1);
            l2=elimina(l2);
            dealloca(l3);
            break;
        case 6:
            printf("\narrivederci\n");
            break;
        default:
            printf("\nscelta non valida\n");
            break;

        }

    }while(scelta!=6);

    return 0;
}


void menu()
{
 printf("\t****\n1)alterna elementi lista 1 e lista 2\n2)unisci elementi lista 1 lista 2\n3)interseca elementi in comune");
 printf("\n4)elimina elementi doppi\n5)elimina tutte le liste\n6)esci\n");
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
    nodo*tmp=NULL;
    for(;p!=NULL;p=tmp)
    {
        tmp=p->next;
        p->next=NULL;
        free(p);
    }
    return p;
}

nodo*alterna(nodo*l1,nodo*l2)
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
       l2->next=alterna(l1->next,l2->next);
       l3->next=l2;
   }
   return l3;
}

nodo*unisci(nodo*l1,nodo*l2)
{
    nodo*l3=NULL;
    if(l1==NULL)
    {
        return l2;
    }
    else if(l2==NULL)
    {
        return l1;
    }
    else if(l1->primo < l2->primo)
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
}

nodo*interseca(nodo*l1,nodo*l2)
{
    nodo*l3=NULL;
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


nodo*elimina_doppi(nodo*p)
{
    nodo*tmp=p;
    nodo*flag=p;
    if(p==NULL)
    {
        return p;
    }
    p->next=elimina_doppi(p->next);
    while(tmp!=NULL && tmp->next!=NULL)
    {
        tmp=tmp->next;
        if(p->primo == tmp->primo)
        {
            flag=p->next;
            free(p);
        }
    }
    return flag;
}


void dealloca(nodo*p)
{
    if(p!=NULL)
    {
        dealloca(p->next);
        p->next=NULL;
        free(p);
    }
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\nlista: %d \n",p->primo);
        p=p->next;
    }
}
