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

int main()
{
    int i=0,dim,n;
    int num;
    nodo*l=NULL;
    FILE*pf;


    printf("quanti elementi vuoi? ");
    scanf("%d",&dim);
    for(i=0;i<dim;i++)
    {
        printf("inserisci %d valore: ",i+1);
        scanf("%d",&n);
        l=incoda(l,n);
    }
    stampa(l);

    pf=fopen("lista.txt","w");
    if(pf)
    {
        printf("\nsto scrivendo la lista sul file!!!");
        for(i=0;i<dim;i++)
        {
            fprintf(pf,"\n%d-> ",l->primo);
            l=l->next;
        }
        printf("\nho scritto sul file");
    }
    else
    {
        printf("\nerrore di apertura");
    }

    fclose(pf);



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

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("%d->\n",p->primo);
        p=p->next;
    }
}
