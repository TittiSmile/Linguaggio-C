#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA_DOPPIA
{
    int primo;
    struct LISTA_DOPPIA*prev;
    struct LISTA_DOPPIA*next;
}doppia;

doppia*crea(doppia*p,int a);
doppia*incoda(doppia*p,int a);
void stampa(doppia*p);
doppia*alterna(doppia*l1,doppia*l2);

int main ()
{
    doppia*l1=NULL;
    doppia*l2=NULL;
    doppia*l3=NULL;
    l1=incoda(l1,4);l1=incoda(l1,2);
    l2=incoda(l2,3);l2=incoda(l2,5);
    stampa(l1);
    printf("\n\n");
    stampa(l2);
    printf("\n\n");
    l3=alterna(l1,l2);
    stampa(l3);

    return 0;
}

doppia*crea(doppia*p,int a)
{
    doppia*flag=(doppia*)malloc(sizeof(doppia));
    flag->prev=NULL;
    flag->primo=a;
    flag->next=NULL;
    return flag;
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
        if(p->next!=NULL)
        {
            p->next->prev=p;
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

doppia*alterna(doppia*l1,doppia*l2)
{
    doppia*l3=l1;
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
