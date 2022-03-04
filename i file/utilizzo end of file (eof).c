#include <stdio.h>
#include <stdlib.h>
#define max 10
int main ()
{
    FILE*pf;
    int v[max];
    int i=0,j=0;
    int controllo;
    pf=fopen("arrayeof.txt","r");
    if(pf==NULL)
    {
        printf("errore di apertura");
        return 1;
    }
    for(i=0;i<max;i++)
    {
        controllo=fscanf(pf,"%d",&v[i]);
        if(controllo==EOF)             ///scorre fino alla fine.quando finisce il contenuto del file,esce
        {
            break;
        }
    }

    for(i=0;i<max;i++)
    {
        printf("\n%d ",v[i]);
    }
    fclose(pf);
return 0;
}
