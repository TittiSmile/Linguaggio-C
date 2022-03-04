#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
   int dato;
   struct nodo* next;     
        
}Nodo;

int main(int argc, char *argv[])
{
  
  Nodo* Primo=NULL; //il main mantiene l'indirizzo del primo elemento della lista
  Nodo* temp=NULL;
  Nodo* New=NULL;
  int scelta, d,x, trovato;
  
  do
  {
     printf("\n\n**********MENU'*******************\n\n");
     printf("1) inserisci elemento in lista\n");
     printf("2) stampa la lista\n");
      printf("3) cerca in lista\n");
      printf("4) cerca ed elimina in lista\n");
     printf("0) esci\n");
  
     scanf("%d",&scelta);
     
     switch (scelta)
     {
         case 1:
             New=(Nodo*)malloc(sizeof(Nodo)); //cero in Heap nuovo elemento
             printf("inserire dato\n");
             scanf("%d",&d);
             New->dato=d;
             New->next=NULL;
             
             //devo stabilire se è il primo elemento della lista o un successivo...
             
             if(Primo==NULL) //è il primo...valorizzo la testa
             {
               Primo=New;                        
             }
             else //devo collocarlo alla fine della lista
             {
               //scorro la lista fin quando trovo l'eemento che punta a NULL...ossia l'ultimo!!
               temp=Primo;   
               while(temp->next!=NULL) 
               {
                  temp= temp->next  ;//cerco fine lista
               }
                 temp->next= New; //colloco l'indirizzo nel nuovo elemento alla fine...
             }
          break;
         
         case 2:
              temp=Primo; 
               printf("\n*****LISTA*****\n");
               while(temp->next!=NULL)
               {
               printf("elemento:%d\n",temp->dato);
               temp= temp->next ;//scorro il successivo
               }
              printf("elemento:%d\n",temp->dato); //stampo l'ultimo
              
         break;
         case 3:
              temp=Primo; 
              
              printf("inserire elemento da cercare\n");
              scanf("%d",&x);
              trovato=0;
               while(temp->next!=NULL && temp->dato!=x)
               {
                   temp= temp->next ;//scorro il successivo fino alla fine della lista o finquando non lo trova
               }
               if(temp->dato==x) 
               {
                  printf("ok\n"); 
               }
               else
               {
                   printf("non trovato\n");
               }
          break;
          case 4:
              temp=Primo; 
              
              printf("inserire elemento da cercare\n");
              scanf("%d",&x);
              trovato=0;
              
               while(temp->next!=NULL && temp->dato!=x)
               {
               New=temp; //memorizzo quello che sarà il precedente punytatore                       
               temp= temp->next ; //aggiorno il nuovo puntatore...
               }
               
               if(temp->dato==x) 
               {
                
                New->next = temp->next; 
                free(temp);                
                printf("ok eliminato...\n");
               }
               else printf("non trovato\n");
             break;
         case 0:
              //cancellare area Heap...dealloco risorsa
             
              while(Primo->next!=NULL)
               {
                temp=Primo->next; //salvo il successivo...
                  printf("elimino da Heap elemento allocato in:%x\n",Primo); 
                free(Primo);      //cancello l'elemento
                Primo=temp;       //ora primo è il successivo
         
               }
              printf("elimino da Heap elemento allocato in:%x\n",Primo);
              free(Primo);      //cancello l'ultimo elemento
              free(temp);
         break;
     }
  } while(scelta!=0) ; 
  system("PAUSE");	
  return 0;
}
