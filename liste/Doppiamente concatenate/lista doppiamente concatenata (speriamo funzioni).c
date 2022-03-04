///PROBLEMA NELLA STAMPA!!!! (temo che non entri nel ciclo. per il resto penso che va bene)
///AGGIORNAMENTO: no,bella mia,non è solo la stampa il problema ahahah lol vedi altri programmi per avere chiaro come funziona
#include <stdio.h>
#include <stdlib.h>
typedef struct DLISTA   ///d sta per "doppia"
{
    int primo;
    struct DLISTA*prev;
    struct DLISTA*next;

}nodo;

void menu();
nodo*nelem();
int isempty(nodo*p);
void intesta(nodo*p,int a);
void incoda(nodo*p,int a);
void stampa(nodo*p);


int main ()
{
    nodo*l=NULL;
    int i=0,scelta,num;

    do
    {
        menu();
        printf("\ncosa vuoi fare?  ");
        scanf("%d",&scelta);
        l=nelem();
        switch(scelta)
        {
        case 1:
            printf("inserisco in testa:  ");
            scanf("%d",&num);
            intesta(l,num);
            stampa(l); ///la funzione stampa non funziona (lol) temo che non salva il numero (infatti mi dà un indirizzo di memoria)
            break;
        case 2:
            printf("inserisco in coda:  ");
            scanf("%d",&num);
            incoda(l,num);
            break;
        case 3:
            printf("stampo la lista:  ");
            stampa(l);
            break;
        case 4:
            printf("arrivederci");
            break;
        default:
            printf("scelta errata");
            break;
        }

    }while(scelta!=4);


    return 0;
}

void menu()
{
    printf("1)inserisci in testa\n2)inserisci in coda\n3)stampa lista\n4)esci\n");
}

nodo*nelem()
{
    nodo*flag;
    flag=(struct DLISTA*)malloc(sizeof(struct DLISTA));
    flag->prev=flag;
    flag->next=flag;
    return flag;
}

int isempty(nodo*p)
{
    int res=0;
    if(p->next==p)
    {
        res=1;
    }
    return res;
}

void intesta(nodo*p,int a)
{
    nodo*tmp,*var;
    tmp=(struct DLISTA*)malloc(sizeof(struct DLISTA));
    var=(struct DLISTA*)malloc(sizeof(struct DLISTA));
    tmp->primo=a;
    if(isempty(p))
    {
        p->prev=tmp;
        p->next=tmp;
        tmp->prev=p;
        tmp->next=p;
    }
    else
    {
        var=p->next;
        var->prev=tmp;
        tmp->prev=p;
        tmp->next=var;
        p->next=tmp;
    }
}

void incoda(nodo*p,int a)
{
    nodo*tmp,*var;
    tmp=(struct DLISTA*)malloc(sizeof(struct DLISTA));
    var=(struct DLISTA*)malloc(sizeof(struct DLISTA));
    tmp->primo=a;
    if(isempty(p))
    {
        p->prev=tmp;
        p->next=tmp;
        tmp->prev=p;
        tmp->next=p;
    }
    else
    {
        var=p->prev;
        var->next=tmp;
        tmp->prev=var;
        tmp->next=p;
        p->prev=tmp;
    }
}


void stampa(nodo*p)
{
    nodo*tmp;
    ///non entra proprio nel ciclo
    for(tmp=p->next;tmp!=p;tmp=tmp->next)

        printf("\n%d -> \n",&p->primo);

return;
}
