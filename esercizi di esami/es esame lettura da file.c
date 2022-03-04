/*non so bene cosa bisogna fare in questo programma.... guardando le funzioni,suppongo che debba leggere un file ed associarlo
ad una lista,ordinare la lista e poi eliminarla*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 30

typedef struct LISTA
{
    char nome[max];
    char cognome[max];
    int esami;
    struct LISTA *next;
}nodo;

nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
nodo*casuale(nodo*p,int dim);






























































                        ///**********QUESTA PARTE HA QUALCHE ERRORE.NON ELIMINO NULLA MA LA TENGO DA PARTE*********///

/*struct LISTA *leggi (char *nome_file);
struct LISTA *ordine (struct LISTA *p,struct LISTA *flag);
void stampa();
struct LISTA *elimina(struct LISTA *p);

int main ()
{
    struct LISTA *l=NULL;
    char nome_file[max];

    printf("Digitare il nome del file\n");
    scanf("%s",nome_file);
    l=leggi(nome_file);
    stampa(p);
    p=elimina(p);

    return 0;
}
*/





/*struct LISTA *leggi (char *nome_file)
{
 FILE *fp=fopen(nome_file,"r");
 struct LISTA *tmp=NULL;
 if(fp!=NULL)
 {
     struct LISTA *flag=(struct LISTA *)malloc(sizeof(struct LISTA));
     while(fscanf("%s %s %d",flag->nome,flag->cognome,flag->&esami))
     {
         tmp=inordine(tmp,flag);
     }
     fclose(fp);
 }
    else
    {
        printf("errore di lettura file");
    }
}*/



/*struct LISTA *ordine (struct LISTA *p,struct LISTA *flag)
{
  if(p==NULL || p->esami < temp->esami)
  {
      struct LISTA *temp=(struct LISTA*)malloc(sizeof(struct LISTA));
      strcopy(temp->nome,flag->cognome);
      strcopy(flag->nome,flag->cognome);
      temp->next=p;
      p=temp;
  }
  else
  {
      p->next=ordine(p->next,flag);
  }

}*/



/*void stampa()
{
    while(p!=NULL)
    printf("Lista:\n %s %s %d",p->nome,p->cognome,&p->esami);
    p=p->next
}*/

/*struct LISTA *elimina(struct LISTA *p)
{
    struct LISTA *temp=(struct LISTA*)malloc(sizeof(struct LISTA));
 for(;p!=NULL;p=temp)
    {
        temp=p->next;
        p->next=NULL;
        free(p);
    }
    return p;

    /////////////////////////////
    //N.B si potrebbe usare anche questa funzione in modo ricorsivo per eliminare/deallocare:
    /*
      if(p!=NULL)
        elimina(p->next);
        p->next=NULL;
        free(p);



        la funzione deve essere di tipo void

    */
}*/







