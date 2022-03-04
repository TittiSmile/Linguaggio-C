///c'è qualcosa che non torna
#include <stdio.h>
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA*next;
}nodo;

nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
nodo*eldisppospari(nodo*p);
void stampa(nodo*p);

int main ()
{
    nodo*l1=NULL;
    int k=0;
    l1=incoda(l1,23);l1=incoda(l1,15);l1=incoda(l1,50);l1=incoda(l1,51);l1=incoda(l1,8);l1=incoda(l1,16);
    stampa(l1);

    printf("\nelimino i numeri DISPARI in posizione PARI\n\n");
    l1=eldisppospari(l1);
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

nodo*eldisppospari(nodo*p)
{
    /*nodo*tmp;
    if(p)
    {
        if(p->next)
        {
            p->next->next=eldisppospari(p->next->next);
        }
    }
    if(!(p->primo%2!=0))
    {
        tmp=p;
        p=p->next;
        free(tmp);
    }
    return p;*/
      if(p)
     {
         if(p->next)
           {
               p->next->next=eldisppospari(p->next->next);
           }
        if(!(p->primo%2))
             {
                 nodo*tmp=p;
                 p=p->next;
                 free(tmp);
            }
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
