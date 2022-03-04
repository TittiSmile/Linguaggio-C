#include <stdio.h>
#include <stdlib.h>
int main ()
{
    FILE*lettura;
    FILE*scrittura;
    char *cont;
    char parola[100];

    lettura=fopen("testolettura.txt","r");
    if(lettura==NULL)
    {
        printf("errore di apertura");
        return 1;
    }

    scrittura=fopen("copiotesto.txt","w");

    while(1)
    {
        cont=fgets(parola,100,lettura);
        if(cont==NULL)
        {
            break;
        }
        fputs(parola,scrittura);
        ///fputs inserisce ciò che è stato copiato/letto con fgets nel file.
        ///si sarebbe potuto usare anche fprintf(scrittura,"%s",parola). è identico
    }

    fclose(lettura);
    fclose(scrittura);

    printf("ho copiato il testo ");

    return 0;
}
