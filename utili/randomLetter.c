#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char *fillArray(char *a);
char *checkLetter(char *a);
void printArray(char *a);
char *fillRandomArray(char *a);
int findElement(char *a,char c);

int main ()
{
    char lettera_rand,choice,l,l1,l2;
    char alfabeto[25];
    int i=0,alfabeto_len=0,cont=0,scelta,a[5];

    srand(time(NULL));

    printf("\tGENERA LETTERE CASUALI\t\n");

     do
    {
        lettera_rand=rand()%25+'A';
        printf("\n\t\t\tLettera:  %c\n\n",lettera_rand);

        printf("\n\n\ncontinuare? s / n\n");
        scanf("%c",&choice);
        fflush(stdin);


    }while(choice!='n');





    return 0;
}

char *fillArray(char *a)
{
    int i=0;

    for (i=0; i<25; i++)
    {
        a[i]=rand()%25+'A';
    }

   return a;

}

void printArray(char *a)
{
    int i=0;

    for (i=0; i<25; i++)
    {
        printf("%c\n",a[i]);
    }
}


char *checkLetter(char *a)
{
    int i=0,cont=0;
    for(i=0;i<25;i++)
    {

    }

}


char *fillRandomArray(char *a);

int findElement(char *a,char c)
{
    int i=0;
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]==c)
        {
            //return 1;
            printf("\nelemento trovato\n");
            //break;
        }
        else
        {
            printf("\nelemento NON trovato\n");
        }
    }
    return 0;

}



/*
     do
    {
        lettera_rand=rand()%25+'A';
        printf("\n\t\t\tLettera:  %c\n\n",lettera_rand);

        printf("\n\n\ncontinuare? s / n\n");
        scanf("%c",&choice);
        fflush(stdin);


    }while(choice!='n');


*/
