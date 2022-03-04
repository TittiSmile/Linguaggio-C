#include <stdio.h>
#include <malloc.h>
typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;

nodo*nelem(int a);
nodo*intesta(nodo*p,int a);
nodo*incoda(nodo*p,int a);
nodo*fusione(nodo*l1,nodo*l2);
void stampa(nodo*p);
nodo*reverse(nodo*p);


int main ()
{
nodo*l1=NULL;
nodo*l2=NULL;
nodo*l3=NULL;
int i=0,dim1,num1;
int j=0,dim2,num2;

printf("Quanti elementi vuoi nella lista 1? ");
scanf("%d",&dim1);
for(i=0;i<dim1;i++)
{
    printf("\n\tinserisci %d elemento nella lista 1: ",i+1);
    scanf("%d",&num1);
    l1=incoda(l1,num1);
}
printf("\n\t\tstampo lista 1");
stampa(l1);

printf("\nQuanti elementi vuoi nella lista 2? ");
scanf("%d",&dim2);
for(j=0;j<dim2;j++)
{
    printf("\n\tinserisci %d elemento nella lista 2: ",j+1);
    scanf("%d",&num2);
    l2=incoda(l2,num2);
}
printf("\n\t\tstampo lista 2");
stampa(l2);

printf("\nfaccio la fusione delle due liste\n");
l3=fusione(l1,l2);
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

nodo*fusione(nodo*l1,nodo*l2)
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
    else  if(l1->primo > l2->primo)
    {
            l3=l1;
            l3->next=fusione(l1->next,l2);
    }

    else
        {
            l3=l2;
            l3->next=fusione(l1,l2->next);
        }


    return l3;
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d\n",p->primo);
        p=p->next;
    }
}

nodo*reverse(nodo*p)
{
    if(p==NULL)
        return 0;
    reverse(p->next);
    printf("\n%d\n",p->primo);
}
