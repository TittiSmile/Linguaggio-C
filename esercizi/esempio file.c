#include <stdio.h>
#include <stdlib.h>

int main ()
{
    FILE *pf;
    char a;

    pf=fopen ("prova.txt","w");
    if (pf==NULL)
    {
        printf("Impossibile aprire il file\n");
    }


     fprintf(pf,"scemo chi legge! >:D\n\n");
     fclose(pf);

    pf=fopen("prova.txt","r");
    if(pf==NULL)
    {
        printf("Impossibile aprire il file\n");
    }


    while(!feof(pf))
    {
        a=fgetc(pf);
        printf("%c",a);
    }
    fclose(pf);



    return 0;
}
