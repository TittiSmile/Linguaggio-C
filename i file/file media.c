///non so che problema c'è. scrive infondo al file ma il risultato è scorretto
#include <stdio.h>
#include <stdlib.h>
#define max 10
int main ()
{
    FILE*fp;
    int i=0;
    int n;
    int v[max];
    int somma=0;
    float media;

    fp=fopen("media.txt","r");
    if(fp==NULL)
    {
        printf("errore di apertura");
        return 1;
    }
    fscanf(fp,"%d",&n);
    if(n>=10)
    {
        printf("troppi numeri");
    }
    else
    {
        for(i=0;i<n;i++)
        {
            fscanf(fp,"%d",&v[i]);
        }
    }
    fclose(fp);

    for(i=0;i<n;i++)
    {
        somma+=v[i];
    }
    media=somma/n;


    fp=fopen("media.txt","a");
    if(fp==NULL)
    {
        printf("errore di apertura");
        return 1;
    }

    fprintf(fp,"la media e': %f",media);
    fclose(fp);

  printf("ho scritto sul file ");

   return 0;
}
