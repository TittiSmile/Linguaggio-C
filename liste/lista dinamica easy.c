#include <stdio.h>
#include <stdlib.h>




 typedef     struct INFO
            {
               int codice;
               struct INFO* next;    
                   
            }info;



int main(int argc, char *argv[])
{
  
  info* TestaLista=NULL;
  info* temp=NULL;
  info* temp1=NULL;
  int i=0;    //variabile contatore 
  
  //inserisco primo elemento il cui indirizzo è la testa della lista
  
  temp=(info*)malloc(sizeof(info)); //creo tramite allocazione dinamica 
  
  temp->codice=i++;   // inizializzo la lista incrementando 'i'
  temp->next=NULL;    // la lista è terminata 
  
  
  TestaLista=temp; //valorizzo testa
  
  ///secondo...devo vedere dove finisce la lista e agganciarlo in coda
  
   temp1=(info*)malloc(sizeof(info)); //creo elemento 
   
   //per poterlo collocare in coda devo cercarne la fine...
   
   
   temp=TestaLista;
   while(temp->next!=NULL)
   {
      temp=temp->next;
   }                       //alla fine del ciclo temp punta all'ultimo
   
   temp->next=temp1;
   temp1->codice=i++;
   temp1->next=NULL;
  
  
  ///terzo...devo vedere dove finisce la lista e agganciarlo in coda
  
   temp1=(info*)malloc(sizeof(info)); //creo elemento 
   
   //per poterlo collocare in coda devo cercarne la fine...
   
   
   temp=TestaLista;
   while(temp->next!=NULL)
   {
     temp=temp->next;
   }            //alla fine del ciclo temp punta all'ultimo 
    
    temp->next=temp1;
    temp1->codice=i++;
    temp1->next=NULL;
 
 
 
 ///quarto...devo vedere dove finisce la lista e agganciarlo in coda
  
   temp1=(info*)malloc(sizeof(info)); //creo elemento 
   
   //per poterlo collocare in coda devo cercarne la fine...
   
   
   temp=TestaLista;
   while(temp->next!=NULL)
   {
     temp=temp->next;
   } //alla fine del ciclo temp punta all'ultimo 
    
    temp->next=temp1;
    temp1->codice=i++;
    temp1->next=NULL;
 
  printf("lista:\n");   
  ////////////STAMPO LISTA
    temp=TestaLista;
  while(temp->next!=NULL)
  {
    printf("%d\n",temp->codice);                     
  temp=temp->next;
  }
   printf("%d\n",temp->codice);   //stampa ultimo
  
  
  system("PAUSE");	
  return 0;
}
