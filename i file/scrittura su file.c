#include <stdio.h>
#include <stdlib.h>

int main ()
{
    FILE*pf;
    int i=0;
    char s[30];

    pf=fopen("file.txt","w");

    if(pf)
    {
        printf("sto per scrivere sul file.");
        for(i=0;i<20;i++)
        {
            fprintf(pf,"questa e' la riga %d \n",i+1,s);
        }
        printf("\nho scritto sul file.");
    }
    else
    {
        printf("c'è qualche problema...");
    }



    fclose(pf);






    return 0;
}
