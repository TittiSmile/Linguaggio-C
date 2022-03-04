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
doppia*eldisp(doppia*p);
void stampa(doppia*p);

int main ()
{
    doppia*l1=NULL;
    doppia*l2=NULL;
    int n,num;

    //l1=incoda(l1,2);l1=incoda(l1,21);
    l1=intesta(l1,2);l1=intesta(l1,21);l1=intesta(l1,25);
    stampa(l1);
    /*printf("cerca un elemento: ");
    scanf("%d",&num);
    if(ricerca(l1,num))
    {
        printf("elemento trovato");
    }
    else
    {
        printf("elemento NON trovato");
    }*/

    printf("\n\n");
    l1=eldisp(l1);
    stampa(l1);

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
{
    doppia*tmp=(doppia*)malloc(sizeof(doppia));
    tmp->prev=NULL;
    tmp->primo=a;
    tmp->next=p;
    if(p!=NULL)
    {
        p->prev=tmp;
    }
    p=tmp;
    return p;
}

doppia*incoda(doppia*p,int a)
{
    doppia*tmp=(doppia*)malloc(sizeof(doppia));
    if(p==NULL)
    {
        tmp->prev=NULL;
        tmp->primo=a;
        tmp->next=NULL;
        p=tmp;
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
    doppia*tmp;
    if(p!=NULL)
    {
        p->next=elnodo(p->next,a);
        if(p->primo==a)
        {
            if(p->next)
            {
                p->next->prev=p->next;
            }
            if(p->prev)
            {
                p->prev->next=p->prev;
            }
            tmp=p->next;
            free(p);
            p=tmp;
        }
    }

    return p;

}

doppia*eldisp(doppia*p)
{
    doppia*tmp;
    if(p!=NULL)
    {
        p->next=eldisp(p->next);
        if(p->primo%2!=0)
        {
            if(p->next)
            {
                p->next->prev=p->next;
            }
            if(p->prev)
            {
              p->prev->next=p->prev;
            }
            tmp=p->next;
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
        printf("%d\n",p->primo);
        p=p->next;
    }
}
