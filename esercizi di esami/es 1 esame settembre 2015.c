#include <stdio.h>

typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;


struct LISTA *nelem(int a);
struct LISTA *intesta(struct LISTA *p,int a);
struct LISTA *incoda(struct LISTA *p,int a);
struct LISTA *eliminapuntato(struct LISTA *l,struct LISTA *p);
void stampa(struct LISTA *p);

int main ()
{
    struct LISTA *lol=NULL;
    struct LISTA *pun=NULL;
    int i=0,dim=0,num=0;

    printf("Quanti numeri vuoi inserire?\n");
    scanf("%d",&dim);

    for(i=0;i<dim;i++)
    {
        printf("Inserire %d numero ",i+1);
        scanf("%d",&num);
        lol=incoda(lol,num);
    }

    printf("La lista e': ");
    stampa(lol);

   // printf("Digitare elemento da puntare\n");
    //scanf("%d",&pun->primo);
    lol=eliminapuntato(lol,pun);
stampa(lol);

    return 0;
}




struct LISTA *nelem(int a)
{
 struct LISTA *q=(struct LISTA *)malloc(sizeof(struct LISTA));
 q->primo=a;
 q->next=NULL;
 return q;
}

struct LISTA *intesta(struct LISTA *p,int a)
{
    struct LISTA *q=nelem(a);
    q->next=p;
    return q;
}

struct LISTA *incoda(struct LISTA *p,int a)
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


struct LISTA *eliminapuntato(struct LISTA *l,struct LISTA *p)
{

    for(;l!=NULL;l=l->next)
    {
        if(l==p)
        {
            l=p->next;
            p->next=NULL;
            free(p);
        }
    }
    return l;
 /*
 struct LISTA *temp;
 for(;p!=NULL;p=temp)
 {
    temp=p->next;
    p->next=NULL;
    free(p);
 }
 return p;
 */

}

void stampa(struct LISTA *p)
{
    while(p!=NULL)
    {
        printf("\n %d \n",p->primo);
        p=p->next;
    }
}
