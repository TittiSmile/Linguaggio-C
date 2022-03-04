#include <stdio.h>
#include <malloc.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

void menu();
nodo*nelem(int a);
nodo*intesta(nodo*p,int a); ///non è necessaria questa funzione ma l'ho messa lo stesso (:
nodo*incoda(nodo*p,int a);
nodo*ricerca(nodo*p,int a);
nodo*elimina(nodo*p);
nodo*elimina_k(nodo*p,int k);
nodo*minori_prima_k(nodo*p,int k);
void stampa(nodo*p);



int main ()
{
    nodo*l=NULL;
    int k,scelta,num,dim;
   // int n,i=0,numero;

    /*printf("quanto vuoi grande la tua lista? ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
       printf("\ninserisci %d numero ",i+1);
       scanf("%d",&numero);
       l=incoda(l,numero);
    }

    printf("\ndigitare un numero k: ");
    scanf("%d",&k);

    printf("\nla lista e':\n");
    stampa(l);
    printf("\nelimino tutti i numeri maggiori di %d\n",k);

    l=elimina_k(l,k);

     stampa(l);*/



    printf("\ndigitare un numero k: ");
    scanf("%d",&k);


    menu();
    do
    {
        printf("\n\tcosa vuoi fare?\n");
        scanf("%d",&scelta);
        switch(scelta)
        {
        case 1:
            printf("\ninserisci elemento \n");
            scanf("%d",&num);
            l=incoda(l,num);
            break;
        case 2:
            printf("\nricerca elemento nella lista\n");
            scanf("%d",&num);
            if(ricerca(l,num))
            {
                printf("\nelemento trovato\n");
            }
            else
            {
                printf("\nelemento NON trovato\n");
            }
            break;
        case 3:
            printf("\nelimino tutta la lista\n");
            l=elimina(l);
            break;
        case 4:
            printf("elimino tutti i numeri maggiori di %d \n",k);
            l=elimina_k(l,k);
            break;
        case 5:
            printf("\nnumeri più piccoli di %d prima di k\n",k);
            l=minori_prima_k(l,k);
            break;
        case 6:
            printf("\nstampo la lista\n");
            stampa(l);
            break;
        case 7:
            printf("\narrivederci\n");
            break;
        default:
            printf("\nscelta sbagliata\n");
            break;
        }


    }while(scelta!=7);


    return 0;
}


void menu()
{
    printf("\n1)inserisci elemento nella lista\n2)ricerca elemento\n3)elimina\n4)elimina numeri maggiori di k");
    printf("\n5)i numeri minori di k prima di k\n6)stampa\n7)esci");
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
        tmp=p;
        p=p->next;
        free(p);
    }
    return p;
}

nodo*elimina_k(nodo*p,int k)
{

    nodo*tmp;
    if(p==NULL)
    {
        return p;
    }
    else
    {
        p->next=elimina_k(p->next,k);
        if(p->primo>k)
        {
            tmp=p;
            p=p->next;
            free(tmp);
        }
    }
    return p;
}

nodo*minori_prima_k(nodo*p,int k)
{
    nodo*tmp;
    if(p==NULL)
    {
        return p;
    }
    tmp=minori_prima_k(p->next,k);
    if(p->primo<k)
    {
        p->next=tmp;
        return p;
    }
    else
    {
        tmp=incoda(tmp,p);
        return tmp;
    }
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\nlista: %d\n",p->primo);
        p=p->next;
    }
}
