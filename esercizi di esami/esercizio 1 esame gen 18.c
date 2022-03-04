 #include <stdio.h>
 #include <stdlib.h>
 typedef struct LISTA
 {
     int primo;
     struct LISTA*next;
 }nodo;

 nodo*nelem(int a);
 nodo*incoda(nodo*p,int a);
 nodo*eliminak(nodo*p,int k);
 void stampa(nodo*p);

 int main ()
 {
    nodo*l1=NULL;
    int i=0,dim,k;

    l1=incoda(l1,32);l1=incoda(l1,4);l1=incoda(l1,15);l1=incoda(l1,81);l1=incoda(l1,2);
    stampa(l1);
    printf("\ninserisci un numero k:  ");
    scanf("%d",&k);
    l1=eliminak(l1,k);
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

 nodo*eliminak(nodo*p,int k)
 {
     nodo*cur=p;
     nodo*tmp;
     while(cur->next!=NULL)
     {
         if(cur->next->primo > k)
         {
             tmp=cur->next;
             cur->next=cur->next->next;
             free(tmp);
         }
         else
         {
             cur=cur->next;
         }
     }
     if(p->primo > k)
     {
         tmp=p;
         p=p->next;
         free(tmp);
     }
     return p;*/
     /*                            VERSIONE RICORSIVA
     if(p==NULL)
     {
         return p;
     }
     p->next=eliminak(p->next,k);
     if(p->primo > k)
     {
         tmp=p;
         p=p->next;
         free(tmp);
     }
     return p;
     */

 }

 void stampa(nodo*p)
 {
     while(p!=NULL)
     {
         printf("%d\n",p->primo);
         p=p->next;
     }
 }
