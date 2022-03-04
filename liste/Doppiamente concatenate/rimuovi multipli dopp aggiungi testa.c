/*problemi di loop per l'eliminazione (se metto l1 con 44 impazzisce).
non mi elimina in l2 gli elementi multipli di 3 ma li aggiunge solo in testa*/

#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA_DOPPIA
{
    int primo;
    struct LISTA_DOPPIA*next;
    struct LISTA_DOPPIA*prev;
}doppia;

doppia*crea(doppia*p,int a);
doppia*intesta(doppia*p,int a);
doppia*incoda(doppia*p,int a);
doppia*multipli(doppia*l1);
doppia*appendmultipli(doppia*l1,doppia*l2);
void stampa(doppia*p);

int main ()
{
    doppia*l1=NULL;
    doppia*l2=NULL;
    //l1=incoda(l1,33);l1=incoda(l1,12);l1=incoda(l1,44);//l1=intesta(l1,18);l1=intesta(l1,55);
    l1=incoda(l1,33);l1=incoda(l1,12);l1=incoda(l1,2);
    //l1=intesta(l1,33);l1=intesta(l1,12);l1=intesta(l1,2);
    printf("\nLista 1:\n");
    stampa(l1);
    l2=incoda(l2,1);l2=incoda(l2,2);l2=incoda(l2,3);
    printf("\nLista 2:\n");
    stampa(l2);
    l2=appendmultipli(l1,l2);
    l1=multipli(l1);
    printf("\nliste modificate:\nLista 1:\n");
    stampa(l1);
    printf("\nLista2:\n");
    stampa(l2);





    return 0;
}


doppia*crea(doppia*p,int a)
{
    doppia*flag=(doppia*)malloc(sizeof(doppia));
    flag->prev=NULL;
    flag->primo=a;
    flag->next=p;
    return flag;
}


doppia*intesta(doppia*p,int a)
{
    doppia*tmp=(doppia*)malloc(sizeof(doppia));
    tmp->prev=NULL;
    tmp->primo=a;
    tmp->next=NULL;

    if(p==NULL)
    {
        p=tmp;
    }
    else
    {
        tmp->next=p;
        p->prev=tmp;
        p=tmp;

    }
    return p;
}

doppia*incoda(doppia*p,int a)
{
    doppia*tmp=(doppia*)malloc(sizeof(doppia));
    if(p==NULL)
    {
        tmp=crea(p,a);
        p=tmp;
    }
    else
    {
        p->next=incoda(p->next,a);
        if(p->next)
        {
            p->next->prev=p;
        }
    }
    return p;
}

doppia*multipli(doppia*l1)
{
    if(l1!=NULL)
    {
        l1->next=multipli(l1->next);
        if(l1->primo%3==0)
        {
            if(l1->next)
                l1->next->prev=l1->prev;
            if(l1->prev)
                l1->prev->next=l1->next;
            doppia*tmp=l1->next;
            free(l1);
            l1=tmp;
        }
    }
    return l1;
}

doppia*appendmultipli(doppia*l1,doppia*l2)
{
    if(l1!=NULL)
    {
        l2=appendmultipli(l1->next,l2);
        if(l1->primo%3==0)
        {
            l2=intesta(l2,l1->primo);
        }
    }
    return l2;
}

void stampa(doppia*p)
{
    while(p!=NULL)
    {
        printf("%d\n",p->primo);
        p=p->next;
    }
}
