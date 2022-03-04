#include <stdio.h>
#include <stdlib.h>
typedef struct DATA
{
    int giorno;
    int mese;
    int anno;
}dat;

int main ()
{
    dat a;
    FILE*pf;

    printf("****inserimento data (solo con numeri,per esempio 1/1/17)****\ngiorno?  ");
    scanf("%d",&a.giorno);
    printf("mese? ");
    scanf("%d",&a.mese);
    printf("anno? ");
    scanf("%d",&a.anno);
    printf(" la data e': %d/%d/%d",a.giorno,a.mese,a.anno);

    ///provo ad inserirlo in un file.txt

    pf=fopen("data.txt","w");
    if(pf)
    {
        printf("\n\n\nsto per scrivere sul file...\n");
        fprintf(pf,"la data e': %d %d %d",a.giorno,a.mese,a.anno);
        printf("ho scritto sul file\n");
    }
    else
    {
        printf("ho problemi con l'apertura file");
    }

    fclose(pf);



    return 0;
}
