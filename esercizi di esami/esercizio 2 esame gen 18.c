/*data una lista concatenata di interi l1,scrivere una funzione che restituisca una nuova lista l2 contenente gli elementi di
l1 in posizione pari e modifichi l1 in modo tale che contenga solo elementi in posizione dispari
esempio: 22 1 5 3 28 15
output:  l1= 22 5 28       l2= 1 3 15*/
///ho alcuni problemi con l'output della lista 2 (non me la stampa tutta correttamente)
 #include <stdio.h>
 #include <stdlib.h>
 typedef struct LISTA
 {
     int primo;
     struct LISTA*next;
 }nodo;

 nodo*nelem(int a);
 nodo*incoda(nodo*p,int a);
 nodo*eliminapospar(nodo*p,int a);
 nodo*ritorna(nodo*p);
 void stampa(nodo*p);

 int main ()
 {
    nodo*l1=NULL;
    nodo*l2=NULL;
    int i=0,dim,k;

    l1=incoda(l1,22);l1=incoda(l1,1);l1=incoda(l1,5);l1=incoda(l1,3);l1=incoda(l1,28);l1=incoda(l1,15);
    stampa(l1);
    printf("\nritorno la lista solo con numeri di posizione dispari e creo una lista con soli elem pos pari");
    l2=ritorna(l1);
    printf("\t\t***\n");
    stampa(l1);
    printf("\t\t***\n");
    stampa(l2);




     return 0;
 }

 nodo*nelem(int a)
 {
  nodo*q=(struct LISTA*)malloc(sizeof(struct LISTA));
  q->primo=a;
  q->next=NULL;
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

nodo*ritorna(nodo*p)
{
    nodo*l2=NULL;
    nodo*cur=p;
    int cont=1;

    nodo*prev = p;
    //nodo*var = p->next;
    nodo*var=p;

    while(cur!=NULL)
    {
        if(cont%2==0)
        {
            l2=incoda(l2,cur->primo);
            ///potevo fare anche questa funzione a parte ma la traccia vuole un'unica funzione.
            while (prev != NULL && var != NULL)
            {
                prev->next = var->next;
                free(var);
                prev = prev->next;
                if (prev != NULL)
                var = prev->next;
            }
        }

        cur=cur->next;
        cont++;
    }
    return l2;
}

 void stampa(nodo*p)
 {
     while(p!=NULL)
     {
         printf("%d\n",p->primo);
         p=p->next;
     }
 }
