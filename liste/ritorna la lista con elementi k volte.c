/*data una lista disordinata con ripetizioni,scrivere una funzione che ritorni una nuova lista ordinata in modo crescente
 senza ripetizioni che contenga gli elementi che si ripetono esattamente k volte. ESEMPIO:
 input:  k=2 L= 20 10 30 10 20 5 5 20 1
 output: L= 5 10*/
#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
nodo*inordine(nodo*p,int a);
nodo*funzocc(nodo*p,int k);
nodo*eldup(nodo*p);
void stampa(nodo*p);

int main ()
{
    nodo*l1=NULL;
    int k=0;
    int n=0,m=0,dim=0,i=0;
///20 20 20  30  10 10 5 5 1
    l1=incoda(l1,20);l1=incoda(l1,30);l1=incoda(l1,10);l1=incoda(l1,10);l1=incoda(l1,20);l1=incoda(l1,5);l1=incoda(l1,20);
    l1=incoda(l1,5);l1=incoda(l1,1);
    stampa(l1);

    printf("\ninserisci un numero k: ");
    scanf("%d",&k);
    l1=funzocc(l1,k);
    l1=eldup(l1);
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

nodo*inordine(nodo*p,int a)
{
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    if(p==NULL || p->primo > a)
    {
        tmp=nelem(a);
        tmp->next=p;
        p=tmp;
    }
    else
    {
        p->next=inordine(p->next,a);
    }
    return p;
}

nodo*funzocc(nodo*p,int k)
{
    ///non è propriamente corretta
    nodo*tmp;
    nodo*l=NULL;
    int cont=0;
    int var;
    while(p!=NULL)
    {
        var=p->primo;
        tmp=p->next;
        while(tmp!=NULL)
        {
            if(tmp->primo == var)
            //if(tmp->primo == p->primo) //se NON si vuole usare var
            {
                cont++;
            }
           tmp=tmp->next;
        }
        if(cont==k)
        {
            l=inordine(l,var);
            //l=inordine(l,p->primo);//se NON si vuole usare var
        }
        cont=1;
        p=p->next;
    }
    return l;

    ///ancora MENO funzionale
    /*nodo*tmp=p;
    nodo*cur=p;
    nodo*l=NULL;
    int cont=0;
    while(cur!=NULL)
    {
        tmp=cur->next;
        cont=0;
        while(tmp!=NULL)
        {
            if(tmp->primo==cur->primo)
            {
                cont++;
            }
            tmp=tmp->next;
        }
        if(cont==k)
        {
            l=inordine(l,cur->primo);
        }
        cur=cur->next;
    }
    return l;*/

}

nodo*eldup(nodo*p)
{
    nodo*tmp;
    nodo*cur=p;
    nodo*var=p;
    while(var!=NULL)
    {
        while(cur->next!=NULL)
        {
            if(var->primo==cur->next->primo)
            {
                tmp=cur->next;
                cur->next=cur->next->next;
                free(tmp);
            }
            else cur=cur->next;
        }
        var=var->next;
        cur=var;
    }
    return p;
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d->",p->primo);
        p=p->next;
    }
}

