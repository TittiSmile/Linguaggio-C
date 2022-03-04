#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*intesta(nodo*p,int a);
nodo*incoda(nodo*p,int a);
nodo*ricerca(nodo*p,int a);
nodo*elimina(nodo*p);
int occorrenza(nodo*p,int a);
nodo*elocc(nodo*p,int a);
void stampa(nodo*p);
nodo*reverse(nodo*p);
int somma(nodo*p);      //somma tutti gli elementi della lista, somma normale
///
nodo*ordina(nodo*p,nodo*tmp);
nodo*crescente(nodo*p);
///
nodo*alterna(nodo*l1,nodo*l2);
nodo*fondi(nodo*l1,nodo*l2);
nodo*interseca(nodo*l1,nodo*l2);
nodo*diffsimm(nodo*l1,nodo*l2,nodo*l3);
///
nodo*puntdispmax(nodo*p);
nodo*elpari(nodo*p);
void sum(nodo*p);
int sumpre(nodo*p);
///
nodo*leggi(FILE*pf,nodo**p,int n);    ///legge e memorizza elementi di un file.txt
///
nodo*elimina_maggiorik(nodo*p,int k);
nodo*maggioriprimak(nodo*p,int k);

int main ()
{
    nodo*l1=NULL;
    nodo*l2=NULL;
    nodo*l3=NULL;
    int k,n,a,dim,i=0;
    printf("quanto vuoi grande la tua lista?  ");
    scanf("%d",&dim);
    for(i=0;i<dim;i++)
    {
        printf("inserisci %d elemento:   ",i+1);
        scanf("%d",&n);
        l1=incoda(l1,n);
    }
    stampa(l1);






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
    nodo*trovato;
    if(p!=NULL && trovato==NULL)
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
        p=NULL;
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

nodo*elocc(nodo*p,int a)
{
    nodo*tmp=p;
    if(p!=NULL)
    {
        if(p->primo==a)
        {
            p=elocc(p->next,a);
            free(tmp);
        }
        else
        {
            p->next=elocc(p->next,a);
        }
    }
    return p;
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("%d\n",p->primo);
        p=p->next;
    }
}

nodo*reverse(nodo*p)
{
    if(p==NULL)
        return 0;
    reverse(p->next);
    printf("%d\n",p->primo);
}

int somma(nodo*p)      //somma tutti gli elementi della lista, somma normale
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

///
nodo*ordina(nodo*p,nodo*tmp)
{
    if(p==NULL || p->primo > tmp->primo)
    {
        tmp->next=p;
        p=tmp;

    }
    else
    {
        p->next=ordina(p->next,tmp);
    }
    return p;
}

nodo*crescente(nodo*p)
{
    nodo*tmp;
    nodo*l=NULL;
    while(p!=NULL)
    {
        tmp=p;
        p=p->next;
        l=ordina(p,tmp);
    }
    return l;
}

///
nodo*alterna(nodo*l1,nodo*l2)
{
    nodo*l3=l1;
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

nodo*fondi(nodo*l1,nodo*l2)
{
    nodo*l3=NULL;
    if(l1==NULL)
    {
        return l2;
    }
    else if(l2==NULL)
    {
        return l1;
    }
    else if(l1->primo < l2->primo)
    {
        l3=l1;
        l3->next=fondi(l1->next,l2);
    }
    else
    {
        l3=l2;
        l3->next=fondi(l1,l2->next);
    }
    return l3;
}

nodo*interseca(nodo*l1,nodo*l2)
{
    nodo*l3=NULL;
    if(l1)
    {
        l3=interseca(l1->next,l2);
        if(ricerca(l2,l1->primo))
        {
            l3=intesta(l3,l1->primo);
        }
    }
    return l3;
}

nodo*diffsimm(nodo*l1,nodo*l2,nodo*l3)
{
    if(l1==NULL && l2==NULL)
    {
        return l3;
    }
    else if(l1==NULL)
    {
        l3=incoda(l3,l2->primo);
        return diffsimm(l1,l2->next,l3);
    }
    else if(l2==NULL)
    {
        l3=incoda(l3,l1->primo);
        return diffsimm(l1->next,l2,l3);
    }
    else if(l1->primo < l2->primo)
    {
        l3=incoda(l3,l1->primo);
        return diffsimm(l1->next,l2,l3);
    }
    else if(l1->primo > l2->primo)
    {
        l3=incoda(l3,l2->primo);
        return diffsimm(l1,l2->next,l3);
    }
    return diffsimm(l1->next,l2->next,l3);


}

///
nodo*puntdispmax(nodo*p)
{
    nodo*tmp=NULL;
    int max=INT_MIN;
    if(p==NULL)
    {
        return p;
    }
    while(p!=NULL)
    {
        if(p->primo%2!=0 && p->primo > max)
        {
            tmp=p;
            max=p->primo;
        }
        p=p->next;
    }
    return tmp;
}

nodo*elpari(nodo*p)
{
    nodo*tmp;
    if(p)
    {
        if(p->next)
        {
            p->next->next=elpari(p->next->next);
        }
        else if(!(p->primo%2!=0))  ///non sono sicura ci voglia l' else
        {
            tmp=p;
            p=p->next;
            free(tmp);
        }
    }
    return p;
}

void sum(nodo*p)
{
     while(p!=NULL)
    {
        p->primo=sumpre(p);
        p=p->next;
    }
}

int sumpre(nodo*p)
{
    int s=0;
    while(p!=NULL)
    {
        s+=p->primo;
        p=p->next;
    }
  return s;
}

///
nodo*elimina_maggiorik(nodo*p,int k)
{
    nodo*tmp=p;
    if(p!=NULL)
    {
        if(p->primo > k)
        {
            p=elimina_maggiorik(p->next,k);
            free(tmp);
        }
        else
        {
            p->next=elimina_maggiorik(p->next,k);
        }
    }
    return p;
}

nodo*maggioriprimak(nodo*p,int k)
{
    nodo*tmp;
    if(p==NULL || p->next==NULL)
    {
        return p;
    }
    tmp=maggioriprimak(p->next,k);
    if(p->primo < k)
    {
        p->next=tmp;
    }
    else
    {
        ///////trova una soluzione qui.
    }
    return tmp;
}

