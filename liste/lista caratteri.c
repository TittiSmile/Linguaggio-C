#include <stdio.h>
#include <malloc.h>
typedef struct LISTA
{
    char primo;
    struct LISTA *next;
}nodo;

void menu();
nodo*nelem(char a);
nodo*intesta(nodo*p,char a);
nodo*incoda(nodo*p,char a);
nodo*ricerca(nodo*p,char a);
nodo*elimina(nodo*p);
int occorrenza(nodo*p,char a);
nodo*elimina_occorrenza(nodo*p,char a);
void stampa(nodo*p);
nodo*reverse (nodo*p);



int main ()
{
    char scelta=0;
    char car=0;
    nodo*l=NULL;

    menu();

    do
    {
        do
        {
          printf("\n\tcosa vuoi fare?\n");
          scelta=getchar();
        }while(isspace (scelta));
        getchar();

        //printf("\n\tcosa vuoi fare?\n");
        //scanf("%c",&scelta);
        //////////////////////////////////////////
    ///N.B.!!!!!! in questo programma NON funziona la normale acquisizione con scanf e NON so perchè. ho usato il ciclo dowhile
    /// va ricordato che in c++ non ci sono questi problemi!!
        ///////////////////////
        switch(scelta)
        {
        case 'a':
            printf("\ninserisci in testa\n");
            scanf("%c",&car);
            l=intesta(l,car);
            break;
        case 'b':
            printf("\ninserisci in coda\n");
            scanf("%c",&car);
            l=incoda(l,car);
            break;
        case 'c':
             printf("\nquale elemento vuoi ricercare?\n");
            scanf("%c",&car);
            if(ricerca(l,car))
            {
                printf("\nelemento trovato\n");
            }
            else
            {
                printf("\nelemento NON trovato\n");
            }
            break;
        case 'd':
            printf("\nelimino la lista\n");
            l=elimina(l);
            break;
        case 'e':
            printf("\nquale occorrenza vuoi cercare?\n");
            scanf("%c",&car);
            printf("le occorrenze di %c sono: ",car,occorrenza(l,car));
            break;
        case 'f':
            printf("\nquale occorrenza vuoi eliminare?\n");
            scanf("%c",&car);
            l=elimina_occorrenza(l,car);
            break;
        case 'g':
            printf("\nstampo la lista\n");
            stampa(l);
            break;
        case 'h':
            printf("\nstampo al contrario\n");
            l=reverse(l);
            break;
        case 'i':
            printf("\narrivederci\n");
            break;
        default:
            printf("\nscelta errata\n");
            break;
        }

    }while(scelta!='i');



    return 0;
}



void menu()
{
    printf("a)inserisci in testa\nb)inserisci in coda\nc)ricerca elemento\nd)elimina lista\ne)trova occorrenza\n");
    printf("f)elimina occorrenza\ng)stampa\nh)stampa al contrario\ni)esci");
}


nodo*nelem(char a)
{
    nodo*q=(struct LISTA*)malloc(sizeof(struct LISTA));
    q->primo=a;
    q->next=NULL;
    return q;
}


nodo*intesta(nodo*p,char a)
{
    nodo*q=nelem(a);
    q->next=p;
    return q;
}


nodo*incoda(nodo*p,char a)
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


nodo*ricerca(nodo*p,char a)
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

int occorrenza(nodo*p,char a)
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

nodo*elimina_occorrenza(nodo*p,char a)
{
   nodo*tmp=p;
   if(p!=NULL)
   {
       if(p->primo==a)
       {
        p=elimina_occorrenza(p->next,a);
        free(tmp);
       }
       else
       {
           p->next=elimina_occorrenza(p->next,a);
       }
   }
   return p;
}

void stampa(nodo*p)
{
   while(p!=NULL)
   {
       printf("\nlista: %c\n",p->primo);
       p=p->next;
   }
}

nodo*reverse (nodo*p)
{
   if(p==NULL)
     return 0;
   reverse(p->next);
   printf("\nlista: %c\n",p->primo);
}
