#include <stdio.h>
int main ()
{
    FILE *pf;
    int x,y;

    if(pf!=NULL)
    {
        pf=fopen("prova.txt","r");
    }
    else
    {
        printf("errore di apertura file");
    }
    /*
    il controllo sopra può essere scritto anche:
    pf=fopen("prova","r");
    if(pf==NULL)
    {printf("errore di apertura");}
    ...
    ...
    ...
    fclose(pf);
    */

     ///leggo il primo numero dal file
    fscanf(pf,"%d",&x);
    ///leggo il secondo numero dal file
    fscanf(pf,"%d",&y);

    ///chiudo il file
    fclose(pf);

    printf("ho letto i numeri: %d e %d",x,y);


    return 0;
}
