#include <stdio.h>
#define MAXP 20 ///essendo una matrice, considero maxp come righe (ovvero il massimo delle parole)
#define MAXL 30 ///considero maxl la lunghezza massima (per colonne)

int leggi(char file[],char matrice[][MAXL]); //come sempre,mettiamo solo la grandezza delle colonne

int main ()
{
    char matrice[MAXP][MAXL];
    char file [MAXL];
    int i=0,n;

    printf("scrivere il nome del file da aprire: ");
    scanf("%s", file);                                ///scrivere il file da aprire come: file.txt

    n=leggi(file,matrice);
    for(i=0;i<n;i++)
    {
        printf("%s\n",matrice[i]);
    }
    return 0;
}


int leggi(char file[],char matrice[][MAXL])
{
    int i=0;
    FILE *fp;
    fp=fopen(file,"r");
    while(!feof(fp))
    {
        fscanf(fp,"%s",matrice [i]); ///non mettiamo [j] perchè si tratta di una lettura fatta principalmente sulle righe
        i++;
    }
    fclose(fp);
    return i;
}
