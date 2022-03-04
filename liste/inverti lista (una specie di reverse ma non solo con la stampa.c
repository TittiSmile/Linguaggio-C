#include <stdio.h>
#include <malloc.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*intesta(nodo*p,int a); ///non ho intenzione di usarla
nodo*incoda(nodo*p,int a);
nodo*ricerca(nodo*p,int a); ///non ho intenzione di usarla
nodo*eliminalista(nodo*p);  ///come sopra
int occorrenza(nodo*p,int a);///come sopra
nodo*eliminaoccorrenza(nodo*p,int a);///come sopra
void stampa(nodo*p);
nodo*inverti(nodo*p);



int main ()
{
    nodo*l=NULL;
    int dim,i,n;
   /* printf("quanto vuoi grande la tua lista? ");
    scanf("%d",&dim);
    for(i=0;i<dim;i++)
    {
        printf("\ninserisci numero  ");
        scanf("%d",&n);
        l=incoda(l,n);
    }*/

    l=incoda(l,1);l=incoda(l,5);l=incoda(l,31);l=incoda(l,33);
    stampa(l);

 printf("\ninverto gli elementi della lista\n");
 l=inverti(l);
 stampa(l);


    return 0;
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
    return p;
}
nodo*eliminalista(nodo*p)
{
    nodo*tmp=NULL;
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
 int flag;
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

nodo*eliminaoccorrenza(nodo*p,int a)
{
    nodo*tmp=p;
    if(p!=NULL)
    {
        if(p->primo==a)
        {
            p=eliminaoccorrenza(p->next,a);
            free(tmp);
        }
        else
        {
            p->next=eliminaoccorrenza(p->next,a);
        }
    }
    return p;

}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d\n",p->primo);
        p=p->next;
    }
}

nodo*inverti(nodo*p)
{
    ///iterativa
   /* nodo*cur=p;
    nodo*prev=NULL;
    nodo*suc;
    while(cur!=NULL)
    {
        suc=cur->next;
        cur->next=prev;
        prev=cur;
        cur=suc;
    }
    p=prev;
    return p;*/

    ///versione ricorsiva inversione
    /*nodo*tmp=NULL;
    if(p->next->next)
    {
       tmp=inverti(p->next);
    }
    else
    {
        tmp=p->next;
    }

    p->next->next=p;
    p->next=NULL;

    return tmp;*/

}
