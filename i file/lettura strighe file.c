#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct LISTA
{
    char *primo;
    struct LISTA*next;
}nodo;

nodo*nelem(char *a);
nodo*incoda(nodo*p,char *a);
void stampa(nodo*p);

int main ()
{
    nodo*l=NULL;
    int i,n,dim;
    FILE*pf;
    char s[20];

    printf("quante stringhe vuoi? ");
    scanf("%d",&dim);

    for(i=0;i<dim;i++)
    {
        printf("\ninserisci %d stringa: ",i+1);
        scanf("%s",s);
        l=incoda(l,s);
    }
    stampa(l);

    pf=fopen("stringhe lista file.txt","w");
    if(pf)
    {
        printf("scrivo le stringhe sul file: \n");
        for(i=0;i<dim;i++)
        {
            fprintf(pf,"%s->  ",l->primo);
            l=l->next;
        }
        printf("\nho scritto sul file!!!");
    }
    else
    {
        printf("\nerrore di apertura");
    }

    fclose(pf);




    return 0;
}

nodo*nelem(char *a)
{
    nodo*q=(nodo*)malloc(sizeof(nodo));
    a=(char*)malloc(sizeof(char));
    q->primo=a;
    q->next=NULL;
    return q;
}

nodo*incoda(nodo*p,char *a)
{
    if(p==NULL)
    {
        p=nelem(a);
        strcpy(p->primo,a);
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
        printf("%s-> ",p->primo);
        p=p->next;
    }
}

