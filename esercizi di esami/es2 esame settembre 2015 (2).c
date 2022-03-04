#include <stdio.h>
typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;

struct LISTA *nelem(int a);
struct LISTA *incoda(struct LISTA *p,int a);
struct LISTA *creafile(FILE *fp);
struct LISTA *leggifile(FILE *fp);
struct LISTA *eliminadafile (struct LISTA *p,char *nomefile);
void stampa(struct LISTA *p);




int main ()
{
    FILE *fp;
    int i;
    int dim,num;
    struct LISTA *lol=NULL;

    printf("quanti elementi nella lista?");
    scanf("%d",&dim);
    for(i=0;i<dim;i++)
    {
        printf("inserisci %d numero ",i+1):
            scanf("%d",num);
    }

    fp=fopen("file.txt","r");
    lol=incoda(lol,leggifile(fp));
    fclose(fp);




    return 0;
}


struct LISTA *nelem(int a)
{
   struct LISTA *q=(struct LISTA*)malloc(sizeof(struct LISTA));
   q->primo=a;
   q->next=NULL;
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



struct LISTA *leggifile(FILE *fp)
{
 struct LISTA *tmp;
 struct LISTA *p;
 while(!feof(fp))
 {
     tmp=(struct LISTA*)malloc(sizeof(struct LISTA));
     fscanf(fp,"%d",tmp->primo);
     p=incoda(p,tmp);
 }
 return p;
}


struct LISTA *eliminadafile (struct LISTA *p,char *nomefile);




