/*Programma che ti fa scrivere numeri su un file e ti legge il contenuto di quello che hai inserito */
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
nodo*leggi(FILE*pf);
nodo*scrivi(FILE*pf,int n);
void stampa(nodo*p);

int main ()
{
    FILE*pf;
    nodo*l=NULL;
    int i=0,n;

    printf("quanto vuoi grande la lista?   ");
    scanf("%d",&n);

    printf("scrivo nel file:\n");
    l=scrivi(pf,n);

    printf("leggo dalla lista:\n");
    l=leggi(pf);

    stampa(l);

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

nodo*leggi(FILE*pf)
{
    nodo*p=NULL;
    nodo*tmp=(nodo*)malloc(sizeof(nodo));
    pf=fopen("lista.txt","r");
    if(pf)
    {
        while (!feof(pf))
       {
       fscanf(pf,"\n%d ", &tmp->primo);        ///N.B.!!!!!!!!!!!!!***____* se non metto uno spazio tra %d mi stampa due volte l'ultimo numero ._. va fatto così: fscanf(pf," %d ",&tmp->primo)
       p=incoda(p,tmp->primo);
       }
   }
    else
    {
        printf("errore di apertura");
    }
    fclose(pf);

return p;
}

nodo*scrivi(FILE*pf,int n)
{
    int i=0;
    nodo*p=NULL;
    nodo*tmp=(nodo*)malloc(sizeof(nodo));

    pf=fopen("lista.txt","w");                     ///volendo,potrei anche mettere fopen nel main e nell'if potrei richiamare semplicemente la funzione facendo: l=scrivi(pf,n)
    if(pf)
    {
         for(i=0;i<n;i++)
        {
            printf("inserisci numero:  ");
            scanf("%d",&tmp->primo);
            fprintf(pf,"%d ",tmp->primo);
            p=incoda(p,tmp->primo);
        }
    }
    else
    {
        printf("errore di apertura.");
    }

    fclose(pf);

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

