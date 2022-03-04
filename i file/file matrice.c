///ATTENZIONE!!!!! il programma,a mio avviso,è ottimo (cioè ho scritto bene) però mi stampa numeri alla cazzo
#include <stdio.h>
#include <stdlib.h>
#define R 10
#define C 10

void leggi(char file[],int matrice[][C],int *righe,int *colonne); ///metto * alle variabili perchè è passaggio per riferimento ovvero
                                                                 ///passo direttamente la variabile che c'è nel main.

void stampa(int matrice[][C],int righe,int colonne);///non c'è bisogno di mettere '*' perchè dopo la funzione leggi,righe e colonne hanno un valore

int main ()
{
    int matrice [R][C];
    int righe,colonne,i=0,j=0;
    char file[20];

    printf("scrivere il nome del file da aprire:  "); ///scrivere,per esempio, così: nome.txt
    scanf("%s",file);

    printf("\nleggo la matrice da file\n");
    leggi(file,matrice,&righe,&colonne);

    printf("\nstampo la matrice letta\n");
    stampa(matrice,righe,colonne);



    return 0;
}

void leggi(char file[],int matrice[][C],int *righe,int *colonne)
{
    int i=0,j=0,r,c;
    FILE *fp;

    fp=fopen(file,"r");
    fscanf(fp,"%d ", &r);
    fscanf(fp,"%d", &c);

    *righe=r;
    *colonne=c;

     for(i=0;i<r;i++)
     {
            for(j=0;j<c;j++)
         {
             fscanf(fp," %d ",&matrice[i][j]);
         }
     }


    fclose(fp);
}


void stampa(int matrice[][C],int righe,int colonne)
{
    int i=0,j=0;
    for(i=0;i<righe;i++)
    {
        for(j=0;j<colonne;j++)
        {
            printf("%d ",matrice[i][j]);
        }
        printf("\n");
    }
}
