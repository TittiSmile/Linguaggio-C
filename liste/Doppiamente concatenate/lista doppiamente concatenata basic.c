///funziona ma non capisco perchè lo stampa al contrario
#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA_DOPPIA
{
    int primo;
    struct LISTA_DOPPIA*prev;
    struct LISTA_DOPPIA*next;
}doppia;

doppia*inserisci(doppia*p,int a);
doppia*intesta(doppia*p,int a);
doppia*incoda(doppia*p,int a);
doppia*ricerca(doppia*p,int a);
doppia*elnodo(doppia*p,int a);
void stampa(doppia*p);

int main()
{
    doppia*l1=NULL;
    doppia*l2=NULL;
    doppia*l3=NULL;
    int a;

    l1=inserisci(l1,2);l1=inserisci(l1,3);l1=inserisci(l1,1);l1=inserisci(l1,4);
    stampa(l1);
    printf("quale elemento vuoi ricercare? ");
    scanf("%d",&a);
    if(ricerca(l1,a))
    {
        printf("elemento trovato");
    }
    else
    {
        printf("elemento NON trovato");
    }
    printf("\n\nelimino un nodo\n\n");
    elnodo(l1,1);
    stampa(l1);
    printf("\n\nL2:\n");
    l2=intesta(l2,3);l2=intesta(l2,5);l2=intesta(l2,6);
    stampa(l2);
    printf("\n\nL3:\n");
    l3=incoda(l3,7);l3=incoda(l3,8);l3=incoda(l3,9);
    stampa(l3);




    return 0;
}

doppia*inserisci(doppia*p,int a)
{
    doppia*flag=(doppia*)malloc(sizeof(doppia));
    flag->prev=NULL;
    flag->primo=a;
    flag->next=p;
    return flag;

}

doppia*intesta(doppia*p,int a)
{    ///funziona ugualmente (non ho ben capito cosa cambia)
    /*doppia*tmp=(doppia*)malloc(sizeof(doppia));
    tmp->primo=a;
    tmp->next=p;
    tmp->prev=NULL;
    if(p!=NULL)
    {
        p->prev=tmp;
    }
    p=tmp;
    return p;*/
    doppia*tmp=(doppia*)malloc(sizeof(doppia));
    tmp->primo=a;
    tmp->prev = NULL;
    tmp->next = NULL;
    if (p==NULL){
        p=tmp;
    }
    else {
        tmp->next=p;
        p->prev=tmp;
        p=tmp;
    }
    return p;

}

doppia*incoda(doppia*p,int a)
{
    if (p==NULL)
    {
        doppia*tmp=(doppia*)malloc(sizeof(doppia));
        tmp->primo=a;
        tmp->prev=NULL;
        tmp->next=NULL;
        p=tmp;
        /*PUOI ANCHE USARE QUESTO METODO
        tmp=crea(p,a);
        p=tmp;*/
    }
    else
    {
        p->next=incoda(p->next,a);
        if(p->next!=NULL)
        {
            p->next->prev=p;
        }
    }
    return p;
}

doppia*ricerca(doppia*p,int a)
{
    ///funzionano alla stessa maniera
    /*
    doppia*t=NULL;
    if(p==NULL)
    {
        return p;
    }
    else
    {
        t=p;
        while(t!=NULL)
        {
            if(t->primo==a)
            {
                return t;
            }
            t=t->next;
        }
    }
    return NULL;*/
    doppia*trovato=NULL;
    for(;p!=NULL && trovato==NULL;p=p->next)
    {
        if(p->primo==a)
        {
            trovato=p;
        }
    }
    return trovato;
}

doppia*elnodo(doppia*p,int a)
{
     if (p!=NULL)
    {
        p->next=elnodo(p->next,a);
        if(p->primo==a)
          {
                if (p->next)
                 {
                    p->next->prev=p->prev;
                 }
                if (p->prev)
                    {
                       p->prev->next=p->next;
                    }
                doppia*tmp=p->next;
                free(p);
                p=tmp;
          }

    }
    return p;
}

void stampa(doppia*p)
{
    while(p!=NULL)
    {
        printf("%d <-> \n",p->primo);
        p=p->next;
    }
    printf("NULL\n");
}
