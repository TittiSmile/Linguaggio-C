#include <stdio.h>
#include <malloc.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

void menu();
nodo*nelem(int a);
nodo*intesta(nodo*p,int a);
nodo*incoda(nodo*p,int a);
nodo*ricerca(nodo*p,int a);
nodo*elimina(nodo*p);
int occorrenza(nodo*p,int a);
nodo*elimina_occorrenza(nodo*p,int a);
void stampa(nodo*p);
nodo*reverse(nodo*p);
int somma(nodo*p);


int main ()
{
    nodo*l=NULL;
    int scelta,num;

    menu();
    do
    {
        printf("\n\tcosa vuoi fare? \n");
        scanf("%d",&scelta);

        switch(scelta)
        {
        case 1:
            printf("\naggiungi numero in testa \n");
            scanf("%d",&num);
            l=intesta(l,num);
            break;
        case 2:
            printf("\naggiungi elemento in coda \n");
            scanf("%d",&num);
            l=incoda(l,num);
            break;
        case 3:
            printf("\nche elemento vuoi cercare? \n");
            scanf("%d",&num);
            if(ricerca(l,num))
            {
                printf("\nelemento trovato \n");
            }
            else
            {
                printf("\nelemento NON trovato \n");
            }
            break;
        case 4:
            printf("\nelimino la lista \n");
            l=elimina(l);
            break;
        case 5:
            printf("\nquale occorrenza vuoi contare? \n");
            scanf("%d",&num);
            printf("\nil numero di occorrenze di %d e' %d \n",num,occorrenza(l,num));
            break;
        case 6:
            printf("\nquale occorrenza vuoi eliminare? \n");
            scanf("%d",&num);
            l=elimina_occorrenza(l,num);
            break;
        case 7:
            printf("\nstampo la lista \n");
            stampa(l);
            break;
        case 8:
            printf("\nstampo la lista al contrario \n");
            l=reverse(l);
            break;
        case 9:
            printf("\nla somma degli elementi della lista e': %d \n",somma(l));
            break;
        case 10:
            printf("\n arrivederci\n");
            break;
        default:
            printf("\nscelta sbagliata \n");
            break;
        }

    }while(scelta!=10);


   return 0;
}





void menu()
{
    printf("1)inserisci in testa\n2)inserisci in coda\n3)cerca elemento\n4)elimina lista\n5)cerca un'occorrenza");
    printf("\n6)elimina un'occorrenza\n7)stampa la lista\n8)stampa al contrario\n9)somma tutti gli elementi\n10)esci\n");
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

nodo*elimina_occorrenza(nodo*p,int a)
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
        printf("\nlista: %d\n",p->primo);
        p=p->next;
    }
}

nodo*reverse(nodo*p)
{
    if(p==NULL)
        return 0;
    else
    {
        reverse(p->next);
        printf("\nlista al contrario: %d \n",p->primo);
    }
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
