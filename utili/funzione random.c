#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void casuale();

int main ()
{

printf("numeri casuali:\n");
casuale();

    return 0;
}


void casuale()
{
    int contatore,i;
    srand(time(NULL));
    for(i=0;i<5;i++)
      {
          printf("\n%d\n",contatore=rand()%100+1);
      }
}
