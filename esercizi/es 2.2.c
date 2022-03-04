#include <stdio.h>
#include <stdlib.h>

struct studente
{
    char cognome [30];
    short votomax;
    short votomin;
    float media;
}s;

int main ()
{  
   int n;
   printf("Quanti studenti vuoi inserire? (max 5)   ");
   scanf("%d",&n);
   do
   {
          printf("\ncognome?\t\t");
          scanf("%s",s.cognome);
          
           printf("\nvoto massimo?\t");
           scanf("%d",&s.votomax);
           
           printf("\nvoto minimo?\t");
           scanf("%d",&s.votomin);
            
            printf("\nmedia voti?\t");
            scanf("%d",&s.media);
          
   }while(n<0 ||n>5);

    
    
    
    
    
    
    
    
    
    return 0;
}





/* do{ 
        if(&s.votomax<0 || &s.votomax>10)
                {
                  printf("errore!");
                }
        }  while(&s.votomax<0 || &s.votomax>10);*/
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
         /* int conta=0;
    int scelta;
    do
    {
        printf("\n\ncognome? \t");
        scanf("%s",s.cognome);
          
       printf("\nvoto massimo?\t");
       scanf("%d",&s.votomax);
       
       printf("\nvoto minimo?\t");
       scanf("%d",&s.votomin);
        
        printf("\nmedia voti?\t");
        scanf("%d",&s.media);
        
        conta++;
        
    }while (conta<5);
    
    
    do
    {
        printf("\t\t****MENU'****\n\n1)visualizza i dati dei 5 studenti\n\n2)cerca uno studente\n\n3)visualizza lo studente con la media piu' alta\n\n0)esci.");
        switch(scelta)
        {
            case 1:
                
            
        }
        
        
        
        
        
    }while(scelta!=0);
    */
