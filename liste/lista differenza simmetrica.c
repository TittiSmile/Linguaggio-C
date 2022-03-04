/*la differenza simmetrica di due liste è composta da una nuova lista con tutti gli elementi NON comuni
esempio:
l1:    3 2 5 6
l2:    3 8 6 7
l3:    8 5  */
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
nodo*diffsimm(nodo*l1,nodo*l2);///ITERATIVA
nodo*diffsimm2(nodo*l1,nodo*l2,nodo*l3);///RICORSIVA
void stampa(nodo*p);


int main ()
{
    nodo*l1=NULL;
    nodo*l2=NULL;
    nodo*l3=NULL;
    int i=0,dim,n;
    int dom,m;

    /*printf("quanto vuoi grande la lista 1 ?   ");
    scanf("%d",&dim);
    printf("quanto vuoi grande la lista 2 ?   ");
    scanf("%d",&dom);

    for(i=0;i<dim;i++)
    {
        printf("inserisci %d  elemento lista 1:    ",i+1);
        scanf("%d",&n);
        l1=incoda(l1,n);
    }

    for(i=0;i<dom;i++)
    {
        printf("inserisci %d  elemento lista 2:    ",i+1);
        scanf("%d",&m);
        l2=incoda(l2,m);
    }*/
    l1=incoda(l1,5);l1=incoda(l1,7);l1=incoda(l1,2);l1=incoda(l1,8);
    l2=incoda(l2,5);l2=incoda(l2,7);l2=incoda(l2,61);l2=incoda(l2,21);


    printf("\nla lista 1 e':  ");
    stampa(l1);
    printf("\nla lista 2 e':  ");
    stampa(l2);

    printf("\necco la differenza simmetrica tra le due liste: ");
    l3=diffsimm(l1,l2);
   //l3=diffsimm2(l1,l2,l3);
    stampa(l3);



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
nodo*diffsimm(nodo*l1,nodo*l2)
{
///versione ITERATIVA

   nodo*tmp1=l1;
   nodo*tmp2=l2;
   nodo*l3=NULL;
   int cont=0,found=0;
   nodo*top3=NULL;

   while(tmp1!=NULL)
   {
       while(tmp2!=NULL)
       {
           if(tmp1->primo==tmp2->primo)
           {
               cont=1;
               break;
           }
           tmp2=tmp2->next;
       }
       tmp2=l2;
       if(cont==0)
       {
           l3=incoda(l3,tmp1->primo);
       }
       cont=0;
       tmp1=tmp1->next;
   }
   tmp1=l1; tmp2=l2;
   while(tmp2!=NULL)
   {
       while(tmp1!=NULL)
       {
           if(tmp1->primo==tmp2->primo)
           {
               cont=1;
               break;
           }
           tmp1=tmp1->next;
       }
       tmp1=l1;
       if(cont==0)
       {
           l3=incoda(l3,tmp2->primo);
       }
       cont=0;
       tmp2=tmp2->next;
   }
   return l3;



}


nodo*diffsimm2(nodo*l1,nodo*l2,nodo*l3)
{

    if(l1==NULL && l2==NULL)
    {
        return l3;
    }
    else if(l1==NULL)
    {
        l3=incoda(l3,l2->primo);
        return diffsimm2(l1,l2->next,l3);
    }
    else if(l2==NULL)
    {
        l3=incoda(l3,l1->primo);
        return diffsimm2(l1->next,l2,l3);
    }
    else if(l1->primo < l2->primo)
    {
        l3=incoda(l3,l1->primo);
        return diffsimm2(l1->next,l2,l3);
    }
    else if(l1->primo > l2->primo)
    {
        l3=incoda(l3,l2->primo);
        return diffsimm2(l1,l2->next,l3);
    }
    return diffsimm2(l1->next,l2->next,l3);
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d ",p->primo);
        p=p->next;
    }
}


