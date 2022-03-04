#include <stdio.h>
#define max 50
///è importante creare un file di testo e inserire dei numeri a cazzo (in questo caso,si chiama asd)
int leggi(char file[],int v[]);

int main ()
{
    int vettore[max];
    int n;
    int i=0;
    char file[max];

    printf("inserisci il nome del file:  ");
    scanf("%s",file);

    n=leggi(file,vettore);

    printf("contenuto del file:\n");
    for(i=0;i<n;i++)
    {
        printf(" %d ",vettore[i]);
    }

    return 0;
}

int leggi(char file[],int v[])
{
    int i=0;
    FILE*fp;
   // fp=fopen("asd.txt","r");
   fp=fopen(file,"r");
    while(!feof(fp))
    {
        fscanf(fp,"%d",&v[i]);
        i++;
    }
    fclose(fp);
    return i;
}
