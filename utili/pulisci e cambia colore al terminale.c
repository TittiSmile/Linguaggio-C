#include <stdio.h>
#include <stdlib.h>


int main()
{
    int x;
    int scelta;
    int scelta2;
    int colore;

   do
   {

        printf("Ciao bbbello\npremi 5 per pulire lo schermo del terminale\n");
        scanf("%d",&x);
        if(x==5)
        {
            system("cls");
        }
       printf("\ncontinuare?\n\t(1-> si    2->no)");
       scanf("%d",&scelta);


   }while(scelta!=2);


   printf("\nVuoi vedere una cosa figa??? Cambio colore al terminale!");
   printf("\ncolor list:\n0=nero\n1=blu\n2=verde\n3=verdeacqua\n4=rosso\n5=viola\n6=giallo\n7=bianco\n8=grigio\n9=celeste\n");
   printf("10=verde chiaro\n11=ciano\n12=rosso chiaro\n13=rosa\n14=giallo chiaro\n15=beige\n");


   do
   {
        printf("\n\nQual è la tua scelta??\t");
        scanf("%d",&colore);
    switch(colore)
      {
      case 1:
          system ("color 1");
        break;
      case 2:
           system ("color 2");
        break;
      case 3:
           system ("color 3");
        break;
      case 4:
           system ("color 4");
        break;
      case 5:
           system ("color 5");
        break;
      case 6:
           system ("color 6");
        break;
      case 7:
           system ("color 7");
        break;
      case 8:
           system ("color 8");
        break;
      case 9:
           system ("color 9");
        break;
      case 10:
           system ("color A");
        break;
      case 11:
           system ("color B");
        break;
      case 12:
           system ("color C");
        break;
      case 13:
           system ("color D");
        break;
      case 14:
           system ("color E");
        break;
      case 15:
           system ("color F");
        break;
      default:
          printf("\nscelta non valida");
        break;
      }

       printf("\ncontinuare?(3->si  4->no)  \t");
       scanf("%d",&scelta2);

   }while(scelta2=!4);



    return 0;
}
