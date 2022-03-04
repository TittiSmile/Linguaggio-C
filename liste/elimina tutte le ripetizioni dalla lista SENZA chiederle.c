#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
int primo;
struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*intesta(nodo*p,int a);
nodo*incoda(nodo*p,int a);
nodo*eliminadup(nodo*p); ///elimina tutti i duplicati di un numero. è una funzione "elimina occorrenza" senza chiedere quale occorrenza eliminare
void stampa(nodo*p);


int main ()
{
    nodo*l1=NULL;
    int a=0;
    l1=incoda(l1,5);l1=incoda(l1,5);l1=incoda(l1,5);l1=incoda(l1,5);l1=incoda(l1,7);l1=incoda(l1,14);l1=incoda(l1,11);
    stampa(l1);
    printf("\nelimino tutti i duplicati");
    l1=eliminadup(l1);
    stampa(l1);

    return 0;
}


nodo*nelem(int a)
{
    nodo*q=(nodo*)malloc(sizeof(nodo));
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

int occorrenza(nodo*p,int a)
{
    int flag=NULL;
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

nodo*eldup(nodo*p,int a)
{
    if(p!=NULL)
    {
        if(occorrenza(p,a)==1)
        {
            p=intesta(p,a);
        }
    }
    return p;
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n->%d",p->primo);
        p=p->next;
    }
    printf("\t\tNULL");
}

nodo*eliminadup(nodo*p)
{
    nodo*cur=p;
    nodo*var=p;
    nodo*tmp;
    while (var!=NULL)
    {
            while (cur->next!=NULL)
            {
                if (var->primo==cur->next->primo )
                {
                    tmp=cur->next;
                    cur->next=cur->next->next;
                    free(tmp);
                }
                else
                    cur=cur->next;
            }
            var=var->next;
            cur=var;
    }
    return p;
}
