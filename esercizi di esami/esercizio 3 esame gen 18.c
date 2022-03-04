/*Scrivere una funzione ricorsiva in ansi c che data una lista l di interi elimini da tale lista tutti gli elementi con chiave
 di valore PARI ed in posizione DISPARI. Nota bene che la funzione deve ricevere in ingresso la sola lista L*/
 #include <stdio.h>
 #include <stdlib.h>
 typedef struct LISTA
 {
     int primo;
     struct LISTA*next;
 }nodo;

 nodo*nelem(int a);
 nodo*incoda(nodo*p,int a);
 nodo*paridispari(nodo*p);
 void stampa(nodo*p);

 int main ()
 {
    nodo*l1=NULL;
    int i=0,dim,a;

    l1=incoda(l1,32);l1=incoda(l1,4);l1=incoda(l1,15);l1=incoda(l1,81);l1=incoda(l1,2);
    stampa(l1);
    printf("\nelimino i numeri pari in posizione dispari (se ci sono)");
    l1=paridispari(l1);
    printf("\nla lista e':\n");
    stampa(l1);



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

 nodo*paridispari(nodo*p)
 {
     if(p)
     {
         if(p->next)
            p->next->next=paridispari(p->next->next);   ///non so perchè ma con le parentesi e con else non va ò.ò
        if(!(p->primo%2))
             {
                 nodo*tmp=p;
                 p=p->next;
                 free(tmp);
            }
     }
    return p;
 }

 void stampa(nodo*p)
 {
     while(p!=NULL)
     {
         printf("%d\n",p->primo);
         p=p->next;
     }
 }
