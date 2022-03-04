#include <stdio.h>

typedef struct LISTA
{
    char nome;
    int primo;
    struct LISTA *next;
}nodo;

struct LISTA *nelem(int a);
struct LISTA *incoda (struct LISTA *p,struct LISTA *temp);//ATTENZIONE!!! questa è una funzione'incoda' particolare [...]seguegiù
struct LISTA *leggifile (FILE *input);

int main ()
{

    return 0;
}



struct LISTA *nelem(int a)
{
    struct LISTA *q;
 q=(struct LISTA*)malloc(sizeof(struct LISTA));
 q->primo=a;
 q->next=NULL;
 return q;
}

struct LISTA *incoda (struct LISTA *p,struct LISTA *temp)
//visto che parliamo di lettura di file,ho bisogno di un inserimento in coda diverso da quello che si usa di solito
{
 if(p==NULL)
 {
     temp->next=p;
     return temp;
 }
 p->next=incoda(p->next,temp);
 return p;
}


struct LISTA *leggifile (FILE *input)
{
 struct LISTA *p=NULL;
 struct LISTA temp;
 while(!feof(input))
 {
     temp=(struct LISTA*)malloc(sizeof(struct LISTA));
     fscanf(input,"%c","%d",temp->nome,&temp->primo);
     p=incoda(p,temp);
 }
    return p;
}




