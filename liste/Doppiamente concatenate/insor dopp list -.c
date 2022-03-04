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
doppia*insor(doppia*p,int a);
void stampa(doppia*p);

int main ()
{
    doppia*l1=NULL;
    //l1=incoda(l1,3);l1=incoda(l1,1);l1=incoda(l1,12);
    l1=insor(l1,4);l1=insor(l1,1);l1=insor(l1,3);l1=insor(l1,34);
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

doppia*ricerca(doppia*p,int a);
doppia*elnodo(doppia*p,int a);


doppia*insor(doppia*p,int a)
{
    doppia*tmp=(doppia*)malloc(sizeof(doppia));
    if(p==NULL || tmp->primo > a)
    {
        tmp->primo=a;
        tmp->next=p;
        p=tmp;
    }
    else
    {
        p->next=insor(p->next,a);
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
