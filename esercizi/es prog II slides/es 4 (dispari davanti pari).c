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
void stampa(nodo*p);
nodo*fondi(nodo*l1,nodo*l2);
nodo*primapari(nodo*p);//non corretto
nodo*primadispari(nodo*p);//non corretto
nodo*paridispari(nodo*p);///funzione che mette davanti la lista prima i dispari poi i pari

 int main ()
 {
     nodo*l1=NULL;
     nodo*l2=NULL;
     nodo*l3=NULL;
     int i=0;

     l1=incoda(l1,3);l1=incoda(l1,4);l1=incoda(l1,55);l1=incoda(l1,6);
     stampa(l1);
     printf("\n***\n\n");
     /*l2=incoda(l2,11);l2=incoda(l2,2);l2=incoda(l2,7);l2=incoda(l2,21);
     stampa(l2);
     printf("\nfondo le due liste");
     l3=fondi(l1,l2);
     stampa(l3);
     printf("\npari e dispari: ");
     l3=paridispari(l3);
     stampa(l3);*/
     l1=paridispari(l1);
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

 void stampa(nodo*p)
 {
     while(p!=NULL)
     {
         printf("\n%d->",p->primo);
         p=p->next;
     }
 }

nodo*fondi(nodo*l1,nodo*l2)
{
    nodo*l3;
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

nodo*primapari(nodo*p)
{
    nodo*tmp;
    if(p==NULL)
    {
        return p;
    }
    p->next=primapari(p->next);
    if(p->primo%2!=0)          ///elimino i dispari
    {
      tmp=p;
      p=p->next;
      free(tmp);
    }
    return p;
}

nodo*primadispari(nodo*p)
{
    nodo*tmp;
    if(p==NULL)
    {
        return p;
    }
    p->next=primapari(p->next);
    if(p->primo%2==0)        ///elimino i pari
    {
      tmp=p;
      p=p->next;
      free(tmp);
    }
    return p;
}

nodo*paridispari(nodo*p)
{
    int flag=0;
    nodo*tmp=p;
    if(p!=NULL)
    {
        while(tmp!=NULL)
        {
            if(tmp->primo%2!=0)
            {
                flag=p->primo;        /*a=b b=c c=a*/
                p->primo=tmp->primo;
                tmp->primo=flag;
            }
            tmp=tmp->next;
        }
       p->next=paridispari(p->next);
    }
    return p;
}
