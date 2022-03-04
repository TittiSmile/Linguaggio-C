#include <stdio.h>
#include <malloc.h>
typedef struct LISTA
{
    char primo;
    struct LISTA *next;
}nodo;

nodo*nelem(char a);
nodo*intesta(nodo*p,char a);
nodo*incoda(nodo*p,char a);
void stampa(nodo*p);


int main ()
{
    ///non userò lo switch perchè è una lista di caratteri base. non so perchè mi dà gli indirizzi di memoria invece dei caratteri
    nodo*l=NULL;
    char car;
    int dim,i,j,dim2;

    printf("quanti caratteri vuoi inserire?\n");
    scanf("%d",&dim);


    /*for(i=0;i<dim;i++)
    {
        do
        {
           printf("inserisci un carattere ");
           car=getchar();
        }while(isspace(car));
        getchar();
        l=incoda(l,car);
    }*/

    for(i=0;i<dim;i++)
    {
        fflush(stdin);   ///QUEL COSO TI COMPLICAVA LA VITA!!!!!!! questa funzione serve a "pulire" la cache di input. si usa specialmente coi caratteri
        printf("inserisci carattere:  ");
        scanf("%c",&car);
        l=incoda(l,car);
    }

  stampa(l);


    return 0;
}


nodo*nelem(char a)
{
    nodo*q=(struct LISTA*)malloc(sizeof(struct LISTA));
    q->primo=a;
    q->next=NULL;
    return q;
}

nodo*intesta(nodo*p,char a)
{
    nodo*q=nelem(a);
    q->next=p;
    return q;
}

nodo*incoda(nodo*p,char a)
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
        printf("\n%c\n",p->primo);
        p=p->next;
    }
}
