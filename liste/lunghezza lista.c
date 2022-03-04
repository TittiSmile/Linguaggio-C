#include <stdio.h>

typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;

void menu();
nodo *nelem(int a); /// è la stessa cosa di scrivere 'struct LISTA *nelem(int a); '
nodo *intesta(struct LISTA *p,int a);
nodo *incoda (struct LISTA *p,int a);
void stampa (struct LISTA *p);
int lunghezzalista(nodo*p);

int main ()
{
  nodo*l=NULL;
  int scelta,num;


  menu();

do
{
    printf("\t\tdigitare la scelta\n");
    scanf("%d",&scelta);

  switch(scelta)
    {
    case 1:
        printf("\ninserisci elemento in testa:\n");
        scanf("%d",&num);
        l=intesta(l,num);
        break;
    case 2:
        printf("\ninserisci in coda:\n");
        scanf("%d",&num);
        l=incoda(l,num);
        break;
    case 3:
        printf("\nstampo la lista:\n");
        stampa(l);
        if(l==NULL)
        {
            printf("\nlista vuota\n");
        }
        break;
    case 4:
        printf("\n la lunghezza della lista e': %d \n",lunghezzalista(l));
        break;
    case 5:
        printf("\narrivederci");
        break;
    default:
        printf("\nscelta non valida\n");
        break;

    }



}while(scelta!=5);


  return 0;
}


void menu()
{
    printf("1)inserisci in testa\n2)inserisci in coda\n3)stampa lista\n4)stampa lunghezza lista\n5)esci\n");
}


nodo *nelem(int a)
{
    nodo*q=(struct LISTA*)malloc(sizeof(struct LISTA));
    q->primo=a;
    q->next=NULL;
    return q;
}


nodo *intesta(struct LISTA *p,int a)
{
   nodo*q=nelem(a);
   q->next=p;
   return q;
}

nodo *incoda (struct LISTA *p,int a)
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

void stampa (struct LISTA *p)
{
  while(p!=NULL)
  {
      printf("\nlista: %d \n",p->primo);
      p=p->next;
  }
}

int lunghezzalista(nodo*p)
{
    int lun=0;
    while (p!=NULL)
    {
        lun++;
        p=p->next;
    }
    return lun;
}



